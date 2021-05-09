#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "user.h"
#include "priorityQueue.h"
#include "register.h"
#include "functions.h"
#include "vector.h"

extern unsigned int MASTER;

void printUI()
{
    // system("clear");
    printf("\n\n\t\t  *** Friend Book ***\n");
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
    char inp;
    long long a, b;
    scanf(" %c", &inp);
    while ((getchar()) != '\n')
        ;
    if (inp == '1')
    {
        printf("Registering new user\n");
        user *temp = TakeInput(heap);
        list->array_of_users[temp->ID] = temp;
        resize_user_array(list);

        recommend_new(list, temp->ID);
        printf("Taking you to the main menu...\n");
    }
    else if (inp == '2')
    {
        printf("Unregister existing user\n");
        printf("Enter user ID :");
        scanf("%lld", &a);
        unregister(a, list, heap);
    }
    else if (inp == '3')
    {
        printf("Recommend friends to existing user\n");
        printf("Enter user ID: ");
        scanf("%lld", &a);
        if (a <= 0 || a > MASTER || list->array_of_users[a] == NULL)
        {
            printf("\n%lld is not a registered user !", a);
            printf("\nTaking you back to the main menu...");
        }
        else
        {
            printf("How many recommendations do you want: ");
            scanf("%lld", &b);
            recommend_old(b, a, heap, list);
            printf("\nTaking you back to the main menu...\n");
        }
    }
    else if (inp == '4')
    {
        printf("Add friend\n");
        AddSingleFriend(list);
    }
    else if (inp == '5')
    {
        printf("Check friendship status! List 2 user IDs!\n");
        scanf("%lld%lld", &a, &b);
        if (a <= 0 || a > MASTER || list->array_of_users[a] == NULL)
        {
            printf("\n%lld is not a registered user !", a);
            printf("\nTaking you back to the main menu...");
        }
        else if (a <= 0 || b > MASTER || list->array_of_users[b] == NULL)
        {
            printf("\n%lld is not a registered user !", b);
            printf("\nTaking you back to the main menu...");
        }
        else
        {
            if (checkfriendshipstatus(list->array_of_users[a]->following, b) == 1)
            {
                printf("\nYes, they are friends!");
            }
            else
            {
                printf("\nNo, they aren't friends!");
            }
            printf("\nTaking you back to the main menu...\n");
        }
    }
    else if (inp == '6')
    {
        printf("Printing parameters of a user\n");
        long long tempID;
        printf("Enter user ID: ");
        scanf("%lld", &tempID);
        if (tempID <= 0 || tempID > MASTER || list->array_of_users[tempID] == NULL)
        {
            printf("\n%lld is not a registered user !", tempID);
            printf("\nTaking you back to the main menu...");
        }
        else
        {
            userDetails(list, tempID);
        }
    }
    else if (inp == '0')
    {
        printf("Exiting!\nThank you for using this service\n");
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

    char inp = '1';
    system("clear");
    while (inp != '0')
    {
        printUI();
        inp = acceptinput(list, heap);
    }
    printf("\n");

    //Free All Memory
    for (int i = 0; i < list->capacity; i++)
    {
        if (list->array_of_users[i] != NULL)
        {
            // printf("Freeing user %d\n", i);
            free(list->array_of_users[i]->city);
            free(list->array_of_users[i]->country);

            removeall(list->array_of_users[i]->followers);
            free(list->array_of_users[i]->followers);
            removeall(list->array_of_users[i]->following);
            free(list->array_of_users[i]->following);

            free(list->array_of_users[i]->hobby);

            free(list->array_of_users[i]->name);
            free(list->array_of_users[i]->organization);
            free(list->array_of_users[i]);
        }
    }
    free(list->array_of_users);
    free(list);
    freeHeap(heap);
    return 0;
}
