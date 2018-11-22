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

### Implementación del USO con el robot diferencial

En la siguiente figura se sintetiza el sistema a implementar a partir de nodos de UOS:

Cada nodo debe ser implementado y se debe subscribir al máster a través de la librería *uos_client*, escrita por ustedes.

Explicación del funcionamiento de cada nodo:

***Nodos en el robot***
* *motors_controller:* debe recibir un mensaje de tipo *num_array*, el debe contener dos números que representan el movimiento de cada motor [motor_derecho, motor_izquierdo], donde 1.0 representa movimieto hacia adelante, -1.0 hacia atrás, y 0.0 detenido.
* *sensor_controller:* envía un mensaje tipo *num* con un 1.0 si hay un objeto frente al robot, o un 0.0 si no lo hay. Éste mensaje debe ser de tipo *broadcast*.
* *camera_controller:* espera un mensaje de tipo *str* con la palabra 'SHOT', cuando lo recibe, toma una foto y la envía por *ssh* al computador.

***Nodos en el computador***
* *controller:* realiza toda la lógica explicada más adelante (no se debe ejecutae en simultánea con *manual_controller*).
* *manual_controller:* a través de teclas, controla manualmente el sentido de los motores de forma independiente (no se debe ejecutar en simultánea con *controller*).
* *gui:* Gui en Qt que muestre:
  * 
