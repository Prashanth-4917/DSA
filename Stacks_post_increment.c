#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
struct stack
{
    int data[SIZE];
    int top;
};
void push(struct stack *sptr, int num);
void pop(struct stack *sptr);
void display(struct stack *sptr);
void random_numbers();
int main()
{
    random_numbers();
    struct stack *sptr;
    struct stack s;
    sptr=&s;
    sptr->top=0;
    FILE *fp;
    fp=fopen("N_random_numbers_input.txt","r");
    if (fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    int num,ch;
    while(1)
    {
        printf("\n\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n\n");
        printf("Enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            fscanf(fp,"%d",&num);
            push(sptr,num);
            break;
        case 2:
            pop(sptr);
            break;
        case 3:
            display(sptr);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid choice\n");
            break;
        }
    }
    fclose(fp);
    return 0;
}
void push(struct stack *sptr, int num)
{
    if(sptr->top==SIZE)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->data[sptr->top]=num;
        sptr->top++;
    }
}
void pop(struct stack *sptr)
{
    int num;
    if(sptr->top==0)
    {
        printf("Stack underflow\n");
    }
    else
    {
        sptr->top--;
        num=sptr->data[sptr->top];
        printf("POPED %d\n",num);
    }
}
void display(struct stack *sptr)
{
    int i;
    if(sptr->top==0)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("Current Stack Elements are\n");
        for(i=sptr->top-1; i>=0; i--)
            printf("%d\n",sptr->data[i]);
    }
}
void random_numbers()
{
    int P,Q,N;
    printf("Enter the range and quantity of random numbers\n");
    scanf("%d %d %d",&P,&Q,&N);
    FILE *fp;
    fp=fopen("N_random_numbers_input.txt","w");
    if (fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    srand(time(NULL));
    for (int i=0; i<N; i++)
        fprintf(fp,"%d\n",rand()%(Q-P+1)+P);
    printf("%d Random numbers generated and stored in input file.\n",N);
    fclose(fp);
}
