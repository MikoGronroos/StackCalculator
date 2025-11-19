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
      char operatorChar = character;
      addToStack(operators, &operatorChar);
    }
    index++;
    character = input[index];
  }
  printf("%i", output->length);
  for(int i = output->length - 1; i >= 0; i--){
    printf("xd\n");
    //char* test = pop(output);
    printf("%s\n", output->stackContent[i].content);

  }

  printf("----------\n");

  return 0;
}
