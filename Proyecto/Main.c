#include "FuncionesCC.h"
#include <stdio.h>
#include <stdlib.h>
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
    printf( "7. Consultar la candidad de locales ocupados\n" );
    printf( "8. Consultar la candidad de locales disponibles\n" );
    printf( "9. Ordenar\n" );
    printf( "10. Salir\n" );
    scanf( "%d", &opc );

    return opc;
}

int main(){
    int numPiso, numLocal, i, j ;
    printf( "Ingrese la cantidad de pisos del centro comercial: \n" );
    scanf( "%d", &numPiso );
    printf( "Ingrese la cantidad de locales del centro comercial: \n" );
    scanf( "%d", &numLocal );
    local_t** matrizMall = crearCC ( numPiso, numLocal );
    
    for( i = 0; i < numPiso; i++ ){
      for( j = 0; j < numLocal; j++ ){
        printf("%d", matrizMall[ i ][ j ].status );
      }
      printf( "\n" );
    }
int opc;
  do
    {
        opc = menu();
        switch ( opc )
        {
            case 1:
                ingresarLocal( matrizMall, numPiso, numLocal );
                break;

            case 2: 
                listarLocales( matrizMall,  numPiso,  numLocal );
                break;
            
            case 3: buscarPorNombre( matrizMall,  numPiso,  numLocal );
                break;
            
            case 4: buscarPorId( matrizMall,  numPiso,  numLocal );
                break;

            case 5: cambiarNombreLocal( matrizMall,  numPiso,  numLocal );
                break;
            
            case 6: eliminarLocal( matrizMall, numPiso,  numLocal );
                break;
            
            case 7: localesOcupados( matrizMall,  numPiso,  numLocal );
                break;

            case 8: localesLibres( matrizMall,  numPiso,  numLocal );
                break;
            
            case 9: ordenarPorNumEMpleados( matrizMall,  numPiso,  numLocal );
                break;
            
            case 10:  
                break;
            
            default:
                printf("Opcion invalida\n");
                break;
        }
     } while (opc != 10);
   return 0;
}
