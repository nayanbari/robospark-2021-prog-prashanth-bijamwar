// Implement an optimal approach for implementing two stacks in a single array.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

// Structure for two stacks
struct TwoStacks
{
    int arr[MAX];
    int top1;
    int top2;
} ts;

// Size of Stack1
int stack1Size()
{
    return ts.top1 + 1;
}

// Size of Stack2
int stack2Size()
{
    return MAX - ts.top2;
}
// Initialise top1 and top2 here
void init()
{
    ts.top1 = -1;
    ts.top2 = MAX - 1;
}

// Write the code to push the data in Stack 1
void push1(int data)
{
    if (ts.top1 + 1 == ts.top2)
    {
        printf("\n Stack 1 Overflow");
    }
    else
    {
        ts.top1++;
        ts.arr[ts.top1] = data;
    }
}

// Write the code to push the data in Stack 2
void push2(int data)
{
    if (ts.top1 + 1 == ts.top2)
    {
        printf("\n Stack 2 Overflow");
    }
    else
    {
        ts.top2--;
        ts.arr[ts.top2] = data;
    }
}

// Write the code to pop the data from Stack 1
int pop1()
{
    if (stack1Size() == 0)
    {
        printf("\n Stack 1 Underflow");
        return 0;
    }
    else
    {
        int val = ts.arr[ts.top1];
        ts.top1--;
        return val;
    }
}

// Write the code to pop the data from Stack 2
int pop2()
{
    if (stack2Size() == 0)
    {
        printf("\n Stack 2 Underflow");
        return 0;
    }
    else
    {
        int val = ts.arr[ts.top2];
        ts.top2++;
        return val;
    }
}

// Driver Code
int main()
{

    init();

    int opt, element, poppedElement;

    while (opt != 0)
    {

        printf(">> Which option do you want to choose? \n");
        printf(" 1. Push in Stack 1 \n 2. Push in Stack 2 \n 3. Pop from Stack 1 \n 4. Pop from Stack 2 \n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf(">> Enter the element you want to push in Stack 1: \n");
            scanf("%d", &element);
            push1(element);
            break;
        case 2:
            printf(">> Enter the element you want to push in Stack 2: \n");
            scanf("%d", &element);
            push2(element);
            break;
        case 3:
            poppedElement = pop1();
            stack1Size();
            printf(">> The popped element is %d. \n", poppedElement);
            break;
        case 4:
            poppedElement = pop2();
            stack2Size();
            printf(">> The popped element is %d. \n", poppedElement);
            break;
        case 0:
            printf("[!!] Exiting");
            exit(0);
        default:
            printf("[!!] Invalid Input, Try Again");
            break;
        }
    }

    return 0;
}