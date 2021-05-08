#ifndef __FUNC_C
#define __FUNC_C

void resize_user_array(user_list* P);
user_list* create_user_list();

void AddSingleFriend(user_list *list);

void unregister(long long int id, user_list *userlist, struct minHeap* heap);

#endif