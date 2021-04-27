#ifndef __HEAP_H
#define __HEAP_H

#define max_size 100000

typedef int ElementType;

int pQueue[max_size];
int front_,rear_;

void insert(int element);
int extractMin();


#endif