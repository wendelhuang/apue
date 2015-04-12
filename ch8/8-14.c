//用system执行命令行参数

#include <stdio.h>
#include <stdlib.h>//exit,

void
pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number= %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
		WCOREDUMP(status) ? " (core file generated) " : "");
#else
		"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number= %d\n", WSTOPSIG(status));
}

int
main(int argc, char * argv[])
{
	int status;

	if (argc < 2) {
		printf("command-line argument required\n");
		exit(-1);
	}

	if ((status = system(argv[1])) < 0)
		printf("system() error\n");

	pr_exit(status);

	exit(0);
}
