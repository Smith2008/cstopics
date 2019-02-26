---
layout: default
title: Tensoflow & Cuda Installation
permalink: /vision/lectures/tensorflow_cuda
---

# Tensoflow & Cuda Installation

This guide was tested with **Ubuntu 16.04** and a **Nvidia GeForce GTX 1070 Ti**.

Be sure you have your OS updated:

``` bash
$ sudo apt-get update
$ sudo apt-get updgrade
```

## Nvidia drivers

Then, go to the [Nvidia drivers web page](https://www.nvidia.es/Download/index.aspx){:target="blank"}, and select your GPU model, Linux  64-bit, and English (US), then click *SEARCH*. The last version will be showed (it was 418.43 when this guide was written), download it. I downloaded it in *~/installers/cuda9.0/*.

Press *ctrl+alt+F1* to get to a terminal screen, login, and create the next file:

``` bash
$ sudo nano /etc/modprobe.d/nouveau-blacklist.conf
```

And add the lines below:

```
blacklist nouveau
options nouveau modeset=0
```

Regenerate the kernel initramfs:

``` bash
$ sudo update-initramfs -u
```

And reboot:

``` bash
$ reboot
```

On reboot, press *ctrl+alt+F1* again, login, and check that noveau drivers are not loaded (nothing should appear):

``` bash
$ lsmod | grep nouveau
```

Stop the x-server

``` bash
$ sudo service lightdm stop
```

And then, install the driver:

``` bash
$ cd ~/installers/cuda9.0/
$ sudo bash NVIDIA-Linux-x86_64-418.43.run
```

Follow the instructions, and continue ignoring the warnings the installer presents to you. Then reboot:

``` bash
$ reboot
```

Now you can work in the GUI terminal again, test the installation checking the following program:

``` bash
$ nvidia-settings
```

It must show information about your GPU.

## CUDA Toolkit 9.0

Go to the [CUDA Toolkit 9.0 download web page](https://developer.nvidia.com/cuda-90-download-archive){:target="blank"} and select Linux / x86_64 / Ubuntu / 16.04 / runfile(local), then download the Base Installer and all the patches (4 at the time of writing this guide). I saved in *~/installers/cuda9.0/*.

Execute the CUDA installer:

``` bash
$ cd ~/installers/cuda9.0/
$ sudo bash sudo sh cuda_9.0.176_384.81_linux.run
```

Follow the instructions, and install examples and symbolic links. Then install the patches:

``` bash
$ sudo bash sudo sh cuda_9.0.176...
$ sudo bash sudo sh cuda_9.0.176...
$ sudo bash sudo sh cuda_9.0.176...
$ sudo bash sudo sh cuda_9.0.176...
```

In progress...

(Include example of testins Nvidia Samples)

It means that CUDA is running and your GPU was detected by it.

## cuDNN

In progress...

## Anaconda & Tensorflow

In progress...

Run any example...
