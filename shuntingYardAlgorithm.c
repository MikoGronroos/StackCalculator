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
      if(operators->length > 1){
        while(operators->stack[1] != '(' && (getPrecedence(operators->stack[1]) > getPrecedence(operators->stack[0]) || (getPrecedence(operators->stack[1]) == getPrecedence(operators->stack[0])  &&))){
        
        }
      }
    }
    index++;
    character = input[index];
  }

  for(int i = output->length - 1; i >= 0; i--){
    printf("%s\n", output->stack[i].content);

  }

  printf("------\n");

  for(int i = operators->length - 1; i >= 0; i--){
    printf("%s\n", operators->stack[i].content);

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

char* getAssociativity(char operator){
  if(operator == '^'){
    return "right";
  }
  if(operator == '*'){
    return "left";
  }
  if(operator == '/'){
    return "left";
  }
  if(operator == '+'){
    return "left";
  }
  if(operator == '-'){
    return "left"
  }
  return "none";

}
