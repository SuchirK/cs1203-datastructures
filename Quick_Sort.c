
//Deliverable 

//Task: Quick Sorting with Arrays and Linked Lists 

//Quick Sorting is a divide and conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. 

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


//Quick Sort Algorithm


//Quick Sort Function to sort the array

//Quick Sort implementation for Arrays

void quickSort(int *a, int n) { //takes in an array and an integer value
    int i, j, pivot; //declaring three integer variables
    if(n<2) {return;} //if the size of the array is less than 2, return
    pivot = a[n/2]; //setting pivot equal to the middle element in the array
    for(i=0, j=n-1;; i++, j--) { //for loop to iterate through the array
        while(a[i]<pivot) {i++;} //while loop to iterate through the array
        while(pivot<a[j]) {j--;} //while loop to iterate through the array
        if(i>=j) {break;} //if i is greater than or equal to j, break out of the loop
        swap(&a[i], &a[j]); //call the swap function to swap the values of the two elements
    }
    quickSort(a, i); //call the quickSort function to sort the first half of the array
    quickSort(a+i, n-i); //call the quickSort function to sort the second half of the array
}



//Quick Sort implementation for Linked Lists

my_node quickSortLinkedList(my_node head) { //takes in the head of the list
	my_node i, j, pivot; //declaring three pointers to nodes
	if(head==NULL || head->next==NULL) {return head;} //if the head of the list is NULL or the next pointer of the head of the list is NULL, return the head of the list
	pivot = head; //set pivot equal to the head of the list
	for(i=head, j=head->next; j!=NULL; j=j->next) { //for loop to iterate through the list
		if(j->val < pivot->val) { //if the value of the node is less than the value of the pivot
			i = i->next; //set i equal to the next node
			swap(&i->val, &j->val); //to swap the values of the two nodes
		}
	}
	swap(&i->val, &pivot->val); //call the swap function to swap the values of the pivot and the node i is pointing to
	pivot = i; //set pivot equal to i
	pivot->next = quickSortLinkedList(pivot->next); //set the next pointer of the pivot equal to the head of the list returned by the quickSortLinkedList function
	return pivot; //return the pivot
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

	quickSortLinkedList(list); //sorting the linked list

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

	quickSort(a,n); //sorting the Array 

	printf("The Sorted Array is: \n"); 

	printArray(a,n); //printing the sorted linked list


    //Now, time for freedom! Freeing the memory allocated for the array and the linked list

	free(a); 
	freeLinkedList(list);


	return 0;
}


//Reference: Source code '0.c '(Lecture 7) posted on October 11th 2022 by Prof. Debayan Gupta
