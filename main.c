/*
@autors: Dante Bazaldua y Ricardo de la Vega
@date: 26-OCT-2016
*/
#include "libraries.h"

extern void push(float number, float * stack, int pos);
// extern void pop(double * stack, int pos);
// extern void peek(double * stack, int pos);
extern void print( float * stack, int pos);
extern int _compara ( float * value );
//Cuando se borran de la lista.
extern void _recorre ( float res, int c, float* stack, int pos );
extern int _catch( float* in1, float* in2, float *stack, int pos);
/* Funciones de operaciones */
extern float suma( float a, float b );
extern double fcos( float angle );

int main(void){
  float *stack;
  int pos = -1, opt = -1, in = 0;
  int i = 0;
  float value = 0;
  float a = 0,b = 0; //Valores operacionales.
  float sto_res = 0; //Resultado de operacion.
  int catch = 0; // Cantidad de valores que tomo de la lista.
  printf("Stack.\n");
  stack = malloc( sizeof(int) );
  if ( stack == NULL ) {
    printf(" No se pudo alojar memoria. \n");
    exit(1);
  }
  while ( in  == 0 ){
    /*
    If in = 1, that means is quit
    and if n = 0, the program continues.
    */
    in = _compara( &value );
    switch (in) {
      case 0:    //Se estan ingresando numeros
        pos++;
        push( value, stack, pos );
      break;
      case 1:
        //adios
        break;
      case 2:
        //suma
        if ( pos == -1 ) {
          printf("No hay suficientes valores para sumar\n");
        }
        else{
          catch = _catch( &a, &b, stack, pos );
          sto_res = suma( a, b);
          printf("\t\tResultado = %2.1f\n",sto_res);
          _recorre( sto_res, catch, stack, pos );
          pos--;
        }
        in = 0;
        break;
      case 3:
        printf("\t\t[ RESTA ]\n");
        in = 0;
        //suma
        break;
      case 4:
        printf("\t\t[ MULTIPLICACION ]\n");
        in = 0;
        //suma
        break;
      case 5:
        printf("\t\t[ DIVISION ]\n");
        in = 0;
        break;
      case 6:
        printf("\t\t[ MODULO ]\n");
        in = 0;
        break;
      case 7:
        printf("\t\t[ COS ]\n");
        in = 0;
        break;
      case 9:
        printf("\t\t[Size list]: [%2d] \n", pos + 1);
        print( stack, pos );
        in = 0;
      case 404:
        in = 0;
        //Caracter desconocido
        break;
    }
  }
  free(stack);
  return 0;
}
