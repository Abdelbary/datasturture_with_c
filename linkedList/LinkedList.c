 #include "LinkedList.h"

LinkedList * LinkedListNodeInit(uint8_t size, uint8_t init_value[])
{

    ///create first node (head)
    LinkedList *ls = (LinkedList*)malloc(sizeof(LinkedList));
    ls->head = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    ls->head->data = init_value; ///initial value
   ///create a pointer to current node
    LinkedListNode *current = ls->head; 
    /*while there still node to create
      1)create new node
      2)make current node next pointer point to it
      3)change current pointer to point to it */
   
    while(--size){
        ///create new node
        LinkedListNode * node = (LinkedListNode *)malloc(sizeof(LinkedListNode));

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
    current->next_node = ls->head;


    ///make first node point to the last
    ls->head->prev_node = current;
    ///return linked list head
    return ls;
}

uint8_t print(LinkedList *ls){
    ///check for invalid parameters
    if(ls == NULL){
        fprintf(stderr,"print function invalid input <passing a null pointer as first parameter>\n");
        return -1;
    }


    ///create a copy of LinkedListNode to process int
    LinkedListNode *current = ls->head;
    

    ///init loop counter and loop throw the LinkedListNode
    int index = 0;
    do{
        printf("value of %d is %s \n",index,current->data);
        ///move current pointer to last created node
        current = current->next_node;
        ///increase counter
        ++index;
    }while(current != ls->head);


}

LinkedListNode * addNode( LinkedList *ls,uint8_t *data)
{

  ///check for invalid parameters
    if( ls == NULL){
        fprintf(stderr,"addNode function invalid input <passing a null pointer as first parameter>\n");
    }

    ///copy LinkedListNode pointer
     LinkedListNode * head = ls->head; 
     LinkedListNode * tail = ls->tail;
    ///create new node
     LinkedListNode * node = ( LinkedListNode *)malloc(sizeof( LinkedListNode));
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




int find( LinkedList *ls, uint8_t* value)
{
    ///using do while to escape the first node at the first iteration then check on it in while condition
    int index = 0 ;
    LinkedListNode* current = ls->head;
    do{
        if(strcmp(value,current->data) == 0){
            return index;
        }
        current= current->next_node;
        ++index;
    }while(current != ls->head);

    return -1;
}



int deleteNode(LinkedList * ls,int pos){
    ///check for invalid parameters
    if(ls == NULL){
        fprintf(stderr,"deletNode function invalid input <passing a null pointer as first parameter>\n");
        return -1;
    }
    if(pos < 0){
        fprintf(stderr,"deletNode function invalid input <passing a negative position>\n");
        return -1 ;
    }
    ///create a temp pointer
     LinkedListNode *current =ls->head;

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
    }while(current != ls->head);

    return -1;
}



