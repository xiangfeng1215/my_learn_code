#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>

int main(int argc,char** argv)
{
	int sockfd;
	sockfd = socket(AF_UNIX,SOCK_STREAM,0);
	if(sockfd < 0){
		perror("sockfd");
		exit(EXIT_FAILURE);
	}//if
	struct sockaddr_un address;
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path,"server_socket");
	int addrlen = sizeof(address);
	if(connect(sockfd,(struct sockaddr *)&address,(socklen_t)addrlen) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}
	char ch = 'A';
	write(sockfd,&ch,1);
	sleep(1);
	read(sockfd,&ch,1);
	printf("read ch :  %c\n",ch);
	close(sockfd);
	return 0;
}
