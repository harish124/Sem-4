#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<ctype.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

void listDir(char *name)
{
    DIR *mydir;
    struct dirent *myfile;

    mydir = opendir(name);
    if (mydir == NULL)  // opendir returns NULL if couldn't open directory
    {
        //It's a file
        return;
    }
    while((myfile = readdir(mydir)) != NULL)
    {
        printf(" %s\n", myfile->d_name);
    }
    closedir(mydir);
}
int main(int argc,char *argv[])
{
    int n=0;
    if(argc >2)
    {
        printf("\nInvalid no. of arguments\n");
        exit(0);
    }
    if(argc==1)
    {
        DIR *mydir;
        struct dirent *myfile;

        mydir = opendir(".");
        if (mydir == NULL)  // opendir returns NULL if couldn't open directory
        {
            //It's a file or invalid directory
            printf("\nInvalid Path");
            exit(0);
        }
        while((myfile = readdir(mydir)) != NULL)
        {
            printf(" %s ", myfile->d_name);
        }
        closedir(mydir);
        printf("\n");
        exit(0);
    }
    if(strcmp(argv[1],"-1")==0)
    {
        listDir(".");
    }
    else if(strcmp(argv[1],"-l")==0)
    {

        struct dirent **myfile;
        n=scandir(".",&myfile,NULL,alphasort);
        while(n--)
        {
            struct stat s;
            if(strcmp(myfile[n]->d_name,".")==0 ||
               strcmp(myfile[n]->d_name,"..")==0)
                continue;
            else
            {
                stat(myfile[n]->d_name,&s);
                printf("%d %ld %ld %ld %s\n",s.st_mode,s.st_nlink,s.st_mtime,s.st_dev,myfile[n]->d_name);
            }
        }
    }
    else if(strcmp(argv[1],"-R")==0)
    {

        struct dirent **myfile;
        n=scandir(".",&myfile,NULL,alphasort);
        while(n--)
        {
            struct stat s;
            if(strcmp(myfile[n]->d_name,".")==0 ||
               strcmp(myfile[n]->d_name,"..")==0)
                continue;
            else
            {
                printf(" %s\n", myfile[n]->d_name);
                listDir(myfile[n]->d_name);

            }
        }
    }
}//emg
