#ifndef PROJETO_FINAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ICAO 5
#define MAX_IATA 4
#define MAX_NOME 20
#define HORAS 5
#define MAX_CIDADE 20
#define MAX_ID 5

typedef struct
{
   int graus;
   int minutos;
   int segundos;
   char orientacao;

}LATITUDE;

typedef struct
{
   int graus;
   int minutos;
   int segundos;
   char orientacao;

}LONGITUDE;

typedef struct
{
 LONGITUDE x;
 LATITUDE y;

}COORDENADAS;

typedef struct rotas
 {
  struct rotas *prox_rota;
  char origem[MAX_CIDADE];
  char destino[MAX_CIDADE];
  char codigo_voo[MAX_ID];
  char partida[HORAS];
  char chegada[HORAS];

 }ROTAS;

typedef struct aeroportos
{
    char icao[MAX_ICAO];
    char iata[MAX_IATA];
    char nome[MAX_NOME];
    COORDENADAS coordenadas;
    struct aeroportos *prox;
    ROTAS *lista;
    int time_zone;

}BASE;

 typedef struct suporte_aeroportos
 {
    BASE aero;
    struct suporte_aeroportos *prox;

 }AEROPORTOS;

 
 
 
 
 
#endif // PROJETO_FINAL_H_INCLUDED
