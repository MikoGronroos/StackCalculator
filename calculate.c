#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double calculate(stack input){
  stack* output = allocateNewStack(); 
  for(int i = 0; i < input.length; i++){
    char character = *input.stack[i].content;
    if(isdigit(character)){
      char* newChar = malloc(sizeof(char));
      newChar = input.stack[i].content;
      addToStack(output, newChar);
    }else{
      double secondNumber = atof(pop(output));
      double firstNumber = atof(pop(output));
      char* newChar = malloc(sizeof(char));
      if(character == '+'){
        double final = firstNumber + secondNumber;
        sprintf(newChar, "%f", final);
      }
      if(character == '-'){
        double final = firstNumber - secondNumber;
        sprintf(newChar, "%f", final);
      }
      if(character == '*'){
        double final = firstNumber * secondNumber;
        sprintf(newChar, "%f", final);
      }
      if(character == '/'){
        double final = firstNumber / secondNumber;
        sprintf(newChar, "%f", final);
      }
      addToStack(output, newChar);
    }
  }
  double value = atof(output->stack[0].content);
  return value;
}
