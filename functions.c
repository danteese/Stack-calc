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

int _compara ( double * value ){
  float a;
  int q[2],c[10];
  char b[256];
  printf("> ");
  scanf("%s",b);
  q[0]=strcmp("q",b);
  q[1]=strcmp("Q",b);
  //Compara que sea q o Q
  if(q[0]!=0&&q[1]!=0){
      // Is a number
      if(sscanf(b,"%f",&a)==1){
          sscanf(b,"%f",&a);
          printf("%f\n",a);
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
          c[7]=strcmp("imprime",b);
          if(c[0]==0){
            //Función suma
            printf("Suma\n");
            return 2;
          }
          else if (c[1]==0){
            //Función resta
            printf("Resta\n");
            return 3;
          }
          else if (c[2]==0){
            //Función Multiplicación
            printf("Multiplicacion\n");
            return 4;
          }
          else if (c[3]==0){
            //Función división
            printf("Division\n");
            return 5;
          }
          else if (c[4]==0){
            //Función módulo
            printf("Mood\n");
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
            printf("Imprime arreglo\n");
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

void push (double number, double * stack, int pos){
  stack[pos] = number;
}

void pop (double * stack, int pos){
  double val = stack[pos];
  printf("Valor a borrar: %f\n", stack[pos]);
  stack[pos] = -1;
  printf("Valor de retorno: %f\n", val);
}

void peek (double * stack, int pos){
  double val = stack[pos];
}

void print (double * stack, int pos){
  int i;
  if (pos == -1) {
    printf("The stack is empty\n");
  }
  else{
      for (i = 0; i < pos+1; i++) {
        printf("[ %2d ]-[ %2f ]\n", i, stack[i]);
      }
  }
}
