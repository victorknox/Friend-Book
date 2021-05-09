#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "priorityQueue.h"
#include "user.h"
#include "functions.h"

extern unsigned int MASTER; //This stores the Largest user id of any user who ever registered

typedef struct node     //Node for linked list
{
    long long ID;
    struct node *next;
} node;

void insert(node* header, int ID) //Function for inserting node in the beginning of linked list in O(1) time
{
    node *nw = (node *)malloc(sizeof(node));
    assert(nw!=NULL);
    nw->ID = ID;

    (header->ID)++;
    nw->next = header->next;
    header->next = nw;
}

int fcommon(const user *A, const user *B) //returns number of common parameters between user A and user B
{
    int count = 0;
    if (strcmp(A->name, B->name) == 0)
        count++;
    if (A->gender == B->gender)
        count++;
    if ((A->age - B->age) * (A->age - B->age) < 100) // |A's age - B's age| < 10
        count++;
    if (strcmp(A->city, B->city) == 0)
        count++;
    if (strcmp(A->country, B->country) == 0)
        count++;
    if (strcmp(A->hobby, B->hobby) == 0)
        count++;
    if (strcmp(A->organization, B->organization) == 0)
        count++;

    return count;
}

void recommend_new(user_list *list, long long ID)
{
    int recommendations=10; //Stores the number of users still left to be recommended at any given point in time
    int count=0;            //Stores the number of users the program will be able to recommend
    node header[8];         //Array of linked lists
        //header[0] contains all people will 0 common parameters with the given person
        //header[5] linked list contains all people with 5 common parameters and so on

    for(int q=0; q<=7; q++) //Initializing linked lists with header nodes
    {
        header[q].ID=0;
        header[q].next=NULL;
    }

    for(int q=0; q<=MASTER; q++) //Iterates through all user ids to check number of common parameters for all registered users
    {
        if(list->array_of_users[q]==NULL || q==ID) //If user with given id isn't registered or is the newly registered user himself, we continue
        {
            continue;
        }
        int common = fcommon(list->array_of_users[ID], list->array_of_users[q]); //Calculates number of common parameters
        // printf("User %d, %d common parameters\n", q, common);
        insert(&header[common], q);     //Inserts user id in linked list corresponding to number of common parameters
        count++;
        //(header[common].ID)++;
    }
    if(count>10)
        count==10;
    printf("\n\nWe have found %d users for you to befriend! \n", count);
    for(int q=7; q>=0 && recommendations>0; q--)    //Iterates through all linked lists
    {                                               // first we recommend users with all 7 common parameters, then 6, then 5 and so on 
        if(header[q].ID > recommendations) //the ID in the header nodes contain how many users are in that linked list 
        {
            // selectRandom(header[q], recommendations);
            // printf("print %d out of %lld users with %d common parameters\n", recommendations, header[q].ID, q);
            node* temp = header[q].next;
            while(recommendations>=0) //There are more people with same number of common parameters than there are users left to recommend
            {
                printf("%d) User ID: %lld | User name: %s\n", (11-recommendations), temp->ID, list->array_of_users[temp->ID]->name);
                recommendations--;
                temp=temp->next;
            }
            break;
        }
        else
        {
            node* temp = header[q].next;
            while(temp!=NULL)
            {
                printf("%d) User ID: %lld | User name: %s\n", (11-recommendations), temp->ID, list->array_of_users[temp->ID]->name);
                recommendations--;
                temp=temp->next;
            }
        }
    }
    printf("\n");
    if(count > 0){ //If count=0, we have recommended no friends to user
        AddMultipleFriends(list, ID, count); //Allows user to add recommended users as friends
    }
}