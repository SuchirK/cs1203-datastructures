//Given head pointer of a linked list, and an integer k (1<=k<=n),  reverse every k elements of the list"

//Example: Given linked list 1->2->3->4->5->6->7->8->NULL, and k = 3, should return 3->2->1->6->5->4->8->7->NULL


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
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next; //Traverse to the end of the list
        }
        temp->next = newNode; //Insert the new node at the end of the list
    }
}

//Function to print the linked list

void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d- ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to reverse the linked list by k elements 

struct node *reverseByK(struct node *head, int k) 
{
    struct node *current = head;
    struct node *next = NULL;
    struct node *prev = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next; //Store the next node
        current->next = prev; //Reverse the current node
        prev = current; //Move the prev pointer to the current node
        current = next; //Move the current pointer to the next node
        count++; //Increment the count
    } 
    if (next != NULL) //If the next node is not NULL, then we have more nodes to reverse
    {
        head->next = reverseByK(next, k); //Recursively call the function to reverse the remaining nodes
    }
    return prev; //Return the new head
}

int main()
{
    int n, k;
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
    printf("The linked list is: ");
    printList(head);
    printf("\n"); //Print a new line to make things prettier!
    printf("Enter the value of k (to reverse k elements in the list): ");
    scanf("%d", &k);
    head = reverseByK(head, k);
    printf("\n"); //Print a new line to make things prettier!
    printf("The linked list after reversing by k elements is: ");
    printList(head);
    return 0;
}

//




