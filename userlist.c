#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#define ll long long

extern int MASTER; //This is the largest user ID allocated;

// function to resize array of users
void resize_user_array(user_list* P){
    ll cap = P->capacity;
    if(P->capacity - MASTER <= 10){
        P->capacity *= 10;

        P->array_of_users = (user**)realloc(P->array_of_users, sizeof(user*)* P->capacity);
    }
}

user_list* create_user_list(){
    user_list* P = (user_list*)malloc(sizeof(user_list));

    P->capacity = 15;
    P->array_of_users = (user**)malloc(sizeof(user*)* P->capacity);

    return P;
}


