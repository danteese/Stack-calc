#include "libraries.h"

double cos( float angle ){
  float r_angle = 0;
  float ans = 1, res = 1, temp = 1; // Resultados parciales
  int acc = 4; //Numero de iteraciones
  int i = 0; //Contador
  for (i = 1; i < 2*acc; i+=2) {
    temp = (-1)*temp*r_angle*r_angle/(i*(i+1));
    ans = ans + temp;
  }
  return ans;
}
