#include "user.h"
#include "priorityQueue.h"
#include "register.h"
#include "functions.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

void dummyfunc() {}

void printUI()
{
    // system("clear");
    printf("\n\n\t  *** Friend Recommendation System ***\n");
    printf("\n");
    printf("\t\t    List of commands\n");
    printf("\t=========================================\n");
    printf("\t  [1] Register new user\n");
    printf("\t  [2] Unregister existing user\n");
    printf("\t  [3] Recommend friends to existing user\n");
    printf("\t  [4] Add friend to existing user\n");
    printf("\t  [5] Check friendship status\n");
    printf("\t  [6] Print user details\n");
    printf("\t  [0] Exit\n");
    printf("\t=========================================\n");
    //acceptinput();
}

int acceptinput(user_list *list, struct minHeap *heap)
{
    printf("\nEnter choice: ");
    int inp, a, b;
    scanf("%d", &inp);
    if (inp == 1)
    {
        printf("Registering new user\n");
        user *temp = TakeInput(heap);
        list->array_of_users[temp->ID] = temp;

        // recommend_new(list, temp->ID);
    }
    else if (inp == 2)
    {
        printf("Unregister existing user\n");
        scanf("%d", &a);
        unregister(a, list, heap);
        printf("Succesfully unregistered %d\n", a);
    }
    else if (inp == 3)
    {
        printf("Recommend friends to existing user\n");
        printf("Enter user id: ");
        scanf("%d", &a);
        printf("How many recommendations do you want: ");
        scanf("%d", &b);
        recommend_old(b, a, heap, list);
    }
    else if (inp == 4)
    {
        printf("Add friend\n");
        AddSingleFriend(list);
    }
    else if (inp == 5)
    {
        printf("Check friendship status! List 2 user ids!\n");
        scanf("%d%d", &a, &b);
        if (checkfriendshipstatus(list->array_of_users[a]->following, b) == 1)
        {
            printf("\nYes, they are friends!");
        }
        else
        {
            printf("\nNo, they aren't friends!");
        }
    }
    else if (inp == 6)
    {
        printf("Printing parameters of a user\n");
        int tempID;
        scanf("%d", &tempID);
        userDetails(list->array_of_users[tempID]);
    }
    else if (inp == 0)
    {
        printf("Exiting!\nThank you for using this service\n");
        dummyfunc();
    }
    else
    {
        printf("Invalid Input! Please try again!\n");
        inp = acceptinput(list, heap);
    }
    return inp;
}

int main()
{
    user_list *list = create_user_list();
    struct minHeap *heap = initHeap();

    int inp = 1;
    while (inp != 0)
    {
        printUI();
        inp = acceptinput(list, heap);
    }
    printf("\n");

    //Free All Memory

    return 0;
}