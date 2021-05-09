#include <stdio.h>
#include <ctype.h>
#include "vector.h"
#include "user.h"
#include "priorityQueue.h"

extern long long int MASTER;

void AddF(user_list *list, long long a, long long b) //Adds b to friend list of a and a to the anti-friend list of b
{
    add(b, &(list->array_of_users[a]->following));
    add(a, &(list->array_of_users[b]->followers));
}

void AddMultipleFriends(user_list *list, long long a, long long count) //Called after recommending friends to new and old users
{
    // adding multiple users as friends to a user
    printf("would you like to add any of these users as your friends? (y/n): ");
    char inp;
    Line:
    scanf("%c" , &inp);
    while ((getchar()) != '\n') //We are only interested in the first char of users input
        ;                       //We discard all input after the first character
    inp = tolower(inp);
    if(inp != 'y' && inp != 'n'){
        printf("\nError! choose one of (y/n): ");
        goto Line; //Takes user input again as user input was invalid
    }
    if(inp == 'y'){
        long long x; // x is the number of friends to be added
        printf("\nSelect the number of friends you want to add: ");
            scanf("%lld", &x);
        if(x > count){
            x = count; 
            printf("We have only recommended %lld users\n" , count); //User cannot choose to add more friends than those recommended to him
        }
        printf("\nAdding %lld users...\n", x);
        printf("\nplease provide the user IDs of friends you would like to add to user %lld ", a);
        long long b;
        for (int i = 0; i < x; i++) // taking user inputs and calling addfriends function
        {
            printf("\nEnter user ID: ");
            scanf("%lld", &b);
            if(b<=0 || b > MASTER || list->array_of_users[b] == NULL ) // condition to check whether the user ID is valid 
            {
                printf("\n%lld is not a registered user !",b);
                printf("\nPlease enter a valid user ID!\n");
                i--;
                continue;
            }else if(b == a){ // User cannot add themselves as a friend
                printf("\nyou can't add yourself as a friend!\n");
                i--;
                continue;
            }
            printf("\nAdding %lld as a friend of %lld...", b, a);
            AddF(list, a, b);       //Calls the AddF function to add b as friend of a and a in the followers list 
        }
        printf("\nAdded all the friends!\n");
    }
}

void AddSingleFriend(user_list *list) 
{
    //For adding single friend 
    long long a, b;
    printf("Enter user ids of two users: \n");
    scanf("%lld%lld", &a, &b);
    if(a == b){ // User cannot add themselves as a friend
        printf("\nyou can't add yourself as a friend!\n please change your input\n");
        AddSingleFriend(list);
        return;
    }
    if(a<=0 ||a>MASTER || list->array_of_users[a] == NULL) // condition to check whether the user ID is valid 
    {
        printf("\n%lld is not a registered user!",a);
        printf("\nTaking you back to the main menu...");
        return;
    }
    else if(b<=0 ||b>MASTER || list->array_of_users[b] == NULL)// condition to check whether the user ID is valid 
    {
        printf("\n%lld is not a registered user!",b);
        printf("\nTaking you back to the main menu...");
        return;
    }

    printf("\nAdding %lld as a friend of %lld...", b, a);
    AddF(list, a, b);   // calls addF funtion
}