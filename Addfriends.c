#include <stdio.h>
#include "vector.h"
#include "user.h"

void AddF(user_list *list, long long a, long long b)
{
    add(b, &(list->array_of_users[a]->following));
    add(a, &(list->array_of_users[b]->followers));
}

void AddMultipleFriends(user_list *list, long long a)
{
    // adding multiple users as friends to a user
    long long x;
    printf("Select the number of friends u want to add: ");
        scanf("%lld", &x);
    printf("please provide the user IDs of friends u would like to add to %lld", a);
    long long b;
    for (int i = 0; i < x; i++)
    {
        scanf("%lld", &b);
        printf("\nAdding %lld as a friend of %lld...", b, a);
    }
    printf("\nAdded all the friends !");
}

void AddSingleFriend(user_list *list)
{
    long long a, b;
    printf("Enter user ids of two users: \n");
    scanf("%lld%lld", &a, &b);
    printf("\nAdding %lld as a friend of %lld...", b, a);
    AddF(list, a, b);
}