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
typedef struct ST_stackInfo
{
uint8_t  size;
vector * sp;
vector *linkedListHead;
}stackController;


stackController * createStack();
void push(stackController *Controller, uint8_t* data);
void pop(stackController *Controller, uint8_t* data);
void top(stackController *Controller,uint8_t* data);
#endif // STACK_H_INCLUDED
