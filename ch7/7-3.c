//输出命令行参数

#include <stdio.h>
#include <stdlib.h> //exit

int
main(int argc, char * argv[])
{
	int i;
	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
	exit(0);
}
