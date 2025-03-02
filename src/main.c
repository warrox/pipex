#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(const int argc, char **argv)
{
	char  *ptr[] = {"/bin/sh","-c","ls",NULL};
	if(argc < 5){
		printf("./Pipex <file1> <cmd1> <file2> <cmd2>\n");
	}
	const int  pid = open(argv[1],O_RDWR);
	const int pid_1 = open(argv[2], O_RDWR);
	const int  rc = fork();
	(void)pid;
	(void)pid_1;
	if(rc == -1){
		printf("Fork failed\n");
		exit(EXIT_FAILURE);
	}	
	else if(rc == 0){
		execvp("/bin/sh",ptr);
		char *cmd1[] = {strcat("~/bin",argv[3]),0};
		printf("CMD1 : %s", cmd1[0]);
		write(1,"XXX\n",4);
		printf("Child is call\n");
		// execvp(cmd1[0], cmd1);
		// exit(EXIT_SUCCESS);
	}
	wait(NULL);
	printf("Parent is called\n");
}
