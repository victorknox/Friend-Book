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
    unsigned short int cfrating;
    char* organization;

    list followers;
    list following;
}user;

#endif