---
layout: default
title: Homework 1
permalink: /vision/assignments/hw1
---

# Homework 1

Write a python script that performs the point operations studied.

The script's name must be *'linear_process.py'*, and receives arguments with the following format:

``` sh
$ python linear_process.py [flag1] [value1] [flag2] [value2] [flag3] [value3] ...
```

Mandatory arguments:
* *-i*: path to the input image.
* *-o*: operation, could be: *gain_bias*, *gamma_correction*, *gain_x*, *gain_y* or *negative*.

Operation dependent arguments:
* ***gain_bias***:
    * *-a*: alpha (decimal number)
    * *-b*: beta (integer number)
* ***gamma_correction***:
    * *-g*: gamma (decimal number)

For example:

``` sh
$ python linear_process.py -i cat.jpg -o gain_bias -a 0.9 -b 22
```

The *gain_y* option computes an image as this:

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/1_linear5.png" />
  <div>Alpha goes from 1 to 0 as y increases.</div>
</div>

And the *gain_x* option creates the same effect but in the *x* axis.

The program must show a 2x2 subplot grid, containing the original image, original histogram, new image and new histogram.

The folder have to include the *linear_process.py*, two sample images, and a pdf file that explain various combination of arguments and them result.

Create a new **private** Bitbucket repository named *"2018_2_av_lab1_Lastname1Firstname1_Lastname2Firstname2"* (E.g. *"2018_2_av_lab1_CamachoCamilo_SuarezYeison"*),  share it with the account *"camilocamachousta"*. Inside it, create a new folder named *"hw1"*, and add all your homework files.

When the homework is ready, download the repository as a *.zip* file and upload it to the appropriate link in moodle.

Deadline: Ago 20, 23:55
