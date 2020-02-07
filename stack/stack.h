#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define MALLOC_ERROR  -1
#define ONE_NODE       1
#define ZERO 0
#define SUCESS         1
#define ENd_Of_STACK  -1
#define QUEUE_IS_EMPTY 0
/**
 * this module implemting a stack using linked list module
 * ***/
/*
* stack controller structure used to capture info about each stack
*/
typedef struct ST_stackInfo
{
uint8_t  size;
vector * sp;
vector *linkedListHead;
}stackController;

/**
 * Description: create a space for stack in the heap using linked list 
 * and initialize it's control structure.
 * @param port: void
 */
stackController * createStack();

/**
 * Description: make new node and push value into the stack
 * @param controller: pointer to stack controller structure 
 *
 * @param data: pointer to uint8_t that hold the data to be pushed to the stack
 */
void push(stackController *Controller, uint8_t* data);

/**
 * Description: pop elment from the stack if the stack is not empty
 * @param controller: pointer to stack controller structure 
 *
 * @param data: pointer to uint8_t that hold the data poped from the stack
 */
void pop(stackController *Controller, uint8_t* data);

/**
 * Description: get value at top of stack
 * @param controller: pointer to stack controller structure 
 *
 * @param data: pointer to uint8_t that hold the data from top of the stack
 */
void top(stackController *Controller,uint8_t* data);
#endif // STACK_H_INCLUDED
