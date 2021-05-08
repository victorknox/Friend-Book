#include "vector.h"
#include "user.h"
#include "priorityQueue.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void unregister(long long int id, user_list *userlist, struct minHeap *heap) //unregisters a person from the database(say A)
{
      // This first part removes A from all the friends lists of A's antifriends
      if (userlist->array_of_users[id] == NULL)
      {
            printf("User isn't registered!\n");
            return;
      }

      InsertToHeap(heap, id);

      user *user_tbr = userlist->array_of_users[id];          //finds the struct of A in userlist
      for (int i = 0; i < user_tbr->followers->capacity; i++) //traverses antifriendlist of A
      {
            data *P = user_tbr->followers->friend[i];
            while (P->next != NULL)
            {
                  if (P->user_id == 0)
                  {
                        P = P->next;
                        continue;
                  }
                  friends *ff = userlist->array_of_users[P->user_id]->following; //access friend list of B(an antifriend of A)
                  removeval(id, ff);                                             //removes A from friends list of B
                  P = P->next;
            }
      }

      // This next part removes A from all the antifriends lists of A's friends

      for (int i = 0; i < user_tbr->following->capacity; i++) //traverses friendlist of A
      {
            data *Q = user_tbr->following->friend[i];
            while (Q->next != NULL)
            {
                  if (Q->user_id == 0)
                  {
                        Q = Q->next;
                        continue;
                  }
                  friends *aff = userlist->array_of_users[Q->user_id]->followers; //access antifriend list of C(a friend of A)
                  removeval(id, aff);                                             //removes A from antifriends list of C
                  Q = Q->next;
            }
      }

      free(&userlist->array_of_users[id]->age);
      free(userlist->array_of_users[id]->city);
      free(userlist->array_of_users[id]->country);
      free(userlist->array_of_users[id]->followers);
      free(userlist->array_of_users[id]->following);
      free(&userlist->array_of_users[id]->gender);
      free(userlist->array_of_users[id]->hobby);
      free(&userlist->array_of_users[id]->ID);
      free(userlist->array_of_users[id]->name);
      free(userlist->array_of_users[id]->organization);
      free(userlist->array_of_users[id]);

      userlist->array_of_users[id] = NULL;
}
