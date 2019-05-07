---
layout: default
title: Práctica 5
permalink: /programming/operating-systems/assigments/2019-1/prc5
---

# Práctica 5

Escriba un programa en C/C++ que emule las cajas de un banco. Todo el banco se debe ver como un único recurso al que más de un proceso (cliente) puede acceder, es decir, que un único semáforo controlaría el acceso a las cajas.

## Proceso Banco

El banco se deben iniciar con un único parámetro, el cual indica la cantidad de cajas que tiene disponibles, es decir, dicho número debe ser dinámico.El siguiente ejemplo muestra cómo se ejecutaría el banco con 6 cajas disponibles:

``` bash
$ ./banco_gui 6
```

En una interfaz gráfica, se deben mostrar las *N* cajas vacías al iniciar el programa (de forma gráfica, con un dibujo de una caja sin cliente), y a medida que los clientes van ubicándose en cada caja, dicho dibujo debe cambiar a uno en que exista un cliente siendo atendido, y debe mostrar el nombre e identificación del cliente.

Cuando el proceso del banco inicie, éste debe crear algún método de comunicación (memoria compartida o tubería), a través del cual recibe las solicitudes de los clientes que acceden a una de las cajas del banco. Ésta solicitud debe incluir nombre y número de identificación del cliente. Además del semáforo que indica si existen o no cajas desocupadas, es importante crear un semáforo adicional que impida que más de un cliente acceda al mismo tiempo a la memoria compartida / tubería, cuando existe más de una caja libre.

## Proceso Cliente

El proceso cliente se inicia con el nombre y el número de identificación:

``` bash
$ ./cliente "Pepito Perez" "1025485665"
```

Éste proceso no necesita interfaz gráfica, su función es "hacer la cola", cuando exista una caja libre, pasar a ella (a través de la única memoria compartida o tubería), durar un tiempo aleatorio en la caja (entre 5 y 20) segundos, y finalizar.

Se pueden lanzar todos los procesos que se deseen, ya que si las cajas están ocupadas, éstos "harán fila" mientras se desocupa alguna.

## Requerimientos

* Utilizar semaforos para todas las sincronizaciones necesarias.
* Utilizar sólo una memoria compartida o tubería para todas las comunicaciones.
