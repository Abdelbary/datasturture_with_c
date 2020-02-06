#include <stdio.h>
#include <stdlib.h>
#include "linkedList/LinkedList.h"
#include "queue/queue.h"
#include "stack/stack.h"
#define MAX_SIZE 100
#define TRUE     1
#define FALSE    0

char buffer[MAX_SIZE];

uint8_t balanced_parentheses_Application()
{
    uint8_t balanced = TRUE; 
   fgets(buffer,MAX_SIZE,stdin);
   
   /*
   *    remove end of line caharcter if exist
   */
   int i = ZERO;
   while(buffer[i] != '\n')i++;
   buffer[i] = 0;

   //create stack and start check 
   stackController * stack =  createStack();

   i = ZERO;
    uint8_t data;
    while(buffer[i])
    {
        switch (buffer[i])
        {
        case '{':
        case '[':
        case '(':
            push(stack,&buffer[i]);    
        break;
        case '}':
        case ']':
        case ')':
            data = top(stack);
            if(data == buffer[i])
        break;
        default:
            break;
        }
    }
}

void testFun()
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
    stackController * stack = createStack();

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

    free(v);  
}
int main()
{
    balanced_parentheses_Application();
    return 0;
}
