#ifndef __HEE_H
#define __HEE_H

struct minHeap
{
    int * heap;
    int heapSize;
};

struct minHeap* initHeap(void);                            //init the heap 
void InsertToHeap(struct minHeap * heap1,int element);     // inserts the element into the heap and then heapify.                            
int CheckIsEmpty(struct minHeap * heap1);                  //returns 0 if the heap is empty.
int extractMin(struct minHeap * heap1);                    //return the min element and then makes the heap a min heap again.
void freeHeap(struct minHeap* heap1);                      //free the memory of the heap    
                    

#endif 