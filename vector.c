#include <stdio.h>


#define min_no_frds 20
typedef struct data data;
typedef struct friends friends;


struct data
{
  user_id;
  data* next;
};

struct friends
{
  int num_added;
  data self;
  data friend[];
};


friends* vector(data *oftheperson)
{
  friends *person =malloc(sizeof(friends *)+sizeof(data [min_no_frds]));
  if(person==NULL)
  {
    printf("Couldn't allocate memory");
    exit(1);
  }
  else{
  person->self.user_id=oftheperson->user_id;//whatever the data is :)
  person->self.next=NULL;
  person->num_added = 0;
  for(int i=0;i<min_no_frds;i++)
  {
  person->friend[i].user_id=0;
  person->friend[i].next=NULL;}
  //will also allocate all elems of friend user id to zero
  return person;
  }
}
  

void reallocvector(friends *S,int numbertotal)
{
  friends *temp;
  temp=(friends *)realloc(S,sizeof(friends *)+sizeof(data [numbertotal]));
  if(temp==NULL)
  {
    printf("Couldn't allocate more memory");
    return;
  }
  else
  {
    S=temp;
  }
}


int isEmpty(friends *S)
{
  if(S->num_added==0)
  {
    return 1;
  }
  else return 0;
}


int vectortotal(friends *S)
{
  return S->num_added;
}


void remove(friends* S,long long int remove_id)
{
  long long int p= hash(remove_id,(min_no_frds)*ceil(S->num_added/min_no_frds));
  if(S->friend[p].user_id==remove_id) 
  {
    if()
  }
}

int checkfriendshipstatus(friends* S,long long int check_id)
{
  long long int p=hash(check_id,(min_no_frds)*ceil(S->num_added/min_no_frds));
  if(S->friend[p].user_id!=0)
  {
    if(S->friend[p].user_id==check_id)
    return 1;
    else
    {
      data* P=S->friend[p].next;
      while(P!=NULL)
      {
        if(P->user_id==check_id)
        return 1;
        else
        {
          P=P->next;
        }
        
      }
    }
  }
  return 0;
}


void add(long long int user_id, friends* S)
{
  if( S->num_added % min_no_frds != 0 )
  {
    S->num_added++;
    long long int p = hash(user_id,(min_no_frds)*ceil(S->num_added/min_no_frds));
    if(S->friend[p].user_id==0)
    S->friend[p].user_id = user_id ;//data of the person that will be added
    else
    {
      data *P=S->friend[p].next;
      while(P->user_id!=0)
      {
        P=P->next;
      }
      P->user_id=user_id;
      P->next=NULL;
    }
  }
  else
  {
    reallocvector(S,S->num_added+min_no_frds);
    long long int p = hash(user_id,(min_no_frds)*ceil(S->num_added/min_no_frds));
    if(S->friend[p].user_id==0)
    S->friend[p].user_id = user_id ;//data of the person that will be added
    else
    {
      data *P=S->friend[p].next;
      while(P->user_id!=0)
      {
        P=P->next;
      }
      P->user_id=user_id;
      P->next=NULL;
    }
  }
}
                             
                           
                          


  

