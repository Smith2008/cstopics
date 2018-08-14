---
layout: default
title: Processing in the Spatial Domain
permalink: /vision/1_spatial_domain
---

<h1 style="text-align: center;">Processing in the Spatial Domain</h1>

# Color models

Color models are mathematical representations of the color captured by a camera.

## RGB

Represents any color as the set of red, green and blue intensities. It use to be the model that a camera or color sensor gives. Each channel is usually represented for integer in the range [0, 155] for 8 bits systems, or floating point number in the range [0, 1].

<div class="picture">
  <img style="width:90%;" src ="/cstopics/assets/img/vision/1_rgb_cube.png" />
  <div>RGB cube. (https://commons.wikimedia.org/wiki/File:RGB_color_cube.svg)</div>
</div>

Examples:

<p style="background-color:rgb(0, 0, 0);">rgb(0, 0, 0)</p>
<p style="background-color:rgb(255, 0, 0);">rgb(255, 0, 0)</p>
<p style="background-color:rgb(0, 255, 0);">rgb(0, 255, 0)</p>
<p style="background-color:rgb(0, 0, 255);">rgb(0, 0, 255)</p>
<p style="background-color:rgb(255, 255, 0);">rgb(255, 255, 0)</p>
<p style="background-color:rgb(255, 0, 255);">rgb(255, 0, 255)</p>
<p style="background-color:rgb(0, 255, 255);">rgb(0, 255, 255)</p>
<p style="background-color:rgb(255, 255, 255);">rgb(255, 255, 255)</p>

## HSV and HSL

***Hue, Saturation, Value*** model and ***Hue, Saturation, Lightness*** models represents the color with the corresponding components.  

<div class="picture">
  <img style="width:60%;" src ="/cstopics/assets/img/vision/1_hls_hsv.png" />
  <div>HSL and HSV representations. (https://en.wikipedia.org/wiki/Color_model)</div>
</div>

Examples:

<p style="background-color:hsl(0, 100%, 0%);">hsl(0, 100%, 0%)</p>
<p style="background-color:hsl(0, 100%, 25%);">hsl(0, 100%, 25%)</p>
<p style="background-color:hsl(0, 100%, 50%);">hsl(0, 100%, 50%)</p>
<p style="background-color:hsl(0, 100%, 75%);">hsl(0, 100%, 75%)</p>
<p style="background-color:hsl(0, 100%, 100%);">hsl(0, 100%, 100%)</p>

<p style="background-color:hsl(120, 100%, 0%);">hsl(120, 100%, 0%)</p>
<p style="background-color:hsl(120, 100%, 25%);">hsl(120, 100%, 25%)</p>
<p style="background-color:hsl(120, 100%, 50%);">hsl(120, 100%, 50%)</p>
<p style="background-color:hsl(120, 100%, 75%);">hsl(120, 100%, 75%)</p>
<p style="background-color:hsl(120, 100%, 100%);">hsl(120, 100%, 100%)</p>

<p style="background-color:hsl(240, 100%, 0%);">hsl(240, 100%, 0%)</p>
<p style="background-color:hsl(240, 100%, 25%);">hsl(240, 100%, 25%)</p>
<p style="background-color:hsl(240, 100%, 50%);">hsl(240, 100%, 50%)</p>
<p style="background-color:hsl(240, 100%, 75%);">hsl(240, 100%, 75%)</p>
<p style="background-color:hsl(240, 100%, 100%);">hsl(240, 100%, 100%)</p>

## YUV

<div class="picture">
  <img style="width:40%;" src ="/cstopics/assets/img/vision/1_YUV.png" />
  <div>YUV representation with Y=0.5 (https://es.wikipedia.org/wiki/YUV)</div>
</div>

<div class="picture">
  <img style="width:40%;" src ="/cstopics/assets/img/vision/1_YUV0.png" />
  <div>YUV representation with Y=0.0</div>
</div>

<div class="picture">
  <img style="width:40%;" src ="/cstopics/assets/img/vision/1_YUV1.png" />
  <div>YUV representation with Y=1.0</div>
</div>

# Point Operators

Point operators (or point processes) are the simplest way to process image. The result of these operators is calculated from the corresponding pixel in the original image. The point operators produces pixels tranforms, that can be denoted as:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g(\mathbf{x})=h(f(\mathbf{x}))
"/>

or:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g(\mathbf{x})=h(f_0(\mathbf{x}), f_1(\mathbf{x}), ...)
"/>

Where ***x*** is the pixel location *(i,j)*, *g* is the output image and *f(f)* is the input images.

### Brightness and contrast

The commonly transformation is:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g(\mathbf{x})=af(\mathbf{x})+b
"/>

Whose parameters are:

* ***a***: gain, that controls *contrast*.
* ***b***: bias, that controls *brightness*.

Examples:

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/1_linear1.png" />
  <div>Original image.</div>
</div>

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/1_linear2.png" />
  <div>alpha = 1.0, beta = 70.0</div>
</div>

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/1_linear3.png" />
  <div>alpha = 1.5, beta = 0.0</div>
</div>

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/1_linear4.png" />
  <div>alpha = 2.0, beta = -50.0</div>
</div>

The parameters can depend on the ***x*** location:
<p style="background-color:hsl(240, 100%, 100%);">hsl(240, 100%, 100%)</p>
<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g(\mathbf{x}) = a(\mathbf{x})f(\mathbf{x})+b(\mathbf{x})
"/>

Example:

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/1_linear5.png" />
  <div>Alpha goes from 1 to 0 as y increases.</div>
</div>

As this is a linear transformation, the superposition principle is satisfied:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  h(f_0+f_1) = h(f_0) + h(f_1)
"/>

### Blend

It is used to miColor transformsx two images:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g(\mathbf{x}) = (1-\alpha)f_0(\mathbf{x})+\alpha f_1(\mathbf{x})
"/>

Where &alpha; goes from 0 to 1.

Example:

<div class="picture">
  <img style="width:70%;" src ="/cstopics/assets/img/vision/1_blend1.png" />
  <div>alpha=0.25</div>
</div>

<div class="picture">
  <img style="width:70%;" src ="/cstopics/assets/img/vision/1_blend2.png" />
  <div>alpha=0.5</div>
</div>

<div class="picture">
  <img style="width:70%;" src ="/cstopics/assets/img/vision/1_blend3.png" />
  <div>alpha=0.75</div>
</div>

<div class="picture">
  <img style="width:30%;" src ="/cstopics/assets/img/vision/1_blend4.png" />
  <div>Alpha changes with x</div>
</div>

### Gamma correction

Used to invert the gamma mapping applied by some cameras:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g(\mathbf{x}) = f(\mathbf{x})^{\frac{1}{\gamma}}
"/>

<div class="picture">
  <img style="width:60%;" src ="/cstopics/assets/img/vision/1_gamma_curve.png" />
  <div>gamma=[1.0, 0.8, 2.2]</div>
</div>

When input image *f* is normalized in the range *[0, 1]*.

Example:

<div class="picture">
  <img style="width:70%;" src ="/cstopics/assets/img/vision/1_gamma.png" />
  <div>gamma=[1.0, 0.8, 2.2]</div>
</div>

### Negative

Output is:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g(\mathbf{x}) = L-f(\mathbf{x})-1
"/>

Example:

<div class="picture">
  <img style="width:30%;" src ="/cstopics/assets/img/vision/1_negative.png" />
  <div>gamma=[1.0, 0.8, 2.2]</div>
</div>

## Color transforms

When you think about adding brightness to a color image, the first operation you could apply is to add a specific value to all the channels. Let's with the following color:

<p style="background-color:rgb(123, 66, 163); color: white;">rgb(123, 66, 163)</p>

Adding 50 to each channel, you get:

<p style="background-color:rgb(173, 116, 213); color: white;">rgb(173, 116, 213)</p>

In both cases, you could convert to HSV or HSL models [here](https://www.rapidtables.com/convert/color/rgb-to-hsv.html), and check that the Hue value is the same, and the Saturation and Value or Lightness change, if you want to change just one of them, you sould convert to HSV or HSL models, change the specific value, and return to RGB again.

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  rgb(123, 66, 163) = hsv(275°, 59.5\%, 63.9\%)
"/>

Adding 30 to saturation, you get:

<p style="background-color:rgb(102, 17, 163); color: white;">rgb(102, 17, 163)</p>

And adding 30 to value, you get:

<p style="background-color:rgb(180, 97, 239); color: white;">rgb(180, 97, 239)</p>

Image example:

<div class="picture">
  <img style="width:70%;" src ="/cstopics/assets/img/vision/1_rgb_linear.png" />
  <div>alpha=1.0, beta=50</div>
</div>

# References

* [Gonzalez02] Gonzalez R. C., Woods R. E. Digital Image Processing. 2nd Ed. Prentice Hall. 2002.
