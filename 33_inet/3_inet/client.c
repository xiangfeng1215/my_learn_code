#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc,char** argv)
{
	if(argc < 3){
		fprintf(stderr,"  %s is too few argument \n",argv[0]);
		exit(EXIT_FAILURE);
	}
	int client_sockfd;
	struct sockaddr_in client_address;
	int addrlen;
	addrlen = sizeof(client_address);

	client_sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(client_sockfd < 0){
		perror("client sockfd");
		exit(EXIT_FAILURE);
	}
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(atoi(argv[2]));
	client_address.sin_addr.s_addr = inet_addr(argv[1]);

	if(connect(client_sockfd,(struct sockaddr *)&client_address,(socklen_t )addrlen) < 0){
		perror("connect ");
		exit(EXIT_FAILURE);
	}
	char send_buf[BUFSIZ];
	while(1){
		printf("input data:");
		scanf("%s",send_buf);
		if(write(client_sockfd,send_buf,sizeof(send_buf)) < 0){
			perror("write");
		}
		printf("send : %s \n",send_buf);
	}
	close(client_sockfd);
	return 0;
}
