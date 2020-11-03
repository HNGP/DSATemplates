#include <stdio.h>
#define max_size 20

int Q[max_size];
int front=-1;
int rear=-1;

void enqueue(int item)
{
    if(front==-1 && rear==-1)
        front=0;
    else if(rear==max_size-1)
    {
        printf("The Queue is full\n");
        return;
    }
    Q[++rear]=item;
}
void dequeue()
{
    if(front==rear+1 || front==-1)
    {
        printf("The Queue is empty\n");
        return;
    }
    ++front;
}
void print()
{
    while(front<=rear)
    {
        printf("%d ",Q[front++]);
    }
}

void calcMax()
{
    int t = front;
    int max = Q[t];
    while(t<=rear)
    {
        if(max<=Q[t])
        {
            max = Q[t];
        }
        t++;
    }
    printf("The largest element is: %d", max);
}


void evenSum()
{
    int t = front;
    int sum = 0;
    while(front<=rear){
        if(Q[t]%2==0){
            sum=sum+Q[t];
        }
        t++;
    }
    printf("\nSum of even numbers: %d", sum);
}

void oddReplace()
{
    int t = front;
    while(t<=rear){
        if(Q[t]%2!=0){
            Q[t]=-1;
        }
        t++;
    }
}


int main()
{
    int n;
    printf("Enter the number of elements to be entered: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int temp;
        printf("Enter %dth item: ",i+1);
        scanf("%d",&temp);
        enqueue(temp);
    }
    //dequeue();
    //calcMax();
    //evenSum();
    //oddReplace();
    //print();

    return 0;
}