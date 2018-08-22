---
layout: default
title: Practice 2
permalink: /programming/operating-systems/assigments/prc2
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
