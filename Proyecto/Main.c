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
    printf( "0. Salir\n" );
    scanf( "%d", &opc );

    return opc;
}

int main(){
      int **matrizMall, i, j, numPiso, numLocal;
    printf( "Ingrese la cantidad de pisos del centro comercial: \n" );
    scanf( "%d", &numPiso );
    printf( "Ingrese la cantidad de locales del centro comercial: \n" );
    scanf( "%d", &numLocal );

    matrizMall = ( int** )calloc( numPiso, sizeof( int * ) );
    for ( i = 0; i < numPiso; i++){
      matrizMall [ i ] = ( int * )calloc( numLocal, sizeof( int ) );
    }
    for( i = 0; i < numPiso; i++ ){
      for( j = 0; j < numLocal; j++ ){
        matrizMall[ i ][ j ] = i + j;
      }
    }
     for( i = 0; i < numPiso; i++ ){
      for( j = 0; j < numLocal; j++ ){
        printf("%d",matrizMall[ i ][ j ] );
      }
      printf( "\n" );
    }
    return 0;

    int opc;

}
