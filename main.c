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
#define BASE_TEN 10
#define ZERO_ASSCI '0'

/**
 * main application
 * balanced_parentheses_Application()-->function that 
 * 1-use stack to check for matched prantacess
 * 2-use 2 arrays to evaluate expression
 * --the function call getExpression() internally to evaluate the expression givin
 * 
 * testFun()--> function to test queue stack and linked list
 */


/*
*   buffer to hold the input data
*   oprands array to hold input oprads 
*   oprations array to hold the oprations needed to be carried
*/

char buffer[MAX_SIZE];
uint16_t oprands[MAX_SIZE];
uint8_t oprations[MAX_SIZE];

/*variable used to check for balance prantacess*/
uint8_t balanced = TRUE; 



/**
 * Description: function get expression to be evaluated and push it into two array [oprations,oprands]
 * @param indx: index to the buffer array to get the current character
 * @param oprationsIndx: current opration indx in the opration array
 * @param oprandsIndx: current oprands indx in the oprands array
 */
void getExpression(uint8_t indx,uint8_t * oprationsIndx , uint8_t* oprandsIndx)
{
    uint8_t number = ZERO;
    static uint8_t oprandsNum = ZERO;
    static uint8_t oprationCounter = ZERO;

    if(isdigit(buffer[indx]))
    {
        while(isdigit(buffer[indx]))
        {
            number = number * BASE_TEN + (buffer[indx] - ZERO_ASSCI);
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

/**
 * Description: function take expression from user vrify that it has balanced prantacess 
 * and evaluate it's value  
 * @param void
 */
void balanced_parentheses_Application()
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
        printf("expression resulte = %d\n",accumlator);
    } 
}
/**
 * Description: function used to test linked list, stack and queue with various test cases and 
 * logging to the terminal for debugging.
 * @param void:
 */
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
    /*
    *   uncomment to use testFun function to test stack, queue and linked list
    */

    balanced_parentheses_Application();
    //testFun();
    return 0;
}
