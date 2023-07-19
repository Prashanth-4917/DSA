#include<stdio.h>
#define R 8
#define C 8
void pawn(char chess[R][C],int r,char col)
{
    for(int i=0;i<8;i++)
    {
        printf("%c.P     ",col,chess[r][i]);
    }
    printf("\n");
}
void white(char chess[R][C])
{
    printf("W.E     ",chess[0][0]);
    printf("W.H     ",chess[0][1]);
    printf("W.C     ",chess[0][2]);
    printf("W.K     ",chess[0][3]);
    printf("W.Q     ",chess[0][4]);
    printf("W.C     ",chess[0][5]);
    printf("W.H     ",chess[0][6]);
    printf("W.E\n\n",chess[0][7]);
    pawn(chess,0,'W');
}

void black(char chess[R][C])
{
    pawn(chess,8,'B');
    printf("\nB.E     ",chess[8][0]);
    printf("B.H     ",chess[8][1]);
    printf("B.C     ",chess[8][2]);
    printf("B.K     ",chess[8][3]);
    printf("B.Q     ",chess[8][4]);
    printf("B.C     ",chess[8][5]);
    printf("B.H     ",chess[8][6]);
    printf("B.E",chess[8][7]);

}

void blank(char chess[R][C])
{
    printf("\n");
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<8;j++)
        {
            printf("__      ");
        }
        printf("\n\n");
    }
}
int main()
{
    char chess[8][8];
    white(chess);
    blank(chess);
    black(chess);
    return 0;
}
