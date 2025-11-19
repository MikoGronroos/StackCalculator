#include "shuntingYardAlgorithm.h"
#include <stdio.h>
#include "stack.h"

int main(){
  char* input = "1+2";
  stack operators = run(input);

  printf("------\n");

  for(int i = operators.length - 1; i >= 0; i--){
    printf("%s\n", operators.stack[i].content);

  }
}
