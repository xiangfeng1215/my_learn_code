/*
*
*      udp 客户端
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

int main(int argc,char** argv)
{
	if(argc < 4){
		fprintf(stderr," %s is too few argument! < ip > < port > < file > \n",argv[0]);
		exit(EXIT_FAILURE);
	}
	int udp_sockfd = socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in udp_address;
	int udp_addrlen = sizeof(udp_address);
	udp_address.sin_family = AF_INET;
	udp_address.sin_port = htons(atoi(argv[2]));
	udp_address.sin_addr.s_addr = inet_addr(argv[1]);

	if(connect(udp_sockfd,(struct sockaddr*)&udp_address,(socklen_t)udp_addrlen) < 0){
		perror("connect");
		exit(EXIT_FAILURE);
	}
	char send_buf[100];
	
	FILE* fp2 = fopen(argv[3],"rb");
	int size;
	bzero(send_buf,sizeof(send_buf));
	while(1){
		printf("Enter data:\n");
		size = fread(send_buf,sizeof(char),100,fp2);	
		
		//if(sendto(udp_sockfd,send_buf,sizeof(send_buf),0,(struct sockaddr*)&udp_address,(socklen_t)udp_addrlen) < 0){
		//	perror("sendto");
		//	exit(EXIT_FAILURE);
	//	}
		if(sendto(udp_sockfd,send_buf,size,0,(struct sockaddr*)0,0) < 0){
			perror("sendto");
			exit(EXIT_FAILURE);
		}
		printf("client sendto file\n");
		if(size <= 0){
			break;
		}
	}//while
	close(udp_sockfd);
	fclose(fp2);
	return 0;
}
