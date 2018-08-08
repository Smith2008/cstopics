---
layout: default
title: Miniconda
permalink: /programming/python/miniconda
---

# Miniconda

Miniconda allows you to create an independent installation of python and its dependencies. You are able to install several copies of python 2.7 and python 3.6.

## Installation

* Download the installers from the [official page](https://conda.io/miniconda.html){:target="blank"}, both 2.7 and 3.6 versions, for 64-bit Linux machine.

* Execute the 2.7 installer:

``` sh
$ cd /path/where/installer/is
$ sudo chmod 777 Miniconda2-latest-Linux-x86_64.sh
$ ./Miniconda2-latest-Linux-x86_64.sh
```

* Follow the instructions, install on the default folder, and **do not allow the installer to add the miniconda folder to the PATH through .bashrc**.

* Repeat the process with the 3.6 installer.

Both versions of Miniconda are installed in *~/miniconda2* and *~/miniconda3*. Create the following files in your home folder:

* *startConda2.sh* :

``` sh
export PATH=/home/camilo/miniconda2/bin:$PATH
```

* *startConda3.sh* :

``` sh
export PATH=/home/camilo/miniconda3/bin:$PATH
```

So, when you want to use miniconda, start a terminal, and source the correspondent script:

``` sh
$ # New terminal
$ source .startConda2 # You can use dot '.' instead of the command 'source'
$ python
Python 2.7.15 |Anaconda, Inc.| (default, May  1 2018, 23:32:55)
[GCC 7.2.0] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>>
```

``` sh
$ # New terminal
$ source .startConda3 # You can use dot '.' instead of the command 'source'
$ python
Python 3.6.5 |Anaconda, Inc.| (default, Apr 29 2018, 16:14:56)
[GCC 7.2.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>>
```

Now you can install some useful packages:

``` sh
$ # New terminal
$ source .startConda2 # You can use dot '.' instead of the command 'source'
$ pip install numpy matplotlib scipy pandas scikit-learn imageio
```

``` sh
$ # New terminal
$ source .startConda3 # You can use dot '.' instead of the command 'source'
$ pip install numpy matplotlib scipy pandas scikit-learn imageio
```
