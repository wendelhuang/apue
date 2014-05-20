//修改程序8-6以避免竞争条件
#include <stdio.h>
#include <stdlib.h>//exit,

static void charatatime(char *);

int
main(void)
{
	pid_t pid;
	
TELL_WAIT();

	if ((pid = fork()) < 0) {
		printf("fork error\n");
	}else if (pid == 0) {
WAIT_PARENT();
		charatatime("output from child\n");
	}else {
		charatatime("output from parent\n");
TELL_CHILD(pid);
	}

	exit(0);
}

static void
charatatime(char * str)
{
	char *ptr;
	int c;

	setbuf(stdout, NULL);//将标准输出设置为非缓冲的
	for (ptr = str; (c = *ptr++) != 0; )
		putc(c, stdout);
}
