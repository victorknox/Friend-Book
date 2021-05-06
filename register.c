#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "priorityQueue.h"
#include "register.h"
#include "user.h"
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
    system("clear");
    user *newUser = (user *)malloc(sizeof(user));
    printf("**-----THANK U FOR INITIALSING THE REGISTERING WITH US-------**\n");
    newUser->ID = idAllocation(heap);
    printf("****Your unique id is %d****\n\n\n",newUser->ID);

    printf("--->ENTER YOUR NAME\n");
    newUser->name = (char *)malloc(sizeof(char *));
    scanf("%[^\n]%*c", newUser->name); //scaning the name....

    printf("--->Welcome %s, please enter the your gender.\n", newUser->name);
//goto loop for handling the errors of the user in the spelling...
L1:
    printf("--->Type male / female / others\n");

    char gender[10];
    scanf("%s", gender);
    if (strcmp(gender, "male") != 0 && strcmp(gender, "female") && strcmp(gender, "others"))
    {
        printf("**ERROR**\n-->Please check the gender you have typed.<--\n");
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
    printf("--->Enter your age\n");
    unsigned short int age;
    scanf("%hd",&newUser->age);

    //taking the input for the  city 
    printf("--->Enter your city\n");
    newUser->city = (char *)malloc(sizeof(char *));
    scanf(" %[^\n]%*c", newUser->city);

    //taking the user's country
    printf("--->Enter your country\n");
    newUser->country = (char *)malloc(sizeof(char *));
    scanf(" %[^\n]%*c", newUser->country);

    //taking the users most favourite hobby
    printf("--->Enter your hobby (any 1)\n");
    newUser->hobby = (char *)malloc(sizeof(char *));
    scanf(" %[^\n]%*c", newUser->hobby);

    //taking the organisation
    printf("--->Enter the organisation\n");
    newUser->organization = (char *)malloc(sizeof(char *));
    scanf(" %[^\n]%*c", newUser->organization);

    return newUser;
}

void userDetails(user* userAddress)
{
    printf("Name        :- %s\n",userAddress->name);
    printf("Unique ID   :- %d\n",userAddress->ID);
    printf("Gender      :- %c\n",userAddress->gender);
    printf("Age         :- %hd\n",userAddress->age);
    printf("City        :- %s\n",userAddress->city);
    printf("Country     :- %s\n",userAddress->country);
    printf("Hobby       :- %s\n",userAddress->hobby);
}
