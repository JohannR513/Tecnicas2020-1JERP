#include <stdio.h>

int selection_sort( FILE * flujo, int tailleArrangement ){
int array [ tailleArrangement ], n;
	fread( array, sizeof( int ), tailleArrangement, flujo );
	fclose( flujo );
  printf("Leyendo arreglo de archivo\n");
	--tailleArrangement; /* considering that n is the real size of elements */

	if (tailleArrangement < 1){
		return -1;
  }

	for (int i = 0; i < tailleArrangement - 1; ++i) {
		int min = i;

		/* find next smallest */
		for (int j = i + 1; j <= tailleArrangement; ++j)
			if (array[j] < array[min])
				min = j;

		/* swap smallest with current value */
		if (min != i) {
			int tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
	}
 for ( n = 0; n < tailleArrangement; n++){
        printf("Arreglo en posicion %d ordenado %d\n",n,array[n]);

    }
    FILE * pFile = fopen( "selection10000.dat", "wb" );
    fwrite( array, sizeof( int ), tailleArrangement, pFile );
    fclose( pFile );
	return 0;
}


int main( ){
    FILE * flujo = fopen( "10000datos.dat", "rb" );
    selection_sort( flujo, 10000 );

	return 0;
} 