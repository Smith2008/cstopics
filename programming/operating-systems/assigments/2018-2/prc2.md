---
layout: default
title: Practice 2
permalink: /programming/operating-systems/assigments/2018-2/prc2
---

## Practice 2

Una de las aplicaciones más comunes de la programación multihilo recae sobre el área de procesamiento de imágenes. Una de las posibilidades es usar la convolución como herramienta de filtrado. Para esto se necesita un filtro dado por una matriz en dos dimensiones.

La convolución se realiza al sobreponer el filtro (llamado kernel en la literatura) sobre cada uno de los pixeles de la imagen y el resultado del nuevo pixel (pixel de la imagen filtrada) es la suma de los productos elemento a elemento del filtro y la imagen. (Ver [este link](http://machinelearninguru.com/computer_vision/basics/convolution/image_convolution_1.html){:target="blank"}).

En este laboratorio trabajaremos con imágenes en escala de grises, donde 0 corresponde a negro y 255 a blanco. Si luego de filtrar usted obtiene valores negativos o mayores a 255, debe realizar saturación del color del pixel, así:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
    nuevo pixel =
    \begin{cases}
      0,              & \text{si } nuevo pixel < 0\\
      255,            & \text{si } nuevo pixel > 255\\
      nuevo pixel     & \text{en otro caso}
    \end{cases}
"/>

<div class="picture">
  <img style="width:90%;" src ="/cstopics/assets/img/programming/os/prc2_conv.png" />
  <div>Tomado de http://robologs.net/wp-content/uploads/2015/07/convolucion.png</div>
</div>

Es usual que el filtro tenga las siguientes características:
* El filtro corresponde a una matriz cuadrada de tamaño impar.
* La suma de todos los elementos del filtro debe sumar 1.0, para que la imagen filtrada tenga el mismo brillo de la imagen original.
* Si la suma de los elementos del filtro es mayor a 1.0, la imagen resultante será más brillante. Si es menor a 1.0, será más opaca.

Por ejemplo, el filtro Sobel permite detectar separadamente los bordes horizontales y verticales en una imagen en escala de grises. Para ello utiliza las siguientes máscaras o kernels de convolución:

* Gradiente fila (detección de bordes horizontales):

<img class="eq" src="https://latex.codecogs.com/gif.latex?
    G_x = \frac{1}{2}
    \begin{bmatrix}
        +1 & 0 & -1 \\
        +2 & 0 & -2 \\
        +1 & 0 & -1
    \end{bmatrix}
"/>

* Gradiente columna (detección de bordes verticales):

<img class="eq" src="https://latex.codecogs.com/gif.latex?
    G_y = \frac{1}{2}
    \begin{bmatrix}
        +1 & +2 & +1 \\
        0 & 0 & 0 \\
        -1 & -2 & -1
    \end{bmatrix}
"/>

En cada punto de la imagen, el pixel resultante de la aplicación del filtro Sobel es:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
    nuevo pixel = \sqrt{G_x^2 + G_y^2}
"/>

El resultado de este filtro suministra información valiosa sobre las fronteras (bordes) de los objetos en la imagen. Estos resultados pueden ser usados para segmentar la imagen, reconocer objetos, etc.

<div class="picture">
  <img style="width:90%;" src ="/cstopics/assets/img/programming/os/prc2_res.png" />
  <div>Tomado de http://robologs.net/wp-content/uploads/2015/07/convolucion.png</div>
</div>

## Laboratorio

Realice un programa secuencial en C++ para realizar la detección de bordes de imágenes con extensión *.pgm* a través del filtro Sobel. Debe cumplir los siguientes requerimientos:

* El usuario debe ingresar por consola el nombre de la imagen que desea filtrar. Todas las imágenes deben guardarse en la misma ubicación del programa ejecutable, en un directorio llamado imgs.
* No hay límite en el tamaño de la imagen a leer.
* La imagen a leer debe tener extensión *.pgm*, estrictamente. (Estas imágenes las puede abrir en el visualizador de Ubuntu)
* La imagen filtrada debe guardarse en el mismo directorio donde se encuentra la imagen original. El nombre del archivo debe ser *nombreOriginal_filtrada.pgm*

## Librerías

[Image.cpp](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/Image.cpp){:target="blank"} and [Image.h](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/Image.h){:target="blank"}

Esta clase tiene los métodos para realizar lectura/escritura de imágenes .pgm y acceso a pixeles de la imagen.

[Ejemplo](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/os/copy_image.cpp){:target="blank"}

Acceso a pixel *(i,j)*: La imagen se almacena en en un arreglo lineal de tamaño *width x height*, así que se debe implementar la lógica para acceder al pixel correcto.

## Editor de imágenes pgm

Software GIMP (https://ubunlog.com/como-instalar-la-ultima-version-de-gimp-en-nuestro-ubuntu/ )

## Entrega

Create a new **private** Bitbucket repository named *"2018_2_d3_prc2_LastnameFirstname"* (E.g. *"2018_2_d3_prc2_CamachoCamilo"*), share it with the account *"camilocamachousta"*, and add the files below:

* *sobel.cpp* with the *c++* code.
* *Image.cpp* and *Image.h*, original libraries.
* A *Makefile* with the rules *all*, *sobel* and *clean*. (Refer to the [C/C++ in Linux](/cstopics/programming/c-c++/c_c++_in_linux) guide)

When the repository is ready, download it as a *.zip* file and upload it to the appropriate link in moodle.

Deadline: Sep 30
