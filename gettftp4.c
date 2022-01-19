#include "fonctions.h"



int main(int argc, char *argv[]){
// argc: compte le nombre d'arguments que l'on insère 
// argv: série de caractère dans laquelle on met le serveur et le ficher 
	printf("Client started.\n"); //informe que le client à commencer 

	//nous donne l'information requise : la boucle est utilisé ici pour savoir si les arguments utiles sont insérés 
	if (argc <3){ 
		printf("Not enough arguments\n");
		exit (EXIT_FAILURE);
	}
	
	else {
		
		char *server = argv[1];
		char *file = argv[2];
		// nous allons maintenant afficher le datagramme 
		printf("argc: %d\n", argc);
		printf("server: %s\n", server);
		printf("file: %s\n", file);
				
		//indique l'adresse du serveur
		//déclaration des variables utiles		
		struct addrinfo hints;
		memset(&hints,0,sizeof(struct addrinfo));
		// un pointeur sur le pointeur de addrinof pour avoir une liste liée qui contient tous les résultats une fois la fonction exécutée
		struct addrinfo *res;
		// depuis qu'on utilise IPV4 on indique:
		hints.ai_family = AF_INET;
		// on indique qu'on veut utiliser socket 
		hints.ai_socktype = SOCK_DGRAM;
		hints.ai_flags=0;
		hints.ai_protocol = 0;
		
		int resultat = getaddrinfo(server, "1069", &hints, &res);
		printf("resultat : %d\n", resultat); // si gettredinfo tourne elle affiche 0

		// On utilise la boucle pour détecter les erreurs 
		if (resultat != 0){
			fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(resultat));
			exit(EXIT_FAILURE);
			} 
			
			else {
				
				printf("Client socket translated\n");
				}
				
				//  réservation d'un socket dans le serveur

				int clientsocket = socket( res->ai_family, res->ai_socktype, res->ai_protocol);
				printf("clientsocket: %d\n", clientsocket );


				// création d'une requête  RRQ

				char RRQ[150];
				char *mode= "octet";

				RRQ[0]=0;
				RRQ[1]=1;
				mode = "octet";
				strcpy(RRQ+2, file);
				RRQ[2+strlen(file)]=0;
				strcpy(RRQ+3+strlen(file), mode);

				RRQ[3+strlen(file)+strlen(mode)]=0;

				int lenRRQ = 3+strlen(file)+strlen(mode)+1;

				int send = sendto(clientsocket, RRQ, lenRRQ, 0, res->ai_addr, res->ai_addrlen);
				printf("send = %d\n",send);
				
				
				//Réception d'une requête DATA et ACK
				
				struct sockaddr received;
				socklen_t receivedlen;
				char DATA[516];
				DATA[0]=1;
				DATA[1]=1;
				DATA[2]=0xF;
				DATA[3]=0xF;
				strcpy(DATA+4, "Block");
				 
				int rcv = recvfrom(clientsocket, DATA, 1024, 0, (struct sockaddr *)&received, &receivedlen);
				printf("received = %d\n", rcv);
				
				char ACK[4];
				ACK[0] = 0;
				ACK[1] = 4;
				ACK[2] = DATA[2];
				ACK[3] = DATA[3];
				
				
				int rv = recvfrom(clientsocket, ACK, 1024, 0, (struct sockaddr *)&received, &receivedlen);
				printf("received = %d\n", rv);
				
			}

}
