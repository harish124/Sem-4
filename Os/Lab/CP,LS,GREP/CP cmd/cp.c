#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int src,dest,nbread;
    char *buff[1024];
    src=open(argv[1],O_RDONLY);

    if(src==-1)
    {
        printf("\nError while opening the Src file errno = %d",errno);
        exit(0);
    }

    dest =open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR,S_IWUSR,S_IXUSR);

    if(dest==-1)
    {
        printf("\nError while opening the Dest file errno = %d",errno);
        exit(0);
    }

    while((nbread=read(src,buff,1024))>0)
    {
        if(write(dest,buff,nbread)!=nbread)
        {
            printf("\nError in writing data");
        }
    }
    if(nbread==-1)
    {
        printf("\nError in reading data");
    }
    if(close(src)==-1)
    {
        printf("\nError in closing Src file");
    }
    if(close(dest)==-1)
    {
        printf("\nError in closing Dest file");
    }
}//emg
