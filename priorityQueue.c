#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "priorityQueue.h"

void MakeEmptyHeap()
{
    front_ = rear_ = -1;
}

void insert(int element)
{
    if (rear_ >= max_size - 1)
    {
        printf("---OVERFLOW---\n");
        return;
    }
    if ((front_ == -1) && (rear_ == -1))
    {
        rear_++;
        front_++;
        pQueue[rear_] = element;
    }
    else
    {
        rear_++;
        pQueue[rear_] = element;
        heapify();
    }
}

int parentIndex(int index)
{
    return (index - 1) / 2;
}
int leftChildIndex(int index)
{
    return 2 * index + 1;
}
int rightChildIndex(int index)
{
    return 2 * index + 2;
}

void swap(int a, int b)
{
    int temp = pQueue[a];
    pQueue[a] = pQueue[b];
    pQueue[b] = temp;
}

void heapify_insert()
{
    int element = pQueue[rear_], index = rear_;

    while (1)
    {
        if (element < pQueue[parentIndex(index)])
            swap(index, parentIndex(index));
        else
            return;
        index = parentIndex(index);
        if (index == 0)
            return;
    }
}

int extractMin()
{
    int min = pQueue[0];
    heapify_delete();
    return min;
}

int checkForRP(int index)
{
    if (2 * index + 1 > rear_)
        return 0;
    else
        return 1;
}

int checkForLP(int index)
{
    if (2 * index + 2 > rear_)
        return 0;
    else
        return 1;
}

void heapify_delete()
{
    int index = 0;

    pQueue[0] = pQueue[rear_];
    rear_--;

    while (1)
    {
        if (checkForLP(index) && checkForRP(index))
        {
            if (pQueue[leftChildIndex(index)] < pQueue[index] || pQueue[rightChildIndex(index)] < pQueue[index])
            {
                if (pQueue[leftChildIndex(index)] <= pQueue[rightChildIndex(index)])
                {
                    swap(index, leftChildIndex(index));
                    index = leftChildIndex(index);
                }
                else
                {
                    swap(index, rightChildIndex(index));
                    index = rightChildIndex(index);
                }
            }
            else
                return;
        }

        else if (checkForRP(index) == 0)
        {
            if (pQueue[leftChildIndex(index)] < pQueue[index])
            {
                swap(index, leftChildIndex(index));
                index = leftChildIndex(index);
            }
            else
                return;
        }

        else
            return;
    }
}
