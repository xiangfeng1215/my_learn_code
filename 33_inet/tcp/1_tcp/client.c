#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

int main(int argc,char **argv)
{
	if(argc < 3){
		printf("input argument: <ip> <port> \n");
		return -1;
	}
	char buf[MAX_BUF];
	bzero(buf,sizeof(buf));
	int sck_fp = socket(AF_INET,SOCK_STREAM,0);
	if(sck_fp <0){
		perror("socket:");
		exit(-1);
	}
	struct sockaddr_in addr;
	bzero(&addr,sizeof(addr));
	socklen_t addrlen = sizeof(addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2]));
	addr.sin_addr = inet_addr(argv[1]);

	if(connect(sck_fp,(struct sockaddr*)&addr,addrlen) < 0){
		perror("");
		return -1;
	}	
	strcpy(buf,"hello i am zxf");
	send(sck_fp,buf,sizeof(buf),0);

	if(recv(sck_fp,buf,sizeof(buf),0) < 0){
		perror("recv");
		exit(-1);
	}
	printf("recv for sever:%s \n",buf);
	close(sck_fp);
	exit(0);

	return 0;
}
