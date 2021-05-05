#include<stdio.h>
#include"priorityQueue.h"
#include"register.h"

///////
//TEST FILE FOR REGISTER
//PASSED
//////


int main()
{
    struct minHeap * PQueue = initHeap();
    InsertToHeap(PQueue,5);
    InsertToHeap(PQueue,10);
    InsertToHeap(PQueue,3);
    printf("The id allocated is %d .....expected 3\n",idAllocation(PQueue));
    InsertToHeap(PQueue,6);
    InsertToHeap(PQueue,15);


    printf("The emptyness of the heap is *expected 1----->*%d\n",CheckIsEmpty(PQueue));

    printf("%d ",extractMin(PQueue));
    printf("%d ",extractMin(PQueue));
    printf("%d ",extractMin(PQueue));
    printf("%d ",extractMin(PQueue));
    //printf("%li\n",extractMin());
    printf("\n");
    printf("The emptyness of the heap is *expected 0*------>%d\n",CheckIsEmpty(PQueue));

    printf("The id allocated is %d .....expected 1\n",idAllocation(PQueue));
    

}