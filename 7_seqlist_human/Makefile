#!/bin/bash

CC=gcc

main: main.o seqlist_humen.o seqlist_humen.h
	$(CC)	-o $@ $^
clean:
	rm -rf *.o
