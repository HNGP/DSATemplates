#include<stdio.h>
int min_element(int arr[],int n)
{
    int min = 0;
    for (int i = 0; i < n;i++)
    {
        if(arr[i]<min)
            min = arr[i];
    }
    return min;
}

int max_element(int arr[],int n)
{
    int max = 0;
    for(int i = 0; i < n;i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

int kthSmallest(int* arr, int k, int n)
{
    int low = min_element(arr,n);
    int high = max_element(arr,n);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int countless = 0, countequal = 0;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] < mid)
                ++countless;
            else if (arr[i] == mid)
                ++countequal;
        }
        if (countless < k && (countless + countequal) >= k)
        {
            return mid;
        }
        else if (countless >= k)
        {
            high = mid - 1;
        }
        else if (countless < k && countless + countequal < k)
        {
            low = mid + 1;
        }
    }
}

int main()
{	int n; int k;
	scanf("%d", &n);
    int arr[n];
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);
    int x= kthSmallest(arr, k, n);
    printf("%d", x);
    return 0;
}