#include<stdio.h>
#include<stdlib.h>

void merge(int left[],int right[],int a[],int n,int m)
{
    int i=0,j=0,k=0;

    while(i<n && j<m){
        if(left[i]<=right[j]){
            a[k++]=left[i++];
        }
        else{
            a[k++]=right[j++];
        }
    }

    while(i<n)
    {
        a[k++]=left[i++];
    }

    while(j<m)
    {
        a[k++]=right[j++];
    }
}
int mergeSort(int a[],int n,int k)
{
    if(n<2)
    {
        if(a[0]==k)
            return 0;
        else
            return -1;
    }
    int mid = n/2;
    int left[mid], right[n-mid];
    int i;
    for(i=0;i<mid;i++)
    {
       left[i]=a[i];
    }
    for(i=mid;i<n;i++)
    {
        right[i-mid]=a[i];
    }
    int p = mergeSort(left,mid,k);
    int q = mergeSort(right,n-mid,k);
    merge(left,right,a,mid,n-mid);
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            return i;
        }
    }
    return -1;

}

int main()
{
    int n,k;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    int pos = mergeSort(a,n,k);
    if(pos<n/2 && pos>=0)
    {
        printf("%c\n",'A');
        printf("%d\n",pos);
        printf("%d\n",pos);
    }
    else if(pos>=n/2)
    {
        printf("%c\n",'B');
        printf("%d\n",pos-(n/2));
        printf("%d\n",pos);
    }
    if(pos==-1)
    {
        printf("%d",-1);
    }
    return 0;
}