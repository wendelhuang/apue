//exec函数示例

#include <sys/wait.h>

#include <unistd.h>//exec,
#include <string.h>//strcat,
#include <stdio.h>
#include <stdlib.h>//exit,
#include <linux/limits.h>//PATH_MAX,

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int
main(void)
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if(pid == 0) {
		char path[PATH_MAX];
		getcwd(path, PATH_MAX);
		strcat(path, "/echoall");
		if (execle(path, "echoall", "myarg1", "MY ARG2", (char *) 0, env_init) < 0)
			printf("execle error\n");
	}

	if (waitpid(pid, NULL, 0) < 0)
		printf("wait error\n");

	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) {
		if (execlp("echoall", "echoall", "only 1 arg", (char *) 0) < 0)
			printf("execlp error\n");
	}

	exit(0);
}
