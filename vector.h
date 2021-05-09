#ifndef __VECTOR_H
#define __VECTOR_H

typedef struct data data;
typedef struct friends friends;

struct data
{
  long long int user_id;
  data *next;
};


struct friends
{
  long long int capacity;
  long long int num_added;
  data self;
  data *friend[];
};


void add(long long int user_id, friends **S);
long long int hash(long long int user_id, long long int n);
data *createdata();
friends *vector(data oftheperson);
void reallocall(friends **Q);
int checkfriendshipstatus(friends *S, long long int check_id);
int isEmpty(friends *S);
long long int vectortotal(friends *S);
void removeval(long long int check_id,friends* Q);
void removeall(friends *Q);



#endif
