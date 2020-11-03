#include <stdio.h>

void enqueue(int item, int *Q, int *front, int *rear, int n)
{
    if((*rear+1)%n==*front)
    {
        printf("Queue Overflow!\n");
        return;
    }
    if(*front==-1 && *rear==-1)
        *front=*rear=0;
    else
    {
        *rear=(*rear+1)%n;
    }
    Q[(*rear)]=item;
}
void dequeue(int *Q,int *front,int *rear,int n)
{
    if(*front==-1 && *rear==-1)
    {
        printf("Queue Underflow!\n");
        return;
    }
    if(*front==*rear)
    {
        *front=*rear=-1;
    }
    else
    {
        *front=(*front+1)%n;
    }
}
int frontelement(int *Q,int *front)
{
    return Q[*front];
}
int main()
{
    int n = 5;
    int Q[n];
    int front=-1;
    int rear=-1;
    enqueue(1,Q,&front,&rear,n);
    enqueue(2,Q,&front,&rear,n);
    enqueue(3,Q,&front,&rear,n);
    enqueue(4,Q,&front,&rear,n);
    enqueue(5,Q,&front,&rear,n);

    for(int i=0;i<n-1;i++)
    {
        if(front==rear)
        {
            printf("The Winner is Player No: %d\n",frontelement(Q,&front));
            return 0;
        }
        
        for(int j=0;j<2;j++)
        {
            int temp=frontelement(Q,&front);
            dequeue(Q,&front,&rear,n);
            enqueue(temp,Q,&front,&rear,n);
        }
        printf("Player %d is eliminated\n",frontelement(Q,&front));
        dequeue(Q,&front,&rear,n);
    }
    return 0;
}