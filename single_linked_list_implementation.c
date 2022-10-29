// Course Deliverable 1
// Implementation of a Linked List: Given a set of values (assume int), create a linked list from them

#include <stdio.h>
#include <stdlib.h>

struct node { //used to create a node and package several data fields into one. 
    int val;
    struct node* next; //All of the times we are dealing with addresses of the nodes. Pointers to the nodes. This is going to point to the next node
}; 

typedef struct node my_node; //setting my_node as an alias for struct node

//We are going to create a print function 
void printlist(my_node* head) { //printlist function that takes in a pointer to a node
    my_node* temp = head; //current is a pointer to a node. It is set to the head of the list
    while (temp != NULL) { //while current is not equal to null
        printf("%d -", temp->val); //print the value of the current node
        temp = temp -> next; //set current to the next node 
    }

    printf("\n"); //print a new line to make things prettier! 
}


    

//Let's write a function to create a linked list from a set of values.

int main() { 
    my_node n1, n2, n3; //creating three nodes
    my_node *head; //creating a pointer to a node. This is going to point to the first node in the list.

    n1.val = 10; //setting the value of the first node to 10
    n2.val = 15; //setting the value of the second node to 15
    n3.val = 100; //setting the value of the third node to 100

    //let's now link them up into a list 

    head = &n3; //head is going to point to the third node
    n3.next = &n2; //the third node is going to point to the second node
    n2.next = &n1; //the second node is going to point to the first node
    n1.next = NULL; //the first node is going to point to NULL. So we know when to stop 

    //adding a node

    my_node n4; //creating a new node

    n4.val = 20; //setting the value of the new node to 20
    n4.next = &n2; //the new node is going to point to the second node
    n3.next = &n4; //the third node is going to point to the new node
    

    //--Call the print function in main---

    printlist(head); //passing in the head of the list to the print function


    return 0; 
}