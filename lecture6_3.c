//generating random arrays
//C has a special feature which allows you to seed random numbers. Starting from the same seed, you will get the same sequence of random numbers.
// we will use srand() functions
// srand() function takes a seed as an argument. The seed is a number that is used to generate the random numbers.
// srand() function is defined in stdlib.h

/*====================================================================*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    free(a); //For every malloc, free statement. With every malloc, there must be a corresponding free statement.
    return 0; 

}

/*====================================================================*/ 

