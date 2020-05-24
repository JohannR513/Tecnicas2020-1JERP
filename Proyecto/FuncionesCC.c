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
    int piso, local, nEmpleados, nCat;
    do{
        printf( "======================================\n" );
        printf( "Si despues de digitar los datos te aparece nuevamente este menu es porque la posicion que elegiste no esta disponible :c\n" );
        printf( "Elige el piso:\n" );
        scanf( "%d", &piso );
        printf( "Elige el local:\n" );
        scanf( "%d", &local );
        piso --;
        local --;
        printf( "======================================\n" );

    }while ( ( piso > numPiso - 1 || local > numLocal - 1 ) || ( matrizMall [ piso ][ local ].status == OCUPADO ) );
    printf( "======================================\n" );
    printf( "Cual es el nombre del local?\n" );
    scanf( "%s", matrizMall[ piso ][ local ].nombreLocal );
    printf( "Cuantos empleados tiene el local?\n" );
    scanf( "%d", &nEmpleados );
    printf( "Que categoria tiene el local?\n1.Hogar\n2.Comida\n3.Tecnologia\n4.Vestuario\n" );
    scanf( "%d", &nCat );
    if( nCat == 1 ){
    matrizMall[ piso ][ local ].category = HOGAR;
    }
    if( nCat == 2 ){
    matrizMall[ piso ][ local ].category = COMIDA;
    }
    if( nCat == 3 ){
    matrizMall[ piso ][ local ].category = TECNOLOGIA;
    }
    if( nCat == 4 ){
    matrizMall[ piso ][ local ].category = VESTUARIO;
    }
    matrizMall[ piso ][ local ].numEmpleados = nEmpleados;
    matrizMall[ piso ][ local ].status = OCUPADO;
    matrizMall[ piso ][ local ].idLocal = rand() % 10000;
    matrizMall[ piso ][ local ].pisoLocal = piso;
    matrizMall[ piso ][ local ].numLocalxPiso = local;
    printf( "El local %s fue agregado exitosamente :)\n", matrizMall[ piso ][ local ].nombreLocal  );
    printf( "======================================\n" );
    
    }
  
void listarLocales( local_t ** matrizMall, int numPiso, int numLocal ){
   int i, j;
   for( i = 0; i < numPiso; i ++ ){
     for( j = 0; j < numPiso; j ++ ){
       if ( matrizMall[ i ][ j ].status == OCUPADO ){
         printf( "======================================\n" );
         printf( "Nombre: %s\n",matrizMall[ i ][ j ].nombreLocal );
         printf( "Id: %d \n",matrizMall[ i ][ j ].idLocal );
         printf( "Piso: %d\n",matrizMall[ i ][ j ].pisoLocal + 1 );
         printf( "Local: %d\n",matrizMall[ i ][ j ].numLocalxPiso + 1 );
         printf( "Numero de empleados: %d\n",matrizMall[ i ][ j ].numEmpleados );
         if( matrizMall[ i ][ j ].category == HOGAR ){
           printf( "Categoria: Hogar\n" );
         }
         if( matrizMall[ i ][ j ].category == COMIDA ){
           printf( "Categoria: Comida\n" );
         }
         if( matrizMall[ i ][ j ].category == TECNOLOGIA ){
           printf( "Categoria: Tecnologia\n" );
         }
         if( matrizMall[ i ][ j ].category == VESTUARIO ){
           printf( "Categoria: Vestuario\n" );
         }
         printf( "======================================\n" );
     }
   }
  }
 }

local_t* buscarPorNombre( local_t **matrizMall, int numPiso, int numLocal ){
   char search[35];
    printf("Nombre del local: ");
    scanf("%s", search);

    
    int i, j;
    for ( i = 0; i < numPiso; i++ ){
        for ( j = 0; j < numLocal; j++ ){
            if ( !strcmp( matrizMall[ i ][ j ].nombreLocal, search ) ){
                printf( "======================================\n" );
                printf( "Id: %d \n",matrizMall[ i ][ j ].idLocal );
                printf( "Piso: %d\n",matrizMall[ i ][ j ].pisoLocal + 1 );
                printf( "Local: %d\n",matrizMall[ i ][ j ].numLocalxPiso + 1 );
                printf( "Numero de empleados: %d\n",matrizMall[ i ][ j ].numEmpleados );
                if( matrizMall[ i ][ j ].category == HOGAR ){
                  printf( "Categoria: Hogar\n" );
                  }
                if( matrizMall[ i ][ j ].category == COMIDA ){
                  printf( "Categoria: Comida\n" );
                  }
                if( matrizMall[ i ][ j ].category == TECNOLOGIA ){
                  printf( "Categoria: Tecnologia\n" );
                  }
                if( matrizMall[ i ][ j ].category == VESTUARIO ){
                  printf( "Categoria: Vestuario\n" );
                  }
                printf( "======================================\n" );
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
       if( matrizMall[ i ][ j ].idLocal == search ){
         printf( "======================================\n" );
         printf("Nombre: %s\nPiso: %d\nLocal: %d\nNumero de empleados: %d\n", matrizMall[ i ][ j ].nombreLocal, matrizMall[ i ][ j ].pisoLocal + 1, matrizMall[ i ][ j ].numLocalxPiso + 1, matrizMall[ i ][ j ].numEmpleados );
         if( matrizMall[ i ][ j ].category == HOGAR ){
                  printf( "Categoria: Hogar\n" );
                  }
                if( matrizMall[ i ][ j ].category == COMIDA ){
                  printf( "Categoria: Comida\n" );
                  }
                if( matrizMall[ i ][ j ].category == TECNOLOGIA ){
                  printf( "Categoria: Tecnologia\n" );
                  }
                if( matrizMall[ i ][ j ].category == VESTUARIO ){
                  printf( "Categoria: Vestuario\n" );
                  }
          printf( "======================================\n" );
       }
     }
   }

   return NULL;
 }

void cambiarNombreLocal( local_t ** matrizMall, int numPiso, int numLocal ){
  int i, j;
  char newName[ 35 ];
  printf( "======================================\n" );
  printf( "Ingresa el nombre del local que deseas cambiarle el nombre:\n" );
  scanf( "%s", newName );
  for( i = 0; i < numPiso; i++ ){
    for( j = 0; j < numPiso; j++ ){
      if( !strcmp ( matrizMall[ i ][ j ].nombreLocal, newName ) ){
        printf( "Escribe el nuevo nombre del local\n" );
        scanf( "%s", matrizMall[ i ][ j ].nombreLocal );
        printf( "El nombre ha sido cambiado con exito\n" );
        printf( "======================================\n" );
        return;
       }
     }
   }
  printf( "No hemos encontrado el local con el nombre que proporcionaste :C\n" );
   return;
 }

void eliminarLocal( local_t ** matrizMall, int numPiso, int numLocal ){
   int pis, loc;
   printf( "======================================\n" );
   printf( "Ingresa el piso donde esta ubicado el local:\n" );
   scanf( "%d", &pis );
   printf( "Ingresa la ubicacion del local:\n" );
   scanf( "%d", &loc );
  pis--;
  loc--;
  matrizMall[ pis ][ loc ].status = DISPONIBLE;
  printf( "El local %s ha sido borrado exitosamente :)\n", matrizMall[ pis ][ loc ].nombreLocal );
  printf( "======================================\n" );
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
  printf( "======================================\n" );
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
  printf( "El numero de locales disponibles es %d\n", libres );
  printf( "======================================\n" );
  }

void selectionsort(int arr[],int n){
  int min=0;
  for(register int i=0;i<n;i++)
  {
    min=i;
    for(register int j=i;j<n;j++)
    {
      if(arr[min]>arr[j])
      {
        min=j;
      }
    }
    //swap
    int temp = arr[i];
    arr[i] =arr[min];
    arr[min]=temp;
  }
}

void ordenarPorNumEMpleados( local_t ** matrizMall, int      numPiso, int numLocal ){
   int n = numLocal, search, i, k;
   int arr[ n ];
   
   printf( "Ingrese el numero de piso para mostrar locales en ese piso:\n");
   scanf( "%d",&search );
   search -= 1 ;
   for(i=0;i<numPiso;i++){
    for( k = 0; k < numPiso; k ++){
      arr[ k + i ]= matrizMall [ search ][ i ].numEmpleados;
    }
    }
  selectionsort( arr,n );
  printf( "Estos son la cantidad de empleados por local:\n" );
  for( register int i = 0; i < n; i++ )
  {
    printf( "%d ",arr[ i ] );
  }
  printf( "\n" );
    return;
}
