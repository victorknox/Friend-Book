#include <stdio.h>
#include <ctype.h>
#include "vector.h"
#include "user.h"
#include "priorityQueue.h"

extern unsigned int MASTER;

void AddF(user_list *list, long long a, long long b)
{
    add(b, &(list->array_of_users[a]->following));
    add(a, &(list->array_of_users[b]->followers));
}

void AddMultipleFriends(user_list *list, long long a, long long count)
{
    // adding multiple users as friends to a user
    printf("would you like to add any of these users as your friends? (y/n) :");
    char inp;
    Line:
    scanf("%c" , &inp);
    inp = tolower(inp);
    if(inp != 'y' && inp != 'n'){
        printf("\nError! choose one of (y/n)");
        goto Line;
    }
    if(inp == 'y'){
        long long x;
        printf("\nSelect the number of friends u want to add: ");
            scanf("%lld", &x);
        if(x > count){
            x = count;
            printf("We have only recommended %lld users\n" , count);
        }
        printf("\nAdding %lld users...\n", x);
        printf("\nplease provide the user IDs of friends you would like to add to user %lld ", a);
        long long b;
        for (int i = 0; i < x; i++)
        {
            printf("\nEnter user ID: ");
            scanf("%lld", &b);
            if(b > MASTER || list->array_of_users[b] == NULL )
            {
                printf("\n%lld is not a registered user !",b);
                printf("\nPlease enter a valid user ID!\n");
                i--;
                continue;
            }else if(b == a){
                printf("\nyou can't add yourself as a friend!\n");
                i--;
                continue;
            }
            printf("\nAdding %lld as a friend of %lld...", b, a);
            AddF(list, a, b);
        }
        printf("\nAdded all the friends!\n");
    }
}

void AddSingleFriend(user_list *list)
{
    long long a, b;
    printf("Enter user ids of two users: \n");
    scanf("%lld%lld", &a, &b);
    if(a == b){
        printf("\nyou can't add yourself as a friend!\n please change your input\n");
        AddSingleFriend(list);
        return;
    }
    if(a>MASTER || list->array_of_users[a] == NULL)
    {
        printf("\n%lld is not a registered user !",a);
        printf("\nTaking you back to the main menu...");
        return;
    }
    if(b>MASTER || list->array_of_users[b] == NULL)
    {
        printf("\n%lld is not a registered user !",b);
        printf("\nTaking you back to the main menu...");
        return;
    }

    printf("\nAdding %lld as a friend of %lld...", b, a);
    AddF(list, a, b);
}