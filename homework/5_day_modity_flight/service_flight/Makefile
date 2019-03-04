CC=gcc

main:main.c flight.h flight.c list.h fly.h wrapperMain.c wrapperMain.h msg.h shm.h shm.c sem.h sem.c memoryManger.c memoryManger.h
	$(CC)	-o $@ $^	-lpthread	-g
clean:
	rm -f *.c
