---
layout: default
title: Práctica 3
permalink: /programming/operating-systems/assigments/2019-1/prc3
---

# Práctica 2

Debe escribir en C/C++, un servidor que ofrezca servicios de *cálculo avanzado* a otros procesos.

## Suscripción

Cuando otro proceso quiera utilizar los servicios que el proceso servidor ofrece, el primero se debe **suscribir** al segundo a través de un bloque de memoria compartida que el servidor crea, llamada *SHMEM_MATH_SERVER_SUBSCRIPTION*.

Dicha memoria compartida se crea cuando el servidor inicia, siempre y cuando no exista previamente, esto implica que no pueden ser ejecutados dos servidores, y éste debe ser capaz de detectar si existe otro corriendo, mostrar el error, y abortar (la [P] quiere decir que el mensaje lo muestra el hilo principal):

``` bash
$ ./math_server
[P] Iniciando servidor matemático...
[P] ERROR: Ya existe un servidor ejecutándose.
```

Si el servidor logra ser iniciado correctamente, se debe crear la memoria compartida, y ésta se debe volver a eliminar al cerrar el programa con *Ctrl+C*.

La memoria compartida tiene la siguiente distribución:

***Memoria compartida***

| *unsigned char* | Bandera de suscripción |
| *char[81]* | Espacio para nombre de la tubería a suscribir |
| *unsigned char* | Bandera de resultado de suscripción |

Cuando el servidor arranque, éste debe inicializar la *Bandera de suscripción* en 0, el cual significa que ningún proceso se quiere suscribir. A continuación se quedar esperando suscripciones:

``` bash
$ ./math_server
[P] Iniciando servidor matemático...
[P] Esperando suscripciones...
```

El proceso que debe seguir otro proceso para suscribirse, es escribir el path de la tubería (previamente creada), de máximo 80 carácteres, en el *Espacio para nombre de la tubería a suscribir*, iniciar la *Bandera de resultado de suscripción* en 0 para evitar leer resultados de suscripciones previas, y poner la *Bandera de suscripción* en 1.

Cuando el servidor recibe la *Bandera de suscripción* en alto, confirma que el *Espacio para nombre de la tubería a suscribir* contiene una cadena válida (es decir, contiene al menos un \0), y que dicha tubería existe, si alguna de las dos condiciones no existe, se debe mostrar el resultado correspondiente:

``` bash
[P] Nombre de tubería inválido.
[P] Esperando suscripciones...
```

``` bash
[P] La tubería /tmp/una_tuberia_que_no_existe no existe.
[P] Esperando suscripciones...
```

Al descartar los errores anteriores, se debe confirmar que dicha tubería no está previamente suscrita, de lo contrario se muestra el error correspondiente:

``` bash
[P] La tubería ya está suscrita
[P] Esperando suscripciones...
```

Luego de dichas verificaciones, el servidor debe ser capaz de monitorear datos entrantes de todas las tuberías suscritas, además de estar a la espera de nuevas suscripciones.

## Servicios Ofrecidos

Luego de que un cliente suscribe su tubería al servidor, éste puede enviar en cualquier momento solicitudes de servicios, en cualquier orden. Los servicios tienen formatos diferentes para enviar datos y recibir el resutlado, pero siempre empiezan con un entero que identifica el tipo de servicio.

1. Promedio de un vector

El cliente envía la siguiente trama de datos, en dicho orden, a través de la tubería, al servidor:

| *int* | Identificador del servicio = 1 |
| *int* | Tamaño del vector |
| *double* | Primer elemento del vector |
| *double* | Segundo elemento del vector |
| *double* | ... |
| *double* | Último elemento del vector |

Cuando el servidor recibe dichos datos, calcula el promedio, y lo devuelve por la misma tubería:

| *double* | Promedio del vector |

2. Desviación estándar de de los datos contenidos en un vector

3. Ordenamiento de un vector respecto a otro vector

4. Convolución entre una matriz y un filtro

5.

Cuando la transacción con un hilo termina, el servidor queda listo para recibir nuevas transacciones por dicha tubería.

## Notas

Es importante tener en cuenta que se pueden suscribir tantas tuberías como el computador soporte, y todas, de forma independiente, pueden solicitar servicios.

## Precompilado de prueba



## Calificación

## Entrega
