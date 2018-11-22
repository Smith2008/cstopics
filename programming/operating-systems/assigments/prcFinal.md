---
layout: default
title: Práctica Final
permalink: /programming/operating-systems/assigments/prcFinal
---

# Práctica Final

Éste laboratorio se basará en la práctica [Práctica 4](/cstopics/programming/operating-systems/assigments/prc4), el UOS (Useless Operating System) será convertido en el UOS (Useful operating system).

### Mejoras y adiciones al sistema

Se deberán agregar las siguientes características al USO que ya desarrollaron:

* La capacidad de enviar mensajes *broadcast*, es decir, que los envíe un nodo, y éste llegue a todos los demás nodos conectados al máster.
* El máster seguirá siendo un proceso independiente, el cual será ejecutado una única vez para conectar los nodos correspondientes, sin embargo, los clientes ya no serán el mismo proceso. Cualquier programa podrá ser un cleinte UOS, siempre que incluya la librería correspondiente (*uos_client.h* y "uos_client.cpp"), la cual será escrita por ustedes, y debería tener funcinoes como por ejemplo:
    * *connect_to_master(IP_ADDRESS);*
    * *send_str_message(DESTINATION_NODE)*
    * *set_reception_callback(POINTER_TO_RECEPTION_FUNCTION)*

### Robot diferencial

Deben usar un robot diferencial que cuente con lo siguiente:

* Dos ruedas con motores independiente, y una rueda loca. Dependiendo del sentido de giro y la velocidad de cada motor, el robot se moverá hacia adelante, atrás, girará o se detendrá.
* Un sensor de distancia (ultrasónico, láser, o la tecnología deseada).
* Una cámara.

<div style="text-align:center">
  <img style="width:40%;" src ="/cstopics/assets/img/programming/os/robot_diferencial.jpg" />
  <div style="font-size:70%">Ejemplo de robot diferencial.</div>
</div>

Todos los periféricos (motores, sensor y cámara) deben ser conectados al sistema embebido utilizado (Raspberry o Beaglebone), haciendo las interfaces necesarias (puente h, buffer, etc), asegurándose de no dañar las entradas y salidas digitales. Todo se debe alimentar con fuentes que permitan el desplazamiento del robot (por ejemplo baterías), tener en cuenta el voltaje de alimentación de cada elemento.
