#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>


void main()
{
    int shmid = shmget(65,1024,0666);
    char *str = (char *)shmat(shmid,NULL,0);
    printf("\n%s\n",str);
    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);
}
