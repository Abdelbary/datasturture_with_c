#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
typedef struct LinkedListNode{
    uint8_t *data;
    struct LinkedListNode *next_node;
    struct LinkedListNode *prev_node;
}vector;


vector * vectorInit(uint8_t size, uint8_t init_value[]);
uint8_t print(vector * head);
vector * addNode(vector *v,uint8_t *data);
int find(vector * v, uint8_t* value);
int deleteNode(vector * v,int pos);


#endif // LINKEDLIST_H_INCLUDED
