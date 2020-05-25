#include "FuncionesCC.h"
#include <stdio.h>
#include <stdlib.h>
int menu(){
    //Menu con el cual el usuario podra interactuar con el programa
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
    printf( "9. Ordenar por empleados\n" );
    printf( "10. Ordenar por ventas semanales\n" );
    printf( "11. Ordenar por inventario\n" );
    printf( "12. Ordenar por empleados en turno\n" );
    printf( "0. Salir\n");
    scanf( "%d", &opc );

    return opc;
}

int main(){
    int numPiso, numLocal, i, j ;
    //Aqui es donde se crea la matriz que representa al centro comercial
    printf( "Ingrese la cantidad de pisos del centro comercial: \n" );//Pisos del centro comercial
    scanf( "%d", &numPiso );
    printf( "Ingrese la cantidad de locales del centro comercial: \n" );//Locales que tendra cada piso
    scanf( "%d", &numLocal );
    local_t** matrizMall = crearCC ( numPiso, numLocal );
    
    /*Este ciclo imprime la matriz, esto lo hice para asegurarme que la matriz se 
     *estuviera creando con las dimensiones correctas
     */
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
        switch ( opc ){ /*Aqui es donde se invocan las funciones para hacer que el programa
                        * se ejecute
                        */
            case 1: ingresarLocal( matrizMall, numPiso, numLocal );
                break;

            case 2: listarLocales( matrizMall,  numPiso,  numLocal );
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
            
            case 10: ordenarPorVentas( matrizMall, numPiso,  numLocal );
                break;
           
            case 11: ordenarPorInventario( matrizMall, numPiso,  numLocal );
                break;
            
            case 12: ordenarPorEmpleadosTurno( matrizMall, numPiso, numLocal );
                break;

            case 0:  
                break;
            
            default:
                printf( "Opcion invalida\n" );
                break;
        }
     } while ( opc != 0 );
   return 0;
}
