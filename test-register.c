#include <stdio.h>
#include "register.h"
#include "priorityQueue.h"
#include "user.h"
#include <stdlib.h>

int main()
{
    struct minHeap * hezz = initHeap();
    user* user1 = TakeInput(hezz);
    user* user2 = TakeInput(hezz);

    system("clear");
    printf("User 1: \n");
    userDetails(user1);
    printf("\n\nUser 2: \n");
    userDetails(user2);
    return 0;
}