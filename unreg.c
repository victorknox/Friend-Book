#include <stdio.h>

#define min_no_frds 20
typedef struct data data;
typedef struct friends friends;
typedef struct antifriends antifriends;
typedef struct flist flist;
typedef struct aflist aflist;

struct flist //friends hashtable
{
      int size;          //tablesize
      friends *frlist[]; //array of pointers to individual friends lists(pointers to friends structs)
};

struct aflist //antifriends hashtable
{
      int size;               //tablesize
      antifriends *afrlist[]; //array of pointers to individual antifriends lists(pointers to antifriends structs)
};

struct data
{
      int user_id;
      data *next;
};

struct friends
{
      int capacity;
      int num_added;
      data self;
      data *friend[];
};

struct antifriends
{
      int capacity;
      data self;
      data *antifriend[];
};

#ifndef __HEE_H
#define __HEE_H

#define max_size 100000

long extractMin();               //return the min element and then makes the heap a min heap again.
void InsertToHeap(long element); // inserts the element into the heap and then heapify.
int CheckIsEmpty();              //returns 0 if the heap is empty.

#endif

void unregister(flist F, aflist AF, long long int id)
{
      int t = hash(id, AF.size); //finds the index(in AF list) of the id of the person to be removed(say B)

      for (int i = 0; i < AF.afrlist[t]->capacity; i++) //traverse through the antifriends list of B
      {
            data *P = AF.afrlist[t]->antifriend[i];

            while (P->next != NULL)
            {
                  int k = hash(P->user_id, F.size); //finds the index(in F list) of all the antifriends of B

                  data *Q = F.frlist[k]->friend[hash(id, F.frlist[k]->capacity)];

                  while (Q->next != NULL) //traverse through friends lists' of antifriends of B and finds and removes B from each
                  {
                        if (Q->next->user_id == id)
                        {
                              data *T = createdata();
                              T = Q->next;
                              Q->next = T->next;
                              free(T);
                              break;
                        }

                        Q = Q->next;
                  }

                  P = P->next;
            }
      }

      int p = hash(id, F.size); //finds the index(in F list) of the id of the person to be removed(say B)

      for (int j = 0; j < F.frlist[p]->capacity; j++) //traverse through the friends list of B
      {
            data *R = F.frlist[p]->friend[j];

            while (R->next != NULL)
            {
                  int l = hash(R->user_id, AF.size); //finds the index(in AF list) of all the friends of B

                  data *S = AF.afrlist[l]->antifriend[hash(id, AF.afrlist[l]->capacity)];

                  while (S->next != NULL) //traverse through antifriends lists' of friends of B and finds and removes B from each
                  {
                        if (S->next->user_id == id)
                        {
                              data *T = createdata();
                              T = S->next;
                              S->next = T->next;
                              free(T);
                              break;
                        }

                        S = S->next;
                  }

                  R = R->next;
            }
      }

      InsertToHeap(id);
}