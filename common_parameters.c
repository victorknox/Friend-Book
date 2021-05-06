#include <string.h>
#include "user.h"

typedef struct pair
{
    int id;
    int common;
}pair;

int fcommon(const user* A, const user* B) //returns number of common parameters between A and B
{
    int count=0;
    if(strcmp(A->name, B->name)==0)
        count++;
    if(A->gender==B->gender)
        count++;
    if((A->age-B->age)*(A->age-B->age)<100) // |A's age - B's age| <= 10
        count++;
    if(strcmp(A->city, B->city)==0)
        count++;
    if(strcmp(A->country, B->country)==0)
        count++;
    if(strcmp(A->hobby, B->hobby)==0)
        count++;
    if((A->cfrating-B->cfrating)*(A->cfrating-B->cfrating)<250000) // |A's age - B's age| <= 500
        count++;
    if(strcmp(A->organization, B->organization)==0)
        count++;

    return count;
}

void recommend_friends(int N, const user* A, const user** userlist)
{
    // N = largest user id assigned
    pair topten[10];
    int checked=0, i=0;
    while(checked<=10 && i<N) //N = Largest index of any user
    {
        if(userlist[i]!=NULL)
        {
            topten[i].id = userlist[i]->ID;
            topten[i].common = fcommon(A, userlist[i]);
            checked++;
        }
        i++;
    }

    for(int j=i; j<N; j++)
    {
        
    }
}