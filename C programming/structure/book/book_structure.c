#include<stdio.h>

// this code is written by Anees Kokadan
// it is to read the details of 3 books from user 
// and print the details of most expensive book

int main(){

    struct book{
        char title[50];
        char author[30];
        float price;
    };

    int i=0;
    char ch;
    struct book k[2];

    // reading details of three books from user 
    for (i=0; i<=2; i++){
        printf("Enter Name of book %d: ", i+1);
        scanf("%[^\n]", &k[i].title);
        while(ch=getchar()!='\n' && ch!=EOF){}

        printf("Enter author of book %d: ", i+1);
        scanf("%[^\n]", &k[i].author);
        while(ch=getchar()!='\n' && ch!=EOF){}

        printf("Enter price of book %d: ", i+1);
        scanf("%f", &k[i].price);
        while(ch=getchar()!='\n' && ch!=EOF){}
        
    }
    
    // printing details of most expensive book
    float exp=0;
    int l=0;
    for (i=0; i<=2; i++){
        if (k[i].price>exp){
            exp=k[i].price;
            l=i;
        }

    }
    printf("\nThe most expensive book is book %d: %s",l+1, k[l].title);
    printf("\nAuthor: %s ", k[l].author);
    printf("\nExpense is: %.2f", k[l].price);

    
    return 0;
}


