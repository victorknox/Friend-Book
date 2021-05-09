#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "priorityQueue.h"
#include "user.h"
#include "Queue.h"
#include "vector.h"
#include "functions.h"
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

    // executing BFS over the data
    while (!empty(H))
    {
        int v = front(H)->x; // v is a user
        pop(H);

        for (int i = 0; i < list->array_of_users[v]->following->capacity; i++) // traversing through the friends list of v
        {
            data *S = list->array_of_users[v]->following->friend[i] -> next;
            while (S != NULL)
            {
                ll u = S->user_id; // u is a friend of v
                if (!visited[u])
                {
                    visited[u] = true;
                    push(T, u);
                    distance[u] = distance[v] + 1;
                    if (distance[u] > 1 && count < k)
                    {
                        count++;
                        // displays the users info
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
        printf("\nWe have found %lld users for you to befriend!\n" , count);
        if(count > 0){
            AddMultipleFriends(list, userID, count);
        }
        // displays all recommended users info
        return;
    }
    