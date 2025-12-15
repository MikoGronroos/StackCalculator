#include "stack.h"

int getPrecedence(char operator);

char* getAssociativity(char operator);

char* getNumber(char number[]);

int sizeOfNumber(char number[]);

stack run(char* input);


