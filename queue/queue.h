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

/**
 * this module implemting a queue using linked list module
 * ***/
/*
* queue controller structure used to capture info about each queue
*/
typedef struct ST_queueInfo
{
vector * front;
uint8_t size;
vector *linkedListHead;
}queueController;


/**
 * Description: create a space for queue in the heap using linked list 
 * and initialize it's control structure.
 * @param port: void
 */
queueController * createQueue();

/**
 * Description: make new node and enqueue value to the queue
 * @param controller: pointer to queue controller structure 
 *
 * @param data: pointer to uint8_t that hold the data to be enqueued in the queue
 */
void enqueue(queueController *Controller, uint8_t* data);


/**
 * Description: dequeue elment from the queue if the queue is not empty
 * @param controller: pointer to queue controller structure 
 *
 * @param data: pointer to uint8_t that hold the data dequeued from the qeue
 */
uint8_t dequeue(queueController *Controller, uint8_t* data);


/**
 * Description: get value at front of queue
 * @param controller: pointer to queue controller structure 
 *
 * @param data: pointer to uint8_t that hold the data from front of the queue
 */
void front(queueController *Controller,uint8_t* data);

#endif // QUEUE_H_INCLUDED
