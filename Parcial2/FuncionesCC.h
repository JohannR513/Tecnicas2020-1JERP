#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

//Local 
typedef struct Local{
	char nombreLocal[ 35 ];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;//Columnas
	status_l status;
	// Completelo con lo que quiera
} local_t;
//Este enum representa el estado del local
typedef enum status{
	ABIERTO = 1,
	CERRADO = 0
} status_l

/*Agregar las funciones que necesite para satisfacer los requerimientos */
void mostrarLocal( local_t **centroComercial, int numPiso,
		int numLocalxPiso, int numPiso, int numLocalesxPiso );

local_t** reservarMemoria(int numPiso, int numLocal);

void ingresarLocal( local_t**matrizMall, int numPiso, int numLocal );

void listarLocales( local_t**matrizMall, int numPiso, int numLocal );

void buscarLocalNombre( local_t**matrizMall, int numPiso, int numLocal );

void buscarLocalxID( local_t**matrizMall, int numPiso, int numLocal );

void cambiarNombre( local_t**matrizMall, int numPiso, int numLocal );

void eliminar( local_t**matrizMall, int numPiso, int numLocal );




#endif /* FUNCIONESCC_H_ */