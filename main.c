#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "linkedList/LinkedList.h"
#include "queue/queue.h"
#include "stack/stack.h"
#define MAX_SIZE 100
#define TRUE     1
#define FALSE    0

char buffer[MAX_SIZE];
uint8_t balanced = TRUE; 
uint16_t oprands[MAX_SIZE];
uint8_t oprations[MAX_SIZE];

void getExpression(uint8_t indx,uint8_t * oprationsIndx , uint8_t* oprandsIndx)
{
    uint8_t number = ZERO;
    static uint8_t oprandsNum = ZERO;
    static uint8_t oprationCounter = ZERO;

    if(isdigit(buffer[indx]))
    {
        while(isdigit(buffer[indx]))
        {
            number = number * 10 + (buffer[indx] - '0');
            indx++;
        }
        indx--;/*will incremnet it in the checkBalance function*/
        oprands[oprandsNum] = number;
        oprandsNum++;
    }
    else if(buffer[indx] == '*' || buffer[indx] == '-' || buffer[indx] == '+' || buffer[indx] == '/' )
    {
        oprations[oprationCounter] = buffer[indx];
        oprationCounter++;
    }
    oprandsIndx = &oprandsNum;
    oprationsIndx = &oprationCounter;
}

uint8_t balanced_parentheses_Application()
{
    queueController * oprandsQueue = createQueue();
    queueController * oprationsQueue = createQueue();

    int i = ZERO;
    uint8_t oprationsCouter;
    uint8_t oprandsNum;
   fgets(buffer,MAX_SIZE,stdin);
   
   /*
   *    remove end of line caharcter if exist
   */
   while(buffer[i] != '\n')i++;
   buffer[i] = 0;

   //create stack and start check 
    stackController * stack =  createStack();
    i = ZERO;
    uint8_t data;
    while(buffer[i] && balanced)
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
            if(stack->size == 0) balanced = FALSE;
            else{
                top(stack,&data);
                if((buffer[i] == ')' && data != '(') ||
                (buffer[i] == ']' && data != '[')  ||
                (buffer[i] == '}' && data != '{') )
                {
                    balanced = FALSE;
                }
                else 
                {
                pop(stack,&data);
                }
            }
        break;
        default: ;
            /*not a pratacess*/
            getExpression(i,&oprandsNum,&oprationsCouter);
        break;
        }
        i++;
    }

    if(stack->size > 0 || !balanced || buffer[i] != ZERO)
        balanced = FALSE;
    
    if(!balanced) printf("UNBALANCE\n");
    else
    {
        printf("BALANCE\n");

        /*calculate the expression*/
        int oprandsIndx = 0,oprationIndx = 0;
        int accumlator = oprands[oprandsIndx];
        oprandsIndx++;
        while(oprandsIndx <= oprandsNum)
        {
            switch (oprations[oprationIndx])
            {
            case '+':
                accumlator+=oprands[oprandsIndx];
            break;

            case '-':
                accumlator-=oprands[oprandsIndx];
            break;
            case '/':
                accumlator/=oprands[oprandsIndx];
            break;

            case '*':
                accumlator*=oprands[oprandsIndx];
            break;
            }
            oprandsIndx++;
            oprationIndx++;
        }
        printf("%d\n",accumlator);
    } 
}

void testFun()
{
    vector * v  = vectorInit(5,"1");
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
    int i = 0 ,j = 0 , k = 0 ; 
    while(oprands[j] || oprations[k])
    {
      printf(" %d ",oprands[j++]);
      printf("%c ",oprations[k++]);
      printf("%d ",oprands[j++]);
      i++;
    }
    return 0;
}
