#include "FuncionesCC.h"
#include <string.h>

/* Funcion de ejemplo que imprimiria la informacion de un local */
//void mostrarLocal(local_t ** centroComercial, int numPiso,
  //  int numLocalxPiso, int numPisos, int numLocalesxPiso) {
  
  //Se valida si el numero ingresado esta en el rango
/*  if(numPiso<=numLocalxPiso && numLocalxPiso <= numLocalesxPiso)
  {
    printf("Nombre local : %s", centroComercial[numPiso][numLocalxPiso].nombreLocal);
    printf("Numero local : %d ", centroComercial[numPiso][numLocalxPiso].numeroLocal);
  }
  //TODO completarlo con los datos que le sirvan en su caso
}*/
    void ingresarLocal( local_t ** matrizMall, int numPiso, int numLocal ){
      int nPiso, nLocal;
      do{
        printf( "Ingresa el piso donde quieres el local:\n " );
        scanf( "%d", &nPiso );
        if ( nPiso > numPiso -1 ){
          printf( "Esta opcion no es valida\n" );
        }
        printf( "Ingresa el numero del local:\n " );
        scanf( "%d", &nLocal );
        if ( nLocal > numLocal -1 ){
          printf( "Esta opcion no es valida\n" );
        }
      
      }while( nPiso > numPiso - 1 || nLocal > numLocal - 1 );
      printf( "Cual es el nombre del local?\n" );
      scanf( "%s", matrizMall[ nPiso ][ nLocal ].nombreLocal );

      matrizMall[ nPiso ][ nLocal ].status = OCUPADO;
      matrizMall[ nPiso ][ nLocal ].idLocal = rand() % 10000;
    }
 void listarLocales( local_t ** matrizMall, int numPiso, int numLocal ){
   int i, j;
   for( i = 0; i < numPiso; i ++){
     for( j = 0; j < numPiso; j ++){
       if ( matrizMall[ i ][ j ].status == OCUPADO ){
         printf( "%s\nPiso %d, Local %d\nID: %d", matrizMall[ i ][ j ].nombreLocal, matrizMall[ i ][ j ].pisoLocal, matrizMall[ i ] [j ].numLocalxPiso, matrizMall[ i ][ j ].idLocal);
     }
   }
  }
 }

 void buscarPorNombre ( local_t ** matrizMall, int numPiso, int numLocal ){
   int i, j;
   char search[ 35 ];
   printf( "Ingresa el nombre del local que estas buscando:\n" );
   scanf( "%s", search );
   for( i = 0; i < numPiso; i++ ){
     for ( j = 0; i < numLocal; j++ ){
       if( !strcmp ( matrizMall[ i ][ j ].nombreLocal, search ) ){
        printf("Este local esta ubicado en el piso %d, local %d, codigo %d\n", matrizMall[ i ][ j ].pisoLocal, matrizMall[ i ][ j ].numLocalxPiso, matrizMall[ i ][ j ].idLocal );
        return;

       }
     }
   }
   printf( "No existe un local con ese nombre :c" );
   return;
 }
 void buscarPorId( local_t ** matrizMall, int numPiso, int numLocal ){
   int i, j, search;
   printf( "Ingresa el nombre del local que estas buscando:\n" );
   scanf( "%d", &search );
   for( i = 0; i < numPiso; i++ ){
     for( j = 0; j < numPiso; j++ ){
       if( matrizMall[ i ][ j ].idLocal == search ){
         printf("Nombre: %s, esta ubicado en el piso %d, local %d\n", matrizMall[ i ][ j ].nombreLocal, matrizMall[ i ][ j ].pisoLocal, matrizMall[ i ][ j ].numLocalxPiso );
       }
     }
   }
   printf( "No existe un local con ese codigo :c" );
   return;
 }

 void cambiarNombreLocal( local_t ** matrizMall, int numPiso, int numLocal ){
   int i, j;
   char newName[ 35 ];
   printf( "Ingresa el nombre del local que deseas cambiarle el nombre:\n" );
   scanf( "%s", newName );
   for( i = 0; i < numPiso; i++ ){
     for( j = 0; j < numPiso; j++ ){
       if( !strcmp ( matrizMall[ i ][ j ].nombreLocal, newName ) ){
          printf( "Escribe el nuevo nombre del local" );
          scanf( "%s", matrizMall[ i ][ j ].nombreLocal );
          printf( "El nombre ha sido cambiado con exito" );
          return;
       }
     }
   }
  printf( "No hemos encontrado el local con el nombre que proporcionaste :C" );
          return;
 }

 void eliminarLocal( local_t ** matrizMall, int numPiso, int numLocal ){
   int pis, loc;
   printf( "Ingresa el piso donde esta ubicado el local:\n" );
   scanf( "%d", &pis );
   printf( "Ingresa la ubicacion del local:\n" );
   scanf( "%d", &loc );
  
  matrizMall[ pis ][ loc ].status = DISPONIBLE;
  printf( "El local %s ha sido borrado exitosamente :)", matrizMall[ pis ][ loc ].nombreLocal);
  return;
 }
void localesOcupados( local_t ** matrizMall, int numPiso, int numLocal ){
  int ocupados = 0, i, j;
  for( i = 0; i < numPiso; i++ ){
    for( j = 0; j < numPiso; j++ ){
      if ( matrizMall [ i ][ j ].status == OCUPADO ){
        ocupados += 1;
      }
    }
  }
  printf("El numero de locales ocupados es %d", ocupados);
  }
