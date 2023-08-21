#include<stdio.h>
#include<stdlib.h>
typedef struct ABC{
    int data;
    struct ABC *next;
}node;

void pop();
void push();
void trasverse();

node *head,*lastNode;
void main(){
    head=NULL;
    lastNode=NULL;
    int n;
    printf("\tPRESS\n******************\n1.for push\n2.for pop\n3.for trasverse\n4.for exit\n******************\n");
    do{
        printf("\nEnter choice:");
        scanf("%d",&n);
        switch(n){
            case 1: push();
               break;
            case 2: pop();
               break;
            case 3: trasverse();
               break;
            case 4:
               break;
            default:
               break;
        }
    }while (n<4);
}
void push(){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter the element to be pushed:");
    scanf("%d",&temp->data);
    temp->next=head;
    head=temp;
}
void pop(){
    node *temp;
    if(head==NULL){
        printf("Strack is empty.\n");
        return;
    }
    temp=head;
    head=head->next;
    printf("%d is delted.\n",temp->data);
    free(temp);
}
void trasverse(){
    node *dh=head;
    while (dh!=NULL){
        printf("%d ",dh->data);
        dh=dh->next;
    }
}