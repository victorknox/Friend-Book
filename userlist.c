#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#define ll long long

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

