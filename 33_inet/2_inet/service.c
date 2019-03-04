#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc,char** argv)
{

	if(argc < 3){
		fprintf(stderr,"argument is too few\n");
		exit(EXIT_FAILURE);
	}

	int server_sockfd,client_sockfd;
	int server_len,client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(server_sockfd < 0){
		perror("server sockfd");
		exit(EXIT_FAILURE);
	}
	server_address.sin_family= AF_INET;
	server_address.sin_port = htons(atoi(argv[2]));
	server_address.sin_addr.s_addr = inet_addr(argv[1]);
	server_len = sizeof(server_address);
	if(bind(server_sockfd,(struct sockaddr*)&server_address,(socklen_t)server_len) < 0){
		perror("server sockfd");
		exit(EXIT_FAILURE);
	}//end if

	if(listen(server_sockfd,10) < 0 ){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	char buf[BUFSIZ];
	strcpy(buf,"hello world!");
	char recv_buf[BUFSIZ];
	bzero(recv_buf,sizeof(recv_buf));
	//	int flags = fcntl(server_sockfd,F_GETFL,0);
	//	fcntl(server_sockfd,F_SETFL,O_NONBLOCK|flags);
	client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_address,(socklen_t *)&client_len);
	if(client_sockfd < 0){
		perror("accept");
		exit(EXIT_FAILURE);
	}
	pid_t pid = fork();
	if(pid < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
		while(1){
			printf("input data :\n");
			scanf("%s",buf);
			getchar();
			send(client_sockfd,buf,sizeof(buf),0);
			printf("server send : %s success\n",buf);
			if(strncmp(buf,"quit",4) == 0){
				break;
			}
		}//while
		close(client_sockfd);
		exit(EXIT_SUCCESS);
	}
	else if(pid > 0){
		while(1){
			recv(client_sockfd,recv_buf,sizeof(recv_buf),0);
			printf("recv : %s \n",recv_buf);
			if(strncmp(recv_buf,"quit",4) == 0){
				break;
			}
		}//while	
		close(client_sockfd);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}//end if

	return 0;
}
