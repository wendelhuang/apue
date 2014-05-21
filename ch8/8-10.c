//执行一个解释器文件的程序

#include <stdio.h>
#include <stdlib.h>//exit,
#include <sys/wait.h>
#include <linux/limits.h>//PATH_MAX
#include <string.h>//strcat
#include <unistd.h>//execl

int
main(void)
{
	pid_t pid;

	char path[PATH_MAX];
	getcwd(path, PATH_MAX);
	char *filename = "testinterp";
	strcat(path, "/");
	strcat(path, filename);

	if ((pid = fork()) < 0) {
		printf("fork error\n");
	}else if (pid == 0) {
		if (execl(path, filename, "myarg1",
					"MY ARG2", (char *)0) < 0)
			printf("execl error\n");
	}
	if (waitpid(pid, NULL, 0) < 0)
		printf("waitpid error\n");
	exit(0);
}
