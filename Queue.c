#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

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

/* 
Use these 4 lines while executing(before using these functions):

PtrToNode H = Makequeue();
PtrToNode T = Makequeue();
H->Next = T;
T->Prev = H;

*/


queue Makequeue()
{
      queue Q = (queue)malloc(sizeof(Node));
      Q->Next = NULL;
      Q->Prev = NULL;
      return Q;
}

void push(PtrToNode T, ElementType y)
{
      PtrToNode Tmp, L;
      Tmp = Makequeue();
      L = T->Prev;
      Tmp->x = y;
      Tmp->Next = T;
      Tmp->Prev = L;
      L->Next = Tmp;
      T->Prev = Tmp;
}

void pop(PtrToNode H)
{
      PtrToNode Tmp, L;
      Tmp = H->Next;
      if (Tmp->Next == NULL)
      {
            printf("The queue is Empty");
            return;
      }
      L = Tmp->Next;
      H->Next = L;
      L->Prev = H;
      Tmp->Next = NULL;
      Tmp->Prev = NULL;
}

bool empty(PtrToNode H)
{
      if (H->Next->Next == NULL)
      {
            return true;
      }
      else
      {
            return false;
      }
}

PtrToNode front(PtrToNode H)
{
      return H->Next;
}

PtrToNode back(PtrToNode T)
{
      return T->Prev;
}
