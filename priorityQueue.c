#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "priorityQueue.h"


///////////
//PRIORITY QUEUE
//////////

///////////NEW SERIES OF CODE BEGINS HERE///////////

long heap[max_size], heapSize = 0;


void InsertToHeap(long element) //index from the array 1 to max_size.......***parent to index is index/2***.....
{
    heapSize++;
    heap[heapSize] = element;
    int index = heapSize;
    while (heap[index / 2] > element)
    {
        heap[index] = heap[index / 2];
        index /= 2;
    }
    heap[index] = element;
}

int CheckIsEmpty()            //return 0 if it is empty
{
    if ( heapSize ) return 1;
    else return 0;
}
long extractMin()
{
    long minElement, lastElement;
    int child, index;

    minElement = heap[1];
    lastElement = heap[heapSize];
    heapSize--;
    ///////////////////////////
    //LEFT CHILD IS 2*index
    //RIGHT  CHILD IS left_child+1
    ///////////////////////////

    for (index = 1; index * 2 <= heapSize; index = child)
    {
        child = index * 2;
        if (child != heapSize && heap[child + 1] < heap[child]) //right child condition...
            child++;

        if (lastElement > heap[child]) //swapping the elements...
            heap[index] = heap[child];

        else
            break;
    }
    heap[index] = lastElement;
    return minElement;
}

