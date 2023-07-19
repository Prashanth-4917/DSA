#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node *node;

int random_numbers();
node getnode();
node insertend(node head,int num);
void display(node head);
void sort_pos_neg(node newnode);


node newnode,temp;



int main()
{
    node head=NULL;
    int SIZE,num;
    SIZE=random_numbers();
    FILE *fp;
    fp=fopen("N_random_numbers_input.txt","r");
    for(int i=0;i<SIZE;i++)
    {
        fscanf(fp,"%d",&num);
        head=insertend(head,num);
    }
    printf("\n\nELEMENTS IN LINKED LIST ARE\n");
    display(head);
    sort_pos_neg(head);
    return 0;
}

int random_numbers()
{
    int P,Q,N;
    printf("Enter the range of random numbers\n");
    scanf("%d %d",&P,&Q);
    printf("Enter the quantity of random numbers\n");
    scanf("%d",&N);
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
    return N;
}


node getnode()
{
    newnode=(node)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("No memory allocation\n");
        exit(0);
    }
    return (newnode);
}


node insertend(node head,int num)
{
    newnode=getnode();
    newnode->data=num;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newnode;
    }
    return head;
}


void display(node head)
{
    if(head==NULL)
    {
        printf("LL is empty\n");
        exit(0);
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->link;
        }
    }
    printf("\n\n");
}


void sort_pos_neg(node head)
{
    node head_pos=NULL;
    node head_neg=NULL;
    node cur;
    if(head==NULL)
    {
        printf("Linked List empty\n");
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data<0)
                head_neg=insertend(head_neg,cur->data);
            else
                head_pos=insertend(head_pos,cur->data);
            cur=cur->link;
        }
    }
    printf("\n\nPOSITIVE_NUMBERS ARE\n");
    display(head_pos);
    printf("\n\nNEGATIVE NUMBERS ARE\n");
    display(head_neg);
}
