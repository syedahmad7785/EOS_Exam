#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char buff1[20],buff2[10];
    int fd;
    fd=open("fifo",O_RDONLY );
    read(fd,buff1,20);
    read(fd,buff2,20);
    printf("reading data from process 1 : %s	%s\n",buff1,buff2);
    strcat(buff1,buff2);
    printf("concatenation of string = %s",buff1[20]);
    close(fd);
    return 0;
}
