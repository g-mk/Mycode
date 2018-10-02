#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

typedef struct{
	char name[50];
	char ipaddr[50];
	char type[5];
	char class[5];
	int ttl;
}header;