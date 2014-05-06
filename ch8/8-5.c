//调用fork两次以避免僵尸进程
#include <stdio.h>
#include <sys/wait.h>

#include <stdlib.h>//exit,

int
main(void)
{
	pid_t pid;
	
	if ((pid = fork()) < 0) {
		printf("fork error\n");
	}else if (pid == 0) {
		if ((pid = fork()) < 0)
			printf("fork error\n");
		else if (pid > 0)
			exit(0);
		sleep(2);
		printf("second child, parent pid = %d\n", getppid());
		exit(0);
	}

	if (waitpid(pid, NULL, 0) != pid)
		printf("waitpid error\n");

	exit(0);
}
