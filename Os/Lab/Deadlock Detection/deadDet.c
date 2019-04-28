#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n=0;
    printf("\nEnter the no. of resources: ");
    scanf("%d",&n);

    int resource[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the no. of instances of Resource R%d: ",i+1);
        scanf("%d",&resource[i]);
    }

    int p=0;
    printf("\nEnter the no. of processes: ");
    scanf("%d",&p);

    int avail[n];
    int max[p][n];
    int alloc[p][n];
    alloc[0][0]=n;
    int flag[p];
    int req[p][n];


  /*  alloc[0][0]=0;alloc[0][2]=0;alloc[0][1]=1;alloc[0][3]=0;alloc[0][4]=1;
    alloc[1][0]=0;alloc[1][2]=1;alloc[1][1]=0;alloc[1][3]=0;alloc[1][4]=1;
    alloc[2][0]=0;alloc[2][2]=0;alloc[2][1]=0;alloc[2][3]=0;alloc[2][4]=1;
    alloc[3][0]=1;alloc[3][2]=1;alloc[3][1]=0;alloc[3][3]=0;alloc[3][4]=1;

    req[0][0]=1;req[0][2]=1;req[0][1]=0;req[0][3]=1;req[0][4]=0;
    req[1][0]=1;req[1][2]=0;req[1][1]=1;req[1][3]=0;req[1][4]=0;
    req[2][0]=0;req[2][2]=0;req[2][1]=0;req[2][3]=1;req[2][4]=0;
    req[3][0]=0;req[3][2]=0;req[3][1]=0;req[3][3]=0;req[3][4]=0;    */

    //*************************************************
    printf("\nInput the values for Request Matrix:\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nEnter the val for req[%d][%d] :",i,j);
            scanf("%d",&req[i][j]);
        }
    }
    printf("\nInput the values for Alloc. Matrix:\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nEnter the val for alloc[%d][%d] :",i,j);
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("\nPrinting Alloc. & Req matrices below:\n");

    printf("\n  \tAllocation\t\tRequest");
    //printf("\n  \tA B C\t\t\tA B C");
    printf("\n  \t");

    int temp=n;

    for(char resources='A';temp>0;resources++)
    {
        printf("%c ",resources);
        temp--;
    }
    temp=n;
    printf("\t\t\t");
    for(char resources='A';temp>0;resources++)
    {
        printf("%c ",resources);
        temp--;
    }
    for(int i=0;i<p;i++)
    {

        printf("\nP%d\t",i+1);
        for(int j=0;j<n;j++)
        {
            printf("%d ",alloc[i][j]);
        }
        printf("    \t");

        printf("    \t");
        for(int j=0;j<n;j++)
        {
            printf("%d ",req[i][j]);
        }
    }
    printf("\n");
    //************************************
    //Calculating Available below:

    for(int i=0;i<n;i++)
    {
        int s=0;
        for(int j=0;j<p;j++)
        {
            s+=alloc[j][i];
        }
        avail[i]=resource[i]-s;
    }

    printf("\nPrinting Avail. Sequence Below:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",avail[i]);
    }
    printf("\n");
    //Forming Safety Seq. below
    int index=0;

    int itr=0;
    int count=0;
    while(itr<20)
    {
        for(int i=0;i<p;i++)
        {
            count=0;
            for(int j=0;j<n;j++)
            {
                if(req[i][j]<=avail[j])
                {
                    count++;
                }
            }

            if(count==n)
            {
                req[i][0]=999;
                flag[i]=1;
                index++;
                for(int x=0;x<n;x++)
                {
                    avail[x]+=alloc[i][x];
                }
                printf("\nPrinting Avail. Sequence Below:\n");
                for(int i=0;i<n;i++)
                {
                    printf("%d ",avail[i]);
                }
                printf("\n");
            }
        }
        itr++;
        //just stopping after 20 iterations

    }
    printf("\nIndex = %d\n",index);
    if(index!=p)
    {
        printf("\nThe below processes are in deadlock\n");

        for(int i=0;i<p;i++)
        {
            if(flag[i]!=1)
            {
                printf("P%d ",i+1);
            }
        }
        printf("\n");
    }


}//emg
