#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "E:\B.Harish\Sem 4\Os\Lab\Implementation of Paging\stack.h"
typedef struct directory
{
    int sbno;    //starting block no.
    char fname[25];  //filename like producer.c,etc
    int ebno;   //ending block no.
    struct directory *next;
}dir;

int memSize=0;
dir *rt=NULL;

typedef struct node
{
    int sbno;
    int ebno;
    int val;
    struct node *next;
}node;
node *hd=NULL;

void init(int size)
{
    rt=(node *)malloc(sizeof(node));
    initfreeFrameList(size);
    for(int i=0;i<size;i++)
    {
        push(i);
    }
}
//Note memory is allocated contiguously in the array
//Whereas the directory maintains its file via linked list

dir * addFile(dir *rt)
{
    int i=0;
    printf("\nEnter any no. btw [0,%d): ",memSize);
    scanf("%d",&i);
    int fileSize=0;
    char fname[25];
    printf("\nEnter the filename: ");
    getchar();
    gets(fname);
    printf("\nEnter the size of the file: ");
    scanf("%d",&fileSize);
    int temp=fileSize;
    int temp2=i;

}//eadd

void display(dir *rt)
{
    dir *p=rt;
    if(rt==NULL)
     {
         printf("\nEmpty Directory\n");
         return ;
     }
    printf("\nFileName | Starting Block no. | Length of the File");
    while(p!=NULL)
    {
        printf("\n%s             %d                 %d\n",p->fname,p->sbno,p->size);
        p=p->next;
    }
}//edisplay

int main()
{


    printf("\nEnter the size of the memory: ");
    scanf("%d",&memSize);
    init(memSize);

    int ch=0;
    while(1==1)
    {
        printf("\nPress:\n1:To add a file\n2:To see the file directory\n3:Any other no. to exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                rt=addFile(rt);
                break;
            case 2:
                display(rt);
                break;
            default:
                exit(0);
        }
    }

}
