#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int calculate(stack input){
  printf("xd");
  stack* output = allocateNewStack(); 
  for(int i = 0; i < input.length; i++){
    char character = *input.stack[i].content;
    
    if(isdigit(character)){
      char* newChar = malloc(sizeof(char));
      *newChar = character;
      addToStack(output, newChar);
    }else{
      int firstNumber = atoi(pop(output));
      int secondNumber = atoi(pop(output));
      char* newChar = malloc(sizeof(char));
      if(character == '+'){
        int final = firstNumber + secondNumber;
        sprintf(newChar, "%d", final);
      }
      addToStack(output, newChar);
    }
  }
  return atoi(output->stack[0].content);
}
