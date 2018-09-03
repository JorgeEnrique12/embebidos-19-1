#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "datos.h"
#include "defs.h"


int * reservarMemoria(){
    int * memoria;
    memoria = (int*)malloc(sizeof(int)*N);
    if(!memoria){
        perror("Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    return memoria;
}


void llenarArreglo(int *datos){
    register int i;
    srand(getpid());
    for( i = 0; i < N; i++)
    {
        datos[i] = rand() % 255;
    }
    
}
void imprimeArreglo(int * datos){
    register int i;
    
    for(i = 0; i<N; i++)
    {
        if(!(i%16)){
            printf("\n");
        }
        printf("%5d ",datos[i]);
    }
    printf("\n");
    
}