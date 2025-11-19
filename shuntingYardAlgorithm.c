#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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
    return "left";
  }
  return "none";

}

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
    }
    if(!isdigit(character)){
      char* operatorChar = malloc(sizeof(char));
      *operatorChar = character;
      if(operators->length >= 1){
        while(*operators->stack[0].content != '(' && (getPrecedence(*operators->stack[0].content) > getPrecedence(*operatorChar) || (getPrecedence(*operators->stack[0].content) == getPrecedence(*operatorChar) && getAssociativity(*operatorChar) == "left"))){
          char* newChar = pop(operators);
          addToStack(output, newChar);  
        }
      }
      addToStack(operators, operatorChar); 
    }
    char* newChar = pop(operators);
    printf("%s", newChar);
   // while(operators->length > 0){
        
      //char* newChar = pop(operators);
      //addToStack(output, newChar);

    //}
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
