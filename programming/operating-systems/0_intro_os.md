---
layout: default
title: Introduction to Operating Systems
permalink: /programming/operating-systems/0_intro_os
---

# Introducción a los Sistemas Operativos

Un sistema operativo es un software intermedio que permite realizar la interacción entre las apicaciones de alto nivel (editores de texto, reproductores de música, etc.), y el hardware (teclado, mouse, altavoces, pantalla, etc.). Su objetivo principal es abstraer los recusros del computador (periféricos, memoria, procesador, entre otros), de tal forma que los desarrolladores de software puedan hacer uso de ellos sin necesidad de conocer a profundidad su funcionamiento.

La figura mostrada a continuación presenta la abstraccíón gráfica del sistema de cómputo clásico. El hardware incluye la parte física del sistema, en el cual están incluido periféricos (I/Os), memorias volátiles y no volátiles y CPUs.

<div style="text-align:center">
  <img src ="/cstopics/assets/img/programming/os/0_architecture.png" />
  <div style="font-size:70%">Arquitectura de un sistema de cómputo. Tomado de [Silberschatz12]</div>
</div>

## ¿Qué hace el Sistema Operativo?

### Desde el punto de vista del usuario:

Facilitador del uso del hardware.

* Presenta de forma ordenada el contenido de los medio de almacenamiento.
* Da una experiencia de alto rendimiento.
* Administra los periféricos.

El usuario no tiene en cuenta de qué forma se administran los recursos del sistema (ni pretende hacerlo).

### Desde el punto de vista del Sistema

Administrador de recursos.

A los diferentes procesos, el OS asigna:

* Tiempos de acceso a CPU.
* Bloques de memoria.
* Almacenamiento de archivos.
* Acceso a periféricos (I/Os).

### Definición Global del Sistema Operativos

Software que controla la operación de un sistema de cómputo y su uso de recursos.

Principales funciones:

* Administrar la memoria y otros recursos del sistema
* Establecer polı́ticas de seguridad y acceso
* Multiplexar procesos e hilos
* Ejecutar programas solicitados por el usuario
* Proveer una interfaz de usuario básica

Un OS <span style="color:red">no</span> es:

* El hardware del computador
* Un programa de computador
* Una suite de herramientas
* Un entorno de desarrollo
* Una interfaz gráfica para el usuario (GUI)

### Kernel o núcleo

Componente de más bajo nivel del OS:

* Administra el HW
* Permite la ejecución de programas
* Maneja eventos generados por HW (interrupciones) y por SW (llamados)
* Define y gestiona archivos, procesos, directorios y el historial de las últimas operaciones

### Interfaz con el usuario

Suele ser un software adicional al Kernel, y a pesar de están incluida en la mayoría de sistemas operativos, es discutible el hecho de que haga parte de éste.

Puede ser tan básica como una terminal.

<span style="color:red">Figura Terminales DOS, UNIX, Linux.</span>

O puede contar con interfaces gráficas (GUI por sus siglas en inglés) que permitan visualizar de formas más sencillas y prácticas las tareas que se están realizando.


<span style="color:red">Figura GUI de WIndows, Mac, Android, Linux.</span>

## Arquitectura de un Computador

La CPU, la memoria y los periféricos se conectan a través de un BUS, el cual administra de forma autónoma el flujo de los datos. En los sistemas más clásicos, la CPU es el único maestro en la comunicación (genera solicitudes de lectura y escritura al BUS), sin embargo, en sistemas modernos los periféricos procesan datos en simultánea, y pueden necesitar información de la memoria, o incluso de otros periféricos, a éste proceso se le denomina Acceso Directo a Memoria (DMA), y cuando ocurre, el periférico puede convertirse en maestro, y solicitar al BUS la lectura o escritura.

<div style="text-align:center">
  <img src ="/cstopics/assets/img/programming/os/0_architecture2.png" />
  <div style="font-size:70%">Arquitectura de un computador. Tomado de [Silberschatz12]</div>
</div>

La arquitecctura con Neumann, en la cual se basa al mayoría de computadores en la actualidad (familia Intel), presenta una memoria única para instrucciones y datos. Con la modificación más común, tiene un bus adicional para periféricos, como se muestra a continuación.

<div style="text-align:center">
  <img src ="/cstopics/assets/img/programming/os/0_von_neumann.png" />
  <div style="font-size:70%">Arquitectura Con Neumann</div>
</div>

En al mayoría de los casos, el BUS únicamente permite el tráfico de datos entre un maestro y un esclavo, por lo cual es necesario regular de qué forma la CPU y los periféricos acceden al BUS. A este proceso de regulación de tráfico se le denomina arbitraje, y es realizado por el 'Controador de BUS' o 'Controlador de Acceso a Memoria', un bloque físico en hardware que concede acceso al bus de acuerdo con prioridades, tipo de solicitud, orden de llegada, entre otros.

<div style="text-align:center">
  <img src ="/cstopics/assets/img/programming/os/0_ios_bus.png" />
  <div style="font-size:70%">Arbitro conectado a maestros, y señales de solicitud y acceso. Tomado de [Mendías15]</div>
</div><br>

<div style="text-align:center">
  <img src ="/cstopics/assets/img/programming/os/0_arbitro.png" />
  <div style="font-size:70%">Ejemplo de periféricos conectados a un mismo bus. Tomado de [Ruiz12]</div>
</div>

### Proceso de arranque

Cuando un PC (bajo el estándar IBM) arranca, sigue los siguientes pasos para cargar el sistema operativo:

1. Arranca el *BIOS* o *boostrap*, almacenado en una memoria ROM o EEPROM.
2. El *BIOS* hace verificaciones de hardware.
3. El *BIOS* verifica los medios de almacenamiento instalados, carga el bootloader del sistema operativo en memoria, y hace un salto hacia él.
4. El *bootloader* carga el kernel del sistema operativo en memoria, y lo ejecuta.
5. El *kernel* inicia los procesos del sistema, o *system deamons*.
6. El sistema queda en modo *IDLE* o reposo, esperando eventos.

### Eventos e interrupcioness

Los eventos pueden ser externos o internos al sistema, y siempre generan una interrupción. Existen dos tipos de interrupciones:

* **Hardware**: La CPU salta de inmediato a un lugar específico de memoria.
* **Software**: Se ejecuta un llamado a sistema o *system call*.

### Estructura de almacenamiento

Los computadores tienen dos tipos de memoria de almacenamiento, la memoria principal, que es volátil pero rápida, y memoria secundaria, que es no volátil pero lenta. La CPU maneja una jerarquía de memoria, en la cual, almacena los datos más usados en la memoria más rápida, y los menos usados en la más lenta, dicha jerarquía se observa a continuación. Al subir en la pirámide, se incrementa la velocidad, pero incrementa el precio por unidad de almacenamiento, razón por la cual, los computadores tienen menos caché que RAM, o menos discos de estado sólido que discos duros.

<div style="text-align:center">
  <img style="width: 50%;" src ="/cstopics/assets/img/programming/os/0_memories.png" />
  <div style="font-size:70%">Comparación cuantitativa de tipos de memoria.</div>
</div>

Hay que tener en cuenta además que, según la arquitectura Von Neumann, la CPU únicamente puede leer instrucciones de la memoria principal, por lo cual, los programas, que normalmente están en la memoria secundaria (medios de almacenamiento no volátiles) deben ser copiados primero a la memoria principal para así ser ejecutados, éste proceso es realizado por el *kernel*.

A continuación se presenta una comparación cuantitativa entre algunos tipos de memoria.

<div style="text-align:center">
  <img style="width: 75%;" src ="/cstopics/assets/img/programming/os/0_memory_values.png" />
  <div style="font-size:70%">Comparación cuantitativa de tipos de memoria.</div>
</div>

No olvidar el hecho de que los medios de almacenamiento no volátiles, son vistos por el sistema operativo como un periférico o dispositivo I/O.

### Sistemas mononúcleo

En la actualidad, los sistemas mononúcleo se utilizan únicamente en sistemas de cómputo específicos, como pueden ser:

* Controladores de disco.
* Controladores de unidad óptica.
* Periféricos de comunicación.
* Teclados, mouse.
* Electrodomésticos (con el internet de las cosas, ya suelen ser manejados por procesadores de propósito general multinúcleo).
* Hardware de bajo procesamiento.

La principal implementación de sistemas mononúcleo en la actualidad son los microcontroladores.

### Sistemas multinúcleo

Los sistemas de más de un procesador o núcleo aparecieron en aplicaciones que ameritaban alto rendimiento, como servidores, pero lentamente fueron abriendo camino hacia commputadores de mesa, teléfonos celulares, y, con el Internet de las Cosas, todo tipo de dispoositivo.

En los sistemas multinúcleo, los procesadores suelen compartir:

* Señal de reloj
* Memoria
* Periféricos

Algunas de las ventajas de los sustemas multinúcleo son:

* **Incremento de tráfico de datos (*throughput*):** Al dividir el trabajo, el tiempo consumido por una tarea se disminuye (no se divide en la cantidad de núcleos).

* **Economía:** El incremento por núcleo no crece proporcionalmente, debido a que se comparten muchos elementos de la arquitectura.

* **Incremento de la confiabilidad:** Con un sistema desarrollado de forma correcta, el fallo de uno de los núcleos no representa la caída de todo el sistema.

El procesamiento multinúcleo se puede realizar de dos diferentes formas:

* **Procesamiento asimétrico**
    * Existe un procesador "maestro", que controla el sistema en general, y asigna tareas a los demás núcleos.
    * Los "esclavos" están atentos a las órdenes del maestro.
* **Procesamiento simétrico (usualmente usada)**
    * Todos los núcleos realizan tareas del OS.
    * Todos tienen sus propios registros internos y caché.
    * Comparten bus de datos y memoria física.

## Estructura del sistema operativo

A continuación se exponen algunas de las principales características de un OS.:

### Habilidad multiprograma

Permite correr varios programas, incrementando el uso de CPU al tener siempre un trabajo para ejecutar.

<div style="text-align:center">
  <img style="width: 30%;" src ="/cstopics/assets/img/programming/os/0_multiprogram.png" />
</div>

* OS selecciona un trabajo (job1) y se asigna a CPU para ejecución.
* Si job1 tiene que esperar otra operación (ej. lectura I/O), OS selecciona otro trabajo (job2).
* Si job2 tiene que esperar otra operación (ej. lectura I/O), OS selecciona otro trabajo (job3).
* ...
* Eventualmente, job1 termina operación de espera y vuelve a ser asignado por el OS a CPU.

**En general, la idea es:** Maximizar el uso de la CPU realizando siempre la asignaciónd e trabajos de diferentes procesos, de tal manera que nunca este libre (idle).

### Habilidad multitarea (Time sharing ):

CPU ejecuta multiples trabajos, intercalándolos a alta frecuencia, de tal
forma que el ususario pueda interectuar con cada programa.

**Tareas del sistema operativo para soportar multiprograma y multitarea**:

* Job scheduling : decisión de cuál trabajo enviar a memoria.
* Admin de memoria : ubicación del trabajo en memoria.
* CPU scheduling : decición de cuál trabajo de los que están en memoria es el siguiente a ejecutar.

### Manejo de procesos:

Un programa en ejecución es un **proceso**.

Recursos que necesita un proceso:

* Tiempo en CPU
* Acceso a archivos
* Espacio en memoria
* Acceso a dispositivos I/O

<div style="text-align:center">
  <img style="width:75%;" src ="/cstopics/assets/img/programming/os/0_process.png" />
</div>

El OS es responsable de:

* Planificar los procesos e hilos en CPUs.
* Crear/borrar procesos de usuario y de sistema.
* Suspender/retomar procesos.
* Proveer mecanismos de sincronización de procesos.
* Proveer mecanismos de comunicación de procesos.

### Manejo de memoria

La memoria debe ser compartida entre el OS y los programas.

El OS es responsable de:
* Mantener registro de cuales posiciones de memoria están ocupadas y cuál proceso las está usando.
* Decidir cuál proceso y datos deben ser transferidos hacia/desde la memoria.
* Asignar/liberar espacio de memoria.

## Sistemas Operativos Open Source

**UNIX**
* OS multiusuario multitarea.
* Desarrollado a inicios de 1970 en los laboratorios Bell por Ken Thompson , Dennis Ritchie y otros.
* Introdujo la jerarquı́a del sistema de archivos.

**LINUX**
* OS basado en UNIX
* Su kernel fue creado en 1991 por Linus Torvalds, estudiante finlandés.
* Sus actualizaciones son contribuciones de programadores de todo el mundo.
* Principales distribuciones: RedHat, SUSE, Fedora, Debian Slackware y Ubuntu.

**BSD UNIX**
* Desarrollado a inicios de 1978 en la Universidad de Berkeley en California
* Principales distribuciones: freeBSD, netBSD ,openBSD, dragonflyBSD
* Principales contribuciones: manejo de memoria virtual y protocolo TCP/IP

**SOLARIS**
* OS comercial de SunMicrosystems (Oracle) lanzado en 1992
* Basado en BSD-UNIX
* Distribución libre openSolaris (2005-2010)

## Servicios de un Sistema Operativos

<div style="text-align:center">
  <img style="width:75%;" src ="/cstopics/assets/img/programming/os/0_osServices.png" />
</div>

* **Interfaz de usuario:** lı́nea de comandos, interfaz batch, GUI.
* **Ejecución de programas:** cargar programa en memoria y ejecución del proceso.
* **Operaciones I/O:** comunicación con archivos y periféricos
* **Manipulación del sistema de archivos:** permiso de acceso a archivos  directorios.
* **Comunicaciones:** memoria compartida y transmisión de mensajes.
* **Detección de errores:** detección y correcicón de errores en CPU, memoria, dispositivos I/O y programas de usuario.
* **Asignación de recursos:** códigos de asignación especiales para CPU, memoria y almacenamiento.
* **Contabilidad:** seguimiento a cantidad/tipos de recursos utilizados.
* **Protección y seguridad:** protección de información del usuario y de procesos concurrentes

### Intérprete de comandos

Es un programa espcial que se ejecuta al iniciar un proceso o cuando el usuario inicia sesión por primera vez (si es un sistema interactivo). Función principal: recibir y ejecutar los comandos especificados por el usuario.

En UNIX: la mayorı́a de los comandos son implementados como programas del sistema. Ejemplo:

``` bash
rm file.txt
```

<div style="text-align:center">
  <img style="width:60%;" src ="/cstopics/assets/img/programming/os/0_command_line.png" />
</div>

### GUI

* 1ra GUI Xerox Alto computer en 1993. Adopción generalizada en 1980 con Apple Macintosh.

<div style="text-align:center">
  <img style="width:60%;" src ="/cstopics/assets/img/programming/os/0_gui_mac.png" />
</div>

* GUI Ubuntu

<div style="text-align:center">
  <img style="width:60%;" src ="/cstopics/assets/img/programming/os/0_gui_ubuntu.png" />
</div>

## Referencias

* [Silberschatz12] Silberschatz, A., Galvin, P. and Gagne G. Operating System Concepts, 8th Ed, Wiley, 2012

* [Tanenbaum15] Tanenbaum, A. [Modern Operating Systems](https://usta-primo.hosted.exlibrisgroup.com/primo-explore/fulldisplay?docid=57UST_Aleph000147433&context=L&vid=57UST&lang=es_ES&search_scope=57UST&adaptor=Local%20Search%20Engine&tab=57ust_tab&query=any,contains,operating%20systems&sortby=rank&mode=Basic){:target="blank"},  2nd Ed, Prentice-Hall, 2015

* [Mendías15] Mendías J. M. [Estructura y Tecnología de Computadores, Tema 6. Características y protocolos de buses](http://www.fdi.ucm.es/profesor/mendias/512/docs/tema6.pdf){:target="blank"}, Dpto. Arquitectura de Computadores y Automática Universidad Complutense de Madrid.

* [Ruiz12] Ruiz J. J. [Estructura de Computadores, Tema 10](http://www.fdi.ucm.es/profesor/jjruz/WEB2/Temas/EC10.pdf){:target="blank"}, Dpto. Arquitectura de Computadores y Automática Universidad Complutense de Madrid.
