#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fd;
    pid_t pid;
    caddr_t addr;
    struct stat statbuf;

    if (argc != 2) {
        fprintf(stderr, "Usage : %s filename\n", argv[0]);
        exit(1);
    }

    if (stat(argv[1], &statbuf) == -1) {
        perror("stat");
        exit(1);
    }

    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror("open");
        exit(1);
    }

    //mmap을 이용해 메모리 맵핑 실시
	addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0);
	if(addr == MAP_FAILED){
		perror("MMAP");
		exit(1);
	}

    close(fd);

    switch (pid = fork()) {
        case -1 :  /* fork failed */
            perror("fork");
            exit(1);
            break;
        case 0 :   /* child process */
            //printf로 데이터 확인
			printf("1. CHILD : %s\n", addr);
            
			//데이터 변경 및 동기화
			addr[0]='a';
            sleep(1);
			printf("2. CHILD : %s\n", addr);
	
            //바뀐 데이터 확인
			sleep(1);
			printf("3. CHILD : %s\n", addr);
            break;
        default :   /* parent process */
            //printf로 데이터 확인
			printf("1. PARENT : %s\n", addr);

            //데이터 변경 및 동기화
			sleep(2);
			printf("2. PARENT : %s\n", addr);
			addr[1] = 'b';
			
            //바뀐 데이터 확인
			printf("3. PARENT : %s\n", addr);
            break;
    }

    return 0;
}
