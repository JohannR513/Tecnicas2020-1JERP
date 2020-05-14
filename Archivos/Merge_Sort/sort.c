#include<stdio.h>

int arr[ 20 ]; // Arreglo que sera ordenado

int merge( int arr[ ], int l, int m,int h ){
int arr1[ 10 ], arr2[ 10 ]; // Dos matrices temporales para almacenar las dos matrices que se combinaran
int n1, n2, i, j, k;
n1 = m - l + 1;
n2 = h - m;

for( i = 0; i < n1; i++ )
	arr1[ i ] = arr[ l + i ];
for( j = 0; j < n2; j++ )
	arr2[ j ] = arr[ m + j + 1 ];

	arr1[ i ] = 9999; // Indica el final de cada matriz temporal
	arr2[ j ] = 9999;

	i = 0;
	j = 0;
	for( k = l; k <= h; k++ ) { //Proceso para combinar los dos arreglos
		if( arr1[ i ] <= arr2[ j ] )
			arr[ k ] = arr1[ i++ ];
		else
			arr[ k ] = arr2[ j++ ];
}
	return 0;
}

int merge_sort( int arr[ ], int low, int high ){
int mid;
	if( low < high ){
		mid = ( low + high ) / 2;
// Divide y venceras
		merge_sort( arr, low, mid );
		merge_sort( arr, mid+1, high );

// Combina
		merge( arr, low, mid, high );
}

return 0;
}

int main(){
int n, i;

printf( "Ingresa el tamaño del arreglo\n" ); 
scanf( "%d", &n );
printf("Ingresa los elementos:\n" );
for( i = 0; i < n; i++ ) 
	scanf( "%d", &arr[ i ] );
printf( "Arreglo ordenado:\n" ); // Imprime el arreglo ordenado
for( i = 0; i < n; i++ )
	printf( "%d ", arr[ i ] );
merge_sort( arr, 0, n - 1 ); // Ordena el arreglo
FILE * pFile = fopen( "selection10.dat", "wb" );
    fwrite( arr, sizeof( int ), i, pFile );
    fclose( pFile );
	return 0;
return 0;
}