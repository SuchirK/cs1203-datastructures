//Develop an algorithm that prints the first half of a given linked list without knowing how many elements in the array.

//I am going to use the Hare and Tortoise Algorithm. 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

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

//Function to print the array

void printArray(int *arr, int n) 
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

//Function to create a new node. 

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a node in the linked list

void insertNode(int data)
{
    struct node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode; //If the list is empty, make the new node the head
    }
    else
    {
        struct node *temp = head; //Create a temporary node and point it to the head
        while (temp->next != NULL) //Traverse the list until the last node is reached!
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//Function to print the first half of the linked list without utilising the number of elements 'n'. We are going to implement the Hare and Tortoise algo

void printFirstHalf()
{
    struct node *hare = head; //Hare and Tortoise Algorithm
    struct node *tortoise = head;
    while (hare != NULL && hare->next != NULL) //While the hare and the tortoise are not NULL
    {
        hare = hare->next->next; //Move the hare two nodes ahead
        tortoise = tortoise->next; //Move the tortoise one node ahead
    }

    struct node *temp = head; 
    while (temp != tortoise) //Traverse the list until the tortoise is reached
    {
        printf("%d ", temp->data);
        temp = temp->next; 
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
        insertNode(arr[i]);
    }

    printf("The first half of the linked list is: ");
    printf("\n"); //Print a new line to make things prettier!
    printFirstHalf(); //Calling the print function 
    return 0;
}
