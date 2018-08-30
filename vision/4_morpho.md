---
layout: default
title: Segmentation, Edge and Region Detection, and Morphological Processing
permalink: /vision/4_morpho
---

<h1 style="text-align: center;">Morphological Processing</h1>

# Morphological operations

## Structuring element

Defined by:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
{\prod}_{xy}
"/>

It is usually square, and with odd dimensions.

Examples [Stanford2013]:

<div class="picture">
  <img style="width:80%;" src ="/cstopics/assets/img/vision/4_structures.png" />
</div>

Neighborhood "window" operator:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
W\{ f[x,y] \} = \{ f[x-x', y-y']:[x', y'] \in {\prod}_{xy} \}
"/>

## Dilation

Given a structuring element, it is sweeped through the binary image, checking that ***at least one*** of the structure pixels are over a 1 in the original image, if yes, the center of the structuring element becomes 1 in the original image.

Mathematical Definition:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
g \left[ x,y \right] = OR \left[ W \{f \left[ x,y \right] \} \right] := dilate(f,W)
"/>

For example [Gonzalez02], consider the following image ans structuring element:

<div class="picture">
  <img style="width:40%;" src ="/cstopicat least ones/assets/img/vision/4_image_structure.png" />
</div>

The process:

<div class="picture">
  <img style="width:30%;" src ="/cstopics/assets/img/vision/4_ex1_process.png" />
</div>

And the result:

<div class="picture">
  <img style="width:30%;" src ="/cstopics/assets/img/vision/4_ex1_result.png" />
</div>

Example 2, it thickens the text:

<div class="picture">
  <img style="width:60%;" src ="/cstopics/assets/img/vision/4_ex2.png" />
  <div>Original and dilated image. [Gonzalez02]</div>
</div>

Example 3 [Stanford2013]:

* Expands the size of 1-valued objects.
* Smoothes object boundaries.
* Closes holes and gaps.

<div class="picture">
  <img style="width:80%;" src ="/cstopics/assets/img/vision/4_ex3.png" />
</div>

## Erosion

Given a structuring element, it is sweeped through the binary image, checking that ***all of*** the structure pixels are over a 1 in the original image, if yes, the center of the structuring element becomes 1 in the original image, else,  it will be 0.

Mathematical definition;

<img class="eq" src="https://latex.codecogs.com/gif.latex?
g \left[ x,y \right] = AND \left[ W \{f \left[ x,y \right] \} \right] := erode(f,W)
"/>

For example [Gonzalez02], consider the following image ans structuring element:

<div class="picture">
  <img style="width:40%;" src ="/cstopics/assets/img/vision/4_ex1ero_image.png" />
</div>

The process:

<div class="picture">
  <img style="width:30%;" src ="/cstopics/assets/img/vision/4_ex1ero_process.png" />
</div>

And the result:

<div class="picture">
  <img style="width:30%;" src ="/cstopics/assets/img/vision/4_ex1ero_result.png" />
</div>

Example 2, original image, disk of radius 10, 5 and 20:

<div class="picture">
    <img style="width:50%;" src ="/cstopics/assets/img/vision/4_ex2ero.png" />
</div>

Example 3 [Stanford2013]:

* Shrinks the size of 1-valued objects.
* Smoothes object boundaries.
* Removes peninsulas, fingers, and small objects.

<div class="picture">
  <img style="width:80%;" src ="/cstopics/assets/img/vision/4_ex3ero.png" />
</div>

## Relationship between dilation and erosion

* ***Duality***: erosion is dilation of the background.

<img class="eq" src="https://latex.codecogs.com/gif.latex?
dilate(f,W) = NOT[erode(NOT[f],W)]
"/>

<img class="eq" src="https://la/cstopicat least ones/assets/img/tex.codecogs.com/gif.latex?
erode(f,W) = NOT[dilate(NOT[f],W)]
"/>

* ***But***: erosion is *not* the inverse of dilation

<img class="eq" src="https://latex.codecogs.com/gif.latex?
f[x,y] \neq erode \left( dilate \left( f,W \right) \right)
"/>

<img class="eq" src="https://latex.codecogs.com/gif.latex?
f[x,y] \neq dilate \left( erode \left( f,W \right) \right)
"/>

### Examples [Stanford2013]

 Blob separation/detection by erosion:

<div class="picture">
  <img style="width:100%;" src ="/cstopics/assets/img/vision/4_blob1.png" />
</div>

<div class="picture">
  <img style="width:100%;" src ="/cstopics/assets/img/vision/4_blob2.png" />
</div>

Chain link fence hole detection:

<div class="picture">
  <img style="width:100%;" src ="/cstopics/assets/img/vision/4_chain.png" />
</div>

## Opening and closing

* Open:

Removes small 1-regions.

<img class="eq" src="https://latex.codecogs.com/gif.latex?
open(f, W) = dilate( erode( (f,W), W ) )
"/>

* Close:

Removes small 0-regions.

<img class="eq" src="https://latex.codecogs.com/gif.latex?
close(f, W) = erode( dilate( (f,W), W ) )
"/>

### Examples [Stanford2013]

Small hole removal by closing:

<div class="picture">
  <img style="width:100%;" src ="/cstopics/assets/img/vision/4_smallholes.png" />
</div>

Morphological edge detectors

<div class="picture">
  <img style="width:100%;" src ="/cstopics/assets/img/vision/4_borders.png" />
</div>






# Basic Relationships between Pixels

### Neighbors of a Pixel

The pixel *p=f(x,y)*, has two vertical and two horizontal neighbors, that are the *4-neighbors* of *p*, and their distance from *p* is always *1*:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  N_4(p) = f(x+1,y),f(x-1,y),f(x,y+1),f(x,y-1)
"/>

The diagonal neighbors of *p* are:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  N_D(p) = f(x+1,y+1),f(x+1,y-1),f(x-1,y+1),f(x-1,y-1)
"/>

This two sets together are the *8-neighbors*:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  N_8(p) = N_4(p) \cup N_D(p)
"/>

If one of more of the *8-neighbors* pixels are outside the image, it means that *p* is on the border.

### Adjacency, Connectivity, Regions, and Boundaries

Let's define *V* as the set of intensity values that define adjacency. For a binary image (it has only intensity 0 or 1):

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  V = \{1\}
"/>

There are three types of adjacency:

1. **4-adjacency**. Two pixels *p* and *q* with values from *V* are 4-adjacent if *q* is in the set *N<sub>4</sub>(p)*.ftp://ftp.videolan.org/pub/debian/videolan-apt.asc
2. **8-adjacency**. Two pixels *p* and *q* with values from *V* are 8-adjacent if *q* is in the set *N<sub>8</sub>(p)*.
3. **m-adjacency** (mixed adjacency). Two pixels *p* and *q* with values from *V* are m-adjacent if:
    * *q* is in *N<sub>4</sub>(p)*, or
    * *q* is in *N<sub>D</sub>(p)* and the set *N<sub>4</sub>(p) &cap; N<sub>4</sub>(q)* has no pixels whose values are from *V*.

Difference between **8-adjacency** and **m-adjacency**:

<div class="picture">
  <img style="width:60%;" src ="/cstopics/assets/img/vision/0_8vsS.png" />
</div>

A *path* from *p=(x,y)* to *q=(s,t)*, is a sequence of adjacent pixels that are in *V*:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  P = (x_0,y_0),(x_1,y_1),...,(x_n,y_n)
"/>

Where *n* is the length of the path, and:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  (x_0,y_0) = (x,y)
"/>
<img class="eq" src="https://latex.codecogs.com/gif.latex?
  (x_n,y_n) = (s,t)
"/>

The condition to be a path, is that:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  (x_i,y_i) and (x_{i-1}, y_{i-1})
"/>

are adjacent for *1 &le; i &le; n*.

<div class="picture">
  <img style="width:40%;" src ="/cstopics/assets/img/vision/4_paths.png" />
  <div>Paths with 8-adjacency vs m-adjacency</div>
</div>

Being *S* a subset of pixels in an image, *p* and *q* are connected when there is at least one path between them, and the path pixels belong to *S*.

## References

* [Gonzalez02] Gonzalez R. C., Woods R. E. Digital Image Processing. 2nd Ed. Prentice Hall. 2002.

* [Stanford2013] Morphological Image Processing. Stanford University. https://web.stanford.edu/class/ee368/Handouts/Lectures/2014_Spring/Combined_Slides/7-Morphological-Image-Processing-Combined.pdf
