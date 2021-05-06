#ifndef __AFLIST_H
#define __AFLIST_H

typedef struct data data;
typedef struct antifriends antifriends;

struct data
{
      int user_id;
      data *next;
};

struct antifriends
{
      int capacity;
      int num_added;
      data self;
      data *antifriend[];
};

void add(long long int user_id, antifriends **S);
int hash(int user_id, int n);
data *createdata();
antifriends *vector(data oftheperson);
void reallocall1(antifriends **Q);
int checkantifriendshipstatus(antifriends *S, long long int check_id);
int isEmpty1(antifriends *S);
int vectortotal1(antifriends *S);
void removeval1(int check_id, antifriends *Q);
void removeall1(antifriends *Q);

#endif