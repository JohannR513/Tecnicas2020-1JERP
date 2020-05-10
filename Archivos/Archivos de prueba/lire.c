#include <stdio.h>
#include <stdlib.h>

void lireArrangement( FILE * flujo, int tailleArrangement ){
	int array [ tailleArrangement ];
	fread( array, sizeof( int ), tailleArrangement, flujo );
	fclose( flujo );
	printf( "Leyendo el archivo\n" );
	for (int i =0 ; i < tailleArrangement; i++ ){
		printf( "Arreglo en la posicion %d con valor %d\n", i, array[ i ] );
	}
}

int main(){
	FILE * flujo = fopen ("1000000datos.dat", "rb" );
	lireArrangement( flujo, 1000000 );
	return 0;
}