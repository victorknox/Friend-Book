#include <stdio.h>
#include"priorityQueue.h"

///////
//TEST FILE FOR PRIORITY QUEUE
//PASSED
//////

int main()
{
    struct minHeap * PriorQueue = initHeap();

    printf("%d\n",CheckIsEmpty(PriorQueue));

    InsertToHeap(PriorQueue,5);
    InsertToHeap(PriorQueue,7);
    InsertToHeap(PriorQueue,2);
    InsertToHeap(PriorQueue,9);
    InsertToHeap(PriorQueue,1);
    InsertToHeap(PriorQueue,10);

    printf("%d\n",CheckIsEmpty(PriorQueue));

    printf("The min heap elimination starts ---->\n");
    printf("%d ",extractMin(PriorQueue));
    printf("%d ",extractMin(PriorQueue));
    printf("%d ",extractMin(PriorQueue));
    printf("%d ",extractMin(PriorQueue));
    printf("%d ",extractMin(PriorQueue));
    printf("%d ",extractMin(PriorQueue));
    printf("\n");
    printf("%d\n",CheckIsEmpty(PriorQueue));
    
    return 0;

}