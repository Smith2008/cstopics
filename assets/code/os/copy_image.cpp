#include <iostream>
#include <stdio.h>
#include "Image.h"

int main(int argc, char** argv){
	// Objetos de la clase Image
	Image myImage, newImage;
	// Nombre de archivos de entrada y salida
	char *in_path = "./lenas.pgm";
	char *out_path = "./lena2.pgm";
	// Lectura de imagen
	if(myImage.fromFile(in_path) == -1){
		printf("Error al leer la imagen.\n");
		exit(1);
	}
	// Creación de imagen de salida
	newImage = Image(myImage.width, myImage.height);
	// Copia de la imagen original
	memcpy(newImage.data, myImage.data, myImage.width*myImage.height);
	// Escritura de nuevo archivo
	if(newImage.toFile(out_path)){
	  	printf("Error al escribir la imagen.\n");
		exit(1);
	}
	exit(0);
}