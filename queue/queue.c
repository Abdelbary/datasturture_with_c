#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define  FIRST_ELEMENT 1

queueController *  createQueue(uint8_t* data)
{
    /*
    *   create initiale node [base node]
    *   create first node of queue
    *   make front point to the first node.  
    *   set queue size to 1 
    *   return queue
    */

    queueController * queue = (queueController *) malloc(sizeof(queueController));
    queue->linkedListHead =  vectorInit(ONE_NODE,ZERO);
    addNode(queue->linkedListHead,data);
    queue->front = queue->linkedListHead->next_node;
    queue->size = 1;
    return queue;
}

void enqueue(queueController *Controller, uint8_t* data)
{
    /*  add node to the list
    *   increase the size by 1
    */
    addNode(Controller->linkedListHead,data);
    (Controller->size)++;
}

uint8_t dequeue(queueController *Controller,
 uint8_t* data)
{   
    /*  check for if queue is empty 
    *   if its empty return error message
    *   else delet the selected node
    *   move front to the next node
    *   return sucess
    */
   
    int returnValue = SUCESS ; 
    if(Controller->size == 0)
    {
        fprintf(stderr,"deletNode function ERROR <QUEUE IS EMPTY>\n");
        *data = 0;
        returnValue = ENd_Of_QUEUE;
    }
    else
    {
    strcpy(data,(Controller->front->data));
    //printf("%s\n",(Controller->sp->data));

    Controller->front = Controller->front->next_node;
    
    deleteNode(Controller->linkedListHead,FIRST_ELEMENT);
    (Controller->size)--;

    }
    

    return returnValue;
}