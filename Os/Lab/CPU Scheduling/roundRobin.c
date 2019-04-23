#include<stdio.h>
#include "E:\B.Harish\Sem 4\Os\Lab\CPU Scheduling\circularQueue.h"
#include<stdlib.h>

void enQProcessAtThisTime(int timer,process qcopy[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(qcopy[i].at==timer)
        {
            enqueue(qcopy[i]);
            printf("\nEnqueued P%d Successfully\n",qcopy[i].pid);
        }
    }
    //if match not found return error
    //printf("\nProcess not found\n");
}//eselectProcess
int main()
{
    int n=6;
    printf("\nEnter the no. of processes: \n");
    scanf("%d",&n);

    init(n);
    int timerLimit=0;

    int btcopy[n];
    int print[100];

    process *qcopy=(process *)malloc(n*sizeof(process));

    for(int i=0;i<100;i++)
    {
        print[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        process p;
        p.pid=i+1;
        p.at=i;
        printf("\nEnter the bt for P%d: ",i+1);
        scanf("%d",&p.bt);
        p.btcopy=p.bt;
        timerLimit+=p.bt;
        //enqueue(p);
        qcopy[i]=p;
    }

    display();
    int counter=0;
    int quantum=0;
    int quantumcopy;
    printf("\nEnter the time quantum/slice: ");
    scanf("%d",&quantum);
    quantumcopy=quantum;

    //quantum-=1;
    //quantumcopy-=1;
    int j=0;
    int wt=0,tat=0;
    float avgwt=0.0,avgtat=0.0;
    process temp;

    for(int timer =0;timer<=timerLimit+10;timer++)      //Always give some extra timelimit
    {

        enQProcessAtThisTime(timer,qcopy,n);

        j=front;                            //Most important Step

        printf("\n************************** NEXT ITERATION (Timer = %d) ******************************",timer);
        if(j<0 || j>=n)
        {
            continue;       //Skip Invalid values, in case something goes wrong or if all processes have completed execution (which gives j= -1)
        }
        printf("\nProcess Details:\n\tP%d\n\t\tBT: %d\n",q[j].pid,q[j].bt);

        if(quantum<=0)
        {
            quantum=quantumcopy;      //resetting quantum
        }

        if(q[j].bt<=quantum && q[j].bt>0)
        {
            printf("\nEvaluating: P%d\n",q[j].pid);
            while(q[j].bt>0)
            {
                q[j].bt--;
                timer++;
                enQProcessAtThisTime(timer,qcopy,n);        //After every second if the arrival time of the process matches the timer enqueue it.
                print[counter]=q[j].pid;
                counter++;
            }
            quantum=0;
        }
        else if(q[j].bt>quantum && q[j].bt>0)
        {
            printf("\nEvaluating: P%d\n",q[j].pid);
            while(quantum>0)
            {
                q[j].bt--;
                quantum--;
                timer++;
                enQProcessAtThisTime(timer,qcopy,n);        //After every second if the arrival time of the process matches the timer enqueue it.
                print[counter]=q[j].pid;
                counter++;
            }
        }
        else
        {
            //do nothing
        }

        if(quantum==0 && q[j].bt==0)
        {
            //waiting time = completion time - bt- at
            wt=counter - q[j].btcopy - q[j].at;
            avgwt+=wt;
            printf("\nWt = %d\nbtcopy = %d\nCounter = %d",wt,q[j].btcopy,counter);

            //tat = completion time -at

            tat=counter - q[j].at;
            avgtat+=tat;

            dequeue();

            printf("\nLine 1: Timer = %d\nCounter = %d\n",timer,counter);
        }
        else if(q[j].bt>0)
        {
            if(quantum==0)
            {
                dequeue();
                temp.at=q[j].at;
                temp.bt=q[j].bt;
                temp.pid=q[j].pid;
                temp.btcopy=q[j].btcopy;
                enqueue(temp);
                printf("\nEnqueued P%d ",temp.pid);
            }
            printf("\nLine 2: Timer = %d\nCounter = %d\n",timer,counter);

        }
        else
        {
            //do nothing
        }

    }

    //******************************************************************************************************************
    //Gant Chart Code below
    printf("\n|");
    int temp2=99;   //give some dummy value >counter
    for(int i=0;i<counter;i++)
    {
        if(temp2!=print[i])
            printf("P%d | ",print[i]);
        else
            continue;
        temp2=print[i];
    }
    temp2=99;        //give some dummy value >counter
    printf("\n");
    for(int i=0;i<counter;i++)
    {
        if(temp2!=print[i])
            printf("%d   ",i);
        else
            continue;
        temp2=print[i];
    }
    printf("%d\n",counter);

    printf("\nAvg. Waiting time = %lf\nAvg. Turn-Around time = %lf\n",avgwt/n,avgtat/n);
}//emg
