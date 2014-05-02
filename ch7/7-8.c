//打印当前资源限制

#if defined(BSD) || defined(MACOS)
#include <sys/time.h>
#define FMT "%10lld "
/*
 *infinite加括号的宽度为10个字符
 */
#else
#define FMT "%10ld "
#endif

#include <sys/resource.h>

#include <stdio.h>
#include <stdlib.h>//exit

#define doit(name) pr_limits(#name, name)

static void pr_limits(char *, int);

int
main(void)
{
#ifdef RLIMIT_AS
	doit(RLIMIT_AS);
#endif
	doit(RLIMIT_CORE);
	doit(RLIMIT_CPU);
	doit(RLIMIT_DATA);
	doit(RLIMIT_FSIZE);
#ifdef RLIMIT_LOCKS
	doit(RLIMIT_LOCKS);
#endif
#ifdef RLIMIT_MEMLOCK
	doit(RLIMIT_MEMLOCK);
#endif
#ifdef RLIMIT_NOFILE
	doit(RLIMIT_NOFILE);
#endif
#ifdef RLIMIT_NPROC
	doit(RLIMIT_NPROC);
#endif
#ifdef RLIMIT_RSS
	doit(RLIMIT_RSS);
#endif
#ifdef RLIMIT_SBSIZE
	doit(RLIMIT_SBSIZE);
#endif
#ifdef RLIMIT_STACK
	doit(RLIMIT_STACK);
#endif
#ifdef RLIMIT_VMEM
	doit(RLIMIT_VMEM);
#endif
	exit(0);
}

static void
pr_limits(char *name, int resource)
{
	struct rlimit limit;

	if (getrlimit(resource, &limit) < 0)
		printf("getrlimit error for %s\n", name);
	printf("%-14s ", name);
	/*
	 * 最长的name为14个字符
	 */
	if (limit.rlim_cur == RLIM_INFINITY)
		printf("(infinite) ");
	else
		printf(FMT, limit.rlim_cur);
	if (limit.rlim_max == RLIM_INFINITY)
		printf("(infinite) ");
	else
		printf(FMT, limit.rlim_max);
	putchar((int)'\n');
}
