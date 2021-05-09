#ifndef __REG_H
#define __REG_H
#include"priorityQueue.h"
#include"user.h"
//long MASTER =0;                        
// MASTER KEEPING TRAK OF THE MAX ID ALLOCATED
 


unsigned int idAllocation(struct minHeap* heap); //allocate the least available unique id to the user.....
user* TakeInput(struct minHeap *heap);           //taking the input incase of the user registers....
void userDetails(user_list* list,long long int id);             //prints the details of the user....
void lowercase(char* A);                          //to change the string from any case to the lower case.  

//refer user.h for struct user_profile while is typedef as user....

#endif
