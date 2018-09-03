#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "procesos.h"
#include "procesamiento.h"
#include "datos.h"
#include "defs.h"

void procesoPadre(){
	pid_t pid_hijo;
	printf("Proceso padre ejecutado con pid %d\n",getpid());
	int numero;
	for(int np = 0; np < NUM_PROC; np++){
		pid_hijo = wait(&numero);
		printf("Procesos hijo terminado con pid %d y retorno %d\n",pid_hijo,numero>>8);
	}
		
	exit(0);
}
void procesoHijo(int np,int *datos){
    printf("Procesos hijo %d ejecutado con pid %d \n",np,getpid());
	if(np == 0){
        int mayor = mayorArreglo(datos);
        exit(mayor);
    }
    if(np == 1){
        int menor = menorArreglo(datos);
        exit(menor);
    }
    if(np == 2){
        int promedio = promedioArreglo(datos);
        exit(promedio);
    }
    
    if (np == 3) {
        printf("Atreglo Ordenado");
        imprimeArreglo(ordenaArreglo(datos));
        exit(2);
    }
    

}