#include "vector.h"
#include "user.h"
#include "aflist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//minor changes pending
//userlist is a placeholder(my own userlist)
//will add aflist later
//user.h has minor change
//vector.h is from Girija's branch

void unregister(long long int id, user *userlist, int listsize) //unregisters a person from the database(say A)
{
      // This first part removes A from all the friends lists of A's antifriends

      user user_tbr = userlist[hash(id, listsize)];       //finds the struct of A in userlist
      for (int i = 0; i < user_tbr.aflist->capacity; i++) //traverses antifriendlist of A
      {
            data *P = user_tbr.aflist->antifriend[i];
            while (P->next != NULL)
            {
                  int k = hash(P->user_id, listsize); //finds the struct of B(an antifriend of A) in userlist
                  friends *ff = userlist[k].flist;    //access friend list of B
                  removeval(id, ff);                  //removes A from friends list of B
                  P = P->next;
            }
      }

      // This next part removes A from all the antifriends lists of A's friends

      for (int i = 0; i < user_tbr.flist->capacity; i++) //traverses friendlist of A
      {
            data *Q = user_tbr.flist->friend[i];
            while (Q->next != NULL)
            {
                  int j = hash(Q->user_id, listsize);    //finds the struct of C(a friend of A) in userlist
                  antifriends *aff = userlist[j].aflist; //access antifriend list of C
                  removeval1(id, aff);                   //removes A from antifriends list of C
                  Q = Q->next;
            }
      }
}
