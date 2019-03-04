/*
*   	 UDP广播测试程序发送端
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int main(int argc,char** argv)
{
	if(argc < 3 ){
		printf("%s too few argument < ip > < port > \n",argv[0]);
		exit(EXIT_FAILURE);
	}
	int service_sockfd;
	struct sockaddr_in service_address;
	int service_addrlen = sizeof(service_address);

	service_sockfd = socket(PF_INET,SOCK_DGRAM,0);
	if(service_sockfd < 0 ){
		perror("service sockfd");
		exit(EXIT_FAILURE);
	}//if

	service_address.sin_family = PF_INET;
	service_address.sin_port = htons(atoi(argv[2]));
	service_address.sin_addr.s_addr = inet_addr(argv[1]);
	int no = 1;
	if(setsockopt(service_sockfd,SOL_SOCKET,SO_BROADCAST,&no,sizeof(no)) < 0 ){
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	char send_buf[BUFSIZ];
	printf("BUFSIZ : %d \n",BUFSIZ);
	while(1){
		printf("Enter data:\n");
		gets(send_buf);
		if(sendto(service_sockfd,send_buf,sizeof(send_buf),0,(struct sockaddr*)&service_address,(socklen_t)service_addrlen) < 0 ){
			perror("sendto");
		}

		printf("service send : %s \n",send_buf);	
		if(strncmp(send_buf,"quit",4) == 0){
			break;
		}//if
	}//while
	close(service_sockfd);
	return 0;
}





//	if(bind(service_sockfd,(struct sockaddr*)&service_address,(socklen_t)service_addrlen) < 0 ){
//		perror("bind");
//		exit(EXIT_FAILURE);
//	}//if
