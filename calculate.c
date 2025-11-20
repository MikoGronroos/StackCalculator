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
      printf("-------\n");
      int secondNumber = atoi(pop(output));
      int firstNumber = atoi(pop(output));
      char* newChar = malloc(sizeof(char));
      printf("%i, %i\n", firstNumber, secondNumber);
      printf("-------\n");
      if(character == '+'){
        int final = firstNumber + secondNumber;
        sprintf(newChar, "%d", final);
      }
      if(character == '-'){
        int final = firstNumber - secondNumber;
        sprintf(newChar, "%d", final);
      }
      if(character == '*'){
        int final = firstNumber * secondNumber;
        sprintf(newChar, "%d", final);
      }
      if(character == '/'){
        int final = firstNumber / secondNumber;
        sprintf(newChar, "%d", final);
      }
      addToStack(output, newChar);
    }
  }
  printf("\n");
  return atoi(output->stack[0].content);
}
