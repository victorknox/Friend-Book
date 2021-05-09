#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "user.h"
#include "priorityQueue.h"
#include "register.h"
#include "functions.h"
#include "vector.h"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

extern long long int MASTER;

void printUI() //This function prints the list of commands the user can use
{
    // system("clear");
    printf(BLUE);
    printf("\n\n\t\t  *** Friend Book ***\n");
    printf("\n");
    printf(CYAN);
    printf("\t\t    List of commands\n");
    printf(RESET);
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
    //This function acccepts the command from the user and calls the respective function 
    printf(GREEN);
    printf("\nEnter choice: ");
    printf(RESET);
    char inp;
    long long a, b;
    scanf(" %c", &inp);
    while ((getchar()) != '\n')
        ;
    if (inp == '1') //User wants to register new user
    {
        printf(CYAN);
        printf("Registering new user\n");
        printf(RESET);
        user *temp = TakeInput(heap);
        list->array_of_users[temp->ID] = temp; //storing the struct returned by TakeInput in the array of user structs
        resize_user_array(list); //list is a dynamic array of structs and its capacity is updated by this function

        recommend_new(list, temp->ID);
        printf(RED);
        printf("Taking you to the main menu...\n");
        printf(RESET);
    }
    else if (inp == '2')
    {
        //To unregister the existing user 
        printf(CYAN);
        printf("Unregister existing user\n");
        printf(RESET);
        printf("Enter user ID :");
        scanf("%lld", &a);
        unregister(a, list, heap);
        printf(RED);
        printf("\nTaking you back to the main menu...\n");
        printf(RESET);
    }
    else if (inp == '3')
    {
        //An already registered user wants friend recommendations
        printf(CYAN);
        printf("Recommend friends to existing user\n");
        printf(RESET);
        printf("Enter user ID: ");
        scanf("%lld", &a);
        if (a <= 0 || a > MASTER || list->array_of_users[a] == NULL)
        {
            //We check if the user id is valid or not before recommending
            printf(RED);
            printf("\n%lld is not a registered user !", a);
            printf("\nTaking you back to the main menu...");
            printf(RESET);
        }
        else
        {
            printf("How many recommendations do you want: ");
            scanf("%lld", &b);
            recommend_old(b, a, heap, list);
            printf(RED);
            printf("\nTaking you back to the main menu...\n");
            printf(RESET);
        }
    }
    else if (inp == '4')
    {
        //Adds friend to the user by taking user ids of two users
        printf(CYAN);
        printf("Add friend\n");
        printf(RESET);
        AddSingleFriend(list);
    }
    else if (inp == '5')
    {
        //Checks friendship status of two users
        printf(CYAN);
        printf("Check friendship status! List 2 user IDs!\n");
        printf(RESET);
        scanf("%lld%lld", &a, &b);
        //We check if either of the user ID's are invalid bfore checking their friendship status
        if (a <= 0 || a > MASTER || list->array_of_users[a] == NULL)
        {
            printf(RED);
            printf("\n%lld is not a registered user !", a);
            printf("\nTaking you back to the main menu...");
            printf(RESET);
        }
        else if (a <= 0 || b > MASTER || list->array_of_users[b] == NULL)
        {
            printf(RED);
            printf("\n%lld is not a registered user !", b);
            printf("\nTaking you back to the main menu...");
            printf(RESET);
        }
        else
        {
            if (checkfriendshipstatus(list->array_of_users[a]->following, b) == 1)//If both user ids are valid it checks the friendship status
            {
                //It calls the check friendship status function to check for b in the friends list of a
                printf(GREEN);
                printf("\nYes, they are friends!");
                printf(RESET);
            }
            else
            {
                printf(RED);
                printf("\nNo, they aren't friends!");
                printf(RESET);
            }
            printf(RED);
            printf("\nTaking you back to the main menu...\n");
            printf(RESET);
        }
    }
    else if (inp == '6') 
    {
        //Prints details of the user whose ID is mentioned
        printf(CYAN);
        printf("Printing parameters of a user\n");
        printf(RESET);
        long long tempID;
        printf("Enter user ID: ");
        scanf("%lld", &tempID);
        if (tempID <= 0 || tempID > MASTER || list->array_of_users[tempID] == NULL) //Checks if ID is valid
        {
            printf(RED);
            printf("\n%lld is not a registered user !", tempID);
            printf("\nTaking you back to the main menu...");
            printf(RESET);
        }
        else
        {
            userDetails(list, tempID); //Function to print user details
        }
    }
    else if (inp == '0')
    {
        //To exit the program
        printf(RED);
        printf("Exiting!\nThank you for using this service\n"); 
        printf(RESET);
    }
    else
    {
        //If the input is invalid (i.e,it is not a number from 0 to 6)
        printf(RED);
        printf("Invalid Input! Please try again!\n"); 
        printf(RESET);
        inp = acceptinput(list, heap);
    }
    return inp;
}

int main()
{
    user_list *list = create_user_list(); //Creates the userlist array by allocating memory
    struct minHeap *heap = initHeap();    //Creates priority queue

    char inp = '1';
    system("clear");
    while (inp != '0') //loop terminates only when input = 0, i.e the command to exit to program
    {
        printUI();  //Prints list of commands
        inp = acceptinput(list, heap);
    }
    printf("\n");

    //Freeing all the dynamically allocated Memory
    for (long long int i = 0; i < list->capacity; i++)        //Freeing the data of the whole list of users
    {
        if (list->array_of_users[i] != NULL)        //Frees the data of individual user
        {
            // printf("Freeing user %d\n", i);
            free(list->array_of_users[i]->city);
            free(list->array_of_users[i]->country);

            removeall(list->array_of_users[i]->followers);      //frees the list of all anti-friends of the person
            free(list->array_of_users[i]->followers);
            removeall(list->array_of_users[i]->following);      //frees the list of all friends of the person
            free(list->array_of_users[i]->following);

            free(list->array_of_users[i]->hobby);

            free(list->array_of_users[i]->name);
            free(list->array_of_users[i]->organization);
            free(list->array_of_users[i]);
        }
    }

    free(list->array_of_users); //frees array of user structs
    free(list); //frees user_list struct
    freeHeap(heap); //frees the priority queue

    return 0;
}

