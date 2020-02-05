#include "LinkedList.h"

vector * vectorInit(uint8_t size, uint8_t init_value[])
{

    ///create first node (head)
    vector *head = (vector *)malloc(sizeof(vector));
    head->data = init_value; ///initial value
    ///create a pointer to current node
    vector *current = head;
    /*while there still node to create
      1)create new node
      2)make current node next pointer point to it
      3)change current pointer to point to it
     */

    while(--size){
        ///create new node
        vector * node = (vector *)malloc(sizeof(vector));

        ///check for any errors
        if(node ==NULL){
            fprintf(stderr,"not enough memory\n");
            return NULL;
        }

        ///apply node to linked list

        ///set data
        node->data = init_value;

        ///link generated node to linked list
        current->next_node = node;
        node->prev_node = current;

        ///change current pointer to point to lastn node
        current = current->next_node;
    }
    ///link last node to the head
    current->next_node = head;


    ///make first node point to the last
    head->prev_node = current;
    ///return linked list head
    return head;
}

uint8_t print(vector * head){
    ///check for invalid parameters
    if(head == NULL){
        fprintf(stderr,"print function invalid input <passing a null pointer as first parameter>\n");
        return -1;
    }


    ///create a copy of vector to process int
    vector * current = head;

    ///init loop counter and loop throw the vector
    int index = 0;
    do{
        printf("value of %d is %s \n",index,current->data);
        ///move current pointer to last created node
        current = current->next_node;
        ///increase counter
        ++index;
    }while(current != head);


}

vector * addNode(vector *v,uint8_t *data)
{

  ///check for invalid parameters
    if(v == NULL){
        fprintf(stderr,"addNode function invalid input <passing a null pointer as first parameter>\n");
    }

    ///copy vector pointer
    vector * head = v;
    vector * tail = v->prev_node;
    ///create new node
    vector * node = (vector *)malloc(sizeof(vector));
    if(node == NULL){
            fprintf(stderr,"out of memory \n");
            return NULL;
    }
    ///set node data
    node->data = data;
    ///link node to tail
    tail->next_node = node;
    node->prev_node = tail;
    ///link node to head
    node->next_node = head;
    head->prev_node = node;

    return node;
}




int find(vector * v, uint8_t* value){
    ///check for invalid parameters
    if(v == NULL){
        fprintf(stderr,"find function invalid input <passing a null pointer as first parameter>\n");
        return -1;
    }

    vector *head =v;
    ///using do while to escape the first node at the first iteration then check on it in while condition
    int index = 0 ;
    do{
        if(strcmp(value,v->data) == 0){
            return index;
        }
        v= v->next_node;
        ++index;
    }while(v != head);

    return -1;
}



int deleteNode(vector * v,int pos){
    ///check for invalid parameters
    if(v == NULL){
        fprintf(stderr,"deletNode function invalid input <passing a null pointer as first parameter>\n");
        return -1;
    }
    if(pos < 0){
        fprintf(stderr,"deletNode function invalid input <passing a negative position>\n");
        return -1 ;
    }
    ///create a temp pointer
    vector *current =v;

    int index = 0 ;
    do{
        ///check if we found our position
        if(pos == index){
            ///resolve links
            current->prev_node->next_node = current->next_node;
            current->next_node->prev_node = current->prev_node;
            ///free node space
            free(current);
            return 1;
        }
        ///move to the next node and increment the pointer
        current = current->next_node;
        ++index;
        ///check if we reached the end of the list
    }while(current != v);

    return -1;
}



