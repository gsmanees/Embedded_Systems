
#include<stdio.h>

 #pragma pack(1)
   struct k{
         char x : 8;
         char y : 8;
         int z : 8;
    };

int main(){

    // declaring a structure for understanding its memory allocation concept
    // by sizeof operator 
   

    // in this structure first 4 bytes will be allocated to int x
    // then 1 byte to char 
    // then 4 bytes to int x, but there is a overflow for 4 byte cycle
    // hence it will allocate on next 4 byte cycle
    // and it will leave the 3 remaining bytes allocated to previous char
    // hence total 12 bytes will be allocated to this structure
    // this cooncept is called structure padding 

    printf("\nSize of structure k = %d", sizeof(struct k));

return 0;
    }