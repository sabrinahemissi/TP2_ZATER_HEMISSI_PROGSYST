#include "fonctions.h"

int main(int argc, char const *argv[])
{
    switch(argc)
    {
        case 4:
        TFTPGetRequest(argc,argv);
        break;
        default :
        printf("Invalid Arguments \n");
        break;
    }
    return 0;
}

void TFTPGetRequest(int argc, char const* argv[]){
    printf("IP = %s PORT = %s FILE = %s \n",argv[1],argv[2],argv[3]);
}
