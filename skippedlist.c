//Implementing a skipped list with 2 pointers. For simplicity, I will use a 5 floor version 
//Deliverable: Implement a skipped list with 5 floors. .

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 5 //max level of the skipped list is 5

typedef struct node{ //Node structure
    int nodemaster; //Key of the node
    struct node *forward[MAX_LEVEL]; //Essentially, an Array of pointers

}node;

typedef struct skipList{ //Skip list structure
    int level; //Number of levels
    node *header; //Header of the list

}skipList;

node *createNode(int level, int nodemaster){ //Function to create a node
    node *newNode = (node *)malloc(sizeof(node)); //Allocating memory for the node
    newNode->nodemaster = nodemaster; //Setting the key of the node
    for(int i = 0; i < level; i++){ //Setting the pointers of the node
        newNode->forward[i] = NULL;
    }
    return newNode; //Returning the node
}

//Creating a Skip List with two pointers


skipList *createSkipList(){ //Function to create a skip list
    skipList *newSkipList = (skipList *)malloc(sizeof(skipList)); //Allocating memory for the skip list
    newSkipList->level = 1; //Setting the level of the skip list
    newSkipList->header = createNode(MAX_LEVEL, -1); //Creating the header of the skip list
    return newSkipList; //Returning the skip list
}

//Inserting a node in a Skip List

void insert(skipList *list, int nodemaster){ //Function to insert a node in the skip list
    node *update[MAX_LEVEL]; //Array of pointers to update the pointers of the nodes
    node *current = list->header; //Current node
    for(int i = list->level - 1; i >= 0; i--){ //Traversing the skip list
        while(current->forward[i] != NULL && current->forward[i]->nodemaster < nodemaster){ //Traversing the skip list
            current = current->forward[i]; //Updating the current node
        }
        update[i] = current; //Updating the pointers
    }
    current = current->forward[0]; //Updating the current node
    if(current == NULL || current->nodemaster!= nodemaster){ //Checking if the key is already in the skip list
        int randomLevel = rand() % MAX_LEVEL + 1; //Generating a random level.....
        if(randomLevel > list->level){ //Checking if the random level is greater than the level of the skip list
            for(int i = list->level; i < randomLevel; i++){ //Updating the pointers of the nodes
                update[i] = list->header;
            }
            list->level = randomLevel; //Updating the level of the skip list
        }
        node *newNode = createNode(randomLevel, nodemaster); //Creating a new node
        for(int i = 0; i < randomLevel; i++){ //Updating the pointers of the nodes
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

//Deleting a node in a Skip List 


void delete(skipList *list, int nodemaster){ //Function to delete a node from the skip list
    node *update[MAX_LEVEL]; //Array of pointers to update the pointers of the nodes
    node *current = list->header; //Current node
    for(int i = list->level - 1; i >= 0; i--){ //Traversing the skip list
        while(current->forward[i] != NULL && current->forward[i]->nodemaster < nodemaster){ //Traversing the skip list
            current = current->forward[i]; //Updating the current node
        }
        update[i] = current; //Updating the pointers of the nodes
    }
    current = current->forward[0]; //Updating the current node
    if(current != NULL && current->nodemaster == nodemaster){ //Checking if the key is in the skip list
        for(int i = 0; i < list->level; i++){ //Updating the pointers of the nodes
            if(update[i]->forward[i] != current){ //Checking if the node is in the skip list
                break;
            }
            update[i]->forward[i] = current->forward[i]; //Updating the pointers of the nodes
        }
        free(current); //Freeing the memory of the node
        while(list->level > 1 && list->header->forward[list->level - 1] == NULL){ //Updating the level of the skip list
            list->level--;
        }
    }
}

//Searching for a node in a Skip List with two pointers

int search(skipList *list, int nodemaster){ //Function to search for a node in the skip list
    node *current = list->header; //Current node
    for(int i = list->level - 1; i >= 0; i--){ //Traversing the skip list
        while(current->forward[i] != NULL && current->forward[i]->nodemaster <nodemaster){ //Traversing the skip list
            current = current->forward[i]; //Updating the current node
        }
    }
    current = current->forward[0]; //Updating the current node
    if(current != NULL && current->nodemaster == nodemaster){ //Checking if the key is in the skip list
        return 1; //Returning 1 if the key is in the skip list
    }
    return 0; //Returning 0 if the key is not in the skip list
}

//Printing a Skip List with two pointers

void printSkipList(skipList *list){ //Function to print the skip list
    printf("Skipped List: "); //Printing the skip list
    for(int i = 0; i < list->level; i++){ //Traversing the skip list
        node *current = list->header->forward[i]; //Current node
        printf("Level %d: ", i + 1); //Printing the level
        while(current != NULL){ //Traversing the skip list
            printf("%d ", current->nodemaster); //Printing the key of the node
            current = current->forward[i]; //Updating the current node
        }
        printf("\n"""); //Printing a new line to make things look prettier!
    }
}

//Take user input for the number of elements to be inserted in the Skip List and implement the Skip List with two pointers

int main(){ //Main function
    srand(time(NULL)); //Setting the seed for the random number generator
    skipList *list = createSkipList(); //Creating a skip list
    int n; //Number of elements to be inserted in the skip list
    printf("Enter the number of elements to be inserted in the skip list: "); //Asking the user for the number of elements
    scanf("%d", &n); //Taking user input
    for(int i = 0; i < n; i++){ //Inserting the elements in the skip list
        int nodemaster; //Key of the node
        printf("Enter the key of the node: "); //Asking the user for the key of the node
        scanf("%d", &nodemaster); //Taking user input
        insert(list, nodemaster); //Inserting the node in the skip list
    }
    printSkipList(list); //Printing the skip list
    printf("\n"); //Printing a new line to make things look prettier!
    int nodemaster; //Key of the node
    printf("Enter the key of the node to be searched: "); //Asking the user for the key of the node to be searched
    scanf("%d", &nodemaster); //Taking user input
    if(search(list, nodemaster)){ //Searching for the node in the skip list
        printf("The key %d is in the skip list");   //Printing the result
    }
    else{
        printf("The key %d is not in the skip list"); //Printing the result
    }
    printf("\n"); //Printing a new line to make things look prettier!
    printf("Enter the key of the node to be deleted: "); //Asking the user for the key of the node to be deleted
    printf("\n"); //Printing a new line to make things look prettier!
    scanf("%d", &nodemaster); //Taking user input
    delete(list, nodemaster); //Deleting the node from the skip list
    printSkipList(list); //Printing the skip list
    return 0; //Returning 0
}










//Skipped Lists




















