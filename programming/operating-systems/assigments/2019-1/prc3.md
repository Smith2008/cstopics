---
layout: default
title: Práctica 3
permalink: /programming/operating-systems/assigments/2019-1/prc3
---

# Práctica 2

Debe escribir en C/C++, un servidor que ofrezca servicios de *cálculo avanzado* a otros procesos.

### Suscripción

Cuando otro proceso quiera utilizar los servicios que el proceso servidor ofrece, el primero se debe **suscribir** al segundo a través de un bloque de memoria compartida que el servidor crea, llamada *SHMEM_MATH_SERVER_SUBSCRIPTION*.

Dicha memoria compartida se crea cuando el servidor inicia, siempre y cuando no exista previamente, esto implica que no pueden ser ejecutados dos servidores, y éste debe ser capaz de detectar si existe otro corriendo, mostrar el error, y abortar:

``` bash
$ ./math_server
Iniciando servidor matemático...
ERROR: Ya existe un servidor ejecutándose.
```

Si el servidor logra ser iniciado correctamente, se debe crear la memoria compartida, y ésta se debe volver a eliminar al cerrar el programa con *Ctrl+C*.

La memoria compartida tiene la siguiente distribución:

***Memoria compartida***



Revisar si ya existe dicha tubería en las suscritas.
Revisar si la tubería existe.
Revisar si el nombre de la tubería termina en \0


### Entrega
