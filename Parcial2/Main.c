#include "FuncionesCC.h"
#include <stdio.h>
int menu(){
    
    int opc;
    printf( "MENU Centro Comercial:\n");
    printf( "BIENVENIDO :)\n") ;
    printf( "=====================\n" );
    printf( "1. Ingresar un nuevo local\n" );
    printf( "2. Listar locales\n" );
    printf( "3. Buscar local por nombre\n" );
    printf( "4. Buscar local por identificador\n" );
    printf( "5. Cambiar nombre del local\n" );
    printf( "6. Eliminar local\n" );
    printf( "0. Salir\n" );
    scanf( "%d", &opc );

    return opc;
}

int main(){
	
	int numPiso;
	int numLocal;
    printf( "Ingrese la cantidad de pisos del centro comercial: \n" );
    scanf( "%d", &numPiso );
    printf( "Ingrese la cantidad de locales del centro comercial: \n" );
    scanf( "%d", &numLocal );

    local_t** matrizMall;
    mallMatrix = reservarMemoria( numPiso, numLocal );

	return 0;

    int opc;

    do{
        opc = menu();
        switch( opc ){
                case 1: ingresarLocal( matrizMall, numPiso, numLocal );
                        break;

                case 2: listarLocales( matrizMall, numPiso, numLocal );
                        break;

                case 3: buscarLocalNombre( matrizMall, int numPiso, int numLocal );
                        break;
                
                case 4: buscarLocalxID( matrizMall, numPiso, numLocal );
                        break;
                
                case 5: cambiarNombre( matrizMall, numPiso, numLocal );
                        break;

                case 6: eliminar( matrizMall, numPiso, numLocal );
                        break;

                case 0: break;

                default: printf( "Por favor ingresa un opcion valida" );

        }
    }
    while ( opc != 0 );

    return 0;
}
