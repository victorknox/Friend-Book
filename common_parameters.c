#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "user.h"

extern unsigned int MASTER;

typedef struct node
{
    long long ID;
    struct node *next;
} node;

void insert(node* header, int ID)
{
    node *nw = (node *)malloc(sizeof(node));
    nw->ID = ID;

    (header->ID)++;
    header->next = nw->next;
    header->next = nw;
}

int fcommon(const user *A, const user *B) //returns number of common parameters between A and B
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

// select(random)
void recommend_new(const user_list *list, long long ID)
{
    int recommendations=10;
    node header[8];
    for(int q=0; q<=7; q++)
    {
        header[q].ID=0;
        header[q].next=NULL;
    }

    for(int q=0; q<=MASTER; q++)
    {
        if(list->array_of_users[q]==NULL || q==ID)
        {
            continue;
        }
        int common = fcommon(list->array_of_users[ID], list->array_of_users[q]);
        insert(&header[common], q);
        // header[common]++;
    }

    for(int q=7; q>0 && recommendations>0; q++)
    {
        if(header[q].ID > recommendations)
        {
            // selectRandom(header[q], recommendations);
            printf("print %d out of %d users with %d common parameters\n", recommendations, header[q].ID, q);
            break;
        }
        else
        {
            node* temp = header[q].next;
            while(temp!=NULL)
            {
                printf("%d) User ID: %lld\n", (11-recommendations), temp->ID);
                recommendations--;
            }
        }
    }
}