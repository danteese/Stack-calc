/*
@autors: Dante Bazaldua y Ricardo de la Vega
@date: 26-OCT-2016
*/
#include "libraries.h"

extern int push(int *stack, int pos);
extern int pop(int *stack, int pos);
extern int peek(int *stack, int pos);
extern void print(int *stack, int pos);

int main(void){
  int *stack;
  int pos = -1, opt = -1, in = 0;
  int val = 0;
  printf("Stack.\n\n");
  stack = malloc( INIT * sizeof(char) );
  while (in == 0){
    printf("¿Que desea hacer?\n1) Insertar al Stack\n2) Sacar del Stack\n3) Ver el ultimo valor insertado\n4) Imprimir el Stack\n5) Salir\n\n$ ");
    scanf("%d",&opt);
    switch(opt){
      case 1:
        pos++;
        stack = realloc( stack, (INIT + (pos+1)) * sizeof(char));
        val = push(stack, pos);
        printf("\n\nSe ingreso el valor -> %d\n", val);
        break;
      case 2:
        if (pos == -1) {
          printf("The stack is empty\n");
        }
        else{
          val = pop(stack, pos);
          pos--;
          printf("\n\n");
          //printf("\n\nSe saco el valor-> %d\n", val);
          stack = realloc( stack, (INIT + (pos)) * sizeof(char));
        }
        break;
      case 3:
        if (pos != -1) {
          val = peek(stack, pos);
          printf("\n\nEl ultimo valor agregado es -> %d\n", val);
        }
        else{
          printf("The stack is empty\n");
        }

        break;
      case 4:
        print( stack, pos);
        break;
      case 5:
        in=1;
        break;
      default:
        printf("\nERROR... opcion invalida, vuelva a intentar...\n");
        break;
    }
  }
        return 0;
}
