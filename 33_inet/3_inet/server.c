/*
*
*   这是一个服务端，用来测试网络信息的获得
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>

int main(int argc,char** argv)
{
	if(argc < 3){
		fprintf(stderr,"%s is too few argument; < ip > < port >  \n",argv[0]);
		exit(EXIT_FAILURE);
	}
	int server_sockfd,client_sockfd;
	int server_addrlen,client_addrlen;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	server_addrlen = sizeof(server_address);
	client_addrlen = sizeof(client_address);

	server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(server_sockfd < 0){
		perror("server_sockfd");
		exit(EXIT_FAILURE);
	}
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(atoi(argv[2]));
	server_address.sin_addr.s_addr = inet_addr(argv[1]);
	
	if(bind(server_sockfd,(struct sockaddr*)&server_address,(socklen_t)server_addrlen) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	if(listen(server_sockfd,10) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	signal(SIGCHLD,SIG_IGN);
	char recv_buf[BUFSIZ];
	char send_buf[BUFSIZ];
	while(1){
		char ch;
		printf("server wait ...\n");
		client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address,(socklen_t *)&client_addrlen);
		if(client_sockfd < 0){
			perror("client accept");
			exit(EXIT_FAILURE);
		}
		pid_t pid = fork();
		if(pid < 0){
			perror("fork");
			exit(EXIT_FAILURE);
		}else if(pid == 0){
			if(recv(client_sockfd,recv_buf,sizeof(recv_buf),0) < 0){
				perror("recv");
				exit(EXIT_FAILURE);
			}
			printf("recv : %s \n",recv_buf);
			exit(EXIT_SUCCESS);
		}
		else if(pid > 0){
			close(client_sockfd);
		}
	}
	return 0;
}
