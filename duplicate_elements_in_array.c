#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define R 100 //R IS SIZE OF ARRAY.

void duplicates(int a[])
{
    int d,c,flag2=0;
    printf("\n\nThe duplicate elements with their frequencies are\n");
    for(int i=0; i<R; i++)
    {
        int flag=0,c=0;
        for(int j=i+1; j<R; j++)
        {
            if(a[i]==a[j])
            {
                if(a[j]!=0)
                {
                    flag=1;
                    d=a[i];
                    a[j]=0;
                    c++;
                }
            }
        }
        if(flag==1)
        {
            printf("%d occurs %d times\n",d,c+1);
            flag2=1;
        }
    }
    if(flag2!=1)
        printf("There are no duplicate elements.\n");
}

int main()
{
    int a[R];
    int P,Q;
    printf("Enter the range of random numbers\n");
    scanf("%d %d",&P,&Q);
    srand(time(NULL));
    for (int i=0; i<R; i++)
        a[i]=rand()%(Q-P+1)+P;
    FILE *fp;
    fp=fopen("input_file.txt","w");
    if (fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    for (int i=0; i<R; i++)
        fprintf(fp,"%d\n",a[i]);
    printf("%d Random numbers between %d and %d generated and stored in input file.\n\n\n",R,P,Q);
    printf("\n\nThe elements in the array are\n");
    for(int i=0; i<R; i++)
        printf("%d ",a[i]);
    duplicates(a);
    fclose(fp);
    return 0;
}
