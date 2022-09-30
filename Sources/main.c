#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure that holds book information.
struct bookInfo{
    char name[30];
    char author[50];
    char publisher[20];
    int publicationDate;
    int edition;
    float price;
}books[5] = {
    {"Javascript Programlama","Ibrahim Celikbilek","Kodlab",2013,8,55.25},
    {"Algoritma","Kadir Camoglu","Kodlab",2011,5,58.50},
    {"Uygulamalarla Autocad","Ismail Ovali","Kodlab",2018,1,55.25},
    {"Her Yonuyle C","Tevfik Kiziloren","Kodlab",2012,10,97.50},
    {"SQL Server 2019","Selcuk Ozdemir","Kodlab",2020,1,48.75}
};

int main() {
    // We define the required variables and arrays, then discard their default values.
    int shoppingCart[5] = {0,0,0,0,0};
    int process, bookNo, continueProcess;
    float shoppingCartamount = 0;
    printf("BOOK SALES SYSTEM\n\n");
    // We pull and list the books and their information in the bookInfo structure.
    printf("# NO #\t # NAME #\t\t\t\t\t# AUTHOR #\t\t\t\t# PUBLISHER #\t# PUBLICATION DATE #\t# EDITION #\t\t# PRICE #\n\n");
    printf("| %d.\t| %s\t| %s\t| %s\t\t| %d\t\t\t\t\t| %d. Edition\t| %.2f₺\n",1,books[0].name,books[0].author,books[0].publisher,books[0].publicationDate,books[0].edition,books[0].price);
    printf("| %d.\t| %s\t\t\t\t\t| %s\t\t\t| %s\t\t| %d\t\t\t\t\t| %d. Edition\t| %.2f₺\n",2,books[1].name,books[1].author,books[1].publisher,books[1].publicationDate,books[1].edition,books[1].price);
    printf("| %d.\t| %s\t\t| %s\t\t\t| %s\t\t| %d\t\t\t\t\t| %d. Edition\t| %.2f₺\n",3,books[2].name,books[2].author,books[2].publisher,books[2].publicationDate,books[2].edition,books[2].price);
    printf("| %d.\t| %s\t\t\t\t| %s\t\t| %s\t\t| %d\t\t\t\t\t| %d. Edition\t| %.2f₺\n",4,books[3].name,books[3].author,books[3].publisher,books[3].publicationDate,books[3].edition,books[3].price);
    printf("| %d.\t| %s\t\t\t| %s\t\t| %s\t\t| %d\t\t\t\t\t| %d. Edition\t| %.2f₺\n\n",5,books[4].name,books[4].author,books[4].publisher,books[4].publicationDate,books[4].edition,books[4].price);
    do{
        // We discard the default continue processing variable.
        continueProcess = 0;
        // We make the transaction query by taking input from the user.
        printf("1 = Add books to shopping cart.\n2 = View shopping cart.\n3 = Complete shopping.\n4 = Delete all books in shopping cart.\n5 = End program.\n");
        printf("Please enter the transaction number you want to make : ");
        scanf("%d",&process);
        // We run the transaction value we get with the input with if-else queries.
        if(process == 1){
            // The process of adding books to the cart.
            printf("\nPlease enter book no: ");
            scanf("%d",&bookNo);
            if(bookNo > 0 && bookNo <= 5){
                shoppingCartamount += books[bookNo-1].price;
                shoppingCart[bookNo - 1] += 1;
                printf("You have successfully added the book named \"%s\" to the cart!\n\n",books[bookNo - 1].name);
                continueProcess = 1;
            }else{
                printf("Invalid book number. Please try again.\n");
                continueProcess = 1;
            }
        }else if(process == 2){
            // The process of viewing the shopping cart.
            if(shoppingCartamount != 0){
                printf("\nYour shopping cart:\n");
                for(int i=0;i<5;i++){
                    if(shoppingCart[i] != 0){
                        printf("%dx %s: %.2f₺\n",shoppingCart[i],books[i].name,shoppingCart[i] * books[i].price);
                    }
                }
                printf("Total Amount: %.2f₺\n\n",shoppingCartamount);
            }else{
                printf("\nThe transaction is invalid: There are no books in your cart.\n\n");
            }
            continueProcess = 1;
        }else if(process == 3){
            // The shopping completion process.
            if(shoppingCartamount != 0){
                printf("\nThe shopping was completed successfully! These are the books you bought:\n");
                for(int i=0;i<5;i++){
                    if(shoppingCart[i] != 0){
                        printf("%dx %s: %.2f₺\n",shoppingCart[i],books[i].name,shoppingCart[i] * books[i].price);
                    }
                }
                printf("Total Amount: %.2f₺\n\n",shoppingCartamount);
            }else{
                printf("\nThe transaction is invalid: There are no books in your cart.\n\n");
                continueProcess = 1;
            }
        }else if(process == 4){
            // The process of resetting the shopping cart.
            if(shoppingCartamount != 0){
                for(int i=0;i<5;i++){
                    shoppingCart[i] = 0;
                }
                shoppingCartamount = 0;
                printf("\nAll books in the basket were successfully deleted!\n\n");
            }else{
                printf("\nThe transaction is invalid: There are no books in your cart.\n\n");
            }
            continueProcess = 1;
        }else if(process == 5){
            // We provide the program termination process with the goto structure.
            printf("\nThe program is being terminated...\n\n");
            goto theEndOfTheProgram;
        }else{
            printf("Transaction invalid: Incorrect transaction value.\n\n");
            continueProcess = 1;
        }
    }while(continueProcess == 1);
theEndOfTheProgram:
    return 0;
}

// THIS PROGRAM WAS WRITTEN BY ~ ORKUN ALP ALIM ~

