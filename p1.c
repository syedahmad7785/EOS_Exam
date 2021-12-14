#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main()
{
int fd;
fd = open ("mdesdfifo",O_RDWR);
write(fd, "m M'\n",sizeof(char)*10);
close(fd);
return 0;
}



