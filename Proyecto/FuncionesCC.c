#include "FuncionesCC.h"

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