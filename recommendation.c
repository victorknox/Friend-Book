#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"
#define ll long long
#define n 10000
// recommend_old(k, userID);


// queue Makequeue();
// void push(PtrToNode H, ElementType y);//push(H,y) is equivalent to push(y)
// void pop(PtrToNode H);//pop(H) is equivalent to pop()
// bool empty(PtrToNode H);//empty(H) is equivalent to empty() [returns true or false]
// PtrToNode front(PtrToNode H);//front(H) is equivalent to front() [returns pointer to first element of queue]
// PtrToNode back(PtrToNode T);//back(T) is equivalent to back() [returns pointer to last element of queue]


// things needed to execute the function -> no.of.registered users, k,
// friends lists of every user, userID(of the person who needs user recomm)
int main(void){

    // to make the queue
    PtrToNode H = Makequeue();
    PtrToNode T = Makequeue();
    H->Next = T;
    T->Prev = H;
    
    
    ll no_of_registered_users;
    ll s, k, count = 0;
    bool visited[n] = {0};
    ll distance[n] = {0}; // stores dist from array
    
    push(H,s); // s is the userID
    visited[s] = true;
    distance[s] = 0;
    ll recommend[k];
    bool breakflag = false;
    ll last = n;
    while(!empty(H)){
        ll v = front(H);
        pop(H);
        ll listsize;
        // make the traversal random
        for(int i = 0; i < listsize; i++) // traversing through the "following" list of v
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


                    // if(count == k){
                    //     last = distance[u];        }
                    // }
                }
                // if(distance[u] > last){
                //     breakflag = true;
                //     break;
                // }
            }
            // if(breakflag){
            //     break;
            // }
            if(count >= k){
                break;
            }
        }  
        // displays all recommended users info
    return 0;
}


/* things needed to complete - 1) hash tables of registered users, basically following list of every user
                               2) number of registered users, if i can traverse i can do this function */