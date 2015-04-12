//打印实际和有效用户ID

#include <stdio.h>
#include <stdlib.h>//exit,

int
main(void)
{
	printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
	exit(0);
}
