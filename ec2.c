#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(int argc,char *argv[])
{  printf("we are in ec2.c \n");
    printf("pid of ec2 is %d\n",getpid());
}