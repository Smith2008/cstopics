---
layout: default
title: TensorFlow & Cuda Installation
permalink: /vision/lectures/tensorflow_cuda
---

# Installation of Tensoflow with GPU (Cuda)

This guide was tested with **Ubuntu 16.04** and a **Nvidia GeForce GTX 1070 Ti**.

Be sure you have your OS updated:

``` bash
$ sudo apt-get update
$ sudo apt-get upgrade
```

And install some dependencies:

``` bash
$ sudo apt-get install openjdk-8-jdk git python-dev python3-dev python-numpy python3-numpy build-essential python-pip python3-pip python-virtualenv swig python-wheel libcurl3-dev curl
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
$ sudo bash cuda_9.0.176_384.81_linux.run
```

Follow the instructions, and install examples and symbolic links. Then install the patches:

``` bash
$ sudo bash cuda_9.0.176.1_linux.run
$ sudo bash cuda_9.0.176.2_linux.run
$ sudo bash cuda_9.0.176.3_linux.run
$ sudo bash cuda_9.0.176.4_linux.run
```
Follow the instructions each installer. Now, let's test the installation, go to the Nvidia samples folder and run the *deviceQuery* sample:

``` bash
$ cd ~/NVIDIA_CUDA-9.0_Samples/1_Utilities/deviceQuery
$ make run
```

It must compile the sample, and show something like:

```
...
 CUDA Device Query (Runtime API) version (CUDART static linking)

Detected 1 CUDA Capable device(s)

Device 0: "GeForce GTX 1070 Ti"
  CUDA Driver Version / Runtime Version          10.1 / 9.0
...
Result = PASS
```

It means that CUDA is running and your GPU was detected by it.

## cuDNN

Go to the [Nvidia cuDNN download web page](https://developer.nvidia.com/rdp/form/cudnn-download-survey){:target="blank"}, register and/or login, then check "I Agree To the Terms..." / "Download cuDNN v7.5.0 (Feb 21, 2019), for CUDA 9.0", and download:

* cuDNN Runtime Library for Ubuntu16.04 (Deb)
* cuDNN Developer Library for Ubuntu16.04 (Deb)

I saved them in *~/installers/cuda9.0/*, install them (first the runtime library, and then the developer pack):


``` bash
$ cd ~/installers/cuda9.0/
$ sudo dpkg -i libcudnn7_7.5.0.56-1+cuda9.0_amd64.deb
$ sudo dpkg -i libcudnn7-dev_7.5.0.56-1+cuda9.0_amd64.deb
```

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

Then create the tenforflow enviroment:

``` bash
conda create -n tensorflow-gpu python=3.6
source activate tensorflow-gpu  
pip install --upgrade pip
```

## Tensorflow

``` bash
$ source activate tensorflow-gpu  
$ pip install tensorflow-gpu==1.12
```

Test:

``` bash
$ source activate tensorflow-gpu  
$ python
```

``` python
import tensorflow as tf   

hello = tf.constant('Hello, TensorFlow!')

# when you run sess, you should see a bunch of lines with the word gpu in them (if install worked)
# otherwise, not running on gpu
sess = tf.Session()
print(sess.run(hello))
```
