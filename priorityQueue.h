#ifndef __HEE_H
#define __HEE_H

#define max_size 100000

long extractMin();                           //return the min element and then makes the heap a min heap again.
void InsertToHeap(long element);             // inserts the element into the heap and then heapify.
int CheckIsEmpty();                          //returns 0 if the heap is empty.
                    

#endif