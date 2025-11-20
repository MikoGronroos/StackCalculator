#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int addToStack(stack* stack, char* input){
  if(stack->length <= 0){
    stack->stack = malloc(2 * sizeof(struct content));
  }else{
    content* newptr= realloc(stack->stack, (1 + stack->length) * sizeof(struct content));
    stack->stack = newptr;
  }
  stack->length++;
  stack->stack[stack->length-1].content = input;
  return 0;
}

char* pop(stack* stack){
  if(stack->length <= 0){
    return NULL;
  }
  stack->length--;
  char* newContent = stack->stack[stack->length].content;
  if(stack->length <= 0){
    free(stack->stack);
  }else{
    content* newptr = realloc(stack->stack, stack->length * sizeof(struct content));
    stack->stack = newptr;
  }
  return newContent;
}

stack* allocateNewStack(){
  stack *newStack;
  newStack = malloc(sizeof(stack));
  newStack->stack = malloc(sizeof(struct content));
  newStack->length = 0;
  return newStack;
}
