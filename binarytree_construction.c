//Given an array (assume int), construct a Binary Search Tree from it.

//First, make an array of n elements (input from the user) and then convert to BST 

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

//Function to generate a random array of n elements

int *generateArray(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    return arr;
}

//Function to print the array

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

//Function to insert a node in the BST

void insertNode(int data) 
{
    struct node *newNode = createNode(data); 
    if (root == NULL)
    {
        root = newNode; //If the tree is empty, make the new node the root
    }
    else
    {
        struct node *temp = root; //If the tree is not empty, traverse the tree
        while (temp != NULL)  
        {
            if (data < temp->data) 
            {
                if (temp->left == NULL) 
                {
                    temp->left = newNode; //Insert the new node as the left child (which is smaller than the parent)
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
                    temp->right = newNode; //Insert the new node as the right child (which is greater than the parent)
                    break;
                }
                else
                {
                    temp = temp->right; //Traverse the tree
                }
            }
        }
    }
}

//Function to print the BST in Inorder Traversal

void printInorder(struct node *root) 
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left); 
    printf("%d ", root->data);
    printInorder(root->right);
}

//Function to print the BST in Preorder Traversal

void printPreorder(struct node *root) 
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);

}

//Function to print the BST in Postorder Traversal

void printPostorder(struct node *root) 
{
    if (root == NULL)
    {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}




int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); //Taking the user input.
    int *arr = generateArray(n);
    printf("The array is: ");
    printArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        insertNode(arr[i]);
    }
    printf("The BST with Inorder traversal is: ");
    printInorder(root);
    printf("\n");
    printf("\nThe BST with Preorder traversal is: ");
    printPreorder(root);
    printf("\n");
    printf("\nThe BST with Postorder traversal is: ");
    printPostorder(root);
    printf("\n");

    return 0;
}


