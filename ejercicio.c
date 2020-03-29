#include <stdio.h>
#define FILAS 12
#define COLUMNAS 5

typedef struct persona{
   char nombre[ 15 ];
   int diaNacimiento, mesNacimiento, anhoNacimiento; 

} persona;

int menu( ){
   int opcion;

   printf( "Bienvenido\n" );
   printf( "Que deseas hacer?\n" );
   printf( "==========================\n" );
   printf( "1 Agregar un usuario\n" );
   printf( "2 Buscar por mes de nacimiento\n" );
   printf( "0 Salir\n" );
   scanf( "%d", &opcion );

   return opcion;
}

int main ( ){
	int mesNacimiento, i, j, opcion, col = 0; 
	char nombre[ 15 ];
  persona temp, personas [ FILAS ][ COLUMNAS ];
    
  typedef enum meses{
	   ENERO = 1,
	   FEBRERO = 2,
	   MARZO = 3,
	   ABRIL = 4,
	   MAYO = 5,
	   JUNIO = 6,
	   JULIO = 7,
	   AGOSTO = 8,
	   SEPTIEMBRE = 9,
	   OCTUBRE = 10,
	   NOVIEMBRE = 11,
	   DICIEMBRE = 12
} mesesitos;
	opcion = menu;
	switch ( opcion ){
		case 1 :fflush ( stdin );
            printf( "Ingresa el mes de nacimiento:\n" ); scanf("%d",&mesNacimiento);
            if ( mesNacimiento == 1 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf("%d",&personas[ ENERO ][ col++ ].diaNacimiento); 
              printf( "Ingresa el año de nacimiento:\n" ); scanf("%d",&personas[ ENERO ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ ENERO ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ ENERO ][ col ].nombre,personas[ ENERO ][ col -1].anhoNacimiento, personas[ ENERO ][ 0 ].diaNacimiento );
            } 
            if ( mesNacimiento == 2 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ FEBRERO ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ FEBRERO ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ FEBRERO ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ FEBRERO ][ col ].nombre,personas[ FEBRERO ][ col -1].anhoNacimiento, personas[ FEBRERO ][ 0 ].diaNacimiento ); 
            } 
            if ( mesNacimiento == 3 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ MARZO ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ MARZO ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ MARZO ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ MARZO ][ col ].nombre,personas[ MARZO ][ col -1].anhoNacimiento, personas[ MARZO ][ 0 ].diaNacimiento );
            } 
            if ( mesNacimiento == 4 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ ABRIL ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ ABRIL ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ ABRIL ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ ABRIL ][ col ].nombre,personas[ ABRIL ][ col -1].anhoNacimiento, personas[ ABRIL ][ 0 ].diaNacimiento );
            } 
            if ( mesNacimiento == 5 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ MAYO ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ MAYO ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ MAYO ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ MAYO ][ col ].nombre,personas[ MAYO ][ col -1].anhoNacimiento, personas[ MAYO ][ 0 ].diaNacimiento );
            } 
            if ( mesNacimiento == 6 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ JUNIO ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ JUNIO ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ JUNIO ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ JUNIO ][ col ].nombre,personas[ JUNIO ][ col -1].anhoNacimiento, personas[ JUNIO ][ 0 ].diaNacimiento );
            }
            if ( mesNacimiento == 7 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ JULIO ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ JULIO ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ JULIO ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ JULIO ][ col ].nombre,personas[ JULIO ][ col -1].anhoNacimiento, personas[ JULIO ][ 0 ].diaNacimiento );
            }
            if ( mesNacimiento == 8 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ AGOSTO ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ AGOSTO ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ AGOSTO ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ AGOSTO ][ col ].nombre,personas[ AGOSTO ][ col -1].anhoNacimiento, personas[ AGOSTO ][ 0 ].diaNacimiento );
            }
            if ( mesNacimiento == 9 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ SEPTIEMBRE ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ SEPTIEMBRE ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ SEPTIEMBRE ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ SEPTIEMBRE ][ col ].nombre,personas[ SEPTIEMBRE ][ col -1].anhoNacimiento, personas[ SEPTIEMBRE ][ 0 ].diaNacimiento );
            }
            if ( mesNacimiento == 10 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ OCTUBRE ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ OCTUBRE ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ OCTUBRE ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ OCTUBRE ][ col ].nombre,personas[ OCTUBRE ][ col -1].anhoNacimiento, personas[ OCTUBRE ][ 0 ].diaNacimiento );
            }
            if ( mesNacimiento == 11 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ NOVIEMBRE ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ NOVIEMBRE ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ NOVIEMBRE ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ NOVIEMBRE ][ col ].nombre,personas[ NOVIEMBRE ][ col -1].anhoNacimiento, personas[ NOVIEMBRE ][ 0 ].diaNacimiento );
            }
            if ( mesNacimiento == 12 ){
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d",&personas[ DICIEMBRE ][ col++ ].diaNacimiento ); 
              printf( "Ingresa el dia de nacimiento:\n" ); scanf( "%d", &personas[ DICIEMBRE ][ col++ ].anhoNacimiento);
              printf( "Ingresa el nombre:\n" ); scanf("%s", personas[ DICIEMBRE ][ col ].nombre);
              printf( "[Nombre: %s,Año: %d, Dia: %d] fue agregado exitosamente\n", 
              personas[ DICIEMBRE ][ col ].nombre,personas[ DICIEMBRE ][ col -1].anhoNacimiento, personas[ DICIEMBRE ][ 0 ].diaNacimiento );
            }
            
            
            
            
		      break;
    case 0: break;      
}
}