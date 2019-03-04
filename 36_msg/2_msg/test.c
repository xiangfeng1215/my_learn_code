#include "msg.h"

int main(void)
{
	int pipe1[2];
	if((pipe(pipe1)) < 0){
		perror("");
		exit(EXIT_FAILURE);
	}
	pid_t new_pid = fork();
	if(new_pid < 0){
		perror("");
		return -1;
	}

	if(new_pid ==  0){
		printf("this is child\n");
		int input;
		printf("Enter input child:");
		scanf("%d",&input);
		getchar();
		struct msgbuf buf;
		buf.mtype = 10;

		key_t key = get_key(1);
		int msqid = create_msgget(key);
		if(msqid < 0){
			perror("");
			return -1;
		}
		close(pipe1[0]);
		if(write(pipe1[1],&msqid,sizeof(msqid)) < 0){
			fprintf(stderr,"write failed!!");
			exit(EXIT_FAILURE);
		}
		while(input != -1){
			buf.mtext = input;
			if(my_msgsnd(msqid,&buf) < 0){
				perror("");
				return -1;
			}
			printf("Enter input child:");
			scanf("%d",&input);
			getchar();
		}
		printf("child msqid :%d\n",msqid);
		delete_msgq(msqid);
		wait(0);
		exit(0);
	}

	if(new_pid > 0){
		wait(0);
		printf("this is parent\n");
		key_t key = get_key(2);

		int msqid = create_msgget(key);     
		if(msqid < 0){
			perror("");
			return -1;
		}

		int input;
		printf("Enter input parent:");
		scanf("%d",&input);
		getchar();

		struct msgbuf buf;
		buf.mtype = 10;
		int data[100];
		int data_num = 0;
		int i = 0;
		while(input != -1){
			buf.mtext = input;
			data[i] = input;
			i++;
			data_num ++;
			if(my_msgsnd(msqid,&buf) < 0){
				perror("");
				return -1;
			}
			printf("Enter input parent:");
			scanf("%d",&input);
			getchar();
		}

		close(pipe1[1]);
		int new_msqid;
		if(read(pipe1[0],&new_msqid,sizeof(new_msqid))< 0){
			fprintf(stderr,"read new msqid failed!\n");
			exit(0);
		}
		close(pipe1[0]);
		printf("new_msqid: %d\n",new_msqid);

//		struct msqid_ds msg_ds_buf;
//		if(get_info(new_msqid,&msg_ds_buf) < 0){
//			perror("get_info");
//			//exit(EXIT_FAILURE);
//		}
//		int data_buf[msg_ds_buf.msg_qnum];
		int data_buf[6];
//		printf("msg_qnum : %ld\n",msg_ds_buf.msg_qnum);
	
		struct msgbuf new_msgbuf;
		i = 6;
//		i = msg_ds_buf.msg_qnum;
		while(1){
			if(my_msgrcv(new_msqid,&new_msgbuf) < 0){
				fprintf(stderr,"my_msgrcv  error!\n");
				//exit(EXIT_FAILURE);
			}//end if
			data_buf[i-1] = new_msgbuf.mtext;
			printf("new_msgbuf.mtext: %d \n",new_msgbuf.mtext);
			if(new_msgbuf.mtext < 0)
				break;
		}//end while

		int j = data_num;
		i = 5;
		if(i > j){
			while(i){
				for(;j > 0;j--){
					printf("data[%d] * data_buf[%d] = %d\n",i,j,data[i]*data_buf[j]);
				}
				i--;
			}//end while
		}else{
			while(j){
				for(;i > 0;i--){
					printf("data[%d] * data_buf[%d] = %d\n",i,j,data[i]*data_buf[j]);
				}
				j--;
			}//end while

		}//end if
		delete_msgq(msqid);
	}//end if

	return 0;
}
