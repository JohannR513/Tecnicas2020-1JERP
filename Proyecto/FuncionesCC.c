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
    int piso, local, nEmpleados, nCat, nInventario, nEmTurno;
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
    printf( "Cuantos elementos hay en el inventario?\n" );
    scanf( "%d", &nInventario );
    printf( "Cuantos empleados hay en turno?\n" );
    scanf( "%d", &nEmTurno );
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
    matrizMall[ piso ][ local ].empleadosEnTurno = nEmTurno;
    matrizMall[ piso ][ local ].elementosInventario = nInventario;
    matrizMall[ piso ][ local ].status = OCUPADO;
    matrizMall[ piso ][ local ].idLocal = rand() % 10000;
    matrizMall[ piso ][ local ].ventasSemanales = rand() % 200;
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
         printf( "Ventas semanales: %d\n",matrizMall[ i ][ j ].ventasSemanales );
         printf( "Empleados en turno: %d\n", matrizMall[ i ][ j ].empleadosEnTurno );
         printf( "Elementos en el inventario: %d\n", matrizMall[ i ][ j ].elementosInventario );
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
                printf( "Ventas semanales: %d\n",matrizMall[ i ][ j ].ventasSemanales );
                printf( "Numero de empleados en turno: %d\n",matrizMall[ i ][ j ].empleadosEnTurno );
                printf( "Numero de elementos en el inventario: %d\n",matrizMall[ i ][ j ].elementosInventario );
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
         printf("Nombre: %s\nPiso: %d\nLocal: %d\nNumero de empleados: %d\nVentas semanales :%d\nEmpleados en turno: %d\nElementos en el inventario: %d\n", matrizMall[ i ][ j ].nombreLocal, matrizMall[ i ][ j ].pisoLocal + 1, matrizMall[ i ][ j ].numLocalxPiso + 1, matrizMall[ i ][ j ].numEmpleados, matrizMall[ i ][ j ].ventasSemanales, matrizMall[ i ][ j ].empleadosEnTurno, matrizMall[ i ][ j ].elementosInventario );
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

void selectionsort( int arr[],int n ){
  int min = 0;
  for( register int i = 0; i < n ; i++ ){
    min = i;
    for( register int j = i; j < n; j++ ){
      if( arr[ min ] > arr [ j ] ){
        min = j;
      }
    }
  
    int temp = arr[ i ];
    arr[ i ] = arr[ min ];
    arr[min]=temp;
  }
}

void ordenarPorNumEMpleados( local_t ** matrizMall, int      numPiso, int numLocal ){
   int n = numLocal, search, i, k;
   int arr[ 100 ];
   
	 printf( "Ingrese el numero del piso para ver los locales:\n" );
   scanf( "%d", &search );
	 search -= 1 ;
	 for( i = 0; i < numPiso ; i++ ){
    for( k = 0; k < numPiso; k ++ ){
      arr[ k + i ]= matrizMall [ search ][ i ].numEmpleados;
     }
    }
  selectionsort( arr,n );
  printf( "Estos son la cantidad de empleados por local:\n" );

  for( register int i = 0; i < n; i++ ){
    printf( "%d ",arr[ i ] );
  }
  printf( "\n" );
    return;
}

int merge( int arr[], int l, int m, int h ){
  int arr1[ 10 ], arr2[ 10 ];  
  int n1, n2, i, j, k;
  n1 = m - l + 1;
  n2 = h - m;

  for( i = 0; i < n1 ; i++ )
    arr1[ i ] = arr[ l + i ];
  for( j = 0; j < n2 ; j++ )
    arr2[ j ] = arr[ m + j + 1 ];

  arr1[ i ] = 9999;  // To mark the end of each temporary array
  arr2[ j ] = 9999;

  i = 0; j = 0;
  for( k = l ; k <= h ; k++ ){
    if( arr1[ i ] <= arr2[ j ] )
      arr[ k ] = arr1[ i++ ];
    else
      arr[ k ] = arr2[ j++ ];
  }
  
  return 0;
}
int merge_sort( int arr[], int low, int high ){
  int mid;
  if( low < high ){
    mid =( low + high )/2;
   // Divide and Conquer
    merge_sort( arr, low, mid );
    merge_sort( arr, mid + 1, high );
   // Combine
    merge( arr, low, mid, high );
  }
  
  return 0;
}
void ordenarPorVentas( local_t ** matrizMall, int numPiso, int numLocal ){
  int n = numLocal, search, i, k;
   int arr[ 100 ];
   
	 printf( "Ingrese el numero del piso para ver los locales:\n" );
   scanf( "%d",&search );
	 search -= 1 ;
	 for( i = 0; i < numPiso ; i++ ){
    for( k = 0; k < numPiso; k ++ ){
      arr[ k + i ]= matrizMall [ search ][ i ].ventasSemanales;
     }
    }
  
  merge_sort( arr, 0 , n - 1 );  
  
  printf( "Esta es la cantidad de ventas por local:\n" );  
  
  for( register int i = 0; i < n; i++ ){
    printf( "%d ",arr[ i ] );
  }
  printf( "\n" );
    
  return;
}

void insertionSort( int v[], int n ) { 
    int i, key, j; 
    for ( i = 1; i < n; i++ ){ 
        key = v[ i ]; 
        j = i - 1; 
  
       
        while ( j >= 0 && v[ j ] > key ){ 
            v[ j + 1 ] = v[ j ]; 
            j = j - 1; 
        } 
        v[ j + 1 ] = key; 
    }
     printf( "Esta es la cantidad de elementos en el inventario por local:\n" );  
  
  for( register int i = 0; i < n; i++ ){
    printf( "%d ",v[ i ] );
  }
  printf( "\n" );
} 
void ordenarPorInventario( local_t ** matrizMall, int numPiso, int numLocal ){
  int n = numLocal, search, i, k;
   int v[ 100 ];
   
	 printf( "Ingrese el numero del piso para ver los locales:\n" );
   scanf( "%d",&search );
	 search -= 1 ;
	 for( i = 0; i < numPiso ; i++ ){
    for( k = 0; k < numPiso; k ++ ){
      v[ k + i ]= matrizMall [ search ][ i ].elementosInventario;
     }
    }
  insertionSort(v, n); 
}

void quicksort( int *target, int left, int right ){
  if( left >= right ) 
  return;
  int i = left, j = right;
  int tmp, pivot = target[ i ];
  for(;;) {
    while( target[ i ] < pivot) i++;
    while(pivot < target[ j ]) j--;
    if(i >= j) break;
    tmp = target[ i ]; target[ i ] = target[ j ]; target[ j ] = tmp;
    i++; j--;
  }
  quicksort( target, left, i - 1 );
  quicksort( target, j+1, right );
}

void ordenarPorEmpleadosTurno( local_t ** matrizMall, int numPiso, int numLocal ){
int n = numLocal, search, i, k;
   int array[ 100 ];
   
	 printf( "Ingrese el numero del piso para ver los locales:\n" );
   scanf( "%d",&search );
	 search -= 1 ;
	 for( i = 0; i < numPiso ; i++ ){
    for( k = 0; k < numPiso; k ++ ){
      array[ k + i ]= matrizMall [ search ][ i ].empleadosEnTurno;
     }
    }
    quicksort(array, 0, n-1);

  printf( "Esta es la cantidad de empleados en turno por local:\n" );  
  
  for( register int i = 0; i < n; i++ ){
    printf( "%d ",array[ i ] );
  }
  printf( "\n" );
}
