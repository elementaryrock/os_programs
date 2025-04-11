#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>


void main()
{
    int shmid = shmget(65,1024,0666|IPC_CREAT);
    char *str1 = (char *)shmat(shmid,NULL,0);
    printf("\nEnter data\n");
    gets(str1);
    shmdt(str1);
}
