#include "stack.h"
#include <stdio.h>

int run(char* input){
  printf("%s", input);
  stack* output = allocateNewStack();
  stack* operators = allocateNewStack();
  int index = 0;
  char* character = &input[index];
  while(*character != '\0'){
    printf("%s", character);
    index++;
    character = &input[index];
  }

}
