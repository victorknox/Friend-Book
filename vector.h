#ifndef __VECTOR_H
#define __VECTOR_H

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
int hash(int user_id, int n);
data *createdata();
friends *vector(data oftheperson);
void reallocall(friends **Q);
int checkfriendshipstatus(friends *S, long long int check_id);
int isEmpty(friends *S);
int vectortotal(friends *S);
void removeval(int check_id,friends* Q);
void removeall(friends *Q);



#endif
