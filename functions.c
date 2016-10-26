#include "libraries.h"

/******************************************************
*  _compara - Compara caracteres de entrada y deter-  *
*             mina la función a la que hace referen-  *
*             cia, además provee métodos que limpian  *
*             el mismo caracter.                      *
*  Parámetros: ninguno.                               *
*                                                     *
*  Valor de retorno:                                  *
*    int 0 - El caso de ! de q y Q.                   *
*    int 1 - Cuando es q o Q.                         *
*                                                     *
*******************************************************/

int _compara ( void ){
  float a;
  int q[2],c[7];
  char b[256];
  printf("> ");
  scanf("%s",b);
  q[0]=strcmp("q",b);
  q[1]=strcmp("Q",b);
  //Compara que sea q o Q
  if(q[0]!=0&&q[1]!=0){
      if(sscanf(b,"%f",&a)==1){
          sscanf(b,"%f",&a);
          printf("%f\n",a);
          //Regresa el valor de 0
          return 0;
        }
      else{
          c[0]=strcmp("+",b);
          c[1]=strcmp("-",b);
          c[2]=strcmp("*",b);
          c[3]=strcmp("/",b);
          c[4]=strcmp("%",b);
          c[5]=strcmp("fsin",b);
          c[6]=strcmp("fcos",b);
          if(c[0]==0){
            //Función suma
            printf("Suma\n");
          }
          else if (c[1]==0){
            //Función resta
            printf("Resta\n");
          }
          else if (c[2]==0){
            //Función Multiplicación
            printf("Multiplicacion\n");
          }
          else if (c[3]==0){
            //Función división
            printf("Division\n");
          }
          else if (c[4]==0){
            //Función módulo
            printf("Mood\n");
          }
          else if (c[5]==0){
            //Función Cos
            printf("Seno\n");
          }
          else if (c[6]==0){
            //Función coseno
            printf("Coseno\n");
          }
          else{
              //Función desconocida.
              printf("Caracter no valido\n");
          }
        }
      }
      else{
        printf("Bye!\n");
        return 1;
  }
}

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
