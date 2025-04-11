#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void main(int argc,char *argv[])
{
    printf("pid of ec1 is %d",getpid());
    char *args[]={"Hello","Need",NULL};
    execv("./f",args);
}