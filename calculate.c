#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int calculate(stack input){
  stack* output = allocateNewStack(); 
  for(int i = 0; i < input.length; i++){
    char character = *input.stack[i].content;
    if(isdigit(character)){
      char* newChar = malloc(sizeof(char));
      *newChar = character;
      addToStack(output, newChar);
    }else{
      float secondNumber = atof(pop(output));
      float firstNumber = atof(pop(output));
      char* newChar = malloc(sizeof(char));
      if(character == '+'){
        float final = firstNumber + secondNumber;
        sprintf(newChar, "%f", final);
      }
      if(character == '-'){
        float final = firstNumber - secondNumber;
        sprintf(newChar, "%f", final);
      }
      if(character == '*'){
        float final = firstNumber * secondNumber;
        sprintf(newChar, "%f", final);
      }
      if(character == '/'){
        float final = firstNumber / secondNumber;
        sprintf(newChar, "%f", final);
      }
      addToStack(output, newChar);
    }
  }
  return atof(output->stack[0].content);
}
