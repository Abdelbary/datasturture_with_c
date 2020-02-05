#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "stack.h"

stackController *  createStack(uint8_t* data)
{
    /*
    *   initiate stack controller
    *   initiate stack linked list
    *   make first stacked iteam 
    *   make sp point to the stack top
    *   intiate stack size to 1
    *   return stackController
    */
    stackController * stack = (stackController *) malloc(sizeof(stackController));
    stack->linkedListHead =  vectorInit(ONE_NODE,ZERO);
    addNode(stack->linkedListHead,data);
    stack->sp = stack->linkedListHead->next_node;
    stack->size = ONE_NODE;
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

uint8_t pop(stackController *Controller,
 uint8_t* data)
{  
    /*
    *   if stack size is 0 return stack is empty
    *   else load sp data to function data 
    *   delete its node from stack
    *   move sp down
    */
    int returnValue = SUCESS ; 
    if(Controller->size == 0)
    {
        fprintf(stderr,"deletNode function ERROR  <STACK IS EMPTY>\n");
        returnValue = ENd_Of_STACK;
        *data = 0;
    }
    else
    {
    strcpy(data,(Controller->sp->data));
    //printf("%s\n",(Controller->sp->data));

    Controller->sp = Controller->sp->prev_node;
    deleteNode(Controller->linkedListHead,Controller->size);
    (Controller->size)--;

    }
    

    return returnValue;
}