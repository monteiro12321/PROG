#include "projeto_final.h"
/*------------------------------------------------------------
| Nome: insere_aeroporto
| Accao: insere as informacoes de um aeroporto num dado campo da lista
| Devolve: endereco do primeiro elemento da lista de aeroportos
+-------------------------------------------------------------*/
AEROPORTOS *insere_aeroporto(BASE x, AEROPORTOS *inicio)
{ AEROPORTOS *novo, *atual, *anterior=NULL;
  novo=(AEROPORTOS*)calloc(1,sizeof(AEROPORTOS));
  if(novo==NULL)
    { printf("Erro na alocacao de memoria");
      exit(0);
    }
   novo->aero=x;

  if(inicio==NULL)
    inicio=novo;

  atual=inicio;

  while(inicio!=NULL && strcmp(atual->aero.icao, novo->aero.icao)<=0)
    {   anterior=atual;
        atual=atual->prox;
    }
  novo=anterior->prox;
  anterior->prox=novo;
  atual=atual->prox;

return inicio;
}
/*------------------------------------------------------------
| Nome: le_ficheiro_aeroporto
| Accao: analisa os dados do ficheiro de aeroportos
| Devolve: endereco do primeiro elemento da lista de aeroportos
+-------------------------------------------------------------*/
AEROPORTOS *le_ficheiro_aeroportos()
{
  FILE *fp;
  AEROPORTOS *inicio2;
  BASE inicio;
  char linha [100];
  fp=fopen("aeroportos.txt", "r");

  if(fp == NULL)
  { printf("Erro na abertura do ficheiro");
  }

  while(fgets(linha, 100 , fp)!= NULL)
   {sscanf(linha, "%s %s %d %d %d %c %d %d %d %c %s %d", (inicio.icao), (inicio.iata), &(inicio.coordenadas.x.graus),
                                                        &(inicio.coordenadas.x.minutos), &(inicio.coordenadas.x.segundos),
                                                        &(inicio.coordenadas.x.orientacao),
                                                        &(inicio.coordenadas.y.graus), &(inicio.coordenadas.y.minutos), &(inicio.coordenadas.y.segundos),
                                                        &(inicio.coordenadas.y.orientacao), (inicio.nome), &(inicio.time_zone));

    insere_aeroporto(inicio, inicio2);
   }
return inicio2;
}
/*------------------------------------------------------------
| Nome: mostra_aeroporto
| Accao: mostra no ecra os dados de determinado aeroporto. Funcao de teste
| Devolve: void
+-------------------------------------------------------------*/
void mostra_aeroporto (BASE aero)
{
    printf("%s %s %d %d %d %c %d %d %d %c %s %d", aero.icao, aero.iata, aero.coordenadas.x.graus,
                                               aero.coordenadas.x.minutos,
                                               aero.coordenadas.x.segundos,
                                               aero.coordenadas.x.orientacao,
                                               aero.coordenadas.y.graus,
                                               aero.coordenadas.y.minutos,
                                               aero.coordenadas.y.segundos,
                                               aero.coordenadas.y.orientacao,
                                               aero.nome, aero.time_zone);
}
/*------------------------------------------------------------
| Nome: mostra_lista_aeroportos
| Accao:Funcao de teste. Mostra todos os dados da lista
| Devolve: void
+-------------------------------------------------------------*/
void mostra_lista_aeroportos (AEROPORTOS *inicio)
{ while(inicio!=NULL)
   { mostra_aeroporto(inicio->aero);
     inicio=inicio->prox;
   }
}



