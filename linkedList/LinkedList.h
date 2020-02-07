#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
/**
 * this module implemting a doublly linked list module
 * ***/


/*
* linked list node structure as base to the linkedlist
*/
typedef struct LinkedListNode{
    uint8_t *data;
    struct LinkedListNode *next_node;
    struct LinkedListNode *prev_node;
}vector;


/**
 * Description: create a space for linked list in heap with the required node number
 * and initial value 
 * 
 * @param port: size as an uint8_t to hold the number of initail nodes to be created
 * @param port: array of values to be initalized in linked list nodes as an initial value
 */
vector * vectorInit(uint8_t size, uint8_t init_value[]);


/**
 * Description: print linked list nodes in thier order
 * @param head: a pointer to vector struct which points to linked list head
 */
uint8_t print(vector * head);


/**
 * Description: add additional node at  the  end of linked list 
 * 
 * @param head: a pointer to vector struct which points to linked list head
 * 
 * @param data: a pointer to the data to be added to the linked list 
 */
vector * addNode(vector *v,uint8_t *data);


/**
 * Description: find the first occaurance of a node in the linked list with specific value
 * 
 * @param v: a pointer to vector struct which points to linked list head
 * 
 * @param value: a pointer to the data to be added to the linked list 
 */
int find(vector * v, uint8_t* value);


/**
 * Description: delete node from linked list with specifice position
 * 
 * @param v: a pointer to vector struct which points to linked list head
 * 
 * @param pos : positon of the node to be deleted 
 */
int deleteNode(vector * v,int pos);


#endif // LINKEDLIST_H_INCLUDED
