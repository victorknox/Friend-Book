#ifndef __USER_H
#define __USER_H

#include "vector.h"

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

    friends* followers;
    friends* following;
}user;

// an array of pointers, each pointer points to a user
typedef struct user_list{
    long long capacity;
    user** array_of_users;
} user_list;

#endif
