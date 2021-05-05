#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "priorityQueue.h"
#include "register.h"

////////
//**NEED TO INITIALISE THE HEAP IN THE MAIN USING THE FOLLOWING CODE**
////////
//struct minHeap * variableName = initHeap();
////////

int MASTER =0;

int idAllocation(struct minHeap* heap)        //returns the least minimum id to the user....
{
    int userId;
    if (CheckIsEmpty(heap))
    {
        userId = extractMin(heap);
        return userId;
    }
    return ++MASTER;
}



