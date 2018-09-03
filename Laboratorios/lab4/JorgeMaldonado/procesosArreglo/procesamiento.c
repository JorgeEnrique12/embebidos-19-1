#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "procesamiento.h"
#include "datos.h"
#include "defs.h"



int * ordenaArreglo(int * datos){
    int * d = reservarMemoria();
    memcpy ( d, datos, N*sizeof(int));
    for(register int i = 0; i < N; i++){
        for(register int j = 0; j < N-1-i; j++){
            if (d[j] > d[j+1]) {
                int tmp = d[j];
                d[j] = d[j+1];
                d[j+1] = tmp;
            }
        }
    }
    return d;
}
int promedioArreglo(int * datos){
    int promedio=0;
    for(register int i = 0; i< N; i++){
        promedio = promedio + datos[i];
    }
    promedio = promedio << 4;
    return promedio;
}
int mayorArreglo(int * datos){
    register int max = datos[0];
    for(register int i = 0; i<N; i++)
    {      
        if (datos[i]>max) {
            max  = datos[i];
        }    
    }
    return max;
}
int menorArreglo(int * datos){
    register int min = datos[0];
    for(register int i = 0; i<32; i++)
    {      
        if (datos[i] < min) {
            min  = datos[i];
        }    
    }
    return min;
}