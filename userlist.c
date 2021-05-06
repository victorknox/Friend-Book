#include <stdio.h>
#include <stdlib.h>
#define ll long long

#ifndef __USER_H
#define __USER_H

typedef struct adjacency_list
{
    int ID[1000];   //Placeholder
                    //This has to be done using vectors and hashtables 
}list;

typedef struct user_profile
{
    unsigned int ID;
    char* name;
    char gender; //m for male, f for female, o for other, etc.
    unsigned short int age;
    char* city;
    char* country;
    char* hobby; //Contains only 1 hobby (User's favourite hobby)
    char* organization;

    list followers;
    list following;
}user;

#endif

// an array of pointers, each pointer points to a user
typedef struct user_list{
    long long largest_user_ID;
    long long capacity;
    user** array_of_users;
} user_list;

// function to resize array of users
void resize_user_array(user_list* P){
    ll cap = P->capacity;
    printf("\n%lld\n" , P->capacity);
    if(P->capacity - P->largest_user_ID <= 10){
        P->capacity *= 100;

        P->array_of_users = (user**)realloc(P->array_of_users, sizeof(user*)* P->capacity);
    }

}

user_list* create_user_list(){
    user_list* P = (user_list*)malloc(sizeof(user_list));

    P->capacity = 15;
    P->largest_user_ID = 0;
    P->array_of_users = (user**)malloc(sizeof(user*)* P->capacity);

    return P;
}


int main(void){

    user_list* list = create_user_list();

    for(int i = 0; i < 15; i++){
        list->array_of_users[i] = (user*)malloc(sizeof(user));
        list->largest_user_ID++;
        resize_user_array(list);
    }

    return 0;
}


