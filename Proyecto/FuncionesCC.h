#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>

//Local 
typedef enum category{
HOGAR,
COMIDA,
TECNOLOGIA,
VESTUARIO,
}category_l;

typedef enum status{
	DISPONIBLE,
	OCUPADO 
} status_l;

typedef struct Local{
	char nombreLocal[ 35 ];// Nombre del local 
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal; // Piso donde esta ubicado el local
	int numLocalxPiso;//Columnas
  	int numEmpleados; // Cantidad de empleados que tiene el local
  	int ventasSemanales;// Ventas que ha hecho el local en una semana
  	int elementosInventario;//Candidad de elementos en el inventario del local
  	int empleadosEnTurno;// Empleados que estan trabajando actualmente dentro del local
  	status_l status;// Estado del local
  	category_l category;// Categoria del local
	// Completelo con lo que quiera
} local_t;


/*Agregar las funciones que necesite para satisfacer los requerimientos */
//void mostrarLocal(local_t ** centroComercial, int numPiso,
	//	int numLocalxPiso, int numPisos, int numLocalesxPiso);
local_t** crearCC ( int numPiso, int numLocal );
void ingresarLocal( local_t ** matrizMall, int numPiso, int numLocal );
void listarLocales( local_t ** matrizMall, int numPiso, int numLocal );
local_t* buscarPorNombre( local_t **matrizMall, int numPiso, int numLocal );
local_t* buscarPorId( local_t ** matrizMall, int numPiso, int numLocal );
void cambiarNombreLocal( local_t ** matrizMall, int numPiso, int numLocal );
void eliminarLocal( local_t ** matrizMall, int numPiso, int numLocal );
void localesOcupados( local_t ** matrizMall, int numPiso, int numLocal );
void localesLibres( local_t ** matrizMall, int numPiso, int numLocal );
void ordenarPorNumEMpleados( local_t ** matrizMall, int numPiso, int numLocal );
void ordenarPorVentas( local_t ** matrizMall, int      numPiso, int numLocal );
void ordenarPorInventario( local_t ** matrizMall, int numPiso, int numLocal );
void ordenarPorEmpleadosTurno( local_t ** matrizMall, int numPiso, int numLocal );
#endif /* FUNCIONESCC_H_ */
