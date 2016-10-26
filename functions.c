#include "libraries.h"

int push (int * stack, int pos){
  int val = 0;
  printf("Que valor desea ingresar?\n$ ");
  scanf("%d",&val);
  printf("Posicion %d\n",pos);
  stack[pos] = val;
  return val;
}

int pop (int * stack, int pos){
  int val = stack[pos];
  printf("Valor a borrar: %d\n", stack[pos]);
  stack[pos] = -1;
  printf("Valor de retorno: %d\n", val);
  return val;
}

int peek (int * stack, int pos){
  int val = stack[pos];
  return val;
}

void print (int * stack, int pos){
  int i;
  if (pos == -1) {
    printf("The stack is empty\n");
  }
  else{
      for (i = 0; i < pos+1; i++) {
        printf("[ %2d ]-[ %2d ]\n", i, stack[i]);
      }
  }
}
