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

Los pasos que debe seguir otro proceso para suscribirse, es escribir el path de la tubería (previamente creada), de máximo 80 carácteres, en el *Espacio para nombre de la tubería a suscribir*, iniciar la *Bandera de resultado de suscripción* en 0 para evitar leer resultados de suscripciones previas, y poner la *Bandera de suscripción* en 1.

Cuando el servidor recibe la *Bandera de suscripción* en alto, confirma que el *Espacio para nombre de la tubería a suscribir* contiene una cadena válida (es decir, contiene al menos un \0), y que dicha tubería existe, si alguna de las dos condiciones no se cumple, se debe mostrar el resultado correspondiente:

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

Luego de que un cliente suscribe su tubería al servidor, éste puede enviar en cualquier momento solicitudes de servicios, en cualquier orden. Los servicios tienen formatos diferentes para enviar datos y recibir el resultado, pero siempre empiezan con un entero que identifica el tipo de servicio.

Cuando la transacción con un hilo termina, el servidor queda listo para recibir nuevas transacciones por dicha tubería.

### 1. Promedio de un vector

El cliente envía la siguiente trama de datos, en dicho orden, a través de la tubería, al servidor:

| *int* | Identificador del servicio = 1 |
| *int* | Tamaño del vector |
| *double* | Primer elemento del vector |
| *double* | Segundo elemento del vector |
| *double* | ... |
| *double* | Último elemento del vector |

Cuando el servidor recibe dichos datos, calcula el promedio, y lo devuelve por la misma tubería:

| *double* | Promedio del vector |

### 2. Desviación estándar de de los datos contenidos en un vector

El cliente envía la siguiente trama de datos, en dicho orden, a través de la tubería, al servidor:

| *int* | Identificador del servicio = 2 |
| *int* | Tamaño del vector |
| *double* | Primer elemento del vector |
| *double* | Segundo elemento del vector |
| *double* | ... |
| *double* | Último elemento del vector |

Cuando el servidor recibe dichos datos, calcula la desviación estándar, y lo devuelve por la misma tubería:

| *double* | Desviación estándar |

### 3. Ordenamiento de una matriz respecto a una columna

Ordena las filas de una matriz, respecto a una de las columnas de forma ascendente. Datos enviados por el cliente:

| *int* | Identificador del servicio = 3 |
| *int* | Número de filas |
| *int* | Número de columnas |
| *int* | Columna sobre la cual se va a organizar (base 0) |
| *double[rowsXcols]* | Los elementos de la matriz, de izquierda a derecha y de arriba a abajo |

EL servidor responde:

| *double[rowsXcols]* | Matriz ordenada, serializada de la misma forma |

### 4. Multiplicación de dos matrices

Calcula la multiplicación matricial de dos matrices. El cliente envía:

| *int* | Identificador del servicio = 4 |
| *int* | Número de filas de matriz 1 |
| *int* | Número de columnas de matriz 1|
| *int* | Número de filas de matriz 2 |
| *int* | Número de columnas de matriz 2|
| *double[rows1Xcols1]* | Los elementos de la matriz 1, de izquierda a derecha y de arriba a abajo |
| *double[rows2Xcols2]* | Los elementos de la matriz 2, de izquierda a derecha y de arriba a abajo |

El servidor contesta:

| *int* | Número de filas de matriz resultado |
| *int* | Número de columnas de matriz resultado |
| *double[rowsXcols]* | Los elementos de la matriz resultado, de izquierda a derecha y de arriba a abajo |

Si la multiplicación no se puede realizar, se envía 0 en las 2 dimensiones, y nada más.

### 5. Determinante de una matriz

El cliente envía:

| *int* | Identificador del servicio = 5 |
| *int* | Número de filas |
| *int* | Número de columnas |
| *double[rowsXcols]* | Los elementos de la matriz, de izquierda a derecha y de arriba a abajo |

El servidor contesta:

| *double* | Determinante de la matriz |

Si el determinante no se puede calcular, el valor retornado es *NAN*.

## Notas

* Es importante tener en cuenta que se pueden suscribir tantas tuberías como el computador soporte, y todas, de forma independiente, pueden solicitar servicios.

* Todos los algoritmos deben ser escritor por los integrantes del grupo, no se permite el uso de librerías especializadas en álgebra lineal.

## Precompilado de prueba

Puede descargar los precompilados de la solución, con el fin de probar y validad su solución, [aquí](https://github.com/cstopics/cstopics/tree/gh-pages/assets/binaries/digital3_lab3_2019_1){:target="blank"}.

## Calificación

* Funcionamiento (35%)
  * 2.0 unidades si el programa realiza la comunicación de forma correcta, y calcula las operaciones 1 y 2 (debe funcionar correctamente tanto la comunicación como las dos operaciones, si no se aplica un 0.0).
  * 1.0 por cada una de las operaciones 3, 4 y 5.
* Sustentación (35%)
* Informe (30%)

## Entrega

Cree un nuevo repositorio **privado** de GitHub, llamado *"2019_1_d3_prc3_Lastname1Firstname1_Lastname2Firstname2"* (E.g. *"2018_2_d3_prc3_CamachoCamilo_PerezPepito"*), y agrege como colaboradores a todos sus compañeros de grupo, y a la cuenta *edgarcamilocamacho*. El repositorio debe contener:

* Archivos cpp y h.
* Makefile: con reglas para compilar el servidor, y borrar todo.
* README.md: El informe con todas las secciones que lo componen, utilizando el formato Markdown apropiadamente.

Luego, descarguelo como *zip* y súbalo al link de *moodle* correspondiente. **Importante**: cuando suba la tarea a moodle, incluya el link del repositorio de *github*, y el nombre de todos los mienbros del grupo.

Entrega: 11 y 12 de Abril de 2019
