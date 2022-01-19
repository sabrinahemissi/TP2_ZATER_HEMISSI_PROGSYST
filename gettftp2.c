#include "fonctions.h"

struct addrinfo hints,*res;
char ipv4[INET_ADDRSTRLEN];
int main(int argc, char const *argv[]){
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

void TFTPGetRequest(int argc,char const* argv[]){
    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    getaddrinfo(argv[1],argv[2],&hints,&res);
    do{
        inet_ntop(AF_INET,&((struct sockaddr_in *) res->ai_addr)->sin_addr, ipv4, INET_ADDRSTRLEN);
        printf("%s \n",ipv4);
        res = res->ai_next;
    } while (res);
}
