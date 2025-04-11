#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void main(int argc,char *argv[])
{
    printf("pid of ec1 is %d\n", getpid());
    char *args[]={"Hello","Need",NULL};
    execv("./ec2", args);  
    printf("This line won't be executed if execv succeeds\n");
}