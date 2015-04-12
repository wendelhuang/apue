//习题8.1

#include <stdio.h>
#include <stdlib.h>//exit,
#include <unistd.h>//pid_t,

int glob = 6;

int
main(void)
{
	int var;
	pid_t pid;

	var = 88;
	printf("before vfork\n");

	if ((pid = vfork()) < 0) {
		printf("vfork error\n");
	}else if (pid == 0) {
		glob++;
		var++;
		exit(0);
	}
	
	sleep(5);
	int result = printf("pid = %d, glob=%d, var=%d\n", getpid(), glob, var);
	printf("result: ", result);
	exit(0);
}
