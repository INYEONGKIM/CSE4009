CC = gcc
TARGET = exe

$(TARGET) : mkdir.o
	$(CC) -o $(TARGET) mkdir.o

mkdir.o : mkdir.c
	$(CC) -c -o  mkdir.o mkdir.c 

clean :
	rm *.o exe
