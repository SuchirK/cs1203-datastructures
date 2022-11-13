#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//Function Pointer Demos. Using UCHAR MAX and UCHAR MIN

#define UCHAR_MAX 256 //UCHAR_MAX is the maximum value of an unsigned char
#define UCHAR_MIN 0 //UCHAR_MIN is the minimum value of an unsigned char

void blah(int *a, int(*func)(int *x), int n); //declaring a function that takes a pointer to an integer, a function pointer and an integer as arguments and returns nothing
    for(i=0; i < n; i++){ //looping through the array
        a[i] = func(&a[i]); //assigning the value of the function pointer to the array
    }

void qsort (void* base, size_t num, size_t size, int (*compare)(const void*A, const void*B)); //qsort is a function that sorts an array. It takes 4 arguments. The first argument is the array. The second argument is the number of elements in the array. The third argument is the size of each element in the array. The fourth argument is a function pointer that compares two elements in the array.


int (*table[UCHAR_MAX + 1])(int); //declaring a function pointer table. The table has 256 elements. Each element is a function pointer that takes an integer as an argument and returns an integer.

int i,c;  

for (i=0; i<UM,i++){ //looping through the table
    table[i] = putchar; //assigning the address of the function putchar to each element in the table
   
}

table ['a'] = blah; //assigning the address of the function blah to the element in the table that corresponds to the character 'a' 
table ['e'] = blah;

table[c](c); //calling the function that corresponds to the character c in the table.

table['a']('a') //calling the function that corresponds to the character 'a' in the table.




