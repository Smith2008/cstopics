``` sh
# Contenido de la carpeta
# (carpeta, folder102 y folder202 son directorios, los demás son archivos regulares)
$ ls
archivo.txt  carpeta  file1.txt  file2.txt  file3.txt  folder102  folder202

# Si se quiere mover al directorio 'carpeta', se puede escribir:
$ cd c
# Al presionar TAB, la terminal autocompleta con el único directorio que comienza con 'c'.
$ cd carpeta/
# En lugar de presionar Enter, ctrl+C para cancelar.

# Se puede completar con cualquier cantidad de caracteres que contengan el inicio
# del nombre.
$ ls car
# TAB
$ ls carpeta/

# Si existen varios elementos que inician por los mismos caracteres, la terminal
# autocompleta hasta donde tengan en común los elementos, al presionar TAB dos
# veces más, la terminal muestra las alternativas. Agregando un caracter más, se
# finaliza el autocompletado.
$ cat fi
# TAB
$ cat file
# TAB TAB
$ cat file
file1.txt  file2.txt  file3.txt
# Agregar 1
$ cat file1
# TAB
$ cat file1.txt
```
