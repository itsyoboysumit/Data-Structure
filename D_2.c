/*Write a program to implement circular queue using array.*/

#include <stdio.h>

#define MAX 6

int CQ[MAX];
int F, R, flag;
void insert(int item);
int deletion();
void display();

int main()
{
    int n, k, i;
    R = MAX - 1;
    F = MAX - 1;
    flag = 0;
    n = 0;
    printf("\tPRESS\n****************\n1 for insertion\n2 for deletion\n3 for display\n4 for exit\n****************");
    for (i = 0;; i++)
    {
        printf("\nEnter choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the item to be inserted:");
            scanf("%d", &k);
            insert(k);
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
        if (n >= 4)
            break;
    }
    return 0;
}
void insert(int item)
{
    if ((R + 1) % MAX == F && flag == 1)
    {
        printf("Overflow");
    }
    else
    {
        R = (R + 1) % MAX;
        CQ[R] = item;
        flag = 1;
    }
}
int deletion()
{
    if (F == R && flag == 0)
    {
        printf("Underflow");
        return -1;
    }
    else
    {
        F = (F + 1) % MAX;
        int item = CQ[F];
        flag = 0;
        return (item);
    }
}
void display()
{
    if (F == R && F == 0)
    {
        printf("Qqueue is empty.");
    }
    else
    {
        int i = (F + 1) % MAX;
        printf("Current queue:");
        while (i != (R + 1) % MAX)
        {
            printf("%d  ", CQ[i]);
            i = (i + 1) % MAX;
        }
    }
}
