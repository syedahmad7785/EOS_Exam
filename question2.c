#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd;

   

    fd=open("fifo",O_WRONLY | O_CREAT);
    write(fd,"Hello\0",6);
    write(fd,"Bye\0",5);
    close(fd);
    return 0;
}
