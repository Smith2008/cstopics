``` c
#include <stdio.h>
#include <stdlib.h>

int main(){
	char fileName[20];
	FILE *filePointer;

	//call1: mensaje de petición de archivo
	printf("Ingrese nombre del archivo a abrir: \n");
	//call2: lectura de nombre del archivo ingresado por teclado
	scanf("%19s", fileName);
	//call3: intentar abrir el archivo para lectura
	filePointer = fopen(fileName, "r");
	//verificar si el archivo existe
	if(filePointer != NULL){
		//el archivo existe
		//call4: mostrar en pantalla apertura exitosa
		printf("Apertura exitosa de %s \n", fileName);
		//call5: cerrar el archivo
		fclose(filePointer);
		//call6; terminar normalmente
		exit(EXIT_SUCCESS);
	}
	else{
		// el archivo no existe
		//call4: mostrar en pantalla el error
		printf("El archivo %s no existe \n", fileName);
		//call5: terminar de forma abrupta
		exit(EXIT_FAILURE);		
	}
}

```
