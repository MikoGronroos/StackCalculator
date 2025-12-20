#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double calculate(stack input){
  stack* output = allocateNewStack();
  for(int i = 0; i < input.length; i++){
    char* newChar = malloc(128*sizeof(char));
    if(strcmp("pii", input.stack[i].content) == 0){
      double pii = atan(1.0) * 4.0;
      sprintf(newChar, "%f", pii);
      addToStack(output, newChar);
    }else if(isdigit(*input.stack[i].content)){
      newChar = input.stack[i].content;
      addToStack(output, newChar);
    }else{
      double secondNumber = atof(pop(output));
      double firstNumber = atof(pop(output));
      if(*input.stack[i].content == '+'){
        double final = firstNumber + secondNumber;
        sprintf(newChar, "%f", final);
      }
      if(*input.stack[i].content == '-'){
        double final = firstNumber - secondNumber;
        sprintf(newChar, "%f", final);
      }
      if(*input.stack[i].content == '*'){
        double final = firstNumber * secondNumber;
        sprintf(newChar, "%f", final);
      }
      if(*input.stack[i].content == '/'){
        double final = firstNumber / secondNumber;
        sprintf(newChar, "%f", final);
      }
      if(*input.stack[i].content == '^'){
        double final = pow(firstNumber, secondNumber);
        sprintf(newChar, "%f", final);
      }
      addToStack(output, newChar);
    }
  }
  double value = atof(output->stack[0].content);
  return value;
}
