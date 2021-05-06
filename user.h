#include "vector.h"
#include "aflist.h"

#ifndef __USER_H
#define __USER_H

typedef struct user_profile
{
      unsigned int ID;
      char *name;
      char gender; //m for male, f for female, o for other, etc.
      unsigned short int age;
      char *city;
      char *country;
      char *hobby; //Contains only 1 hobby (User's favourite hobby)
      unsigned short int cfrating;
      char *organization;

      friends *flist;
      antifriends *aflist;
} user;

#endif
