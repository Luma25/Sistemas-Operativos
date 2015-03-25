#include <stdio.h>
#include <string.h>


typedef struct 					//--------------------------------- defino la estructura de un libro
{
	char nombre[50];  //nombre del libro
	char tipo[50];    //que tipo de libro es
	int paginas;    //cuantas paginas tiene
	int posicion;   //en que posicion esta el libro
} libreria;

int cant=0;         //declaro variable global que lleva la cuenta de libros ingresados
libreria libros[50];   // defino la cantidad de libros que pueden haber: 50 espacios para libros

void imprimir_libro(libreria &book)    //--------------------------------- imprimir datos de libro
{
	printf( "Nombre : %s\n", book.nombre); //imprimo nombre
    printf( "Tipo : %s\n", book.tipo);   //imprimo tipo
    printf( "Paginas : %d\n", book.paginas); //imprimo paginas
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
}

void buscar_nombre(char *name)       //------------------------------- buscar por nombre
{
	for(int i=0; i<cant; i++)  //busco dentro de todas las posiciones
	{
		if(strcmp(libros[i].nombre,name)==0) //comparo el nombre buscado con el nombre del libro actual
		{
			imprimir_libro(libros[i]);  //imprimo datos del libro actual
		}
	}
}

void buscar_tipo(char *type)       //------------------------------- buscar por tipo
{
	for(int i=0; i<cant; i++)  //busco dentro de todas las posiciones
	{
		if(strcmp(libros[i].tipo,type)==0) //comparo el tipo buscado con el tipo del libro actual
		{
			imprimir_libro(libros[i]);  //imprimo datos del libro actual
		}
	}

}

void imprimir_todos()       //------------------------------- imprimir todos los libros
{
	for(int i=0; i<cant; i++)  //busco dentro de todas las posiciones
	{	
		printf("libro %d\n",i);
		imprimir_libro(libros[i]);  //imprimo datos del libro actual	
	}
}

void imprimir_posicion(int pos)       //------------------------------- imprimir el libro en la posicion deseada
{
	for(int i=0; i<cant; i++)  //busco dentro de todas las posiciones
	{	
		if(libros[i].posicion==pos)
		{
			imprimir_libro(libros[i]);  //imprimo datos del libro actual
		}	
	}
}


int main() //------------------------------------------------------ main
{
   int menu=0;   //defino variables auxiliares para trabajar en el menu
   char titulo[50];  
   char estilo[50];
   int pags;
   int position;

   while(1) // inicializo el menu
   {	
   	   printf("Buscar por nombre: 1\n"); //opciones para que el usuario elija lo que desee hacer
	   printf("Buscar por tipo: 2\n");
	   printf("imprimir todos los libros: 3\n");
	   printf("imprimir libro por posicion: 4\n");
	   printf("ingresar libro: 5\n");
	   printf("salir: 6\n");
	   printf("------> ");

	   scanf("%d",&menu); // recibo la opcion con la instruccion deseada del usuario

  	   if(menu==1)
  	   {
  	   		printf("nombre del libro a buscar: "); 
  	   		scanf("%s",titulo); //recibo nombre del libro a buscar
  	   		buscar_nombre(titulo); //llamo a la funcion buscar_nombre para efectuar la busqueda con el nombre ingresado como parametro
  	   }

  	   if(menu==2)
  	   {
  	   		printf("tipo del libro a buscar: ");
  	   		scanf("%s",estilo); //recbibo el tipo del libro a buscar
  	   		buscar_tipo(estilo); //llamo a la funcion buscar_tipo para efectuar la busqueda con el tipo ingresado como parametro
  	   }

  	   if(menu==3)
  	   {
  	   		imprimir_todos(); //llamo a la funcion imprimir_todos
  	   }

  	   if(menu==4)
  	   {
  	   		printf("posicion a buscar: ");
  	   		scanf("%d",&position); //recibo la posicion del libro a buscar
  	   		imprimir_posicion(position); //llamo a la funcion imprimir_posicion para efectuar la impresion del libro en la posicion ingresada, la que se entrega como parametro
  	   }

  	   if(menu==5) // se agrega un libro a la libreria
  	   {
  	   		printf("nombre del libro: ");
  	   		scanf("%s",titulo); //recibo el nombre del libro a ingresar
		    strcpy( libros[cant].nombre, titulo);  //almaceno el nombre del libro en la posicion cant

		    printf("tipo del libro: ");
		    scanf("%s",estilo); //recibo el tipo del libro a ingresar
 		    strcpy( libros[cant].tipo, estilo); //almaceno el tipo del libro  en la posicion cant

 		    printf("cantidad de paginas del libro: ");
 		    scanf("%d",&pags); //recibo la cantidad de paginas que tiene el libro a ingresar
 		    libros[cant].paginas = pags; //almaceno la cantidad de paginas del libro  en la posicion cant

   		    libros[cant].posicion = cant; //almaceno la posicion del libro en la cual fue ingresado (cant)
  	   		cant++; //aumento en 1 la variable global que almacena la cantidad de libros ingresados
  	   }

  	   if(menu==6)
  	   {
  	   		break; //termino el programa
  	   }
   }

   return 0;
}