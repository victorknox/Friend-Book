#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "priorityQueue.h"
#include "register.h"
#include "user.h"
#include "vector.h"
////////
//**NEED TO INITIALISE THE HEAP IN THE MAIN USING THE FOLLOWING CODE**
////////
//struct minHeap * variableName = initHeap();
////////

unsigned int MASTER = 0;

unsigned int idAllocation(struct minHeap *heap) //returns the least minimum id to the user....
{
    unsigned int userId;
    if (CheckIsEmpty(heap))
    {
        userId = extractMin(heap);
        return userId;
    }
    return ++MASTER;
}

user* TakeInput(struct minHeap *heap) //taking the input incase of the user registers
{
    //system("clear");
    user *newUser = (user *)malloc(sizeof(user));
    // printf("**-----THANK U FOR INITIALSING THE REGISTERING WITH US-------**\n");
    newUser->ID = idAllocation(heap);
    printf("\nYour unique ID is %d \n\n",newUser->ID);

    printf("Enter your name: ");
    newUser->name = (char *)malloc(sizeof(char *));
    scanf(" %[^\n]%*c", newUser->name); //scaning the name....

    printf("\n\t\tWelcome %s!\n\nPlease enter your gender ", newUser->name);
//goto loop for handling the errors of the user in the spelling...
L1:
    printf("(Select one of male/female/other): ");

    char gender[1000];
    scanf("%[^\n]%*c", gender);
    if (strcmp(gender, "male") != 0 && strcmp(gender, "female") && strcmp(gender, "other"))
    {
        printf("**ERROR**\n Please select a gender option \n");
        goto L1;
    }
    newUser->gender = gender[0];
    /////////////////////
    //storing the gender
    //m for male
    //f for female
    //o for others
    //////////////////////

    //taking input for age
    printf("Enter your age: ");
    unsigned short int age;
    scanf("%hd",&newUser->age);

    //taking the input for the  city 
    printf("Enter your city: ");
    newUser->city = (char *)malloc(sizeof(char *));
    scanf(" %[^\n]%*c", newUser->city);

    //taking the user's country
    printf("Enter your country: ");
    newUser->country = (char *)malloc(sizeof(char *));
    scanf(" %[^\n]%*c", newUser->country);

    //taking the users most favourite hobby
    printf("Enter your hobby (any 1): ");
    newUser->hobby = (char *)malloc(sizeof(char *));
    scanf(" %[^\n]%*c", newUser->hobby);

    //taking the organisation
    printf("Enter your organisation: ");
    newUser->organization = (char *)malloc(sizeof(char *));
    scanf(" %[^\n]%*c", newUser->organization);
    printf("\n User successfully registered!\n\nTaking you to the main menu...");
    
    //Creating friends list
    data* temp = createdata();
    temp->user_id=newUser->ID;
    newUser->following = vector(*temp);
    newUser->followers = vector(*temp);

    return newUser;
}

void userDetails(user* userAddress)
{
    if(userAddress==NULL)
    {
        printf("User isn't registered!\n");
        return;
    }
    printf("Name        : %s\n",userAddress->name);
    printf("Unique ID   : %d\n",userAddress->ID);
    printf("Gender      : %c\n",userAddress->gender);
    printf("Age         : %hd\n",userAddress->age);
    printf("City        : %s\n",userAddress->city);
    printf("Country     : %s\n",userAddress->country);
    printf("Hobby       : %s\n",userAddress->hobby);
}
