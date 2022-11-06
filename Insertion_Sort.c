
//Deliverable 

//Task: Insertion Sorting with Arrays and Linked Lists 

#include<stdio.h>
#include<stdlib.h>
#include <time.h>

struct node{
    int val;
    struct node * next;
};	

typedef struct node * my_node; //setting my_node as an alias for struct node

//creating a swap function 

void swap(int *x, int*y) { //takes in two pointers to integers
    int temp = *x; //setting temp equal to the value of the first pointer
    *x = *y; //setting the value of the first pointer equal to the value of the second pointer
    *y = temp; //setting the value of the second pointer equal to the value of temp
}

//generate an array 

int * generateArray(int n) { //takes in an integer value 
	int * temp = malloc( n * sizeof(int) ); //allocating memory for the array
	if(temp) { 
		for(int i=0; i<n; i++) {temp[i] = rand()%100;} //setting the value of each element in the array to a random number between 0 and 100
	}
	return temp;
}

//Function to convert to linked list from the array 

my_node* array_to_linkedlist(int *a, int n) { //takes in an array and an integer value
int i; //declaring an integer variable
	my_node head = NULL;       //setting the head of the list to NULL
	my_node temp = NULL;       //setting temp to NULL

	// special case for head
	if(n>0) { //if the size of the array is greater than 0
		head = malloc( sizeof(struct node) ); //allocate memory for the head of the list
		head->val  = a[0]; //set the value of the head of the list equal to the first element in the array
		head->next = NULL; //set the next pointer of the head of the list to NULL
		temp = head; //set temp equal to the head of the list
	}


	for(i=1; i<n; i++) { //for loop to iterate through the array
		temp->next = malloc( sizeof(struct node) ); //allocate memory for the next node
		temp = temp->next; //set temp equal to the next node
		temp->val = a[i]; //set the value of the node equal to the value of the element in the array
		temp->next = NULL; //set the next pointer of the node to NULL
	}

	return head; 
}

//Function to free the linked list 

void freeLinkedList(my_node head) { //takes in the head of the list
	my_node prev;  //declaring a pointer to a node called prev

	while(head) { //while the head of the list is not NULL
		prev = head; //set prev equal to the head of the list
		head = head->next; //set the head of the list equal to the next node
		free(prev); //free the memory of the previous node
	}
}

//printing 

void printArray(int * a, int n) { //takes in an array and an integer value
	printf("Array = "); //print the string "Array = "
	for(int i=0; i<n; i++) { //for loop to iterate through the array
		printf( i?", %d":"%d", a[i]); //print the value of each element in the array
	}
	printf(".\n"); //print a new line
}

void printArray1(int *a, int n) { //takes in an array and an integer value
	for(int i=0; i<n; i++) { //for loop to iterate through the array
		printf(" %d- ", a[i]); //print the value of each element in the array
	}
}

void printLinkedList(my_node head) { //takes in the head of the list 
	my_node c; //declaring a pointer to a node called c
	printf("Linked List = "); //print the string "Linked List = "
	for(c=head; c!=NULL; c=c->next) { //for loop to iterate through the list
		printf( c==head?"%d-":", %d-", c->val); //print the value of each node in the list
	}
	printf(".\n"); //print a new line
}


//Insertion Sort Algorithm


//Insertion Sort Function to sort the array

void insertionSortArray(int *a, int n) { //takes in an array and an integer value
    int i, j; //declaring two integer variables
    for(i=1; i<n; i++) { //for loop to iterate through the array
        j = i; //set j equal to i
        while(j>0 && a[j-1]>a[j]) { //while j is greater than 0 and the value of the element in the array at index j-1 is greater than the value of the element in the array at index j
            swap(&a[j-1], &a[j]); //swap the values of the elements in the array at index j-1 and j
            j--; //decrement j
        }
    }
}

//Insertion sort procedure for linked list

void insertionSortLinkedList(my_node head) { //takes in the head of the list
    my_node i, j, temp; //declaring three pointers to nodes called i, j, and temp
    for(i=head->next; i!=NULL; i=i->next) { //for loop to iterate through the list
        j = i; //set j equal to i
        while(j->next!=NULL && j->val>j->next->val) { //while the next pointer of j is not NULL and the value of j is greater than the value of the next node
            swap(&j->val, &j->next->val); //swap the values of the nodes
            j = j->next; //set j equal to the next node
        }
    }
}

//Main Area: Add a scan f function to take in the number of elements in the array

int main(int argc, char **argv) { 
	int * a; //declaring a pointer to an integer called a

    //take user input for n
    int n; //declaring an integer variable called n

    printf("Enter your desired number of elements:"); 
 
    scanf("%d", &n); //Taking the input the user -- the number of elements in the array

	my_node list;  //declaring a pointer to a node called list

	srand(time(NULL)); //setting the seed for the random number generator

	a = generateArray(n); //setting a equal to the array generated by the generateArray function
	list = array_to_linkedlist(a,n); //setting list equal to the linked list generated by the array_to_linkedlist function

	printf("The Un-Sorted Linked List is: \n"); 

	printLinkedList(list); //printing the linked list

	insertionSortLinkedList(list); //sorting the linked list

    printf("\n"); //added a new line to make things prettier!

	printf("The Sorted Linked List is: \n"); 

	printLinkedList(list); //printing the sorted linked list

	printf("\n"); //added a new line to make things prettier!

	printf("--------------------------------------------\n"); //added a new line to make things really prettier!

	//-----------------------------------------//

	//Now,let's print the array and sort the array

	printf("The Un-Sorted Array is: \n"); 

	printArray(a,n); //Print the Array 

	printf("\n"); //added a new line to make things prettier!

	insertionSortArray(a,n); //sorting the Array 

	printf("The Sorted Array is: \n"); 

	printArray(a,n); //printing the sorted linked list


    //Now, time for freedom! Freeing the memory allocated for the array and the linked list
	free(a); 
	freeLinkedList(list);


	return 0;
}


//Reference: Source code '0.c '(Lecture 7) posted on October 11th 2022 by Prof. Debayan Gupta
