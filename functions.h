#ifndef __FUNC_C
#define __FUNC_C

// contains function prototypes for functions called in multiple files

void resize_user_array(user_list* P);
user_list* create_user_list();

void AddSingleFriend(user_list *list);

void unregister(long long int id, user_list *userlist, struct minHeap* heap);

void recommend_old(int k, long long userID, struct minHeap *heap, user_list* list);

void recommend_new(user_list *list, long long ID);

void AddMultipleFriends(user_list *list, long long a, long long count);
#endif
