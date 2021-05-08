#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define min_no_antfrds 23 //The minimum number of antifriends
typedef struct data data;
typedef struct antifriends antifriends;

struct data //It is the form in which the data of the person or his friends/antifriends will be stored
{
      int user_id; //It has the user id of a friend/antifriend or the person itself
      data *next;  //It points to the next friend/antifriend as we are using seperate chaining in the hash table
};

struct antifriends //It is for the antifriends of a person
{
      int capacity;       //It stores the current capacity of the antifriends it can store
      int num_added;      //It stores the data of number of antifriends added
      data self;          //It stores the data of self of a person
      data *antifriend[]; //It is a flexible array to store the number of antifriends as in the capacity
};

int hash(int user_id, int n) //It is the hash function of the hashtable
{
      return user_id % n;
}

void add1(long long int user_id, antifriends **S);

data *createdata() //It allocates the required data and points it's next to NULL and returns the pointer to data.
{
      data *createdata = (data *)malloc(sizeof(struct data));
      if (createdata == NULL)
      {
            printf("Error!! Couldn't allocate the sufficient memory\n");
            exit(1);
      }

      createdata->user_id = 0; //The user id is initialised to zero
      createdata->next = NULL;
      return createdata;
}

antifriends *vector1(data oftheperson) //It creates the data to allocate the antifriends of the person by taking the user id of the person through data
{
      antifriends *person = (antifriends *)malloc(sizeof(antifriends *) + sizeof(data[min_no_antfrds])); //Implementation of flexible arrays which is further needed in realloc also
      if (person == NULL)
      {
            printf("Error!! Memory couldn't be allocated\n");
            exit(1);
      }
      else
      {
            person->self.user_id = oftheperson.user_id; //Allocates the user id of the person
            person->self.next = NULL;                   //The next of the person points to NULL
            person->num_added = 0;                      //The number of persons added initially is zero
            person->capacity = min_no_antfrds;          //Initial capacity is initialised to minimum number of antifriends
            for (int i = 0; i <= min_no_antfrds; i++)
            {
                  person->antifriend[i] = createdata();
            }
            //will also allocate all elems of antifriend user id to zero and next pointer to NULL
            return person;
      }
}

void reallocall1(antifriends **Q) //Reallocates all the data manually once the number of antifriends added becomes equal to the capacity
{
      antifriends *temp = *Q;
      *Q = (antifriends *)malloc(sizeof(antifriends *) + sizeof(data[min_no_antfrds + temp->capacity])); //Flexible array thus finds it's use because we can reallocate it to any capacity
      if (*Q == NULL)
      {
            printf("Error!! Couldn't allocate more memory\n");
            exit(1);
      }
      (*Q)->self.user_id = temp->self.user_id; //It reallocates the data of the person and initialises the number added and capacity to 0 and new capacity
      (*Q)->self.next = NULL;
      (*Q)->num_added = 0;
      (*Q)->capacity = min_no_antfrds + temp->capacity;
      for (int i = 0; i < (*Q)->capacity; i++)
      {
            (*Q)->antifriend[i] = createdata();
      }
      for (int i = 0; i < temp->capacity; i++) //It reallocates all the antifriends of the person using the add1 function
      {
            while (temp->antifriend[i]->next != NULL)
            {
                  add1(temp->antifriend[i]->next->user_id, Q);
                  temp->antifriend[i]->next = temp->antifriend[i]->next->next;
            }
      }
      free(temp);
}

int isEmpty1(antifriends *S) //Checks whether the person has any antifriends at all
{
      if (S->num_added == 0)
      {
            return 1;
      }
      else
            return 0;
}

int vectortotal1(antifriends *S) //It gives total number of antifriends added
{
      return S->num_added;
}

int checkantifriendshipstatus(antifriends *S, long long int check_id) //Checks the antifriendship status given the user id and the person for which we have to check
{
      long long int p = hash(check_id, S->capacity);
      if (S->antifriend[p]->next == NULL)
            return 0;
      if (S->antifriend[p]->next->user_id != 0)
      {
            if (S->antifriend[p]->next->user_id == check_id)
                  return 1;
            else
            {
                  data *P = S->antifriend[p]->next->next;
                  while (P != NULL)
                  {
                        if (P->user_id == check_id)
                              return 1;
                        else
                        {
                              P = P->next;
                        }
                  }
            }
      }
      return 0;
}

void add1(long long int user_id, antifriends **S) //It is the add function to add an antifriend
{
      if (checkantifriendshipstatus(*S, user_id) == 1) // Since we dont want to add the same person twice
            return;
      if (((*S)->num_added + 1) % ((*S)->capacity) != 0) //checking if we have to reallocate. It reallocates after it reaches the capacity
      {
            long long int p = hash(user_id, (*S)->capacity); //Creating the hash function
            if ((*S)->antifriend[p]->next == NULL)
            {
                  (*S)->antifriend[p]->next = createdata();
                  (*S)->antifriend[p]->next->user_id = user_id;
            }
            else
            {
                  data *Q = (*S)->antifriend[p]->next;
                  while (Q->next != NULL)
                  {
                        Q = Q->next;
                  }
                  Q->next = createdata();
                  Q->next->user_id = user_id;
            }
      }
      else //Incase it has to realloc
      {
            reallocall1(S);
            long long int p = hash(user_id, (*S)->capacity);
            if ((*S)->antifriend[p]->next == NULL)
            {
                  (*S)->antifriend[p]->next = createdata();
                  (*S)->antifriend[p]->next->user_id = user_id;
            }
            else
            {
                  data *q = (*S)->antifriend[p]->next;
                  while (q->next != NULL)
                  {
                        q = q->next;
                  }
                  q->next = createdata();
                  q->next->user_id = user_id;
            }
      }
      (*S)->num_added++; //Since a user_id has been added it increments the number added
}

void removeval1(int check_id, antifriends *Q) //Removes a particular user id given the person from which it has to be deleted and the user id
{
      int m = 0;
      long long int p = hash(check_id, Q->capacity);
      while (Q->antifriend[p]->next != NULL) //Checks for the particular user id and 'm' indicates if such value is there or not
      {
            if (Q->antifriend[p]->next->user_id == check_id)
            {
                  data *P = createdata();
                  P = Q->antifriend[p]->next;
                  Q->antifriend[p]->next = Q->antifriend[p]->next->next;
                  m = 1;
                  break;
            }
            Q->antifriend[p]->next = Q->antifriend[p]->next->next;
      }
      if (m == 1) //if such user id is there it decrements the number added
            Q->num_added--;
}

void removeall1(antifriends *Q) //Empties the list of all the antifriends of the person one at a time using removeval1 function
{
      for (int i = 0; i < Q->capacity; i++)
      {
            data *S = Q->antifriend[i]->next;
            while (S != NULL)
            {
                  removeval1(S->user_id, Q);
                  S = S->next;
            }
      }
      //It traverses the whole hashtable and deletes all the user id's
      Q->num_added = 0;
}
