#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

char* STR(char*);
//char* RRQ(char*,char*);
//char* FrameRRQ(char*,char*);
char* StrAppend(char*, char);
void PrintFrame(char*);
void TFTPGetRequest(int, char const**);
void TFTPPutRequest(int, char const**);
struct FrameRRQ{
	char* Frame, *File, *Mode;
	int length;
};
#define INVALID_SOCKET -1 
#define SOCKET_ERROR -1
#define PORT 69
#define MAX_RRQ 128
