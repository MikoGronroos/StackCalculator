#include "stack.h"
#include <stdio.h>

int run(char input[]){
  printf("%s\n------\n", input);
  stack* output = allocateNewStack();
  stack* operators = allocateNewStack();
  int index = 0;
  char character = input[index];
  while(character != '\0'){
    printf("%c\n", character);
    index++;
    character = input[index];
  }
  return 0;
}
