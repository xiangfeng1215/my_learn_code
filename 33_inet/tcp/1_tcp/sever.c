#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

int main(int argc,char **argv)
{
	char buf[MAX_BUF];
	if(argc < 3){
		printf(" usage : %s  < ip > < port >\n",argv[0]);
		exit(-1);
	}
	int sck_fd = socket(AF_INET,SOCK_STREAM,0);
	if(sck_fd < 0){
		perror("sockeet");
		exit(-1);
	}
	struct sockaddr_in serveraddr,clientaddr;
 	socklen_t peerlen;
	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(atoi(argv[2]));
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);

	if(bind(sck_fd,(struct sockaddr*)&serveraddr,sizeof(serveraddr) )< 0){
		perror("bind");
	}
	printf("bind success\n");
	if(listen(sck_fd,10) < 0){
		perror("listen failed");
		exit(-1);
	}
	printf("listen \n");

	peerlen = sizeof(clientaddr);
	int connfd ;
	while(1){
		if((connfd = (accept(sck_fd,(struct sockaddr*)&clientaddr,&peerlen))) < 0){
			perror("connect :");
			exit(-1);
		}
		memset(buf,0,sizeof(buf));
		if(recv(connfd,buf,sizeof(buf),0) < 0){
			perror("recv :");
			exit(-1);
		}
		printf("received a message :%s\n",buf);
		strcpy(buf,"wecome come");
		send(connfd,buf,sizeof(buf),0);
		close(connfd);
	}//end while

	close(sck_fd);
	exit(0);
	return 0;
}
