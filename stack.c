#include "stack.h"
#include <stdlib.h>

int addToStack(stack* stack, char* input){
  stack->length++;
  if(stack->length <= 0){
    stack->stackContent = malloc(sizeof(content));
  }else{
    realloc(stack->stackContent, stack->length * sizeof(content));
  }
  stack->stackContent[stack->length-1].content = input;
  return 0;
}

char* pop(stack* stack){
  if(stack->length <= 0){
    return NULL;
  }
  stack->length--;
  char* newContent = stack->stackContent[stack->length].content;
  if(stack->length <= 0){
    free(stack->stackContent);
  }else{
    realloc(stack->stackContent, stack->length * sizeof(content));
  }
  return newContent;
}

stack* allocateNewStack(){
  stack *newStack;
  newStack = malloc(sizeof(stack));
  newStack->stackContent = malloc(sizeof(content));
  return newStack;
}
