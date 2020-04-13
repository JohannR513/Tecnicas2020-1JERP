#include "FuncionesCC.h"

/*Esta funcion se encarga de crear la matriz que representara al centro comercial
*utilizando memoria dinamica
*/
local_t** reservarMemoria(int numPiso, int numLocal){
    local_t** matrizMall = malloc( sizeof( local_t* ) * numPiso ); 
    for( int i = 0; i < numPiso; i++){
        matrizMall[i] = malloc( sizeof( local_t ) * numLocal );
        for ( int j = 0; j < numLocal; j++ )
            
            matrizMall[ i ][ j ].idLocal = 0;
    }
    return matrizMall;
}

/*Esta funcion se encarga de pedirle al usuario la ubicacion donde quiere su local
*/
void ingresarLocal( local_t**matrizMall, int numPiso, int numLocal ){
    int nPiso, nLocal;
    while(1){
        printf( "En que piso quieres ubicar el local?\n" );
        scanf( "%d", &nPiso );
        printf( "En que parte del piso quieres el local?\n" );
        scanf( "%d", nLocal );

        nPiso--;
        nLocal--;
        //Despues de haber pedido la ubicacion debera revisar que elespacio este disponible
         if( nPiso >= numPiso || nLocal >= numLocal){
            printf( "Esta ubicacion no pertenece al centro comercial" );
        }
        else if ( matrizMall[ nPiso ][ nLocal ].status == 1){
            printf( "El local esta ocupado" ); 
        }
    }
    //Cuando ha encontrado un lugar disponible el usuario debe darle un nombre y el id se le asigna con la funcion rand
    printf( "Cual es el nombre del local?:\n" );
    scanf( "%s", punt-> nombreLocal ); 
    punt->idLocal = idLocal;
    punt->idLocal = rand () % (N-M+1) + M;
    punt->status = 1;
}

//Esta funcion se encarga de listar los locales del edificio
void listarLocales( local_t**matrizMall, int numPiso, int numLocal ){
    for( int i = 0; i < numPiso; i++){
        for( int j = 0; j < numLocal; i++ ){
            printf( "%s, %d, %d, %d", matrizMall[ i ][ j ].nombreLocal, matrizMall[ i ][ j ].idLocal, 
            matrizMall[ i ][ j ].pisoLocal, matrizMall[ i ][ j ].numLocalxPiso );
        }
    }
}

/*Esta funcion se encarga de buscar un local por un nombre suministrado por el usuario
*/
void buscarLocalNombre( local_t**matrizMall, int numPiso, int numLocal ){
    char nombre[35];
    printf( "Escribe el nombre del local:\n" );
    scanf( "%s", &nombre);
    for( int i = 0; i < numPiso; i++){
        for( int j = 0; j < numLocal; j++ ){
            /*Si depues de hacer el recorrido el nombre ingresado esta en la matriz se imprimira
            *en pantalla la informacion
            */
            if( !strcmp( matrizMall[ i ][ j ].nombreLocal, nombre ) ){
                printf( "Almacen: %s\n Identificador: %d\n Piso: %d\n", matrizMall[ i ][ j ].nombreLocal,
                         matrizMall[ i ][ j ].idLocal, matrizMall[ i ][ j ].pisoLocal );
            }
        }
    }
    //de no ser asi el programa te indicara que el nombre ingresado no existe
    if( matrizMall[ i ][ j ] == 0 ){
                     printf( "%s no existe sorry\n", nombre );
                  }
}
//Esta funcion es como la anterior solo que esta lo busca usando el identificador del local
void buscarLocalxID( local_t**matrizMall, int numPiso, int numLocal ){
    int id;
    printf( "Escribe el identificador del local: \n" );
    scanf( "%d", &idLocal );
    for( int i = 0; i < numPiso; i++){
        for( int j = 0; j < numLocal; i++){
            //compara a ver si la informacion suministrada se encuentra en la matriz
            if( matrizMall[ i ][ j ].idLocal == id){
                printf( "Almacen: %s\n Piso: %d\n", matrizMall[ i ][ j ].nombreLocal,
                         matrizMall[ i ][ j ].pisoLocal );
            }
        }
    }
    if( matrizMall[ i ][ j ] == 0 ){
        printf( "El codigo %d no existe sorry\n", id );
        }
}   `
//esta funcion se encarga de cambiar el nombre de un local
void cambiarNombre( local_t**matrizMall, int numPiso, int numLocal ){
    char nombre[35];
    printf( "Escribe el nombre del local:\n" );
    scanf( "%s", &nombre);
    /*El usuario debe escribir el nombre del local al que se le cambiara el nombre
    *si lo encuentra entonces podra darle un nombre nuevo
    */
    for( int i = 0; i < numPiso; i++ ){
        for( int j = 0; j < numLocal; j++ ){
          if( !strcmp( matrizMall[ i ][ j ].nombreLocal, nombre ) ){
              char newName[ 35 ];
              printf( "Escribe el nuevo nombre:\n " );
              scanf( "%s", newName );
              strcpy( punt->nombreLocal, newName ) ;
          }  
        }
    }
    //Si no pudo encontrar el local el programa le avisara 
    if( matrizMall[ i ][ j ] == 0 ){
        printf( "%s no existe sorry\n", nombre );
     }  
}
//Esta funcion debera "eliminar" un local, esto quiere decir que su estado pasara a estar desocupado
void eliminar( local_t**matrizMall, int numPiso, int numLocal ){
    int nPiso, nLocal;//Variables para que el usuario de la ubicacion
    while(1){
        printf( "Piso donde esta ubicado:\n " );
        scanf( "%d", &nPiso );
        printf( "Ubicacion del local:\n " );
        scanf("%d", &nLocal);

        nPiso--;//Indices
        nLocal--;
        //Se encarga de verificar que el valor ingresado este en la matriz
        if( nPiso >= numPiso || nLocal >= numLocal){
            printf( "Esta ubicacion no pertenece al centro comercial" );
        }
        //este verifica que el estado sea 1, si es 0 quiere decir que ya esta desocupado
        else if ( matrizMall[ nPiso ][ nLocal ].status == 0){
            printf( "El local esta desocupado" ); 
        }
    }
    //Si los datos ingresados por el usuario eran correctos entonces el estado del local pasara a desocupado
     matrizMall[ nPiso ][ nLocal ].status = 0;
}