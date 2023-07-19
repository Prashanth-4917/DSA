#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
struct details
{
    int rank;
    char name[10];
    char gender;
    char branch[3];
};

struct queue
{
    struct details student[SIZE];
    int front,rear;
};


void enqueue(struct queue *qptr,struct details data)
{
    if(qptr->rear==-1&&qptr->front==-1)
    {
        qptr->front=qptr->rear=0;
        qptr->student[qptr->rear]=data;
    }
    else if((qptr->rear+1)%SIZE==qptr->front)
        printf("Queue Overflow\n");
    else
    {
        qptr->rear=(qptr->rear+1)%SIZE;
        qptr->student[qptr->rear]=data;
    }
}


struct details dequeue(struct queue *qptr)
{
    struct details data;
    if(qptr->front==-1&&qptr->rear==-1)
    {}
    else if(qptr->front==qptr->rear)
    {
        data=qptr->student[qptr->front];
        qptr->front=qptr->rear=-1;
    }
    else
    {
        data=qptr->student[qptr->front];
        qptr->front=(qptr->front+1)%SIZE;
    }
    return data;
}


void display(struct queue *qptr)
{
    int i;
    if(qptr->front==-1&&qptr->rear==-1)
        printf("Queue is Empty\n");
    else if(qptr->front<=qptr->rear)
    {
        printf("STUDENTS standing in queue are:\n");
        printf("RANK\tNAME\tGENDER\tBRANCH\n");
        for(i=qptr->front; i<=qptr->rear; i++)
            printf("%d\t%s\t%c\t%s\n",qptr->student[i].rank,qptr->student[i].name,qptr->student[i].gender,qptr->student[i].branch);
    }
    else
    {
        printf("STUDENTS standing in queue are:\n");
        printf("RANK\tNAME\tGENDER\tBRANCH\n");
        for(i=qptr->front; i<SIZE; i++)
            printf("%d\t%s\t%c\t%s\n",qptr->student[i].rank,qptr->student[i].name,qptr->student[i].gender,qptr->student[i].branch);
        for(i=0; i<=qptr->rear; i++)
            printf("%d\t%s\t%c\t%s\n",qptr->student[i].rank,qptr->student[i].name,qptr->student[i].gender,qptr->student[i].branch);
    }
}


int main()
{
    struct queue *qptr,q;
    qptr=&q;
    qptr->front=qptr->rear=-1;
    FILE *fp,*fpe,*fpc,*fpm;
    fp=fopen("All_student_details.txt","r");
    fpe=fopen("ECE_Students.txt","w");
    fpc=fopen("CSE_Students.txt","w");
    fpm=fopen("MECH_students.txt","w");
    if(fp==NULL||fpe==NULL||fpc==NULL||fpm==NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    int ch;
    struct details data;
    while(1)
    {
        printf("\n\nEnter your choice\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            fscanf(fp,"%d %s %c %s",&data.rank,data.name,&data.gender,data.branch);
            enqueue(qptr,data);
            printf("Enqueued Successfully\n");
            break;
        case 2:
            data=dequeue(qptr);
            if(strcmp(data.branch,"ECE")==0)
                fprintf(fpe,"%d %s %c %s\n",data.rank,data.name,data.gender,data.branch);
            else if(strcmp(data.branch,"CSE")==0)
                fprintf(fpc,"%d %s %c %s\n",data.rank,data.name,data.gender,data.branch);
            else if(strcmp(data.branch,"MECH")==0)
                fprintf(fpm,"%d %s %c %s\n",data.rank,data.name,data.gender,data.branch);
            printf("Dequeued Successfully\n");
            break;
        case 3:
            display(qptr);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter Valid Choice\n");
        }
    }
    fclose(fp);
    fclose(fpe);
    fclose(fpc);
    fclose(fpm);
    return 0;
}
