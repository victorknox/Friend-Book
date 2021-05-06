#include "vector.h"
#include "user.h"
#include "aflist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void unregister(long long int id, user_list *userlist) //unregisters a person from the database(say A)
{
      // This first part removes A from all the friends lists of A's antifriends

      user *user_tbr = userlist->array_of_users[id];       //finds the struct of A in userlist
      for (int i = 0; i < user_tbr->aflist->capacity; i++) //traverses antifriendlist of A
      {
            data *P = user_tbr->aflist->antifriend[i];
            while (P->next != NULL)
            {
                  friends *ff = userlist->array_of_users[P->user_id]->flist; //access friend list of B(an antifriend of A)
                  removeval(id, ff);                                         //removes A from friends list of B
                  P = P->next;
            }
      }

      // This next part removes A from all the antifriends lists of A's friends

      for (int i = 0; i < user_tbr->flist->capacity; i++) //traverses friendlist of A
      {
            data *Q = user_tbr->flist->friend[i];
            while (Q->next != NULL)
            {
                  antifriends *aff = userlist->array_of_users[Q->user_id]->aflist; //access antifriend list of C(a friend of A)
                  removeval1(id, aff);                                    //removes A from antifriends list of C
                  Q = Q->next;
            }
      }
}
