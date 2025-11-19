#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int run(char input[]){
  printf("%s\n------\n", input);
  stack* output = allocateNewStack();
  stack* operators = allocateNewStack();
  int index = 0;
  char character = input[index];
  while(character != '\0'){
    if(isdigit(character)){
      char* outputChar = malloc(sizeof(char));
      *outputChar = character;
      addToStack(output, outputChar);
    }else{
      char* operatorChar = malloc(sizeof(char));
      *operatorChar = character;
      addToStack(operators, operatorChar);
      while(){
        
      }
    }
    index++;
    character = input[index];
  }

  for(int i = output->length - 1; i >= 0; i--){
    printf("%s\n", output->stackContent[i].content);

  }

  printf("------\n");

  for(int i = operators->length - 1; i >= 0; i--){
    printf("%s\n", operators->stackContent[i].content);

  }
  return 0;
}

int getPrecedence(char operator){
  if(operator == '^'){
    return 4;
  }
  if(operator == '*'){
    return 3;
  }
  if(operator == '/'){
    return 3;
  }
  if(operator == '+'){
    return 2;
  }
  if(operator == '-'){
    return 2;
  }
  return 0;
}
