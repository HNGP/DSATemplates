#include<stdio.h>
#include<stdlib.h>


int countDigit(int n){
    if (n == 0) 
        return 0; 
    return 1 + countDigit(n / 10); 
}


int calcMax(int n1, int n2){
    if(n1>n2){
        return n1;
    } else {
        return n2;
    }

}

int divideconc(int num[], int x, int y){

    int max1, max2;
    if(y-x<=1){
        return (calcMax(num[x], num[y]));
    } else {
        max1 = divideconc(num, x , (x + y)/2);
        max2 = divideconc(num, ((x+y)/2 + 1), y);
    }
    return (calcMax(max1, max2));

}



int main()
{
    int num, n;
    scanf("%d", &num);
    if(num==0000){
        printf("%d",0);
    } else {
    n = countDigit(num);

    int arr[n];
    for(int i=0; i<n; i++){
        arr[i] = num%10;
        num = num/10;
    }
    int x = 0;
    int y = n-1;
    int ans = divideconc(arr, x, y);
    printf("%d", ans);
    }

}