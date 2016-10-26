/*
@autors: Dante Bazaldua y Ricardo de la Vega
@date: 26-OCT-2016
*/
#include "libraries.h"

extern void push(double number, double * stack, int pos);
extern void pop(double * stack, int pos);
extern void peek(double * stack, int pos);
extern void print(double * stack, int pos);
extern int _compara ( double * value );
extern double fcos( float angle );

int main(void){
  double *stack;
  int pos = -1, opt = -1, in = 0;
  int val = 0;
  double value = 0;
  double res = 0;
  printf("Stack.\n\n");
  stack = malloc( INIT * sizeof( double ) );
  while ( in  == 0 ){
    /*
    If in = 1, that means is quit
    and if n = 0, the program continues.
    */
    in = _compara( &value );
    //Se estan ingresando numeros
    switch (in) {
      case 0:
        pos++;
        stack = malloc( (INIT * ( pos + 1 ) ) * sizeof( double ) );
        push( value, stack, pos );
        printf("\t\t[Size list]: [%2d] \n", pos + 1);
      break;
      case 1:
        //adios
        break;
      case 2:
        in = 0;
        //suma
        break;
      case 9:
        in = 0;
        print( stack, pos );
      case 404:
        in = 0;
        //Caracter desconocido
        break;
    }
  }
  free(stack);
  return 0;
}
