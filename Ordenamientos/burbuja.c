#include<stdio.h>

#define SIZE 5


void mostrarLista(int *);

int main( int argc, char** argv ){

	int lista[ SIZE ]= { 5, 2, 4, 1, 3 };
	int n, l = SIZE , i, temp;

	mostrarLista( lista );


	do{
		n = 0;
		//Recorrer la lista
		for( i = 1; i < l ; i++ ){
			//Verificar si los dos valores estan ordenados
			if( *( lista + i - 1 ) > *( lista + i ) ){
				//Ordenar si es necesario
				temp =*( lista + i - 1 );
				*( lista + i - 1 ) =*( lista + i );
				*( lista + i ) = temp;
				n = i;
				mostrarLista( lista );
			}
		}
		l = n;
	}	while( n != 0 );
	
}

//Función para mostrar estado de la lista

void mostrarLista( int *a ){
  int i;
  for( i = 0; i < SIZE ; i++ ) printf( "\t[ %d ] ", *( a + i ) );
  printf( "\n" );
}