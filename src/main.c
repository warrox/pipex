#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
	if(argc < 5){
		printf("./Pipex <file1> <cmd1> <file2> <cmd2>\n");
	}
	int pid = open(argv[1],O_RDWR);
	int pid_1 = open(argv[2], O_RDWR);
	int rc = fork();
	(void)pid;
	(void)pid_1;
	if(rc == -1){
		printf("Fork failed\n");
		exit(EXIT_FAILURE);
	}	
	else if(rc == 0){
		printf("Child is call\n");
	}
	wait(NULL);
	printf("Parent is called\n");

}
