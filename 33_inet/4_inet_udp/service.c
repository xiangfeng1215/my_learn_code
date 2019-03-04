/*
*
*ＵＤＰ服务端
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc,char** argv)
{

	if(argc < 3){
		fprintf(stderr,"  %s is to few argument < ip > < port > < file > \n",argv[0]);
		exit(EXIT_FAILURE);
	}

	int udp_socket = socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in udp_address;
	int udp_addrlen = sizeof(udp_address);

	udp_address.sin_family = AF_INET;
	udp_address.sin_port = htons(atoi(argv[2]));
	udp_address.sin_addr.s_addr = inet_addr(argv[1]);

	if(bind(udp_socket,(struct sockaddr*)&udp_address,(socklen_t)udp_addrlen) < 0){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	char recv_buf[100];

	FILE* fp1 = fopen(argv[3],"wb+");
	int size;
	bzero(recv_buf,sizeof(recv_buf));
	while(1){
		printf("wait server....\n");
	//	if(recvfrom(udp_socket,recv_buf,sizeof(recv_buf),0,NULL,NULL) < 0){
	//		perror("recvfrom is error");
	//		exit(EXIT_FAILURE);
	//	}
		if((size=recvfrom(udp_socket,recv_buf,sizeof(recv_buf),0,(struct sockaddr*)&udp_address,(socklen_t*)&udp_addrlen) )< 0){
			perror("recvfrom is error");
			exit(EXIT_FAILURE);
		}
		fwrite(recv_buf,sizeof(char),size,fp1);
        if(!size)
			  break;
	}//while
	close(udp_socket);
	fclose(fp1);
	return 0;
}
