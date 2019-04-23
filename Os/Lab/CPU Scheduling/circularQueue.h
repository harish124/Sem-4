#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int bt,at,pid,btcopy;
}process;

int size=0;
process *q;
int rear=-1,front=-1;
void init(int n)
{
    q=(process *)malloc(n*sizeof(process));
    size=n;
}

int isFull()
{
    if(front==(rear+1)%size)
    {
        return 1;
    }

    return 0;
}

int isEmpty()
{
    if(rear==-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(process val)
{
    if((front==0 && rear==size -1)|| front==rear+1)
    {
        printf("\nOverflow!!\nVal not inserted\n");
        return;
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%size;
        q[rear]=val;
    }

}
void dequeue()
{
    if(front==-1)
    {
        printf("\nUnderflow!!\n");
    }
    else
    {
        process elm=q[front];
        if(front==rear)
        {
            //One element case
            front=rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
        printf("\nVal popped = %d",elm.pid);


    }
}
int dqR()
{
    //Spl case of dequeue
    int elm=q[rear].pid;
    printf("\nVal popped = P%d\n",elm);
    if(front==rear)
    {
        //single element case
        front=rear=-1;
        return 1;
    }
    else
    {
        rear=(rear-1+size)%size;    //This line is different from dqF
    }
}

void enqF(process val)
{
    //Spl case of dequeue
    if(isEmpty())
    {
        front=rear=0;
        q[front]=val;
        return;
    }
    else
    {
        front=(front-1+size)%size;  //This line is different from dqF
        q[front]=val;
        return;
    }
}

void display()
{
    if(front==-1)
    {
        printf("\nQueue is already empty\n");
        return;
    }
    int i=front;
    for(i=front;i!=rear;i=(i+1)%size)
    {
        printf("\nP%d\n\tAT: %d\n\tBT: %d",q[i].pid,q[i].at,q[i].bt);
    }
    printf("\nP%d\n\tAT: %d\n\tBT: %d\n",q[i].pid,q[i].at,q[i].bt);
}
