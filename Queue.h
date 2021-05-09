#ifndef __Q_C
#define __Q_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long int ElementType;

struct node
{
      ElementType x;
      struct node *Next;
      struct node *Prev;
};

typedef struct node Node;
typedef struct node *PtrToNode;
typedef struct node *queue;

//H and T are dummy nodes pointing to the beginning and end of the queue respectively

queue Makequeue();
void push(PtrToNode H, ElementType y);//push(H,y) is equivalent to push(y)
void pop(PtrToNode H);//pop(H) is equivalent to pop()
bool empty(PtrToNode H);//empty(H) is equivalent to empty() [returns true or false]
PtrToNode front(PtrToNode H);//front(H) is equivalent to front() [returns pointer to first element of queue]
PtrToNode back(PtrToNode T);//back(T) is equivalent to back() [returns pointer to last element of queue]
void Freequeue(PtrToNode H,PtrToNode T);//frees the queue [frees all memeory of the queue]

/* 
Use these 4 lines while executing(before using these functions):

PtrToNode H = Makequeue();
PtrToNode T = Makequeue();
H->Next = T;
T->Prev = H;

*/

#endif


