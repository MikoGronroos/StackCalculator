#include "shuntingYardAlgorithm.h"
#include <stdio.h>
#include "calculate.h"
#include "stack.h"

int main(){
  char* input = "1+2";
  stack output = run(input);
  
  int value = calculate(output);

}
