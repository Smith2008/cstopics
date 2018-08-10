---
layout: default
title: Segmentation, Edge and Region Detection, and Morphological Processing
permalink: /vision/4_morpho
---

# Segmentation, Edge and Region Detection, and Morphological Processing

## Basic Relationships between Pixels

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
