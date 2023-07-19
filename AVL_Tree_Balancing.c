#include<time.h>
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in AVL tree
struct AVLNode
{
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

FILE *fp;

// Function to get the height of a node
int getHeight(struct AVLNode* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// Function to calculate the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to create a new node with the given data
struct AVLNode* createNode(int data)
{
    struct AVLNode* newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to right rotate subtree rooted with y
struct AVLNode* rightRotate(struct AVLNode* y)
{
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return the new root
    return x;
}

// Function to left rotate subtree rooted with x
struct AVLNode* leftRotate(struct AVLNode* x)
{
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return the new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct AVLNode* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Function to insert a node into AVL tree
struct AVLNode* insert(struct AVLNode* node, int data)
{
    // Perform the normal BST insertion
    if (node == NULL)
    {
        return createNode(data);
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else     // Duplicate keys are not allowed
    {
        return node;
    }

    // Update the height of the current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Check the balance factor of the node to determine if it's unbalanced
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && data > node->right->data)
    {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}


// Function to print the AVL tree in inorder traversal
void inorder(struct AVLNode* node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
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


// Function to test the AVL tree implementation
int main()
{
    int num,N;
    struct AVLNode* root = NULL;
    fp=fopen("RANDOM_INPUT.txt","w+");
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
    printf("Inorder traversal of the AVL tree: ");
    inorder(root);
    printf("\n");
    fclose(fp);
    return 0;
}
