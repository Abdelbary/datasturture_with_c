#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "../linkedList/LinkedList.h"

#define MALLOC_ERROR  -1
#define ONE_NODE       1
#define ZERO           0
#define SUCESS         1
#define ENd_Of_QUEUE  -1

typedef struct ST_queueInfo
{
vector * front;
uint8_t size;
vector *linkedListHead;
}queueController;


queueController * createQueue(uint8_t* data);
void enqueue(queueController *Controller, uint8_t* data);
uint8_t dequeue(queueController *Controller, uint8_t* data);

#endif // QUEUE_H_INCLUDED
