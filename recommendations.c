#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "priorityQueue.h"
#include "user.h"
#include "Queue.h"
#include "vector.h"
#define ll long long

extern unsigned int MASTER;
// recommend_old(k, userID);

// things needed to execute the function -> no.of.registered users, k,
// friends lists of every user, userID(of the person who needs user recomm)
void recommend_old(int k, long long userID, struct minHeap *heap, user_list* list)
{

    // to make the queue
    ll n = MASTER - (heap->heapSize);
    PtrToNode H = Makequeue();
    PtrToNode T = Makequeue();
    H->Next = T;
    T->Prev = H;

    ll no_of_registered_users;
    ll s = userID, count = 0;
    bool visited[n+1]; // n here is the total number of registered users
    ll distance[n+1];  // stores dist from first user

    // initializing all values to 0
    for(int i = 0; i < n+1; i++){
        visited[i]  = false ;
        distance[i] = 0;
    }

    push(T, s); // s is the userID
    visited[s] = true;
    distance[s] = 0;
    // ll recommend[k];
    // bool breakflag = false;
    // ll last = n;

    while (!empty(H))
    {
        int v = front(H)->x; // v is a user
        pop(H);

        for (int i = 0; i < list->array_of_users[v]->following->capacity; i++)
        {
            data *S = list->array_of_users[v]->following->friend[i] -> next;
            while (S != NULL)
            {
                ll u = S->user_id; // a friend of v
                if (!visited[u])
                {
                    visited[u] = true;
                    push(T, u);
                    distance[u] = distance[v] + 1;
                    if (distance[u] > 1 && count < k)
                    {
                        // recommend[count] = u;
                        count++;
                        // display the users info
                        printf("\n%lld: userID:%lld  username: %s", count , u, list->array_of_users[u]->name);
                    }
                }

                if (count >= k)
                {
                    break;
                }
                S = S->next;
            }
        }
    }
        // for (int i = 0; i < userlist[s]->friends->capacity; i++) // traversing through the "following"/friends list of v
        // {

        //     ll u; // a friend of v
        //     if (!visited[u])
        //     {
        //         visited[u] = true;
        //         push(H, u);
        //         distance[u] = distance[v] + 1;
        //         if (distance[u] > 1 && count < k)
        //         {
        //             recommend[count] = u;
        //             count++;
        //             // display the users info
        //             printf("\n%lld: userID:  username: ", count);
        //         }
        //     }

        //     if (count >= k)
        //     {
        //         break;
        //     }
        // }
        // displays all recommended users info
        return;
    }

    /* things needed to complete - 1) hash tables of registered users, basically following list of every user
                               2) number of registered users, if i can traverse i can do this function */