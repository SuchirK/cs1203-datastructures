// Course Deliverable 2

//Task: Reversing a Linked List: Given a Linked List, reverse it


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

//Let's create a function that reverses a linked list

void reverse(my_node* head) {
    my_node* current = head; //current is a pointer to a node. It is set to the head of the list
    my_node* prev = NULL; //prev is a pointer to a node. It is set to NULL
    my_node* next = NULL; //next is a pointer to a node. It is set to NULL

    while (current != NULL) { //while current is not equal to NULL
        next = current -> next; //set next to the next node
        current -> next = prev; //set the next pointer of the current node to the previous node
        prev = current; //set prev to the current node
        current = next; //set current to the next node
    }

    head = prev; //set the head to the previous node

    my_node* print = head; //create a pointer to a node called print. Set it to the head of the list

    while (print!= NULL) {
        printf ("%d -", print->val); //print the value of the current node
        print = print -> next; //set print to the next node
    }
    printf("\n");
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

    printf("Linked list is: \n");
    printlist(head); //passing in the head of the list to the print function
    printf("\n"); //print a new line to make things prettier! 
    printf("Reversed Linked list is: \n");
    reverse(head); //passing in the head of the list to the reverse function

    return 0; 
}

