#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "stack.h"
#include "queue.h"

#define MAX_SIZE 100
int main()
{
    vector         * v  = vectorInit(5,"1");
    //gstr_stackController * st = createStack();
    addNode(v,"150");
    addNode(v,"15");
    addNode(v,"200");
    deleteNode(v,6);
    int pos = find(v,"15");
    if(pos != -1)
    printf("found it at %d\n" ,pos );
    print(v);
    stackController * stack = createStack("5");

    uint8_t x[100];
        printf("-------------------\n");

    push(stack,"6");
    push(stack,"7");
    print(stack->linkedListHead);
    pop(stack,x);
    printf("%s\n",x);
    pop(stack,x);
    printf("%s\n",x);
     pop(stack,x);
    printf("%s\n",x);
    pop(stack,x);
    printf("%s\n",x);
    push(stack,"10");
    pop(stack,x);
    printf("%s\n",x);
    pop(stack,x);
    printf("%s\n",x);
    printf("-------------------\n");
    queueController * queue = createQueue("10");
    enqueue(queue,"9");
    print(queue->linkedListHead);
    dequeue(queue,x);
    printf("%s\n",x);
    enqueue(queue,"9");
    dequeue(queue,x);
    printf("%s\n",x);
    print(queue->linkedListHead);
    dequeue(queue,x);
    printf("%s\n",x); 
    print(queue->linkedListHead);

    free(v);    return 0;
}
