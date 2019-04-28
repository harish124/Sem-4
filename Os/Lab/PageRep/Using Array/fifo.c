#include<stdio.h>
#include<stdlib.h>

int checkIfAlreadyPresent(int val,int mem[],int availableFrames)
{
    for(int i=0;i<availableFrames;i++)
    {
        if(val==mem[i])
        {
            return 1;
        }

    }

    return 0;
}//echeck

int displayMem(int mem[],int availableFrames)
{

    for(int i=0;i<availableFrames;i++)
    {
        printf("\n%d",mem[i]);
    }
    printf("\n");
}

int main()
{
    int n=0;
    printf("\nEnter the length of the page reference string: ");
    scanf("%d",&n);
    int pageRefStr[n];

    printf("\nEnter the page reference string: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pageRefStr[i]);
    }

    printf("\nEnter the no. of frames available: ");
    int no_of_frames=0;
    scanf("%d",&no_of_frames);
    int mem[no_of_frames];
    int present=0,front=0,pageFaults=0;
    for(int i=0;i<no_of_frames;i++)
    {
        mem[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        present=checkIfAlreadyPresent(pageRefStr[i],mem,no_of_frames);

        if(!present)
        {
            mem[front]=pageRefStr[i];
            front=(front+1)%no_of_frames;
            pageFaults++;
        }
        else
        {
            continue;
        }


        displayMem(mem,no_of_frames);
    }

    printf("\nNo. of pagefaults = %d",pageFaults);
}//emg
