#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5
struct stack
{
    int data[SIZE];
    int top;
};


void push(struct stack *sptr, int num)
{
    if(sptr->top==SIZE-1)
        printf("Stack Overflow\n");
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
void pop(struct stack *sptr)
{
    if(sptr->top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        sptr->data[sptr->top];
        sptr->top--;
    }
}
void display(struct stack *aptr,struct stack *bptr,struct stack *cptr)
{
    if(aptr->top==-1)
        printf("Stack A empty\n");
    if(bptr->top==-1)
        printf("Stack B empty\n");
    if(cptr->top==-1)
        printf("Stack C empty\n");
    else
    {
        printf("\n\n\nSTACK A\tSTACK B\tSTACK C\n");
        while(aptr->top!=-1||bptr->top!=-1||cptr->top!=-1)
        {
            printf("%d\t%d\t%d\n",aptr->data[aptr->top],bptr->data[bptr->top],cptr->data[cptr->top]);
            aptr->top--;
            bptr->top--;
            cptr->top--;
        }
    }
}
int peek(struct stack *sptr)
{
    int i,num;
    if(sptr->top==-1)
    {
        printf("Stack empty\n");
    }
    else
    {
        num=sptr->data[sptr->top];
    }
    return num;
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


int main()
{
    struct stack *aptr,*bptr,*cptr;
    struct stack a,b,c;
    aptr=&a;
    bptr=&b;
    cptr=&c;
    aptr->top=bptr->top=cptr->top=-1;
    random_numbers();
    FILE *fp;
    fp=fopen("N_random_numbers_input.txt","r");
    if (fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    int ch,num;
    printf("Enter 1 to push elements into stack until stack is full\n");
    while(aptr->top!=SIZE-1&&bptr->top!=SIZE-1&&cptr->top!=SIZE-1)
    {
        scanf("%d",&ch);
        if(ch)
        {
            fscanf(fp,"%d",&num);
            push(aptr,num);
            fscanf(fp,"%d",&num);
            push(bptr,num);
            fscanf(fp,"%d",&num);
            push(cptr,num);
        }
        else
            printf("Invalid Entry\n");
    }
    display(aptr,bptr,cptr);
    printf("Enter 1 to pop elements from stack until winner is decided\n");
    int x,y,z;
    while(aptr->top!=-1&&bptr->top!=-1&&cptr->top!=-1)
    {
        scanf("%d",&ch);
        if(ch)
        {
            x=peek(aptr);
            y=peek(bptr);
            z=peek(cptr);
            if(x<=y&&x<=z)
                pop(aptr);
            else if(y<=x&&y<=z)
                pop(bptr);
            else if(z<=x&&z<=y)
                pop(cptr);
            display(aptr,bptr,cptr);
        }
        else
            printf("Invalid Entry\n");
    }
    if(aptr->top==-1)
        printf("A is winner\n");
    if(bptr->top==-1)
        printf("B is winner\n");
    if(cptr->top==-1)
        printf("C is winner\n");
    return 0;
}
