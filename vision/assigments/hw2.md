---
layout: default
title: Homework 2
permalink: /vision/assignments/hw2
---

# Homework 2

Write a python script that blends two images, and shows the result.

<div class="picture">
  <img style="width:70%;" src ="/cstopics/assets/img/vision/1_blend1.png" />
  <div>alpha=0.25</div>
</div>

The program must show error if the images do not have the same dimensions.

The script's name must be *'blend_process.py'*, and receives arguments with the following format:

``` sh
$ python linear_process.py [flag1] [value1] [flag2] [value2] [flag3] [value3] ...
```

Mandatory arguments:
* *-i*: path to the first input image.
* *-j*: path to the second input image.
* *-o*: operation, could be: *normal_blend*, *x_blend* or *y_blend*.

Operation dependent arguments:
* ***normal_blend***:
    * *-a*: alpha (decimal number)

For example:

``` sh
$ python linear_process.py -i cat.jpg -i dog.jpg -o normal_blend -a 0.4
```

The *x_blend* option computes an image as this:

<div class="picture">
  <img style="width:35%;" src ="/cstopics/assets/img/vision/1_blend_linear.png" />
</div>

And the *gain_x* option creates the same effect but in the *y* axis.


Create a new folder named *"hw2"* in your *lab1* repository, and add all your homework files.

When the homework is ready, download the repository as a *.zip* file and upload it to the appropriate link in moodle.

Deadline: Ago 20, 23:55
