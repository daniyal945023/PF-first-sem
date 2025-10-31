#include <stdio.h>



int top = -1;


void push(int stack[], int value, int maxSize)
{
    if (top >= maxSize - 1)
    {
        printf("stack is full\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop(int stack[]){
    if(top == -1){
        printf("Stack is empty\n");
    } else {
    stack[top] = 0;
    top--; 
    }
}

void peek(int stack[]){
     if (top == -1) {
        printf("Stack is empty. Nothing to peek.\n");
    } else {
    printf("Top value of stack is %d", stack[top]);
}
}

void display(int stack[]){
    if(top == -1){
        printf("Stack empty\n");
    } else {
      for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
      }
    }
}


   


int main()
{

    int maxSize;
    printf("Enter maximum stack size: ");
    scanf("%d", &maxSize);
    int stack[maxSize];
    int choice, value;

    do{
    printf("Stack Menu:\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");
    
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter value to push: ");
        scanf("%d", &value);
        push(stack, value, maxSize);
        break;

    case 2:
        pop(stack);
        break;

    case 3:
        peek(stack);
        break;

    case 4:
        display(stack);
        break;

    case 5:
         printf("Program terminated\n");
        break;
    }
    } while(choice != 5);
    return 0;
}