// C program to demonstrate insert
// operation in binary
// search tree.
#include<time.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

FILE *fp,*prefp,*infp,*postfp;

// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    // First recur on left child
    printInorder(node->left);
    // Then print the data of node
    fprintf(infp,"%d ", node->key);
    printf("%d ", node->key);
    // Now recur on right child
    printInorder(node->right);

}

void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
    // First print data of node
    fprintf(prefp,"%d ", node->key);
    printf("%d ", node->key);
    // Then recur on left subtree
    printPreorder(node->left);
    // Now recur on right subtree
    printPreorder(node->right);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    // First recur on left subtree
    printPostorder(node->left);
    // Then recur on right subtree
    printPostorder(node->right);
    // Now deal with the node
    fprintf(postfp,"%d ", node->key);
    printf("%d ", node->key);
}


// A utility function to insert
// a new node with given key in BST
struct node* insert(struct node* node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
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


// Driver Code
int main()
{
    int num,N;
    struct node* root = NULL;
    fp=fopen("RANDOM_INPUT.txt","w+");
    infp=fopen("INORDER.txt","w");
    prefp=fopen("PREORDER.txt","w");
    postfp=fopen("POSTORDER.txt","w");
    if (fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    N=random_numbers(fp);
    fscanf(fp,"%d",&num);
    root=insert(root,num);
    for(int i=1;i<N;i++)
    {
        fscanf(fp,"%d",&num);
        insert(root, num);
    }
    // Print order-wise traversal of the BST
    printf("INORDER:");
    printInorder(root);
    printf("\nPREORDER:");
    printPreorder(root);
    printf("\nPOSTORDER:");
    printPostorder(root);
    fclose(fp);
    fclose(infp);
    fclose(prefp);
    fclose(postfp);
    return 0;
}
