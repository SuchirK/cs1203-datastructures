//Deleting Notes from a Binary Search Tree
//Deliverable

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

//Function to insert a node in the BST (Same as binarysearchtree.c)

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

//Function to delete a node from the BST

void deleteNode(int data) 
{
    struct node *temp = root; //Pointer to the node to be deleted
    struct node *parent = NULL; //Pointer to the parent of the node to be deleted
    while (temp != NULL) 
    {
        if (data == temp->data)  //If the node to be deleted is found
        {
            break;
        }
        else if (data < temp->data) //If the data to be deleted is less than the current node data. 
        {
            parent = temp; //Update the parent pointer
            temp = temp->left; //Update the temp pointer
        }
        else
        {
            parent = temp; //Update the parent pointer
            temp = temp->right; //Update the temp pointer
        }
    }
    if (temp == NULL)
    {
        printf("Node not found in the BST \n");
    }
    //We will have to take different cases depending on the children

    //Case 1: Node to be deleted has no children

    else if (temp->left == NULL && temp->right == NULL)
    {
        if (parent == NULL)
        {
            root = NULL;
        }
        else
        {
            if (parent->left == temp)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        free(temp);
    }
    //Case 2: Node to be deleted has one child

    else if (temp->left == NULL || temp->right == NULL)
    {
        if (parent == NULL)
        {
            if (temp->left == NULL)
            {
                root = temp->right;
            }
            else
            {
                root = temp->left;
            }
        }
        else
        {
            if (parent->left == temp)
            {
                if (temp->left == NULL)
                {
                    parent->left = temp->right;
                }
                else
                {
                    parent->left = temp->left;
                }
            }
            else
            {
                if (temp->left == NULL)
                {
                    parent->right = temp->right;
                }
                else
                {
                    parent->right = temp->left;
                }
            }
        }
        free(temp);
    }

    //Case 3: Node to be deleted has two children

    else
    {
        struct node *successor = temp->right; //Pointer to the successor of the node to be deleted
        struct node *successorParent = temp; //Pointer to the parent of the successor
        while (successor->left != NULL) //Find the Successor
        {
            successorParent = successor;
            successor = successor->left;
        }
        temp->data = successor->data;
        if (successorParent->left == successor)
        {
            successorParent->left = successor->right;
        }
        else
        {
            successorParent->right = successor->right;
        }
        free(successor);
    }

}

//Function to print the BST in pre-order traversal

void preOrder(struct node *root) 
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
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
    for (int i = 0; i < n; i++)
    {
        insertNode(arr[i]);
    }
    printf("The BST is: ");
    preOrder(root);
    printf("\n");
    int data;
    printf("Enter the data to be deleted: ");
    scanf("%d", &data);
    deleteNode(data);
    printf("The BST after deletion is: ");
    preOrder(root);
    printf("\n");
    return 0;
}




