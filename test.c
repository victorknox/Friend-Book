#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <assert.h>

#define N 100
#define k 10 //assume k < N

typedef struct node
{
   int ID;
   int val;
   struct node *next;
} node;

void shuffle(int *array, size_t n) // Copied from gfg. Only used for debugging.
{
   if (n > 1)
   {
      size_t i;
      for (i = 0; i < n - 1; i++)
      {
         size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
         int t = array[j];
         array[j] = array[i];
         array[i] = t;
      }
   }
}

void insert(node *recommend, int val, int ID)
{
   node *new = (node *)malloc(sizeof(node));
   new->ID = ID;
   new->val = val;
   node *temp = recommend;
   while (temp->next != NULL && temp->next->val < val)
   {
      temp = temp->next;
   }
   new->next = temp->next;
   temp->next = new;
}

int removemin(node *recommend)
{
   int removed = 0;
   node *temp = recommend->next; //temp!=NULL afaik
   int min = temp->val;
   while (temp->val == min)
   {
      node *a = temp;
      temp = temp->next;
      assert(temp != NULL);
      free(a);
      removed++;
   }
   recommend->next = temp;
   return removed;
}

int checkmin(node *recommend)
{
   int minno = 0;
   node *temp = recommend->next;
   int min = temp->val;
   while (temp != NULL && temp->val == min)
   {
      minno++;
      temp = temp->next;
   }
   return minno;
}

int main()
{
   srand((unsigned)time(NULL));
   int a[N];
   for (int i = 0; i < N; i++)
   {
      a[i] = rand() % 10;
   }
   shuffle(a, N);
   for (int i = 0; i < N; i++)
   {
      if (i % 10 == 0)
         printf("\n");
      printf("%d\t", a[i]);
   }
   printf("\n\n");

   //Random array created

   int min = INT_MAX, minno = 0, nodes = 0;
   node *recommend = (node *)malloc(sizeof(node));
   recommend->val = 69;
   recommend->ID = -1;
   recommend->next = NULL;

   for (int i = 0; i < k; i++)
   {
      if (a[i] < min)
      {
         min = a[i];
         minno = 1;
      }
      if (a[i] == min)
      {
         minno++;
      }
      insert(recommend, a[i], i);
      nodes++;
   }

   for (int i = k; i < N; i++)
   {
      if (a[i] < min)
      {
         continue;
      }
      else if (a[i] == min)
      {
         minno++;
         insert(recommend, a[i], i);
         nodes++;
         if (nodes-minno>=k)
         {
            nodes -= removemin(recommend);
            minno = checkmin(recommend);
            min=recommend->next->val;
         }
      }
      if (a[i] > min)
      {
         insert(recommend, a[i], i);
         nodes++;
         if (nodes-minno>=k)
         {
            nodes -= removemin(recommend);
            minno = checkmin(recommend);
            min=recommend->next->val;
         }
      }
   }

   //Printing
   recommend = recommend->next;
   while (recommend != NULL)
   {
      printf("User %d\t(Common Parameters: %d)\n", recommend->ID, recommend->val);
      recommend = recommend->next;
   }

   printf("\nAfter selecting random minno=%d\n", minno);
}