#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<ctype.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int no_of_files=argc-3;
    int fd[no_of_files];


    if(argc<4)
    {
        printf("\nInsufficient arguments\n");
        exit(0);
    }
    for(int i=3;i<argc;i++)
    {
        int temp=open(argv[i],O_RDONLY);
        if(temp==-1)
        {
            printf("\nError in opening file %s\n",argv[i]);
            exit(0);
        }
        fd[i-3]=temp;
    }

    if(strcmp(argv[1],"-c")==0)
    {
        int count=0;

        for(int i=0;i<no_of_files;i++)
        {
            char buff[100];
            count=0;
            read(fd[i],buff,99);
            char *token;
            //printf("\nBuff: %s",buff);
            token=strtok(buff,"\n");
            //printf("\nToken: %s",token);
            while(token!=NULL)
            {
                if(strstr(token,argv[2]))
                {
                    count++;
                }
                token=strtok(NULL,"\n");
            }
            printf("\n%s : %d\n",argv[i+3],count);
        }

    }
    else if(strcmp(argv[1],"-n")==0)
    {
        int count=0;

        for(int i=0;i<no_of_files;i++)
        {
            char buff[100];
            count=0;
            read(fd[i],buff,99);
            char *token;
            //printf("\nBuff: %s",buff);
            token=strtok(buff,"\n");
            //printf("\nToken: %s",token);
            while(token!=NULL)
            {
                count++;
                if(strstr(token,argv[2]))
                {
                    printf("\n%s : Line %d : %s\n",argv[i+3],count,token);
                }
                token=strtok(NULL,"\n");
            }

        }
    }
    else if(strcmp(argv[1],"-v")==0)
    {
        int count=0;

        for(int i=0;i<no_of_files;i++)
        {
            char buff[100];
            count=0;
            read(fd[i],buff,99);
            char *token;
            //printf("\nBuff: %s",buff);
            token=strtok(buff,"\n");
            //printf("\nToken: %s",token);
            while(token!=NULL)
            {
                count++;
                if(strstr(token,argv[2])==NULL)
                {
                    printf("\n%s : Line %d : %s\n",argv[i+3],count,token);
                }
                token=strtok(NULL,"\n");
            }

        }
    }

}//emg
