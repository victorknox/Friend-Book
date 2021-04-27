

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


int hash(int user_id, int n) : I am implementing the hash function as mod(n); The hash function will be changed to implement horner's rule.


data *createdata(): It creates the data for storing the userid and next and returns the pointer to the data.It initialises all the userids to zero and next points to NULL.


friends *vector(data oftheperson): It creates the data to the struct friends using the min_no_of_frds as elems of array friend and returns the pointer to it.


void add(long long int user_id, friends** S): It adds the friends of the person when userid is given. If there is no collision it adds according to the hash value.
If there is a collision it uses seperate chaining. If the num_added is greater than capacity it reallocs the data and adds according to the above.



