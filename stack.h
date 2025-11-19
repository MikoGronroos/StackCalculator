typedef struct content{

  char* content;

} content;

typedef struct stack{

  int length;
  content* stackContent;

} stack;

int addToStack(stack* stack, char* input);

char* pop(stack* stack);

stack* allocateNewStack();
