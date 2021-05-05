The min_no_of_frds I have initialised to 20. It can be changed according to requirements. 



Struct data:

It, as of now contains the userid of a person and pointer to next friend with the same hash value. Used in seperate chaining.

As per requirements we can add different fields like name or city. It is the data of the friends of the person.

It is also initially used to add the user name of the person and the next pointer points to NULL. 


Struct friends:

It contains:
friend[] : It is a dynamically allocated 'flexible array' used to store the data of the friends using data* as the pointer to data of the friends.If any collision
           occurs I am implementing seperate chaining.
           
self     : Contains the data of the self. That is userid and the next pointer points to NULL.

capacity : It is the capacity of the friends. That is friend[0]->friend[capacity-1] will be present.

num_added: It contains the details of number of friends added till then.


**Functions:


int hash(int user_id, int n) : I am implementing the hash function as mod(n); The hash function will be changed to implement horner's rule.


data *createdata(): It creates the data for storing the userid and next and returns the pointer to the data.It initialises all the userids to zero and next points to NULL.


friends *vector(data oftheperson): It creates the data to the struct friends using the min_no_of_frds as elems of array friend and returns the pointer to it.


void add(long long int user_id, friends** S): It adds the friends of the person when userid is given. If there is no collision it adds according to the hash value.
If there is a collision it uses seperate chaining. If the num_added is greater than capacity it reallocs the data and adds according to the above.


void reallocall(friends** Q): It take pointer to the pointer to the struct friends and assigns all the data to a temporary pointer temp. Reallocates all the data in temp to Q which has been 'malloc'ed again (Realloc doesnt seem useful since the hash function changes). Now the data has been reallocated and it returns to the function add where it adds the necessary data.


int checkfriendshipstatus(friends *S, long long int check_id): It checks the friendship status of the person and a given userid. It returns '0' if not a friend and '1' if it is a friend.


int isEmpty(friends *S): Checks if there are friends to a person. If no friends ae added it returns '1' else returns '0'.


int vectortotal(friends *S): It returns the total number of friends a person has.


void removeval(int check_id,friends* Q): It removes the friend with a given id and decrements the number of friends added.



void removeall(friends *Q): It removes all friends of the person. Useful in deleting a person completely.



An example of the main function that I have used::

#include <stdio.h>
#include "vector.c"

int main()
{
    data p;
    p.user_id=2020;
    p.next=NULL;
    friends *person;
    person=vector(p);
    
    add(4041,&person);
    add(4042,&person);
    add(2021,&person);
    add(4043,&person);
    add(4047,&person);
    add(4049,&person);
    add(4051,&person);
    add(4039,&person);
    add(2026,&person);
    
    int q=checkfriendshipstatus(person,2021);
    printf("%d",q);

    removeval(4047,person);
    q=checkfriendshipstatus(person,4047);
    printf(" %d",q);
    removeval(4041,person);
    q=checkfriendshipstatus(person,4041);
    printf(" %d",q);
    removeval(4042,person);
    q=checkfriendshipstatus(person,4042);
    printf(" %d",q);
    removeval(2021,person);
    q=checkfriendshipstatus(person,2021);
    printf(" %d",q);
    removeval(4049,person);
    q=checkfriendshipstatus(person,4049);
    printf(" %d",q);
    printf(" %d",person->num_added);
    return 0;
}





