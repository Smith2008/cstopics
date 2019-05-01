---
layout: default
title: TensorFlow Installation
permalink: /vision/lectures/tensorflow_env
---

# Installation of Tensoflow in Anaconda

## Anaconda

Download [Anaconda 3 from here](https://www.anaconda.com/distribution/#download-section){:target="blank"} and install it:

``` bash
$ cd ~/installers/
$ chmod +x Anaconda3-2018.12-Linux-x86_64.sh
$ ./Anaconda3-2018.12-Linux-x86_64.sh
```

Follow the instructions. Reload bashrc:

``` bash
$ source ~/.bashrc
```

## Course enviroment

*Note: If your computer has a NVIDIA GPU, and you want to use it to train your models, skip to Using GPU section*.

In order to install automatically all the packages you need for the course, you can download [this *yml* file](https://raw.githubusercontent.com/cstopics/cstopics/gh-pages/assets/anaconda_enviroments/tf_vision.yml){:target="blank"}, and run in your terminal:

``` bash
$ conda env create -n tf_vision -f tf_vision.yml
```

*Note: If you get problems creating the enviroment automatically, then create the enviroment empty, open the yml file with a text editor, and install each package manually with pip.*

To start using your new environment, execute in your terminal:

``` bash
$ source activate tf_vision
```

## Using GPU

If you have a NVIDIA GPU, you can use it to train your models, but the installation process is quite different.

***Advantage of using GPU:*** Your models will train faster (very faster).

***Disadvantage of using GPU:*** The installation is a little painful, and sometimes you can broke your Linux installation. (But you need to do it only once).

If you want it, follow [this guide](/cstopics/vision/lectures/tensorflow_cuda){:target="blank"}, and then, install the *tf_vision.yml* packages manually using *pip* (except *tensorflow*, that would already be installed).
