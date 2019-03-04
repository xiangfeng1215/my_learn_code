/*
*  这个一个UDP超时服务端
*  
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

void Function_sig(int signo)
{
	if(signo == SIGALRM){
		printf(" recv time out");
	}
	return;
}


int main(int argc,char** argv)
{
	if(argc < 3){
		fprintf(stderr," %s : too few argumet : <ip> <port> \n",argv[0]);
		exit(EXIT_FAILURE);
	}//end if

	int server_sockfd,client_sockfd;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	int server_addrlen = sizeof(server_address);
	int client_addrlen = sizeof(client_address);

	server_sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(server_sockfd < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(atoi(argv[2]));
	server_address.sin_addr.s_addr = inet_addr(argv[1]);
	if(bind(server_sockfd,(struct sockaddr *)&server_address,(socklen_t)server_addrlen) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	
	}//if
	char recv_buf[BUFSIZ];
	bzero(recv_buf,sizeof(recv_buf));

//	signal(SIGALRM,Function_sig);
	struct sigaction act;
	sigaction(SIGALRM,NULL,&act);
	act.sa_handler = Function_sig;
	act.sa_flags &= ~ SA_RESTART;
	sigaction(SIGALRM,&act,NULL);

	while(1){
		printf("waiting 6s....\n.");
		alarm(6);
		if(recvfrom(server_sockfd,recv_buf,sizeof(recv_buf),0,NULL,NULL) < 0){
			perror("recvfrom");
			//exit(EXIT_FAILURE);
		}
		alarm(0);
		printf("server recv: %s \n",recv_buf);

		if(strncmp(recv_buf,"quit",4) == 0){
			break;
		}
	}//while
	close(server_sockfd);

	return 0;
}
