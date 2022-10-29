
// Bubble Sorting for Linked Lists 

/*====================================================================*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int val;
    struct node *next; //All of the times we are dealing with addresses of the nodes. Pointers to the nodes
};

typedef struct node * NodeAddress; 


/*====================================================================*/ 

//Let's do Bubble Sort..Simple version of Bubble Sort

//Imagine there are people standing in a line. You want to sort them in ascending order. Bubble sort would compare the first two people and swap them if they are in the wrong order. Then compare the second and third people and swap them if they are in the wrong order. Then compare the third and fourth people and swap them if they are in the wrong order. And so on until you reach the absolute end.

// Bubble sort is stupid. 

void bubbleSort(int *a, int n) {
    int done, i, t;

    for (done = 0; done < n; done++) {
        for (i = 0; i < n-1; i++) {
            if (a[i] > a[i+1]) {
                //swap these elements since they are in the wrong order.
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
            }
        } //end of the i loop 
    } // end of the done loop
}


/*====================================================================*/ 

int * generateArray(int n) { //generate function. 
    int *t = malloc(n * sizeof(int)); //allocate memory for the array.
    if (t) {
    for (int i = 0; i < n; i++) {t[i] = rand()%1000;} //Chopping out the last three digits of the random number.  In essence, its generating a random number between 0 and 1000. 
    }
    return t;
}

NodeAddress linkedListFromArray (int * a, int n) {
    for (i = 0; i < n; i++) {
        temp = malloc(sizeof(struct node)); //allocate memory for the new node. 
        temp->val = a[i]; //assign the value to the new node temp. 
        temp->next = NULL; //assign the next pointer to NULL. 
        }
    }
}



/*====================================================================*/ 
void printArray2 (int *a, int n){
    printf ("Array = ");
    for (int i = 0; i < n; i++) {
        printf(i?", %d":"%d", a[i]); //If i is not the first element, going to print comma space and the element. If it is the first element, just print the element. 
    }
    printf(".\n"); //full stop at the end   

}
/*====================================================================*/ 
void printArray1 (int *a, int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

}

/*====================================================================*/ 

void printLinkedList(NodeAddress head) {
    NodeAddress c; 
    printf ("Linked List = ");
    for (c = head; c!=NULL; c = c->next) {
        printf(c==head? "%d":", %d", c->val); //If c->next is not NULL, going to print comma space and the element. If it is NULL, just print the element. 
    }
    

/*====================================================================*/ 
int main(int argc, char **argv) {

    int *a; 
    int n = 10; 
    NodeAddress list;

    srand(time(NULL)); //seed the random number generator. Time NULL is a special value that tells the computer to use the current time as the seed.
    a = generateArray(n);
    list = linkedlistFromArray (a, n);
  
    printArray2 (a, n); //print the second array.
    bubbleSort(a, n);
    printArray2 (a, n); //print the second array. Sorted by bubble sort.

    printLinkedList(list);

    free(a); //For every malloc, free statement. With every malloc, there must be a corresponding free statement.
    return 0; 

}

/*====================================================================*/ 

