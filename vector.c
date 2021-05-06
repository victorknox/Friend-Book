#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define min_no_frds 23         //The minimum number of friends
typedef struct data data;
typedef struct friends friends;

struct data    //It is the form in which the data of the person or his friends will be stored
{
  int user_id;       //It has the user id of a friend or the person itself
  data *next;        //It points to the next friend as we are using seperate chaining in the hash table
};

struct friends                //It is for the friends of a person
{
  int capacity;               //It stores the current capacity of the friends it can store
  int num_added;              //It stores the data of number of friends added
  data self;                  //It stores the data of self of a person
  data *friend[];             //It is a flexible array to store the number of friends as in the capacity
};

void add(long long int user_id, friends **S);

int hash(int user_id, int n)      //It is the hash function of the hashtable
{
  return user_id % n;
}

data *createdata()            //It allocates the required data and points it's next to NULL and returns the pointer to data.
{
  data *createdata = (data *)malloc(sizeof(struct data));
  if (createdata==NULL)
  {
    printf("Error!! Couldn't allocate the sufficient memory\n");
    exit(1);
  }
  
  createdata->user_id = 0;      //The user id is initialised to zero
  createdata->next = NULL;
  return createdata;
}

friends *vector(data oftheperson)     //It creates the data to allocate the friends of the person by taking the user id of the person through data
{
  friends *person = (friends *)malloc(sizeof(friends *) + sizeof(data[min_no_frds]));     //Implementation of flexible arrays which is further needed in realloc also
  if (person == NULL)
  {
    printf("Error!! Memory couldn't be allocated\n");
    exit(1);
  }
  else
  {
    person->self.user_id = oftheperson.user_id;       //Allocates the user id of the person
    person->self.next = NULL;                         //The next of the person points to NULL
    person->num_added = 0;                            //The number of persons added initially is zero
    person->capacity = min_no_frds;                   //Initial capacity is initialised to minimum number of friends
    for (int i = 0; i <= min_no_frds; i++)
    {
      person->friend[i] = createdata();
    }
    //will also allocate all elems of friend user id to zero and next pointer to NULL
    return person;
  }
}
void reallocall(friends **Q)                            //Reallocates all the data manually once the number of friends added becomes equal to the capacity
{
  friends *temp = *Q;
  *Q = (friends *)malloc(sizeof(friends *) + sizeof(data [min_no_frds+temp->capacity]));      //Flexible array thus finds it's use because we can reallocate it to any capacity
  if(*Q==NULL)
  {
    printf("Error!! Couldn't allocate more memory\n");
    exit(1);
  }
    (*Q)->self.user_id = temp->self.user_id;            //It reallocates the data of the person and initialises the number added and capacity to 0 and new capacity
    (*Q)->self.next = NULL;
    (*Q)->num_added = 0;
    (*Q)->capacity = min_no_frds+temp->capacity;
    for (int i = 0; i < (*Q)->capacity; i++)
    {
      (*Q)->friend[i] = createdata();
    }
  for (int i = 0; i < temp->capacity; i++)              //It reallocates all the friends of the person using the add function
  {
    while (temp->friend[i] -> next != NULL)
    {
      add(temp->friend[i] -> next -> user_id, Q);
      temp->friend[i] -> next = temp->friend[i] -> next -> next;
    }
  }
  free(temp);
}



int checkfriendshipstatus(friends *S, long long int check_id)       //Checks the friendship status given the user id and the person for which we have to check
{
  long long int p = hash(check_id, S->capacity);
  if(S->friend[p]->next==NULL)
  return 0;
  if (S->friend[p]->next->user_id != 0)
  {
    if (S->friend[p]->next->user_id == check_id)
      return 1;
    else
    {
      data *P = S->friend[p]->next->next;
      while (P!= NULL)
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




int isEmpty(friends *S)           //Checks whether the person has any friends at all
{
  if (S->num_added == 0)
  {
    return 1;
  }
  else
    return 0;
}

int vectortotal(friends *S)         //It is the total number of friends added
{
  return S->num_added;
}

void add(long long int user_id, friends **S)      //It is the add function to add a friend
{
  if(checkfriendshipstatus(*S,user_id)==1)        // Since we dont want to add twice
  return;
    if (((*S)->num_added+1) % ((*S)->capacity) != 0)    //checking if we have to reallocate. It reallocates after it reaches the capacity
    {
      long long int p = hash(user_id, (*S)->capacity);      //Creating the hash function
      if ((*S)->friend[p] -> next == NULL)
      {
        (*S)->friend[p] -> next = createdata();
        (*S)->friend[p] -> next -> user_id = user_id;
     }
      else
      { 
        data *Q = (*S)->friend[p] -> next;
        while (Q->next != NULL)
        {
          Q = Q->next;
        }
        Q->next = createdata();
        Q->next->user_id = user_id;
      }
    }
    else                                              //Incase it has to realloc
    {
      reallocall(S);
      long long int p = hash(user_id, (*S)->capacity);
      if ((*S)->friend[p] -> next == NULL)
      {
        (*S)->friend[p] -> next = createdata();
        (*S)->friend[p] -> next -> user_id = user_id;
      }
      else
      {
        data *q = (*S)->friend[p] -> next;
        while (q->next != NULL)
        {
          q = q->next;
        }
        q->next = createdata();
        q->next->user_id = user_id;
      }
    }
    (*S)->num_added++;
}

void removeval(int check_id,friends* Q)         //Removes a particular user id given the person from which it has to be deleted and the user id
{
    int m=0;
  long long int p=hash(check_id, Q->capacity);
  while(Q->friend[p]->next!=NULL)
  {
    if(Q->friend[p]->next->user_id==check_id)
    {
      data* P=createdata();
      P=Q->friend[p]->next;
      Q->friend[p]->next=Q->friend[p]->next->next;
      //free(P);
      m=1;
      break;
    }
    Q->friend[p]->next=Q->friend[p]->next->next;
  }
  if(m==1)
  Q->num_added--;
}


void removeall(friends *Q)                  //Empties the list of all the friends of the person
{
  for (int i = 0; i < Q->capacity; i++)
  {
    data *S = Q->friend[i]->next;
    while (S != NULL)
    {
      removeval(S->user_id, Q);
      S = S->next;
    }
  }
  //It traverses the whole hashtable and deletes all the user id's
  Q->num_added=0;
}


void printall(friends *Q)     //prints all the friends of the person
{
  for (int i = 0; i < Q->capacity; i++)     //traverses the whole hash table
  {
    data *S = Q->friend[i]->next;
    while (S != NULL)
    {
      printf("%d\n",S->user_id);
      S = S->next;
    }
  } 
}





