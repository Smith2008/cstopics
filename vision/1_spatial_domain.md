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

It is used to combine two images:

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

## Histogram equalization

The histogram is essentially a probability function, and the idea of the histogram equalization is to convert it in a flat function, using all the intensities. This operation can be done calculating the normalized distribution function, and multiplying it by *L-1*. This could be used as a LUT to map the new pixel values.

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  c(I)=(L-1)\frac{1}{N}\sum^{i=0}_{I}{h(i)}
"/>

Where *h* is the original histogram, and *c* should be the LUT.

Example:

<div class="picture">
  <img style="width:90%;" src ="/cstopics/assets/img/vision/1_histeq.png" />
</div>

Sometimes the histogram equalization does not work well enough, so you can parform blend between the original and the equalized image.

<div class="picture">
  <img style="width:90%;" src ="/cstopics/assets/img/vision/1_eqblend.png" />
  <div>[Szeliski11]</div>
</div>

Other methods:

<div class="picture">
  <img style="width:90%;" src ="/cstopics/assets/img/vision/1_eqlocal.png" />
  <div>[Szeliski11]</div>
</div>

# Linear filtering (neighborhood operator)

Linear filters can be performed as a correlation operation:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g = f \otimes h
"/>

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g(i,j) = \sum_{k,l}f(i+k, j+l)h(k,l)
"/>

Where *g* is the filtered image, *f* is the original image and *h* is the filter, whose value are called *filter coefficients*, and **the sum of them must be *1.0***.

<div class="picture">
  <img style="width:90%;" src ="/cstopics/assets/img/vision/1_linear_filter.png" />
  <div>[Szeliski11]</div>
</div>

The linear filter can also be executed as a convolution operation:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g = f \ast h
"/>

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g(i,j) = \sum_{k,l}f(i-k, j-l)h(k,l) = \sum_{k,l}f(k, l)h(i-k,j-l)
"/>

Correlation and convolution are shift-invariant operations, but a shift-variant version could be used:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  g(i,j) = \sum_{k,l}f(i-k, j-l)h(k,l;i,j)
"/>

## Padding (border effect)

When border pixel are calculated, the filter need pixels that outside the image, there are some processes to face this problem:

* ***zero***: read the outside pixels as zero.
* ***constant***: read the outside pixels as a specific value, usually L/2.
* ***clamp***: repeat the border pixels.
* ***wrap***: loop “around” the image in a “toroidal” configuration.
* ***mirror***: reflect the image.

<div class="picture">
  <img style="width:90%;" src ="/cstopics/assets/img/vision/1_padding.png" />
  <div>[Szeliski11]</div>
</div>

## Typical filters

### Average (mean) filter

5x5 filter:

| 1/25 | 1/25 | 1/25 | 1/25 | 1/25 |
|------|------|------|------|------|
| 1/25 | 1/25 | 1/25 | 1/25 | 1/25 |
| 1/25 | 1/25 | 1/25 | 1/25 | 1/25 |
| 1/25 | 1/25 | 1/25 | 1/25 | 1/25 |
| 1/25 | 1/25 | 1/25 | 1/25 | 1/25 |

Example:

<div class="picture">
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_avg_0.gif" />
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_avg_1.gif" />
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_avg_2.gif" />
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_avg_3.gif" />
  <div>Original, 3x3, 5x5, 7x7 (https://homepages.inf.ed.ac.uk/rbf/HIPR2/filtops.htm)</div>
</div>

<div class="picture">
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_avg2_0.gif" />
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_avg2_1.gif" />
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_avg2_2.gif" />
  <div>Original, 3x3, 5x5, (https://homepages.inf.ed.ac.uk/rbf/HIPR2/filtops.htm)</div>
</div>

### Gaussian filter

Modeled by:

<div class="picture">
  <img style="width:30%;" src ="/cstopics/assets/img/vision/1_gauss_eq.png" />
</div>

<div class="picture">
  <img style="width:40%;" src ="/cstopics/assets/img/vision/1_gauss_plot.png" />
</div>

<div class="picture">
  <img style="width:40%;" src ="/cstopics/assets/img/vision/1_gauss_table.png" />
</div>

Examples:

<div class="picture">
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_gaus1_0.gif" />
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_gaus1_1.gif" />
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_gaus1_2.gif" />
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_filter_gaus1_4.gif" />
  <div>Original, 5x5, 9x9, 15x15 (https://homepages.inf.ed.ac.uk/rbf/HIPR2/filtops.htm)</div>
</div>

### Sobel filters

Gradients in *x* and *y* are calculated.

<div class="picture">
  <img style="width:70%;" src ="/cstopics/assets/img/vision/1_sobel_eq.png" />
</div>

Then, the magnitude and direction can be computed:

<div class="picture">
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_sobel_mg.png" />
  <img style="width:20%;" src ="/cstopics/assets/img/vision/1_sobel_ph.png" />
</div>

Examples:

<div class="picture">
  <img style="width:30%;" src ="/cstopics/assets/img/vision/1_sobel1_0.png" />
  <img style="width:30%;" src ="/cstopics/assets/img/vision/1_sobel1_1.png" />
  <img style="width:30%;" src ="/cstopics/assets/img/vision/1_sobel1_2.png" />
</div>

<br>

<div class="picture">
  <img style="width:45%;" src ="/cstopics/assets/img/vision/1_sobel2_0.jpg" />
  <img style="width:45%;" src ="/cstopics/assets/img/vision/1_sobel2_1.jpg" />
  <img style="width:45%;" src ="/cstopics/assets/img/vision/1_sobel2_2.jpg" />
  <img style="width:45%;" src ="/cstopics/assets/img/vision/1_sobel2_3.jpg" />
</div>

# References

* [Gonzalez02] Gonzalez R. C., Woods R. E. Digital Image Processing. 2nd Ed. Prentice Hall. 2002.
* [Szeliski11] Szeliski R. Computer Vision, Algorithms and Applications. 1st Ed. Springer. 2011.
