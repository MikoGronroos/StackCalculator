#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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

stack run(char input[]){
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
    if(!isdigit(character) && character != '(' && character != ')'){
      char* operatorChar = malloc(sizeof(char));
      *operatorChar = character;
      if(operators->length >= 1){
        while(*operators->stack[operators->length-1].content != '(' && (getPrecedence(*operators->stack[operators->length-1].content) > getPrecedence(*operatorChar) || (getPrecedence(*operators->stack[operators->length-1].content) == getPrecedence(*operatorChar) && getAssociativity(*operatorChar) == "left"))){
          char* newChar = pop(operators);
          addToStack(output, newChar); 
          break;        
        }
      }
      addToStack(operators, operatorChar); 
    }
    if(!isdigit(character) && character == '('){
      char* operatorChar = malloc(sizeof(char));
      *operatorChar = character;
      addToStack(operators, operatorChar); 
    }
    if(!isdigit(character) && character == ')'){
      while(true){
        char* newChar = pop(operators);
        if(*newChar != '('){
          addToStack(output, newChar);
        }else{
          break;
        }
      }
    }
    index++;
    character = input[index];
  }
  while(operators->length > 0){
        
    char* newChar = pop(operators);
    addToStack(output, newChar);

  }
  return *output;
}
