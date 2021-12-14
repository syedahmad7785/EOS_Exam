#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fd;
	char buff[10];
	fd=open("mdesdfifo",O_RDWR);
	read(fd,buff,10);
	printf("length of reading buffer in P2is  %d", strlen(buff));
	close(fd);
	return 0;
}

