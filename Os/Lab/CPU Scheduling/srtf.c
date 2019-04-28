#include<stdio.h>
#include "E:\B.Harish\Sem 4\Os\Lab\CPU Scheduling\schedulingInputs.h"
#include<stdlib.h>

int main()
{
    int n=6;
    printf("\nEnter the no. of processes: \n");
    scanf("%d",&n);

    int bt[n+1],at[n+1],pid[n+1],btcopy[n];
    getInputs(n,bt,pid,at,1);
    bt[n]=9999;
    at[n]=9999;
    pid[n]=9999;

    int posOfSmallProcess=0;
    int print[100];
    int counter=0;

    /*pid[0]=0;
    pid[1]=1;
    pid[2]=2;
    pid[3]=3;
    pid[4]=4;
    pid[5]=5;

    at[0]=0;
    at[1]=1;
    at[2]=2;
    at[3]=3;
    at[4]=4;
    at[5]=5;

    bt[0]=8;
    bt[1]=4;
    bt[2]=2;
    bt[3]=1;
    bt[4]=3;
    bt[5]=2;*/

    int wt[n],tat[n];
    float avgwt=0.0,avgtat=0.0;

    for(int i=0;i<50;i++)
    {
        print[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        btcopy[i]=bt[i];
    }
    for(int i=0;i<n;i++)
    {
        wt[i]=-1;
        tat[i]=-1;
    }

    for(int timer=0;timer<25;timer++)       //just give some random big value > sum of the burst time of all the process;
    {
        bt[n]=9999;
        for(int j=0;j<n;j++)
        {
            if(bt[j]<=0)
            {
                continue;
            }
            if(at[j]<=timer && bt[j]<=bt[n])
            {
                if(bt[j]==bt[n])
                {
                    if(at[j]>at[n])
                    {
                        continue;
                    }
                }  //When two process have the same bt then select the process with least arrival time.

                bt[n]=bt[j];
                at[n]=at[j];
                posOfSmallProcess=j;

            }
        }
        //printf("\nSmall Process index = %d",posOfSmallProcess);
        if(bt[posOfSmallProcess]>0)
        {
            bt[posOfSmallProcess]--;
            print[counter]=pid[posOfSmallProcess];
            //printf("P%d = %d\n",counter+1,pid[counter]);
            counter++;
        }
        if(bt[posOfSmallProcess]==0 && wt[posOfSmallProcess]==-1)
        {
            //waiting time = completion time -bt - at
            wt[posOfSmallProcess]= (timer+1)-at[posOfSmallProcess]-btcopy[posOfSmallProcess];
            avgwt+=wt[posOfSmallProcess];

            //tat = completion time -at
            tat[posOfSmallProcess]=(timer+1) - at[posOfSmallProcess];
            avgtat+=tat[posOfSmallProcess];
        }

    }
    display(n,btcopy,pid,at,wt,tat,1);
    int temp=99;
    for(int i=0;i<counter;i++)
    {
        if(temp!=print[i])
            printf("P%d  ",print[i]+1);
        else
            continue;
        temp=print[i];
    }
    temp=99;        //give some dummy value
    printf("\n");
    for(int i=0;i<counter;i++)
    {
        if(temp!=print[i])
            printf("%d   ",i);
        else
            continue;
        temp=print[i];
    }
    printf("%d\n",counter);
    printf("\nAvg. Waiting time = %lf\nAvg. Turn-Around time = %lf\n",avgwt/n,avgtat/n);

}//emg
