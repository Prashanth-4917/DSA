#include<time.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

FILE *fp;
struct TreeNode* newNode(int item)
{
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}


struct TreeNode* insert(struct TreeNode* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}


void printNodesAtLevel(struct TreeNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        printf("%d ", root->data);
    }
    else if (level > 1)
    {
        printNodesAtLevel(root->left, level - 1);
        printNodesAtLevel(root->right, level - 1);
    }
}


int getHeight(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if(leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}


void printNodesByLevel(struct TreeNode* root)
{
    int height = getHeight(root);
    int level;

    for (level = 1; level <= height; level++)
    {
        printf("\nNodes at level %d: ", level);
        printNodesAtLevel(root, level);
        printf("\n");
    }
}

int random_numbers(FILE *fp)
{
    int N;
    printf("Enter the quantity of random numbers\n");
    scanf("%d",&N);
    srand(time(NULL));
    for (int i=0; i<N; i++)
        fprintf(fp,"%d\n",rand()%(100-10+1)+10);
    printf("%d Random numbers generated and stored in input file.\n\n\n",N);
    rewind(fp);
    return N;
}



void printTree(struct TreeNode* root, int level) {
    if (root == NULL)
        return;

    int i;
    printTree(root->right, level + 1);
    printf("\n");
    for (i = 0; i < level; i++)
        printf("    ");
    printf("%d", root->data);
    printTree(root->left, level + 1);
}


int main()
{
    int num,N;
    struct TreeNode* root = NULL;
    fp=fopen("RANDOM_INPUT.txt","w+");
    if (fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    N=random_numbers(fp);
    fscanf(fp,"%d",&num);
    root=insert(root,num);
    for(int i=1; i<N; i++)
    {
        fscanf(fp,"%d",&num);
        insert(root, num);
    }

    printf("Printing nodes at each level:\n");
    printNodesByLevel(root);
    printTree(root,0);
    fclose(fp);

    return 0;
}

