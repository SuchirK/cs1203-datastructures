//In this code, we are going to be introduced to assert. 


#include <assert.h> //assert.h is a header file that defines a macro that can be used as a standard debugging tool.

int main(int argc, char *argv[]){ //argc is the number of arguments passed to the program. argv is an array of pointers to the arguments passed to the program. 

    assert(2+2 == 5); //assert is a macro that checks if the condition is true. If the condition is true, the program continues. If the condition is false, the program terminates. 

    //Whereever possible, start using assertions instead of printf. Another disadvantage of printf is that it is not a debugging tool. It is a tool to print information to the user. One you have fixed your program, you need to delete these printfs...
    
    //Assert is almost like a printf. It prints the error message and then terminates the program. 

    return 0;

}

