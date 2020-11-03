#include<stdio.h>
#include<string.h>


int rec(int x){

    int max, temp, newm;
    if(x<10){
        max = x%10;
    } else {
        max = x%10;
        temp = x/10;
        newm = rec(temp);
        if (max<newm){
            max = newm;
        }
    }
    return max;
}




int main(){

    int num;
    scanf("%d", &num);
    int ans = rec(num);
    printf("%d", ans);

}