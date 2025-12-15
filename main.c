#include "shuntingYardAlgorithm.h"
#include <stdio.h>
#include "calculate.h"
#include "stack.h"

int main(){
  char input[256];
  scanf("%255s", input);
  stack output = run(input);
  
  double value = calculate(output);

  printf("%f\n", value);
  return 0;
}
