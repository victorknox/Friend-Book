#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "priorityQueue.h"


///////////
//PRIORITY QUEUE
//////////

//*****NEW SERIES OF CODE BEGINS HERE*****//

struct minHeap* initHeap(void)
{
    struct minHeap* temp = (struct minHeap*)malloc(sizeof(struct minHeap));
    assert(temp!=NULL);
    temp->heapSize = 0;
    temp->heap = (int *)malloc(100000*sizeof(int));
    assert(temp->heap!=NULL);
    return temp;
}


void InsertToHeap(struct minHeap * heap1,int element)    //index from the array 1 to max_size.......***parent to index is index/2***.....
{
    heap1->heapSize++;
    heap1->heap[heap1->heapSize] = element; 
    int index = heap1->heapSize;
    while (heap1->heap[index / 2] > element)
    {
        heap1->heap[index] = heap1->heap[index / 2];
        index /= 2;
    }
    heap1->heap[index] = element;
}

int extractMin(struct minHeap * heap1)
{
    int minElement, lastElement, child, index;

    minElement = heap1->heap[1];
    lastElement = heap1->heap[heap1->heapSize];
    heap1->heapSize--;

    ///////////////////////////
    //LEFT CHILD IS 2*index 
    //RIGHT  CHILD IS left_child+1
    ///////////////////////////

    for (index = 1; index * 2 <= heap1->heapSize; index = child)
    {
        child = index * 2;
        if (child != heap1->heapSize && heap1->heap[child + 1] < heap1->heap[child])    //right child condition...
            child++;
        
        if (lastElement > heap1->heap[child])                             //swapping the elements...
            heap1->heap[index] = heap1->heap[child];
 
        else 
            break;
    }
    heap1->heap[index] = lastElement;
    return minElement;
}


int CheckIsEmpty(struct minHeap * heap1)            //return 0 if it is empty
{
    if ( heap1->heapSize ) return 1;
    else return 0;
}


void freeHeap(struct minHeap* heap1)              //free the memory of the heap
{
    free(heap1);
}
