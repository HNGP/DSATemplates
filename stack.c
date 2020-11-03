#include <stdio.h>

int main() {
    
    int stack[8]; int stack2[8];
    int top1 = -1; int top2 = -1;
    
    void pop(int *topvar, int stack[]) {
        int data;
        if(*topvar!=-1) {
            data = stack[*topvar];
            *topvar = *topvar - 1;   
            printf("\nPopped out: %d",data);
            printf("\nTop now at: %d", *topvar);
        } else {
            printf("\nStack is empty.\n");
        }
    }

    void push(int data, int *topvar, int stack[]) {
        if(*topvar!=8) {
            
            *topvar = *topvar + 1;   
            stack[*topvar] = data;
            printf("\nInserted successfully: %d", data);
            printf("\nTop now at: %d", *topvar);
        } else {
            printf("Stack is full.\n");
        }
    }

    



   push(20, &top1, stack);
   push(21, &top1, stack);
   push(25, &top1, stack);
   push(25, &top1, stack);
  
   
   return 0;
}