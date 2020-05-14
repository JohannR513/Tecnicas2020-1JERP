#include <stdio.h>
#include <stdlib.h>

void sauvegarderArrangement( FILE * flujo, int tailleArrangement ){
	int array[ tailleArrangement  ], num;
	for ( int i = 0; i < tailleArrangement ; i++ ){
		num = rand() % 20000;
		array[ i ] = num;
	}
	fwrite( array, sizeof( int ), tailleArrangement , flujo );
	fclose( flujo );
}
int main(){
	FILE * flujo = fopen( "1000000datos.dat", "wb" );
	sauvegarderArrangement( flujo, 100000 );

	return 0;
}