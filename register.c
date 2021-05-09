#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include<assert.h>

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
    char A[100];
    //system("clear");
    user *newUser = (user *)malloc(sizeof(user));
    // printf("**-----THANK U FOR INITIALSING THE REGISTERING WITH US-------**\n");
    newUser->ID = idAllocation(heap);
    printf("\nYour unique ID is %d \n\n",newUser->ID);

    printf("Enter your name: ");
    scanf(" %[^\n]%*c", A); //scaning the name....
    newUser->name = (char *)malloc(strlen(A)*sizeof(char));
    assert(newUser->name!=NULL);
    strcpy(newUser->name,A);

    printf("\n\t\tWelcome %s!\n\nPlease enter your gender ", newUser->name);
//goto loop for handling the errors of the user in the spelling...
L1:
    printf("(Select one of male/female/other): ");

    char gender[20];
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
    printf("Enter your age: ");                            //age is between 0 and 200
    unsigned short int age;
L2:
    if (scanf("%hd", &newUser->age) == 0)
    {
        while ((getchar()) != '\n');                       //**clear the buffer as if it contains more than one charecter...**
        printf("**ERROR**\nYou have not entered number, please re-enter the age properly.\n");
        goto L2;
    }
    else                                                 
    {
        if(newUser->age >=200 || newUser->age <0)
        {
            printf("**ERROR**\nYou have entered a huge number or a negetive age,\nPlease re-enter the age properly.\n");
            goto L2;
        }
    }

    //taking the input for the  city 
    memset(A,'\0',100*sizeof(char)); 
    printf("Enter your city: ");
    scanf(" %[^\n]%*c", A);
    newUser->city = (char *)malloc(strlen(A)*sizeof(char));
    assert(newUser->city!=NULL);
    strcpy(newUser->city,A);

    //taking the user's country
    memset(A,'\0',100*sizeof(char));
    printf("Enter your country: ");
    scanf(" %[^\n]%*c", A);
    newUser->country = (char *)malloc(strlen(A)*sizeof(char));
    assert(newUser->country!=NULL);
    strcpy(newUser->country,A);

    //taking the users most favourite hobby
    memset(A,'\0',100*sizeof(char));
    printf("Enter your hobby (any 1): ");
    scanf(" %[^\n]%*c", A);
    newUser->hobby = (char *)malloc(strlen(A)*sizeof(char));
    assert(newUser->hobby!=NULL);
    strcpy(newUser->hobby,A);

    //taking the organisation
    memset(A,'\0',100*sizeof(char));
    printf("Enter your organisation: ");
    scanf(" %[^\n]%*c", A);
    newUser->organization = (char *)malloc(strlen(A)*sizeof(char));
    assert(newUser->organization!=NULL);
    strcpy(newUser->organization,A);
    
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
    printf("Organization: %s\n",userAddress->organization);
}
