/*
   *	UDP组播发送数据包端
   *
   * 
   *
 */

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
#include <signal.h>
#include <errno.h>

int main(int argc,char** argv)
{
	if(argc < 3 ){
		fprintf(stderr,"%s is too few argument; < ip > < port > \n",argv[0]);
		exit(EXIT_FAILURE);
	}//end if

	int sockfd;
	struct sockaddr_in service_address;
	int service_addrlen = sizeof(service_address);
	
	sockfd = socket(PF_INET,SOCK_DGRAM,0);
	if(sockfd < 0){
		perror("sockfd");
		exit(EXIT_FAILURE);
	}
	bzero(&service_address,sizeof(service_address));
	service_address.sin_family = PF_INET;
	service_address.sin_port = htons(atoi(argv[2]));
	service_address.sin_addr.s_addr = inet_addr(argv[1]);

	char send_buf[BUFSIZ];
	while(1){
		printf("Enter data:\n");
		gets(send_buf);
		if(sendto(sockfd,send_buf,sizeof(send_buf),0,(struct sockaddr*)&service_address,(socklen_t)service_addrlen) < 0){
			perror("sendto");
			exit(EXIT_FAILURE);
		}//if
		printf("send buf : %s \n",send_buf);

		if(strncmp(send_buf,"quit",4) == 0){
			break;
		}
	}//while
	close(sockfd);
	return 0;
}
