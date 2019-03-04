#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc,char** argv)
{

	if(argc < 3){
		fprintf(stderr,"the argumet is too few\n");
		fprintf(stderr,"input : <ip> < port > \n");
		exit(EXIT_FAILURE);
	}

	struct hostent *hostinfo;

	int client_sockfd;
	struct sockaddr_in client_address;
	int client_addrlen;
	client_sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(client_sockfd < 0){
		perror("client sockfd");
		exit(EXIT_FAILURE);
	}

	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(atoi(argv[2]));
	client_address.sin_addr.s_addr = inet_addr(argv[1]);

	client_addrlen = sizeof(client_address);

	if(connect(client_sockfd,(struct sockaddr*)&client_address,(socklen_t)client_addrlen) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}	

	char recv_buf[BUFSIZ];
	char send_buf[BUFSIZ];
	bzero(send_buf,sizeof(send_buf));
	pid_t pid = fork();
	if(pid < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
		while(1){
			if(recv(client_sockfd,recv_buf,sizeof(send_buf),0) < 0){
				fprintf(stderr,"recv\n");
			}
			printf("recv: %s\n",recv_buf);
			if(strncmp(recv_buf,"quit",4) == 0){
				break;
			}
			hostinfo = gethostbyname(argv[1]);
			printf("host: %s \n",hostinfo->h_name);
		}//while
		exit(EXIT_SUCCESS);
	}
	else if(pid > 0){
		while(1){
			printf("Enter data:");
			scanf("%s",send_buf);
			getchar();

			if(strncmp(send_buf,"quit",4) == 0){
				break;
			}
			if(send(client_sockfd,send_buf,sizeof(send_buf),0) < 0){
				perror("send");
			}
			printf("send success\n");		
		}//while

		close(client_sockfd);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	return 0;
}
