#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define min_no_frds 20
typedef struct data data;
typedef struct friends friends;

struct data
{
  int user_id;
  data *next;
};

struct friends
{
  int capacity;
  int num_added;
  data self;
  data *friend[];
};

void add(long long int user_id, friends **S);

int hash(int user_id, int n)
{
  return user_id % n;
}

data *createdata()
{
  data *createdata = (data *)malloc(sizeof(struct data));
  createdata->user_id = 0;
  createdata->next = NULL;
  return createdata;
}

friends *vector(data oftheperson)
{
  friends *person = (friends *)malloc(sizeof(friends *) + sizeof(data[min_no_frds]));
  if (person == NULL)
  {
    printf("Couldn't allocate memory");
    exit(1);
  }
  else
  {
    person->self.user_id = oftheperson.user_id; //whatever the data is :)
    person->self.next = NULL;
    person->num_added = 0;
    person->capacity = min_no_frds;
    for (int i = 0; i <= min_no_frds; i++)
    {
      person->friend[i] = createdata();
    }
    //will also allocate all elems of friend user id to zero
    return person;
  }
}
void reallocall(friends **Q)
{
  friends *temp = *Q;
  *Q = (friends *)malloc(sizeof(friends *) + sizeof(data [min_no_frds+temp->capacity]));;
  (*Q)->self.user_id = temp->self.user_id; //whatever the data is :)
    (*Q)->self.next = NULL;
    (*Q)->num_added = 0;
    (*Q)->capacity = min_no_frds+temp->capacity;
    for (int i = 0; i < (*Q)->capacity; i++)
    {
      (*Q)->friend[i] = createdata();
    }
  for (int i = 0; i < temp->capacity; i++)
  {
    while (temp->friend[i] -> next != NULL)
    {
      add(temp->friend[i] -> next -> user_id, Q);
      temp->friend[i] -> next = temp->friend[i] -> next -> next;
    }
  }
  free(temp);
}



int checkfriendshipstatus(friends *S, long long int check_id)
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




int isEmpty(friends *S)
{
  if (S->num_added == 0)
  {
    return 1;
  }
  else
    return 0;
}

int vectortotal(friends *S)
{
  return S->num_added;
}

void add(long long int user_id, friends **S)
{
  if(checkfriendshipstatus((*S),user_id==0)
  {
    (*S)->num_added++;
    if ((*S)->num_added % ((*S)->capacity) != 0)
    {
      long long int p = hash(user_id, (*S)->capacity);
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
    else
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
  }
}

void removeval(int check_id,friends* Q)
{
  long long int p=hash(check_id, Q->capacity);
  while(Q->friend[p]->next!=NULL)
  {
    if(Q->friend[p]->next->user_id==check_id)
    {
      data* P=createdata();
      P=Q->friend[p]->next;
      Q->friend[p]->next=Q->friend[p]->next->next;
      free(P);
      break;
    }
    Q->friend[p]->next=Q->friend[p]->next->next;
  }
  Q->num_added--;
}


void removeall(friends *Q)
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
  Q->num_added=0;
}


