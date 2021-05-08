#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"
#define ll long long
#define n 10000


// recommend_old(k, userID);


// things needed to execute the function -> no.of.registered users, k,
// friends lists of every user, userID(of the person who needs user recomm)
void recommend_old(int k,ll userID){

    // to make the queue
    PtrToNode H = Makequeue();
    PtrToNode T = Makequeue();
    H->Next = T;
    T->Prev = H;
    
    
    ll no_of_registered_users;
    ll s = userID , k, count = 0;
    bool visited[n] = {0}; // n here is the total number of registered users
    ll distance[n] = {0}; // stores dist from first user
    
    push(H,s); // s is the userID
    visited[s] = true;
    distance[s] = 0;
    ll recommend[k];
    bool breakflag = false;
    ll last = n;

    while(!empty(H)){
        ll v = front(H);
        pop(H);
        ll listsize; // number of friends of v

        for(int i = 0; i < userlist[s]->friends->capacity ; i++) // traversing through the "following"/friends list of v
        {

            ll u; // a friend of v
            if(!visited[u]){
                visited[u] = true;
                push(H, u);
                distance[u] = distance[v] + 1;
                if(distance[u]> 1 && count < k){
                    recommend[count] = u;
                    count++;
                    // display the users info
                    printf("\n%lld: userID:  username: " , count);
                }
            }

            if(count >= k){
                break;
            }
        }  
        // displays all recommended users info
    return 0;
}


/* things needed to complete - 1) hash tables of registered users, basically following list of every user
                               2) number of registered users, if i can traverse i can do this function */