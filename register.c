#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "priorityQueue.h"
#include "register.h"

int MASTER =0;

unsigned long idAllocation()        //returns the least minimum id to the user....
{
    unsigned long userId;
    if (CheckIsEmpty())
    {
        userId = extractMin();
        return userId;
    }
    return ++MASTER;
}



