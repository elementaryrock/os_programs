#include <stdio.h>
#include <unistd.h>

void main()
{
    printf("\nI am A\n");
    printf("\nPid of A:%d\n",getpid());
    printf("\nPPid of A:%d\n",getppid());
    int b = fork();
    if(b==0)
    {
        printf("\nI am B\n");
        printf("\nPid of B: %d\n",getpid());
        printf("\nPPid of B: %d\n",getppid());
        int c= fork();
        if(c==0)
        {
            printf("\nI am C\n");
            printf("\nPid of C: %d\n",getpid());
            printf("\nPPid of C: %d\n",getppid());
        }
    }
}