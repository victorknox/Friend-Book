

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
