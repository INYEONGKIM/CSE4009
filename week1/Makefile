CC = gcc
TARGET = a_exe

$(TARGET) : foo.o bar.o main.o
	$(CC) -o $(TARGET) main.o bar.o foo.o

foo.o : foo.c
	$(CC) -c -o foo.o foo.c

bar.o : bar.c
	$(CC) -c -o bar.o bar.c

main.o : main.c
	$(CC) -c -o main.o main.c

clean:
	rm *.o a_exe
