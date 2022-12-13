//AVL Trees. Given an array, construct an AVL tree with helper operations (including left and right rotations)
//Deliverable 
//1. AVL tree with helper operations
//2. AVL tree with helper operations and a function that takes an array and constructs an AVL tree.
//An AVL tree is a self balancing binary search tree. It is balanced if the difference between the heights of the left and right subtrees of any node is at most 1.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

//Function to generate a random array of n elements. Standard generating array function!

int *generateArray(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; //Random number between 0 and 99
    }
    return arr;
}

//Function to print the array. Standard printing array function!

void printArray(int *arr, int n) 
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

//Function to create a new node

struct node *createNode(int data) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to insert a node into the AVL tree. Same as binarysearchtree.c (BSTs)

void insertNode(int data) 
{
    struct node *newNode = createNode(data); 
    if (root == NULL)
    {
        root = newNode; //If the tree is empty, make the new node the root
    }
    else
    {
        struct node *temp = root;
        while (temp != NULL)
        {
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

//Function to find the height of the tree

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
}

//Function to find the balance factor (k) of the tree

int balanceFactor(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return height(root->left) - height(root->right); //k = height of left subtree - height of right subtree
    }
}

//Function to perform a left rotation

struct node *leftRotate(struct node *root) //Left Rotation
{
    struct node *newRoot = root->right; //New root is the right child of the current root
    struct node *temp = newRoot->left; //Temp is the left child of the new root
    newRoot->left = root; //The new root's left child is the current root
    root->right = temp; //The current root's right child is the temp
    return newRoot; 
}

//Function to perform a right rotation

struct node *rightRotate(struct node *root) //Right Rotation
{
    struct node *newRoot = root->left; //New Root is the left child of the current root
    struct node *temp = newRoot->right; //Temp is the right child of the new root
    newRoot->right = root; //The new root's right child is the current root
    root->left = temp; //The current root's left child is the temp
    return newRoot; //Return the new root
}

//Function to insert a node into the AVL tree and balance it

void insertNodeBalanced(int data)
{
    struct node *newNode = createNode(data); 
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        struct node *temp = root;
        while (temp != NULL)
        {
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    int balance = balanceFactor(root); //Find the balance factor of the tree
    if (balance > 1 && data < root->left->data) //If the balance factor is greater than 1 and the data is less than the left child of the root, perform a right rotation
    {
        root = rightRotate(root);
    }
    else if (balance < -1 && data > root->right->data) //If the balance factor is less than -1 and the data is greater than the right child of the root, perform a left rotation
    {
        root = leftRotate(root);
    }
    else if (balance > 1 && data > root->left->data) //If the balance factor is greater than 1 and the data is greater than the left child of the root, perform a left rotation on the left child of the root and then a right rotation on the root
    {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    else if (balance < -1 && data < root->right->data) //If the balance factor is less than -1 and the data is less than the right child of the root, perform a right rotation on the right child of the root and then a left rotation on the root
    {
        root->right = rightRotate(root->right); 
        root = leftRotate(root);
    }
}

//Function to print the AVL tree

void printTree(struct node *root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = generateArray(n);
    printf("The array is: ");
    printArray(arr, n);
    printf("\n"); //Print a new line to make things prettier!
    for (int i = 0; i < n; i++)
    {
        insertNodeBalanced(arr[i]);
    }
    printf("The AVL tree is: ");
    printf("\n"); //Print a new line to make things prettier!
    printTree(root);
    return 0;
    
}


