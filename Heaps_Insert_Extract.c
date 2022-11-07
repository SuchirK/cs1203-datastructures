    //Deliverable
    
    //Task: Implement insert() and extract_max() operations given a heap in the form of an array.

    //Heap is a binary tree that has a HEAP property //Which is a min-heap property and a max-heap property. 

    #define MAX 100

    typedef struct heap{
        int data[MAX];
        int size;

    }heap;



    void siftdown(heap *h, int i){ //takes in a pointer to a heap and an integer value
        int temp; //declaring an integer variable
        int done = 0; //declaring an integer variable and setting it equal to 0
        int maxchild; //declaring an integer variable (maxchild- Child of the parent with the largest value)

        while((i*2 <= h->size) && (!done)){ //while loop to iterate through the heap
            if(i*2 == h->size){ //if the left child of the parent is the last element in the heap
                maxchild = i*2; //set maxchild equal to the left child of the parent
            }
            else if(h->data[i*2] > h->data[i*2+1]){ //if the value of the left child of the parent is greater than the value of the right child of the parent
                maxchild = i*2; //set maxchild equal to the left child of the parent
            }
            else{ //if the value of the right child of the parent is greater than the value of the left child of the parent
                maxchild = i*2+1; //set maxchild equal to the right child of the parent
            }

            if(h->data[i] < h->data[maxchild]){ //if the value of the parent is less than the value of the maxchild
                temp = h->data[i]; //set temp equal to the value of the parent
                h->data[i] = h->data[maxchild]; //set the value of the parent equal to the value of the maxchild
                h->data[maxchild] = temp; //set the value of the maxchild equal to the value of temp
                i = maxchild; //set i equal to the value of maxchild
            }
            else{
                done = 1; //set done equal to 1
            }
        }
    }

    //Function to generate an array 

    int * generateArray(int size) { //takes in an integer value 
        int * temp = malloc( size * sizeof(int) ); //allocating memory for the array
        if(temp) { 
            for(int i=0; i<size; i++) {temp[i] = rand()%100;} //setting the value of each element in the array to a random number between 0 and 100
        }
        return temp;
    }

    //Build a max heap from an array

    heap* build_max_heap(heap *h, int *a, int size){
        int i;
        for(i=0; i<size; i++){
            h->data[i+1] = a[i];
        }
        h->size = size;
        for(i=size/2; i>=1; i--){
            siftdown(h, i);
        }
    }

    //Function to print the heap 

    void print_heap(heap *h){
        int i;
        for(i=1; i<=h->size; i++){
            printf("%d", h->data[i]);
        }
    printf(".\n"); //print a new line
    }

    //Function to insert an element into the heap

    void insert(heap *h, int x){
        int i;
        if(h->size == MAX){
            printf("Heap is full");
            return;
        }
        h->size++;
        i = h->size;
        while((i != 1) && (x > h->data[i/2])){
            h->data[i] = h->data[i/2];
            i = i/2;
        }
        h->data[i] = x;
    }

    //Extracting from Heap

    int extract_min(heap *h){ //takes in a pointer to a heap
        int min = h->data[1]; //set min equal to the value of the first element in the heap
        h->data[1] = h->data[h->size]; //set the value of the first element in the heap equal to the value of the last element in the heap
        h->size--; //decrement the size of the heap by 1
        siftdown(h, 1); //call the siftdown function to reorganize the heap
        return min; //return the value of min
    }


    //Main Execution Space. Also, taking input from user

    int main(){
        int size, i, x;

        heap *h = malloc(sizeof(heap)); //allocating memory for the heap

        printf("Enter the number of elements: "); //prompting the user to enter the number of elements in the array

        scanf("%d", &size); //scanning the number of elements in the array

        int a = generateArray(size); //calling the generateArray function to generate an array

        h = build_max_heap(h, a, size); //calling the build_max_heap function to build a max heap from the array

        printf("The max heap is: "); //printing the max heap

        print_heap(&h);

        printf("Enter the element to be inserted: "); //prompting the user to enter the element to be inserted

        scanf("%d", &x); //scanning the element to be inserted

        insert(h, x); //calling the insert function to insert the element into the heap

        printf("The heap after inserting the element is: "); //printing the heap after inserting the element

        print_heap(&h);

        printf("The minimum element in the heap is: %d, extracted from the heap\n", extract_max(h)); //printing the minimum element of the heap

        return 0;

    }


