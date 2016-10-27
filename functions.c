#include "libraries.h"

/******************************************************
*  _compara - Compara caracteres de entrada y deter-  *
*             mina la función a la que hace referen-  *
*             cia, además provee métodos que limpian  *
*             el mismo caracter.                      *
*  Parámetros:                                        *
*    double * value: Recibe el apuntador de la varia- *
*                   que se ocupará.                   *
*                                                     *
*  Valor de retorno:                                  *
*    int 0 - Numeros                                  *
*    int 1 - Cuando es q o Q.                         *
*    int 2 - Cuando +                                 *
*    int 3 - Cuando -                                 *
*    int 4 - Cuando *                                 *
*    int 5 - Cuando /                                 *
*    int 6 - Cuando %                                 *
*    int 7 - Cuando fcos                              *
*    int 8 - Cuando son operadores                    *
*    int 9 - Cuando son operadores                    *
*    int 404 - No válido                              *
*                                                     *
*******************************************************/

int _compara ( float * value ){
  float a;
  int q[2],c[10];
  char b[256];
  printf("$: ");
  scanf("%s",b);
  q[0]=strcmp("q",b);
  q[1]=strcmp("Q",b);
  //Compara que sea q o Q
  if(q[0]!=0&&q[1]!=0){
      // Is a number
      if(sscanf(b,"%f",&a)==1){
          sscanf(b,"%f",&a);
          //printf("%f\n",a);
          //Return the value of number
          *value = a;
        }
      else{
          c[0]=strcmp("+",b);
          c[1]=strcmp("-",b);
          c[2]=strcmp("*",b);
          c[3]=strcmp("/",b);
          c[4]=strcmp("%",b);
          c[5]=strcmp("fsin",b);
          c[6]=strcmp("fcos",b);
          c[7]=strcmp("-show",b);
          if(c[0]==0){
            //Función suma
            return 2;
          }
          else if (c[1]==0){
            //Función resta
            return 3;
          }
          else if (c[2]==0){
            //Función Multiplicación
            return 4;
          }
          else if (c[3]==0){
            //Función división
            return 5;
          }
          else if (c[4]==0){
            //Función módulo
            return 6;
          }
          else if (c[6]==0){
            //Función coseno
            printf("Coseno\n");
            return 7;
          }
          else if (c[5]==0){
            //Función Cos
            printf("Seno\n");
            return 8;
          }
          else if (c[7]==0){
            //Función imprime el arreglo
            printf("\nImprime lista\n");
            return 9;
          }
          else{
              //Función desconocida.
              printf("[ Caracter no valido ]\n");
              return 404;
          }
        }
      }
      else{
        printf("Bye!\n");
        return 1;
  }
  return 0;
}

/******************************************************
*  _compara - Compara caracteres de entrada y deter-  *
*             mina la función a la que hace referen-  *
*             cia, además provee métodos que limpian  *
*             el mismo caracter.                      *
*  Parámetros:                                        *
*    float number: Utiliza un numero que introduce el *
*                  usuario y lo guarda en la locación *
*                  actual de memoria.                 *
*   float * stack: Apuntador a la lista.              *
*   int pos:  Cantidad de elementos de la lista.      *
*                                                     *
*  Valor de retorno:                                  *
*    Ninguno                                          *
*******************************************************/
void push (float number, float * stack, int pos){
  int i = 0;
  stack[pos] = number;
}
/*
 + Estas funciones no se ocupan actualmente pero eliminan
  y muestran el último numero ingresado.
*/
// void pop (double * stack, int pos){
//   double val = stack[pos];
//   printf("Valor a borrar: %f\n", stack[pos]);
//   stack[pos] = -1;
//   printf("Valor de retorno: %f\n", val);
// }
//
// void peek (double * stack, int pos){
//   double val = stack[pos];
// }
//

/******************************************************
*  print - Recorre la lista e imprime los números     *
*  Parámetros:                                        *
*   float * stack: Apuntador a la lista.              *
*   int pos:  Cantidad de elementos de la lista.      *
*                                                     *
*  Valor de retorno:                                  *
*    Ninguno                                          *
*******************************************************/

void print (float * stack, int pos){
  int i;
  if (pos == -1) {
    printf("The stack is empty\n");
  }
  else{
      for (i = 0; i < pos+1; i++) {
        printf("\t\t\t[ %2d ]-[ %2.1f ]\n", i, stack[i]);
      }
  }
}

/******************************************************
*  _recorre - Recorre la lista cuando se ha efectuado *
*             una operacion y la acomoda.             *
*  Parámetros:                                        *
*    float res: Resultado obtenido por la operacion   *
*    int c: Cantidad de valores que se tomaron de la  *
*           lista cuando se efectuo una operacion.    *
*   float * stack: Apuntador a la lista.              *
*   int pos:  Cantidad de elementos de la lista.      *
*                                                     *
*  Valor de retorno:                                  *
*    Ninguno                                          *
*******************************************************/
void _recorre ( float res, int c, float * stack, int pos ){ //Recorre la cantidad de valores usados
  float *temp;
  int i = 0;
  temp = malloc( sizeof(int));
  for (i = 0; i < pos+1; i++) {
    temp[i] = stack[i];
    //printf("Temp: [%2.1f]\n", temp[i]);
  }
  if (c == 1) { //Cuando no se recorre
    printf("No hay más valores.\nUtilce el comando -show para mostrar los valores almacenados.\n");
  }
  else{
    stack[0] = res;
    for (i = 1; i < pos+1; i++) {
      stack[i] = temp[i+1];
    }
  }
  free(temp);
}

/******************************************************
*  _catch - Obtiene los primeros valores de la lista  *
*           para efectuar una operacion y por defecto *
*           en caso de que se encuentre solo uno, se  *
*           determina el valor de la segunda variable *
*           como 0.                                   *
*  Parámetros:                                        *
*    float *in1: Apuntador a una variable a modificar *
*    float *in2: Apuntador a una variable a modificar *
*   float * stack: Apuntador a la lista.              *
*   int pos:  Cantidad de elementos de la lista.      *
*                                                     *
*  Valor de retorno:                                  *
*    Cantidad de valores que fueron tomados.          *
*******************************************************/
int _catch( float* in1, float* in2, float *stack, int pos){
  if (pos >= 1) {
    *in1 = stack[0];
    *in2 = stack[1];
    return 2;
  }
  else if (pos == 0) {
    *in1 = stack[0];
    *in2 = 0;
  }
  return 1;
}
