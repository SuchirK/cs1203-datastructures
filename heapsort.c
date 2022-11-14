//Given an array, build a heap and sort it! First, we build a heap and then do selection sort on it. This is called HEAPSORT. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

typedef struct heap{ //declaring a struct called heap
    int data[MAX]; //declaring an integer array called data
    int size; //declaring an integer variable called size

}heap; //end of struct

//swap function

void swap(int *a, int *b){ //takes in two pointers to integers
    int temp = *a; //declaring an integer variable and setting it equal to the value of the first pointer
    *a = *b; //setting the value of the first pointer equal to the value of the second pointer
    *b = temp; //setting the value of the second pointer equal to the value of temp
}


void siftdown(heap *h, int i){ //takes in a pointer to a heap and an integer value
    int temp; //declaring an integer variable
    int done = 0; //declaring an integer variable and setting it equal to 0
    int maxchild; //declaring an integer variable (maxchild- Child of the parent with the largest value)

    while((i*2 <= h->size) && (!done)){ //while loop to iterate through the heap
        if(i*2 == h->size){ //if the left child of the parent is the last element in the heap
            maxchild = i*2; //set maxchild equal to the left child of the parent
        }
        else if(h->data[i*2] > h->data[i*2+1]){ //if the value of the left child of the parent is greater than the value of the right child of the parent
            maxchild = i*2; //set maxchild equal to the left child of the parent
        }
        else{ //if the value of the right child of the parent is greater than the value of the left child of the parent
            maxchild = i*2+1; //set maxchild equal to the right child of the parent
        }

        if(h->data[i] < h->data[maxchild]){ //if the value of the parent is less than the value of the maxchild
            temp = h->data[i]; //set temp equal to the value of the parent
            h->data[i] = h->data[maxchild]; //set the value of the parent equal to the value of the maxchild
            h->data[maxchild] = temp; //set the value of the maxchild equal to the value of temp
            i = maxchild; //set i equal to the value of maxchild
        }
        else{
            done = 1; //set done equal to 1
        }
    }
}

//Function to generate an array

int * generateArray(int size) { //takes in an integer value 
    int * temp = malloc( size * sizeof(int) ); //allocating memory for the array
    if(temp) { 
        for(int i=0; i<size; i++) {temp[i] = rand()%100;} //setting the value of each element in the array to a random number between 0 and 100
    }
    return temp;
}

//Build a max heap from an array

heap* build_max_heap(heap *h, int *a, int size){
    int i;
    for(i=0; i<size; i++){
        h->data[i+1] = a[i];
    }
    h->size = size;
    for(i=size/2; i>=1; i--){
        siftdown(h, i);
    }
    return h;
}

//Function to print the array

void printArray(int *a, int size) { //takes in an array and an integer value
    for(int i=0; i<size; i++) {printf("%d ", a[i]);} //prints the value of each element in the array
    printf("\n");
}

//Function to print the heap

void printHeap(heap *h) { //takes in a pointer to a heap
    for(int i=1; i<=h->size; i++) {printf("%d ", h->data[i]);} //prints the value of each element in the heap
    printf("\n");
}   

//Sorting the heap using selection sort

void heapsort1(heap* h, int n) {  //takes in a pointer to a heap and an integer value
     for(int i = n/2 - 1; i >= 0; i--) { //for loop to iterate through the heap
        siftdown(h, i); //calling the siftdown function
    }
}


int main(){ //main area
    int size; //declaring an integer variable
    printf("Enter the size of the array: "); //prompting the user to enter the size of the array
    scanf("%d", &size); 
    int *a = generateArray(size);
    printf("The array is: "); //printing the array
    printArray(a, size); //calling the printArray function

    heap *h = malloc(sizeof(heap)); //allocating memory for the heap
    
    h = build_max_heap(h, a, size); //calling the build_max_heap function

    printf("The heap is: "); 
    printHeap(h);

    heapsort1(h, size);
    
    printf("The sorted heap is: ");
    printHeap(h);
    return 0;
}


















