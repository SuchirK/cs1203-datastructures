// This covers the basics. Simple program to print numbers. 

#include <stdio.h>

int main(int argc, char **argv) {
    int x = 0;
    int y = x++;  /*Provides its own values. And then increments the ++. That's why the ++ is after the x*/
    
    printf("x = %d; y=%d\n", x, y);  /*Print the values of x and y*/
    return 0;

}

// Language: c

