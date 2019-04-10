#include<stdio.h>

int getInputs(int size,int bt[],int pid[],int at[],int flag)    //flag -->1 -->preemptive else 0
{
    for(int i=0;i<size;i++)
    {
        printf("\nEnter the pid: ");
        scanf("%d",&pid[i]);
        printf("\nEnter the burst time: ");
        scanf("%d",&bt[i]);

        if(flag==1)
        {
            printf("\nEnter the arrival time: ");
            scanf("%d",&at[i]);
        }
        else
        {
            at[i]=0;
        }

    }
}

void display(int size,int bt[],int pid[],int at[],int wt[],int tat[],int flag)
{
    if(flag==1)
        printf("\nPID\tAT\tBT\tWT\tTAT\n");
    else
        printf("\nPID\tBT\tWT\tTAT\n");
    for(int i=0;i<size;i++)
    {
        if(flag==1)
            printf("P%d \t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],wt[i],tat[i]);
        else
            printf("P%d \t%d\t%d\t%d\n",pid[i],bt[i],wt[i],tat[i]);
    }
    printf("\n");
}
