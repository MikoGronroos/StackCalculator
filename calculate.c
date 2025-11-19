#include "stack.h"
#include <stdio.h>

int calculate(stack input){
  printf("------\n");

  for(int i = input.length - 1; i >= 0; i--){
    printf("%s\n", input.stack[i].content);

  }
  return 0;
}
