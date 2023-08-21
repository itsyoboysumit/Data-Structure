/*APPLICATION OF QUEUE DATA STRUCTURE
1. The famous car manufacturing company, NavaVista, launching their Battery Operated subsidixed 6-seater
Car this 1st December. For that NavaVista had opened the booking for 100 customer only. YOur job is to
maintain the booking details on a first book first basis. You have to accept the follwing details from
the customer : (Name, AadharNo, MobileNo, City). Write a menu driven program to accept a booking , show
the customers details, and sequence in which booking will be served orr 1st December.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2

struct customer
{
    char name[30];
    char AadharNo[17];
    char MobileNO[11];
    char city[20];
};
int f = -1;
int r = -1;
struct customer LQ[MAX];
void insert(char a[30], char b[17], char c[11], char d[20]);
void del();
void display();

int main()
{
    char a[30], b[17], c[11], d[20];
    int n;
    printf("\t PRESS\n");
    printf("*******************\n1. for insertion \n2. for deletion \n3. for display\n4. for exit\n******************");
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d",&n);
        getchar(); // Consume the newline character left in the buffer
        switch (n)
        {
        case 1:
            printf("Enter customer name:");
            gets(a);
            printf("Enter Aadhar Number:");
            gets(b);
            printf("Enter mobile no:");
            gets(c);
            printf("Enter city name:");
            gets(d);
            insert(a, b, c, d);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("EXITED");
            return 0;
        default:
            break;
        }
        
        
    }
    return 0;
}
void insert(char a[30], char b[17], char c[11], char d[20]){
    if(r==MAX-1){
        printf("Sorry, we really appreaciate your effort but currently booking is over.");
    }
    else{
        if(f==-1){
            f=0;
            r=0;
        }
        else{
            r++;
        }
        strcpy(LQ[r].name,a);
        strcpy(LQ[r].AadharNo,b);
        strcpy(LQ[r].MobileNO,c);
        strcpy(LQ[r].city,d);
    }
}
void del(){
    if(f==-1){
        printf("Underflow.");
    }
    else{
        char a[30], b[17], c[11], d[20];
        strcpy(a,LQ[f].name);
        strcpy(b,LQ[f].AadharNo);
        strcpy(c,LQ[f].MobileNO);
        strcpy(d,LQ[f].city);

    }
    if(f==r){
        f=-1;
        r=-1;
    }
    else{
        f++;
    }
}
void display(){
    if(f==-1){
        printf("Queue is empty.");
    }
    else {
        for(int i=f;i<=r;i++){
            printf("\nRECORD NO : %d",i);
            printf("\nNAME OF CUSTOMER:%s",LQ[i].name);
            printf("\nAADHAR NO: %s",LQ[i].AadharNo);
            printf("\nMOBILE NO: %s",LQ[i].MobileNO);
            printf("\nCITY ADDRESS: %s",LQ[i].city);
            printf("\n______________________________");
        }
    }
}
