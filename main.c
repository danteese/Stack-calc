/*
@autors: Dante Bazaldua y Ricardo de la Vega
@date: 26-OCT-2016
*/
#include "libraries.h"

extern int push(int *stack, int pos);
extern int pop(int *stack, int pos);
extern int peek(int *stack, int pos);
extern void print(int *stack, int pos);
extern void _compara( char in[256]);
extern double fcos( float angle );

int main(void){
  int *stack;
  int pos = -1, opt = -1, in = 0;
  int val = 0;

  float value = 0;
  double res = 0;
  printf("Stack.\n\n");
  stack = malloc( INIT * sizeof(char) );
  while ( in  == 0 ){
    //If in = 1, that means is quit
    in = _compara( );

  }
  free(stack);
  return 0;
}
