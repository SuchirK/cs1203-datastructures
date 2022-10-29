// Memory Play Ground

#include <stdio.h>
#include <stdlib.h>

int *blah(int val) {
    int x; 
    int * pointer = &x; 
    x = val*val; 
    return pointer; // return the address of x. But the house of x is already gone.
}

int main(int argc, char **argv) {
    int *b = blah(3);
    printf("%d.\n", *b);  
    return 0;
}

// Danger: The compiler might not warn you that you need to stop playing around. You need to stop doing it! It's not going to shout it to you! 

// Half way through the program, you might malloc something else and overwriting the location. 

// It's a silent killer. You might do something and would not realise something bad is happening!

// You need to be careful.

