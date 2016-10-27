#include "libraries.h"

/******************************************************
*  fcos - Obtiene el valor del coseno debido a una    *
*         aproximación mediante Series de Taylor.     *
*  Parámetros:                                        *
*    float angle - Ángulo en grados                   *
*                                                     *
*  Valor de retorno:                                  *
*    double ans: Valor del coseno                     *
*                                                     *
*******************************************************/

double fcos( float angle ){
  float r_angle = 0;
  float ans = 1, res = 1, temp = 1; // Resultados parciales
  int acc = 3; //Numero de iteraciones
  int i = 0; //Contador
  r_angle = (angle * PI)/180;
  for (i = 1; i < 2*acc; i+=2) {
    temp = (-1)*temp*r_angle*r_angle/(i*(i+1));
    ans = ans + temp;
  }
  return ans;
}

float suma( float a, float b ){
  float res = a + b;
  return res;
}

float resta( float a, float b ){
  float res = a - b;
  return res;
}

float mult( int c, float a, float b ){
  float res = 0;
  //c: Cantidad de valores que tomo de la lista
  if ( c == 1 ) {
    b = 1;
  }
  res = a * b;
  return res;
}

float division( int c, float a, float b ){
  float res = 0;
  if( c == 1){
    b = 1;
  }
  if( b == 0 ){
    printf("\t\t\t\t [Valor indeterminado]\n");
    res = -9999;
  }
  else{
     res = a / b;
  }
  return res;
}

float modulo(float a, float b){
  float res;
  int x,y;
  x = a;
  y = b;
  if( b == 0 ){
    printf("\t\t\t\t [Valor indeterminado]\n");
    res = -9999;
  }
  else{
    res = (x % y);
  }
  return res;
}
