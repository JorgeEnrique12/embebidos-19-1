#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "datos.h"
#include "procesos.h"
#include "procesamiento.h"
#include "defs.h"


int main(){

    int *datos;
    datos = reservarMemoria();
    llenarArreglo(datos);
    imprimeArreglo(datos);
    
    int np;
	pid_t pid;
	for(np = 0; np < NUM_PROC; np++)
	{
		pid = fork();
		if(pid == -1){
			perror("No se creo el proceso...");
			exit(EXIT_FAILURE);
		}
		if(!pid){
			procesoHijo(np,datos);
			
		}
	}
    procesoPadre();
    
    free(datos);
    return 0;
}