#include <stdio.h>
#include "register.h"
#include "priorityQueue.h"
#include "user.h"
#include <stdlib.h>

//////////
//TEST FOR IMPLEMENTATION OF THE REGISTER WITH TAKING THE INPUT
//PASSED
//////////

int main()
{

    struct minHeap * hezz = initHeap();      
    InsertToHeap(hezz,5);                       //adding 5 to the min heap
    InsertToHeap(hezz,2);                       //adding 2 to the min heap

    //expected user id ----> 2 for user1 as it is available in the heap
    //expected user id ----> 5 for user2 as it is available in the heap

    //expected user id ----> 1 for user3 as the heap is empty as the master is in 1

    user* user1 = TakeInput(hezz);
    user* user2 = TakeInput(hezz);
    user* user3 = TakeInput(hezz);

 
    
    system("clear");
    printf("User 1: \n");
    userDetails(user1);
    printf("\n\nUser 2: \n");
    userDetails(user2);
    printf("\n\nUser 3: \n");
    userDetails(user3);

    return 0;
}