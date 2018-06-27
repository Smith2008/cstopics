---
layout: default
title: Programming
permalink: /programming/operating-systems/into-linux
---

# Introduction to Linux

## What is GNU/LINUX?

GNU/Linux es un sistema operativo, así como Microsoft Windows o macOS, con la diferencia fundamental de que es libre y gratuito, desarrollado por una comunidad de programadores de forma voluntaria.

De igual manera que con los demás sistemas operativos, GNU/Linux se divide en dos secciones fundamentales:

**El núcleo**, o kernel, encargado de realizar el control directo del harware, gestionarlo, y abstraerlo para las aplicaciones de alto nivel. Adicionalmente, administra los recursos, con el fin de garantizar que los programas ejecutados en el ordenador puedan acceder al hardware.

**Las aplicaciones** del sistema operativo permiten al usuario el uso del ordenador de una forma sencilla, sin tener que comprender los procesos internos que están ocurriendo dentro del procesador. Éstas aplicaciones incluyen la interfaz gráfica, gestores de archivos, editores de texto, etc. La mayoría de los programas desarrollados para éste sistema operativo fueron realizados por el proyecto [GNU](https://www.gnu.org/home.en.html)

## Distribuciones de Linux

Una distribución es una versión precompilada de Linux, en conjunto con paquetes y programas necesarios para permitir el uso de ésto por el usuario final. A lo largo de la historia de Linux han existido tres grandes distribuciones, Debian, Slackware y Red Hat, cada una de las cuales, a su vez, ha desencadenado el desarrollo de distribuciones basadas en ellas. En este link se encuentra esquematizada la jerarquía de la mayoría de distribuciones conocidas de Linux.

El desarrollo de éste curso se llevará a cabo bajo Ubuntu (se recomienda la versión 16.04.3 LTS), una distribución libre de GNU/Linux basada en Debian. Sin embargo, la mayoría de las herramientas y procesos que se realicen, funcionarán de manera correcta en cualquier distribución basada en Debian.

## Sistema de Archivos y Árbol de Directorios

El sistema de archivos manejado por Linux maneja una organización diferente a la acostumbrada en sistemas basados en Windows, en dónde las carpetas más altas en la jerarquía corresponden a las unidades de almacenamiento (C:\, D:\, etc.). En Linux todos los archivos están contenidos en un directorio denominado raíz, y representado por el símbolo "/".

Las unidades o particiones realizadas en las unidades de almacenamiento son "montadas" en directorios, y se acceden a través del sistema de archivos. A continuación se presenta de forma gráfica la jerarquía de directorios, y una breve descripción.
