
#include<stdio.h>

void printBinary(int num){
 for(int bit=31;bit>=0;bit--){
 printf("%d",(num>>bit)&1);
 }
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printBinary(num);

}





