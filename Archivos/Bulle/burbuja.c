#include<stdio.h>
#include <stdlib.h>


void lireArrangement( FILE * flujo, int tailleArrangement ){
	int array [ tailleArrangement ];
    int n, l = tailleArrangement , i, temp;
	fread( array, sizeof( int ), tailleArrangement, flujo );
	fclose( flujo );
	printf( "Leyendo el archivo\n" );
	do{
		n = 0;
		//Recorrer la lista
		for( i = 1; i < tailleArrangement ; i++ ){
			//Verificar si los dos valores estan ordenados
			if( *( array + i - 1 ) > *( array + i ) ){
				//Ordenar si es necesario
				temp =*( array + i - 1 );
				*( array + i - 1 ) =*( array + i );
				*( array + i ) = temp;
				n = i;
				
			}
		}
		l = n;
	}	while( n != 0 );
  for ( temp = 0; temp < tailleArrangement; temp++ ){
    printf( "Arreglo en la posicion %d con valor %d\n", temp, array[ temp ] );
  }
   FILE * pFile = fopen( "10000burbuja.dat", "wb" );
    fwrite( array, sizeof( int ), tailleArrangement, pFile );
    fclose(pFile);
}
int main(){
	FILE * flujo = fopen ("10000datos.dat", "rb" );
	lireArrangement( flujo, 10000 );
	return 0;
}

//Función para mostrar estado de la lista

