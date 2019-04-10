#include<stdio.h>
#include "E:\B.Harish\Sem 4\Os\Lab\CPU Scheduling\schedulingInputs.h"
#include<stdlib.h>

int main()
{
    int n=7;
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

    int prio[n+1];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the priority for process P%d: ",pid[i]);
        scanf("%d",&prio[i]);
    }

    /*pid[0]=0;
    pid[1]=1;
    pid[2]=2;
    pid[3]=3;
    pid[4]=4;
    pid[5]=5;
    pid[6]=6;

    at[0]=0;
    at[1]=1;
    at[2]=2;
    at[3]=3;
    at[4]=4;
    at[5]=5;
    at[6]=6;

    bt[0]=1;
    bt[1]=7;
    bt[2]=3;
    bt[3]=6;
    bt[4]=5;
    bt[5]=15;
    bt[6]=8;

    prio[0]=2;
    prio[1]=6;
    prio[2]=3;
    prio[3]=5;
    prio[4]=4;
    prio[5]=10;
    prio[6]=9;*/


    prio[n]=999;
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

    for(int timer=0;timer<50;timer++)       //just give some random big value > sum of the burst time of all the process (in this case it is 45);
    {
        prio[n]=9999;                   //Just reinitializing prio[n] after evry inner j loop.
        for(int j=0;j<n;j++)
        {
            if(bt[j]<=0)
            {
                continue;
            }
            if(at[j]<=timer && prio[j]<=prio[n])    //low priority number means it has higher priority. i.e prio 1 >prio 2
            {
                if(prio[j]==prio[n])
                {
                    if(at[j]>at[n])
                    {
                        continue;
                    }
                }  //When two process have the same bt then select the process with least arrival time.

                prio[n]=prio[j];
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

            //tat = completion time -bt
            tat[posOfSmallProcess]=(timer+1) - at[posOfSmallProcess];
            avgtat+=tat[posOfSmallProcess];
        }

    }
    displayWithPrio(n,btcopy,pid,at,prio,wt,tat,1);

    int temp=99;    //give some dummy value
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
