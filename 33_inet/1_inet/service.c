#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


#include <assert.h>


int main(int argc,char** argv)
{
	int server_sockfd,client_sockfd;
	int server_len,client_len;
	
	struct sockaddr_un server_address;
	struct sockaddr_un client_address;

	unlink("server_socket");
	server_sockfd = socket(AF_UNIX,SOCK_STREAM,0);
	if(server_sockfd < 0){
		perror("sickid");
		exit(EXIT_FAILURE);
	}
	server_address.sun_family = AF_UNIX;
	strcpy(server_address.sun_path,"server_socket");
	server_len = sizeof(struct sockaddr_un);
	if(bind(server_sockfd,(struct sockaddr*)&server_address,(socklen_t)server_len) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	if(listen(server_sockfd,5) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	while(1){
		char ch;
		printf("server waiting.... \n");
		client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_address,(socklen_t*)&client_len);
		read(client_sockfd,&ch,1);
		printf("read ch : %c \n",ch);
		ch = 'G';
		write(client_sockfd,&ch,1);
		printf("write ch : %c \n",ch);
		close(client_sockfd);
	}//end while
	return 0;
}
