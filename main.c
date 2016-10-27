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
extern float resta( float a, float b );
extern float mult( int c, float a, float b );
extern float mult( int c, float a, float b );
extern float division( int c, float a, float b );
extern float modulo(float a, float b);
extern double fcos( float angle );

int main( int argc, char **argv ){
  float *stack;
  int pos = -1, opt = -1, in = 0;
  int i = 0;
  float value = 0;
  float a = 0,b = 0; //Valores operacionales.
  float sto_res = 0; //Resultado de operacion.
  int catch = 0; // Cantidad de valores que tomo de la lista.

  //Comprobaciones inciales:
  if (argc == 2) {
    if (strcmp(argv[1],"-h") == 0) {
      //Ayuda
      system("clear");
      printf("\n\t\t\t\tCalculadora Polaca.\nEntradas:\n\n");
      printf("\n(1): El programa recibe valores numéricos, operadores y palabras reservadas.\n");
      printf("\n(2): Los operadores son: \n\t(+) +: Suma\n\t(+) -: Resta\n\t(+) /: Division\n\t(+) *: Multiplicacion\n\t(+) %c : Modulo\n",37);
      printf("\n(3): Palabras reservadas: \n\t(+) fcos: Realiza el cos del angulo que se encuentre en el top de la lista.\n");
      printf("\n\t(+) -show: Muestra la lista en orden ascendente para que sepas que haz ingresado.\n");
      printf("\nPresione ENTER para continuar. \n");
      getchar();
      printf("\n(4): Razonamiento: \n\t(+) El programa recibirá numeros los cuales irá apilando en una fila, los cuales al ingresar un operador/palabra reservada se trabaja con los primeros en top.\n");
      printf("\tEjemplo: (valores ingresados por usuario)\n");
      printf("\t\t1\n");
      printf("\t\t2\n");
      printf("\t\t+\tResultado = 3\n");
      printf("\tNueva lista:\n");
      printf("\t\t3 (Notese que se cambió el 1 por el nuevo resultado)\n");
      exit(1);
    }
    else{
      printf("Modo de ejecución incorrecto. Pruebe ./calc -h\n");
      exit(1);
    }
  }

  else{
    printf("Modo de ejecución incorrecto. Pruebe ./calc -h\n");
    exit(1);
  }

  system("clear");
  printf("\t\t\t\tCalculadora v1.5\n\n");
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
          //Suma: top - (top-1)
          catch = _catch( &a, &b, stack, pos );
          sto_res = suma( a, b);
          printf("\t\t\t\t [ %2.1f + %2.1f = %2.1f ]\n",a,b,sto_res);
          _recorre( sto_res, catch, stack, pos );
          if( pos != 0 ){
              pos--;
          }
        }
        in = 0;
        break;
      case 3:
        if ( pos == -1 ) {
          printf("No hay suficientes valores para restar\n");
        }
        else{
          //Resta: top - (top-1)
          catch = _catch( &a, &b, stack, pos );
          sto_res = resta( a, b);
          printf("\t\t\t\t [ %2.1f - %2.1f = %2.1f ]\n",a,b,sto_res);
          _recorre( sto_res, catch, stack, pos );
          if( pos != 0 ){
              pos--;
          }
        }
        in = 0;
        //suma
        break;
      case 4:
        if ( pos == -1 ) {
          printf("No hay suficientes valores para multiplicar\n");
        }
        else{
          //printf("\t\t[ MULTIPLICACION ]\n");
          catch = _catch( &a, &b, stack, pos );
          if ( catch == 1) {
            b = 1;
          }
          sto_res = mult(catch,a, b);
          printf("\t\t\t\t [ %2.1f * %2.1f = %2.1f ]\n",a,b,sto_res);
          _recorre( sto_res, catch, stack, pos );
          if( pos != 0 ){
              pos--;
          }
	       }
        in = 0;
        break;
      case 5:
        if ( pos == -1 ) {
        printf("No hay suficientes valores para dividir\n");
        }
        else{
          //printf("\t\t[ DIVISION ]\n");
          catch = _catch( &a, &b, stack, pos );
          sto_res = division(catch,a,b);
          if ( catch == 1) {
            b = 1;
          }
          //Si no es un valor indeterminado puede mostrarse resultado y recorrer.
          if (sto_res != -9999) {
            printf("\t\t\t\t [ %2.1f / %2.1f = %2.1f ]\n",a,b,sto_res);
            _recorre( sto_res, catch, stack, pos );
          }
          if( pos != 0 ){
              pos--;
          }
        }
        in = 0;
        break;
      case 6:
        if ( pos == -1 ) {
          printf("No hay suficientes valores para obtener el residuo\n");
        }
        else{
          catch = _catch( &a, &b, stack, pos );
          sto_res = modulo( a, b);
          if (sto_res != -9999) {
            printf("\t\t\t\t [ %2.1f MOD %2.1f = %2.1f ]\n",a,b,sto_res);
            _recorre( sto_res, catch, stack, pos );
          }
          if( pos != 0 ){
              pos--;
          }
        }
        in = 0;
        break;
      case 7:
        if ( pos == -1 ) {
          printf("No hay suficientes valores para obtener el coseno\n");
        }
        else{
          catch = _catch( &a, &b, stack, pos );
          sto_res = fcos(a);
          printf("\t\t\t\tCos [%2.1f] = %2.9f\n",a,sto_res);
          // _recorre( coseno, catch, stack, pos );
          stack[0] = sto_res;
          if( pos != 0 ){
              pos--;
          }
        }
        in = 0;
        break;
      case 9:
        printf("[Size list]: [%2d] \n", pos + 1);
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
