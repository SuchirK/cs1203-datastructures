// Course Deliverable 1.1
// In this implementation, we are going to create a function that will add a node to the end of the list for us!
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

//Let's create a function that makes new nodes for us

my_node *make_new_node(int val) { //takes in an integer value
    my_node *new_node = (my_node*)malloc(sizeof(my_node)); //creating a new node and allocating memory for it
    new_node->val = val; //setting the value of the new node to the value that was passed in
    new_node->next = NULL; //setting the next pointer to NULL
    return new_node; //returning the new node
}
    
//Let's write a function to create a linked list from a set of values.

int main() { 
    my_node *head = NULL; //creating a pointer to a node. This is going to point to the first node in the list, which is NULL in this case.
    my_node *tmp;

    for (int i = 0; i<30; i++ ){
        tmp = make_new_node(i); //creating a new node and setting it to tmp
        tmp -> next = head; 
        head = tmp;
    }



    //--Call the print function in main---

    printlist(head); //passing in the head of the list to the print function


    return 0; 
}