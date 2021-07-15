#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
typedef struct stack {
    char** memory;
    int sp;
}stack;

stack* initStack();
void push(stack* st, char* slot);
char* pop(stack* st);
char* peek(stack* st);
#endif // !STACK_H