#include <stdio.h>
#include <stdlib.h>
#include "../linkedList/LinkedList.h"
#include "stack.h"

stackController *  createStack()
{
    /*
    *   initiate stack controller
    *   initiate stack linked list
    *   make sp point to the stack top
    *   intiate stack size to 0
    *   return stackController
    */
    stackController * stack = (stackController *) malloc(sizeof(stackController));
    stack->linkedListHead =  vectorInit(ONE_NODE,ZERO);
    stack->sp = stack->linkedListHead->next_node;
    stack->size = ZERO;
    return stack;
}

void push(stackController *Controller, uint8_t* data)
{
    /*
    *   add stackNode | load it with values
    *   move stack pointer to point to it
    *   increase stack size by 1
    */ 
    Controller->sp = addNode(Controller->linkedListHead,data);
    (Controller->size)++;
}

void pop(stackController *Controller,uint8_t* data)
{  
    /*
    *   if stack size is 0 return stack is empty
    *   else load sp data to function data 
    *   delete its node from stack
    *   move sp down
    */
    int returnValue = SUCESS ; 
    if(Controller->size == ZERO)
    {
        fprintf(stderr,"deletNode function ERROR  <STACK IS EMPTY>\n");
        returnValue = ENd_Of_STACK;
        *data = ZERO;
    }
    else
    {
    data = Controller->sp->data;
    //printf("%s\n",(Controller->sp->data));

    Controller->sp = Controller->sp->prev_node;
    deleteNode(Controller->linkedListHead,Controller->size);
    (Controller->size)--;
    }
}

void top(stackController *Controller,uint8_t* data)
{  
    /*
    *   if stack size is 0 return stack is empty
    *   else load sp data to function data 
    *   delete its node from stack
    *   move sp down
    */
    if(Controller->size == 0)
    {
        fprintf(stderr,"deletNode function ERROR  <STACK IS EMPTY>\n");
    }
        *data = *(Controller->sp->data);

}