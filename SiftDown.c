//implement a simple siftdown heap

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct heap{
    int data[MAX];
    int size;

}heap;

void siftdown(heap *h, int i){
    int temp;
    int done = 0;
    int maxchild;

    while((i*2 <= h->size) && (!done)){
        if(i*2 == h->size){
            maxchild = i*2;
        }
        else if(h->data[i*2] > h->data[i*2+1]){
            maxchild = i*2;
        }
        else{
            maxchild = i*2+1;
        }

        if(h->data[i] < h->data[maxchild]){
            temp = h->data[i];
            h->data[i] = h->data[maxchild];
            h->data[maxchild] = temp;
            i = maxchild;
        }
        else{
            done = 1;
        }
    }
}

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

int main(){
    heap h;
    h.size = 0;
    insert(&h, 10);
    insert(&h, 20);
    insert(&h, 30);
    insert(&h, 40);
    insert(&h, 50);
    insert(&h, 60);
    insert(&h, 70);
    insert(&h, 80);
    insert(&h, 90);
    insert(&h, 100);
    insert(&h, 110);
    insert(&h, 120);
    insert(&h, 130);
    insert(&h, 140);
    insert(&h, 150);
    insert(&h, 160);
    insert(&h, 170);
    insert(&h, 180);
    insert(&h, 190);
    insert(&h, 200);
    insert(&h, 210);
    insert(&h, 220);
    insert(&h, 230);
    insert(&h, 240);
    insert(&h, 250);
    insert(&h, 260);
    insert(&h, 270);
    insert(&h, 280);
    insert(&h, 290);
    insert(&h, 300);
    insert(&h, 310);
    insert(&h, 320);
    insert(&h, 330);
    insert(&h, 340);
    insert(&h, 350);
    insert(&h, 360);
    insert(&h, 370);
    insert(&h, 380);
    insert(&h, 390);
    insert(&h, 400);
    insert(&h, 410);
    insert(&h, 420);
    insert(&h, 430);
    insert(&h, 440);
    insert(&h, 450);
    insert(&h, 460);
    insert(&h, 470);
    insert(&h, 480);
    insert(&h, 490);
    insert(&h, 500);
    insert(&h, 510);
    insert(&h, 520);
    insert(&h, 530);
    insert(&h, 540);
    insert(&h, 550);
    insert(&h, 560);
    insert(&h, 570);
    insert(&h, 580);
    insert(&h, 590);
    insert(&h, 600);
    insert(&h, 610);

    for(int i = 1; i <= h.size; i++){
        printf("%d ", h.data[i]);
    }

    return 0;

}
