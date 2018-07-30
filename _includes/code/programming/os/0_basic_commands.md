``` bash
# 'pwd': Muestra el directorio actual o de trabajo.
$ pwd
/home/pepito

# 'ls': Muestra el contenido de un directorio.
$ ls # Muestra únicamente el nombre de los elementos contenidos en el directorio actual.
...
$ ls -l # Muestra el contenido del directorio actual con detalles.
...
$ ls -lh # Muestra el contenido del directorio actual con detalles, mostrando el tamaño de los archivos en formato amigable (kB, MB, GB, etc.).
...
$ ls /usr/local # Muestra el contenido de un directorio específico (utilizando una dirección absoluta).
...
$ ls Downloads # Muestra el contenido del directorio 'Downloads' (utilizando una dirección relativa, 'Descargas' si el OS está en español).
...
$ ls ./Downloads # Muestra el contenido del directorio 'Downloads' (utilizando el alias de directorio actual).
...
$ ls ../../usr/bin # Muestra el contenido de un directorio usando el alias de directorio superior.
...

# 'cd': Cambia el directorio actual de trabajo
$ cd Downloads # Dirección relativa
$ pwd
/home/pepito/Downloads
$ cd .. # Alias de directorio superior
$ pwd
/home/pepito
$ cd . # Alias de directorio actual
$ pwd
/home/pepito
$ cd /usr/local/bin # Dirección absoluta
$ pwd
/usr/local/bin
$ cd ../.. # Directorio superior del directorio superior
$ pwd
/usr
$ cd # Es equivalente a 'cd ~' o 'cd /home/pepito'
$ pwd
/home/pepito

# 'mkdir': Crea un directorio
$ mkdir linuxTutorial # Crea el directorio linuxTutorial en el home de pepito
$ ls
... (se debe encontrar el directorio creado)
$ mkdir linuxTutorial/folder1 # Crea el directorio folder1 dentro de linuxTutorial (dirección relativa)
$ mkdir /home/pepito/linuxTutorial/folder2 # Dirección absoluta
$ cd linuxTutorial
$ mkdir folder3 # Entra a la carpeta linuxTutorial y crea el folder3
$ ls
folder1  folder2  folder3

# 'echo': Imprime un mensaje por pantalla
# '>': Redirecciona la salida de un comando a un archivo (reemplazando contenido).
# '>>': Redirecciona la salida de un comando a un archivo (concatenando).
# 'cat': Imprime el contenido de un archivo en pantalla.
$ cd folder1
$ echo 'Hola a todos'
Hola a todos
$ echo 'Hola a todos' > file1.txt # Guarda la salida en file1.txt
$ cat file1.txt
Hola a todos
$ echo 'Adiós' > file1.txt # Reemplaza el contenido de file1.txt
Adiós
$ echo 'Hola' > file2.txt # Guarda la salida en file2.txt
$ cat file2.txt
Hola
$ echo 'a' >> file2.txt # Agrega una nueva línea
$ cat file2.txt
Hola
a
$ echo 'todos!' >> file2.txt # Agrega una nueva línea
$ cat file2.txt
Hola
a
todos!
$ cat file2.txt >> file3.txt # Guarda el contenido de file2.txt en file3.txt
$ echo 'Copia' >> file3.txt # Agrega una nueva línea
$ cat file3.txt
Hola
a
todos!
Copia

# 'cp': Crea una copia de un archivo o un directorio, con la opción '-r' copia directorios.
$ cp file1.txt ../folder2/ # Copia file1.txt a folder2 con el mismo nombre
$ ls ../folder2/
...
$ cp file1.txt ../folder3/file100.txt # Copia file1.txt a folder3 con el nombre file100.txt
$ ls ../folder3/
...
$ cd ..
$ cp -r ./folder1/ ./folder2/ # Crea una copia de folder1 dentro de folder2
$ ls ../folder2/
...
$ cp -r folder1 folder3/newFolder # Crea una copia de folder1 dentro de folder2 con nuevo nombre
$ ls ../folder3/
...
$ cp -r folder1 folder4 # Crea una copia de folder1 en la carpeta actual (linuxTutorial) con un nuevo nombre.
$ ls
...

# 'mv': Mueve un archivo o directorio (no necesita '-r' para mover directorios)
$ mv ./folder1/file1.txt . # Mueve el archivo file1.txt del directorio folder1 a linuxTutorial
$ ls folder1
...
$ ls
...
$ mv folder4 folder1/ # Mueve folder4 de linuxTutorial a folder1
$ ls folder1
...

# 'rm': Elimina un archivo o directorio, con la opción '-r' borra directorios. (los archivos eliminaros con este comando no se pueden recuperar)
$ ls folder2
...
$ rm folder2/file1.txt
$ ls folder2
...
$ ls
...
$ rm -r ./folder3
$ ls
...
```
