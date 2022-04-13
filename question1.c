
#include <sys/wait.h>
   #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>
   #include <string.h>
   #include <sys/types.h>
   #include <sys/stat.h>
   #include <fcntl.h>

int main()
{
    pid_t id;  // Data type pid variable for return type for FORK()API
    int fd_p_c[2]; // file discriptor for sending data from parent to child.
    int fd_c_p[2]; // file discriptor for sending data from child to parent.
    float var;
    float  var2;
    float  var3,var4;
    float  sum;
    pipe(fd_p_c);  //Creating pipe file discriptor for parent to child.
    pipe(fd_c_p);  //Creating pipe file discriptor for child to parent.
    printf("Before calling fork!\n");
    id= fork(); // Creating child process
    printf("After calling fork!\n");

    if (id != 0)  //parent process path
    {
        printf("Enter the Variables\n");
        scanf("%f",&var);
        scanf("%f",&var2);
        write(fd_p_c[1],&var,sizeof(var));    //writing variable 1 to Child Process
        write(fd_p_c[1],&var2,sizeof(var2));  // writing variable 2 to Child Process
        printf("Parent id : %d\nParent Sends Data : %f and %f\n",getpid(), var,var2);
        read(fd_c_p[0],&sum,sizeof(sum));     // reading sum of Variable 1 and variable 2 from Child Process.
        printf("Received SUM data form child to Parent is :%f\n",sum);
    }
    else      // child process path
    {
        read(fd_p_c[0],&var3,sizeof(var3)); //Reading Variable 1 from Parent Process.
        read(fd_p_c[0],&var4,sizeof(var4)); // Reading Variable 2 from Parent Process.
        sum=var3+var4;
        printf("Child id : %d\nChild Parents id: %d\nChild Receives Data : %f and %f\n",getpid(),getppid(), var3,var4);
       // printf("Sum of received data is :%f\n",sum);
        write(fd_c_p[1],&sum,sizeof(sum));  // Writing Sum to Parant Process.
    }
    return 0;
}
