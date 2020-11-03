#include<stdio.h>

int get_right_child(int tree[], int index,int x)
{
    if(tree[index]!=-1 && ((2*index)+2)<x)
        return tree[(2*index)+2];
    return -1;
}

int get_left_child(int tree[],int index,int x)
{
    if(tree[index]!=-1 && ((2*index)+1)<x)
        return tree[(2*index)+1];
    return -1;
}

int main()
{
    int h,x,i=0;
    int countl=0,countu=0;
    scanf("%d",&h);
    x= (2<<h)-1;
    int arr[x];
    for(i=0;i<x;i++)
    {
        scanf("%d",&arr[i]);
    }
    int ele=0;
    scanf("%d",&ele);
    for(i=0;i<x;i++)
    {
        int y=get_right_child(arr,i,x);
        if(y<ele && y!=-1)
            countl++;
        else if(y>ele && y!=-1)
            countu++;
    }
    for(i=0;i<x;i++)
    {
        int z= get_left_child(arr,i,x);
        if(z<ele && z!=-1)
            countl++;
        else if(z>ele && z!=-1)
            countu++;
    }
    if(arr[0]>ele)
        countu++;
    else if(arr[0]<ele)
        countl++;
    printf("\n%d",countl);
    printf("\n%d",countu);
}