// This is from Lecture 1

#include <stdio.h>
#include <stdlib.h>

// Task: I want you to change the increment and n and see at what point you end up with an extra loop

int main(int argc, char** argv){

    float i;
    float increment = 0.0000000001; //Change around this
    float n = 0.00000002; //And this (this is 10 times increment)
    int count = 1;

    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count++;
    }

    return 0;
}

// Notes: Each increase of the decimal points of the 'increament' increases the loops by 10 times. 
// Increasing the value of the increment reduced the number of loops. 
// Increasing the value of n increased the number of loops. 
// The number of loops is the same as the value of n divided by the value of increment.