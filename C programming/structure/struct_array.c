#include<stdio.h>
int main(){

    // structure definition
    struct employee {
        char name[32];
        int id;
        float salary;
    };


// structure array declaration
struct employee k[5];

// variables declaration
int i=0;
char ch;


// reading data fro user and assigning to structure array
for (i=0; i<5; i++){
    printf("Enter name %d: ", i+1);
    scanf("%31[^\n]", k[i].name);
    printf("Enter ID %d: ", i+1);
    scanf("%d", &k[i].id);
    printf("Enter salary %d: ", i+1);
    scanf("%f", &k[i].salary);


    // this while loop is used to avoid the remaining address locations in name array 
    while(ch=getchar()!='\n'&&ch!=EOF)
{
    // nothing is to be written here, leave it as blank
}


} // for loop ends here

// priniting the entered data, from structure array 
for (i=0; i<5; i++){

    printf("Name %d: %s\nID %d: %d\nSalary %d: %.2f\n\n", i+1, k[i].name, i+1, k[i].id, i+1, k[i].salary);

}

    return  0;
}