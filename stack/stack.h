#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define MALLOC_ERROR  -1
#define ONE_NODE       1
#define ZERO 0
#define SUCESS         1
#define ENd_Of_STACK  -1

typedef struct ST_stackInfo
{
vector * sp;
int size;
vector *linkedListHead;
}stackController;


stackController * createStack(uint8_t* data);
void push(stackController *Controller, uint8_t* data);
uint8_t pop(stackController *Controller, uint8_t* data);

#endif // STACK_H_INCLUDED
