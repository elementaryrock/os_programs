#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

void main()
{
    int fd,r,s,f;
    char buff[100]="Hello";
    char ans[100];
    f=creat("file.txt",S_IRWXU);
    fd=open("file.txt",O_RDWR);
    s=write(fd,buff,strlen(buff));
    lseek(fd,0,SEEK_SET);
    r=read(fd,ans,strlen(buff));
    printf("\nContent is :\n");
    for(int i=0;i<strlen(buff);i++)
    {
        printf("%c",ans[i]);
    }
    printf("\n");
    close(fd);
}