#include<stdio.h>
#include<stdlib.h>


    // 1 1 2 3 5 8 13 21

void fibonacci(int x){
    int i,t1=0, t2=1, next;
        for (i=0; i<x; i++){
        printf("%d ", t1);
        next = t1+t2;
        t1=t2;
        t2=next;
    }

}
int main(){


    int n;
    printf("\nEnter the number of terms ");
    scanf("%d",&n);
    
    fibonacci(n);




}