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


local_t** crearCC( int numPiso, int numLocal ){
      local_t** matrizMall = malloc( sizeof( local_t* ) * numPiso );

    int i, j;
    for( i = 0; i < numPiso; i++ ){
        matrizMall[ i ] = malloc( sizeof ( local_t ) * numLocal );
        for ( j = 0; j < numPiso; j++ ){
            
            matrizMall[ i ][ j ].idLocal = DISPONIBLE;
        }
    }

    return matrizMall;
}
void ingresarLocal( local_t ** matrizMall, int numPiso, int numLocal ){
    int piso, local;
    do{
        printf( "Si despues de digitar los datos te aparece nuevamente este menu es porque la posicion que elegiste no esta disponible :c\n" );
        printf( "Elige el piso:\n" );
        scanf( "%d", &piso );
        printf( "Elige el local:\n" );
        scanf( "%d", &local );

    }while ( ( piso > numPiso -1 && local > numLocal-1 ) || ( matrizMall [ piso ][ local ].status == OCUPADO ) );
    printf( "Cual es el nombre del local?\n" );
    scanf( "%s", matrizMall[ piso ][ local ].nombreLocal );
    matrizMall[ piso ][ local ].status = OCUPADO;
    matrizMall[ piso ][ local ].idLocal = rand() % 10000;
    matrizMall[ piso ][ local ].pisoLocal = piso;
    matrizMall[ piso ][ local ].numLocalxPiso = local;
    printf( "El local fue agregado exitosamente :)\n" );
    }
  
void listarLocales( local_t ** matrizMall, int numPiso, int numLocal ){
   int i, j;
   for( i = 0; i < numPiso; i ++){
     for( j = 0; j < numPiso; j ++){
       if ( matrizMall[ i ][ j ].status == OCUPADO ){
         printf( "Nombre: %s\n",matrizMall[ i ][ j ].nombreLocal );
         printf( "Id: %d \n",matrizMall[ i ][ j ].idLocal );
         printf( "Piso: %d\n",matrizMall[ i ][ j ].pisoLocal);
         printf( "Local: %d\n",matrizMall[ i ][ j ].numLocalxPiso);
     }
   }
  }
 }
local_t* buscarPorNombre(local_t **matrizMall, int numPiso, int numLocal){
   char search[35];
    printf("Nombre del local: ");
    scanf("%s", search);

    //Se recorre la matriz usando dos ciclos
    int i, j;
    for ( i = 0; i < numPiso; i++ ){
        for ( j = 0; j < numLocal; j++ ){
            if ( !strcmp( matrizMall[ i ][ j ].nombreLocal, search ) ){
                printf("Id: %d\nPiso: %d\nLocal: %d\n",matrizMall[ i ][ j ].idLocal, matrizMall[ i ][ j ].pisoLocal, matrizMall[ i ][ j ].numLocalxPiso);
              return 0;
            }
        }
    }
 printf( "No hemos encontrado el local con el nombre que proporcionaste :C\n" );
    return 0;
}
local_t* buscarPorId( local_t ** matrizMall, int numPiso, int numLocal ){
   int i, j, search;
   printf( "Ingresa el id del local que estas buscando:\n" );
   scanf( "%d", &search );
   for( i = 0; i < numPiso; i++ ){
     for( j = 0; j < numPiso; j++ ){
       if( matrizMall[ i ][ j ].idLocal == search )
         printf("Nombre: %s, esta ubicado en el piso %d, local %d\n", matrizMall[ i ][ j ].nombreLocal, matrizMall[ i ][ j ].pisoLocal, matrizMall[ i ][ j ].numLocalxPiso );
         
     }
   }

   return NULL;
 }

  void cambiarNombreLocal( local_t ** matrizMall, int numPiso, int numLocal ){
   int i, j;
   char newName[ 35 ];
   printf( "Ingresa el nombre del local que deseas cambiarle el nombre:\n" );
   scanf( "%s", newName );
   for( i = 0; i < numPiso; i++ ){
     for( j = 0; j < numPiso; j++ ){
       if( !strcmp ( matrizMall[ i ][ j ].nombreLocal, newName ) ){
          printf( "Escribe el nuevo nombre del local\n" );
          scanf( "%s", matrizMall[ i ][ j ].nombreLocal );
          printf( "El nombre ha sido cambiado con exito\n" );
          return;
       }
     }
   }
  printf( "No hemos encontrado el local con el nombre que proporcionaste :C\n" );
   return;
 }
void eliminarLocal( local_t ** matrizMall, int numPiso, int numLocal ){
   int pis, loc;
   printf( "Ingresa el piso donde esta ubicado el local:\n" );
   scanf( "%d", &pis );
   printf( "Ingresa la ubicacion del local:\n" );
   scanf( "%d", &loc );
  
  matrizMall[ pis ][ loc ].status = DISPONIBLE;
  printf( "El local %s ha sido borrado exitosamente :)\n", matrizMall[ pis ][ loc ].nombreLocal);
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
  printf( "El numero de locales ocupados es %d\n", ocupados );
  }
 void localesLibres( local_t ** matrizMall, int numPiso, int numLocal ){
  int libres = 0, i, j;
  for( i = 0; i < numPiso; i++ ){
    for( j = 0; j < numPiso; j++ ){
      if ( matrizMall [ i ][ j ].status == DISPONIBLE ){
        libres += 1;
        
      }
    }
  }
  printf( "El numero de locales ocupados es %d\n", libres );
  }
