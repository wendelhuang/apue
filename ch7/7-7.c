//自动变量的不正确使用

#include <stdio.h>

#define DATAFILE "datafile"

FILE *
open_data(void)
{
	FILE *fp;
	char databuf[BUFSIZE];

	if ((fp = fopen(DATAFILE, "r")) == NULL)
		return(NULL);
	if (setvbuf(fp, databuf, _IOLBF, BUFSIZE) != 0)
		return(NULL);
	return(fp);
}
