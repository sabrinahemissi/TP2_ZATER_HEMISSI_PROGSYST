#include "fonctions.h"

struct addrinfo hints,*res;
char ipv4[INET_ADDRSTRLEN];
struct sockaddr_in* _address;
int sock;
int main(int argc, char const *argv[])
{
    switch(argc){
        case 4:
        TFTPGetRequest(argc,argv);
        break;
        default :
        printf("Invalid Arguments \n");
        break;
    }
    return 0;
}

void TFTPGetRequest(int argc,char const* argv[])
{
    
    /*Création d'une socket*/
    
    sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    
    /*Configuration*/
	memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;
    
    getaddrinfo(argv[1],argv[2],&hints,&res);
    
    _address = (struct sockaddr_in *) res->ai_addr;
    inet_ntop(AF_INET,&_address->sin_addr, ipv4, INET_ADDRSTRLEN);
    
    printf("%s\n",ipv4);
   
    if(sock != INVALID_SOCKET)
    {
		printf("La socket %d est maintenant ouverte\n" , sock);
		
	}
	
	return;
}

