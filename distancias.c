#include "projeto_final.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float retorna_distancia( )
{
  float latitude_a, longitude_a, latitude_b, longitude_b; /*graus decimais*/
  int graus_lat_a, minutos_lat_a, segundos_lat_a, eixo_lat_a, graus_lon_a, minutos_lon_a, segundos_lon_a, eixo_lon_a;
  int graus_lat_b, minutos_lat_b, segundos_lat_b, eixo_lat_b, graus_lon_b, minutos_lon_b, segundos_lon_b, eixo_lon_b;
  float xa, ya, za, xb, yb, zb;
  float angulo_graus, angulo_rad, produto_interno ;
  char linha[100];
  
  /* No painel deve aparecer os graus minutos segundos eixo (latitude) graus minutos segundos eixo (longitude) ex: 38 46 52 N 9 8 9 W 
  VAI TER QUE LER OS VALORES PRIMEIRO*/
  
  if (eixo_lat_a=="N" || eixo_lat_a=="E")
  latitude_a = (graus_lat_a + (minutos_lat_a/60) + (segundos_lat_a/3600));
  else
    if(eixo_lat_a=="S" || eixo_lat_a=="W")
  latitude_a = (graus_lat_a + (minutos_lat_a/60) + (segundos_lat_a/3600)) * (-1);
  
 if (eixo_lon_a=="N" || eixo_lon_a=="E")
  latitude_a = (graus_lon_a + (minutos_lon_a/60) + (segundos_lon_a/3600));
  else
    if(eixo_lon_a=="S" || eixo_lon_a=="W")
  latitude_a = (graus_lon_a + (minutos_lon_a/60) + (segundos_lon_a/3600)) * (-1);
  
  xa= 6381 * cos(latitude_a) * cos(longitude_a);
  ya= 6381 * cos(latitude_a) * sin (longitude_a);
  za= 6381 * sin (latitude_a);

  if (eixo_lat_b=="N" || eixo_lat_b=="E")
  latitude_b = (graus_lat_b + (minutos_lat_b/60) + (segundos_lat_b/3600));
  else
    if(eixo_lat_b=="S" || eixo_lat_b=="W")
  latitude_b = (graus_lat_b + (minutos_lat_b/60) + (segundos_lat_b/3600)) * (-1);
  
 if (eixo_lon_b=="N" || eixo_lon_b=="E")
  latitude_b = (graus_lon_b + (minutos_lon_b/60) + (segundos_lon_b/3600));
  else
    if(eixo_lon_b=="S" || eixo_lon_b=="W")
  latitude_b = (graus_lon_b + (minutos_lon_b/60) + (segundos_lon_b/3600)) * (-1);
  
  xb= 6381 * cos(latitude_b) * cos(longitude_b);
  yb= 6381 * cos(latitude_b) * sin (longitude_b);
  zb= 6381 * sin (latitude_b);
  
  produto_interno = xa*xb + ya*yb + za*zb;
  angulo_graus= 1/ cos(( produto_interno )/( sqrt( xa*xa + ya*ya + za*za)*sqrt( xb*xb + yb*yb + zb*zb))):
  
  /*Transformacao em radianos*/
  angulo_rad= (angulo_graus * 3.14) / 180;
  
  distancia= angulo_rad * 6381;
    
  return distancia; /*Distancia em km */
}


