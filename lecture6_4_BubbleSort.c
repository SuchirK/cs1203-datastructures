
/*====================================================================*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
int main(int argc, char **argv) {

    int *a; 
    int n = 10; 

    srand(time(NULL)); //seed the random number generator. Time NULL is a special value that tells the computer to use the current time as the seed.
    a = generateArray(n);
    printArray2 (a, n); //print the second array.
    bubbleSort(a, n);
    printArray2 (a, n); //print the second array. Sorted by bubble sort.

    free(a); //For every malloc, free statement. With every malloc, there must be a corresponding free statement.
    return 0; 

}

/*====================================================================*/ 

