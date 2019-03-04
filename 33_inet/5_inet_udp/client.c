#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

int main(int argc,char **argv)
{	
	if(argc < 3){
		fprintf(stderr," %s too few argument; linke < ip > < port > \n",argv[0]);
		printf("FILE %s \n",__FILE__);
		printf("line %d \n",__LINE__);
		printf("data %s \n",__DATE__);
		printf("time %s \n",__TIME__);
		exit(EXIT_FAILURE);
	}//if

	int client_sockfd;
	struct sockaddr_in client_address;
	struct sockaddr_in server_address;
	int client_addrlen = sizeof(client_address);
	int server_addrlen = sizeof(server_address);
	char send_buf[BUFSIZ];
	
	client_sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(client_sockfd < 0 ){
		perror("client_sockfd");
		exit(EXIT_FAILURE);
	}//if

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(atoi(argv[2]));
	server_address.sin_addr.s_addr = inet_addr(argv[1]);

	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(atoi(argv[2]));
	client_address.sin_addr.s_addr = inet_addr(argv[1]);

	bzero(send_buf,sizeof(send_buf));
	while(1){
		printf("Enter data : \n");
		scanf("%s",send_buf);
		getchar();
		if(sendto(client_sockfd,send_buf,sizeof(send_buf),0,(struct sockaddr*)&server_address,(socklen_t)server_addrlen) < 0 ){
			perror("sendto ");
			exit(EXIT_FAILURE);
		}

		if(strncmp(send_buf,"quit",4) == 0){
			break;
		}//if
	}//while
	close(client_sockfd);
	return 0;
}

