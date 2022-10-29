//Playing around with arrays

#include <stdio.h>
#include <stdlib.h>

int * generateArray(int n) { //generate function. 
    int *t = malloc(n * sizeof(int)); //allocate memory for the array.
    if (t) {
    for (int i = 0; i < n; i++) {t[i] = i;} 
    }
    return t;
}


void printArray2 (int *a, int n){
    printf ("Array = ");
    for (int i = 0; i < n; i++) {
        printf(i?", %d":"%d", a[i]); //If i is not the first element, going to print comma space and the element. If it is the first element, just print the element. 
    }
    printf(".\n"); //full stop at the end   

}

void printArray1 (int *a, int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

}

int main(int argc, char **argv) {

    int *a; 
    int n = 10; 

    a = generateArray(n);
    printArray2 (a, n); //print the second array.

    free(a); //For every malloc, free statement. With every malloc, there must be a corresponding free statement.
    return 0; 

}
