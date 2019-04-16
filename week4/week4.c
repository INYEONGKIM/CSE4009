#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>


int main(int argc, char *agrv[]){
	mode_t mode;
	char *str,c;
	
	if(argc<2){
		perror("No path");
		exit(1);
	}
	str = strrchr(agrv[1], '/');
	if(str==NULL){
		perror("ERROR");
		exit(1);
	}
	if(mkdir(str, 0777) != 0){
		perror("Make Error");
		exit(1);
	}

	/*
	while (str != NULL){
		printf("%s\n", str);
		str = strrchr(str,'/');
	}
	*/

	/*
	if((str=strdup(argv[1])!=NULL){
		
	}
	*/
	

	return 0;
}
