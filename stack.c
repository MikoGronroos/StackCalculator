#include "stack.h"
#include <stdlib.h>

int addToStack(stack* stack, char* input){
  if(stack->length <= 0){
    stack->stack = malloc(sizeof(content));
  }else{
    int *memory = realloc(stack->stack, stack->length * sizeof(content));
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

    int* memory = realloc(stack->stack, stack->length * sizeof(content));
  }
  return newContent;
}

stack* allocateNewStack(){
  stack *newStack;
  newStack = malloc(sizeof(stack));
  newStack->stack = malloc(sizeof(content));
  return newStack;
}
