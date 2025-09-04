
// program to swap two numers using bit manipulation
// coded by Anees Kokadan

#include<stdio.h>

void swap (int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main(){
    int a, b;
    printf("Enter a= ");
    scanf("%d", &a);
    printf("Enter b= ");
    scanf("%d", &b);

    swap(&a,&b);
    printf("Values after swapping:\na= %d\nb= %d", a, b);


    return 0;

}