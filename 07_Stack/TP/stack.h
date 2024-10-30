#ifndef STACK_H
#define STACK_H

const int MAX_SIZE = 15;

typedef char infotype;

struct stack {
    infotype info[MAX_SIZE];
    int Top; 
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype x);
infotype pop(stack &S);
void printInfo(stack S);

#endif