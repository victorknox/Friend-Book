#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Queue.h"

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

void Freequeue(PtrToNode H, PtrToNode T)
{
      while (H->Next != T)
      {
            pop(H);
      }
      free(H);
      free(T);
}
