---
layout: default
title: Digital Image Fundamentals
permalink: /vision/0_fundamentals
---

# Digital Image Fundamentals

## Applications Examples

### Image Filtering and Restoration

<div class="picture">
  <img style="width:75%;" src ="/cstopics/assets/img/vision/0_app1.jpg" />
  <div>https://in.mathworks.com/matlabcentral/fileexchange/21357-homomorphic-filtering</div>
</div>

<div class="picture">
  <img style="width:75%;" src ="/cstopics/assets/img/vision/0_app2.jpg" />
  <div>http://what-when-how.com/embedded-image-processing-on-the-tms320c6000-dsp/image-enhancement-via-spatial-filtering-image-processing-part-2/</div>
</div>

### Perspective Correction

<div class="picture">
  <img style="width:75%;" src ="/cstopics/assets/img/vision/0_app3.png" />
  <div>https://www.quora.com/Do-you-need-perspective-correction-camera-mistake-correction-for-photos</div>
</div>

### Morphological Analysis

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/0_app4.png" />
  <div>https://www.semanticscholar.org/paper/9359-(-Volume-3-%2C-Issue-8-)-PCB-Defect-Detection-Kamalpreet/592fd41d58ac50a38da9a8d9dd55ad34ec3e1a00</div>
</div>

### Object Detection

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/0_app5.png" />
  <div>https://www.google.com.co/url?sa=i&source=imgres&cd=&ved=2ahUKEwj-wrHQl8_cAhUD0FkKHS4VB9cQjhx6BAgBEAM&url=https%3A%2F%2Fjoshua19881228.github.io%2F2017-06-13-An-Introduction-to-CNN-based-Object-Detection%2F&psig=AOvVaw2cN_cuG7dZMuVB0nv3WHDA&ust=1533327347325700</div>
</div>

### Traffic Analysis

<div style="text-align:center">
  <iframe width="420" height="345" src="https://www.youtube.com/embed/F_M_skebbpA?t=29">
  </iframe>
</div>

<div style="text-align:center">
  <iframe width="420" height="345" src="https://www.youtube.com/embed/xVwsr9p3irA">
  </iframe>
</div>

### Object Tracking

<div style="text-align:center">
  <iframe width="420" height="345" src="https://www.youtube.com/embed/SKXk6uB8348">
  </iframe>
</div>

<div style="text-align:center">
  <iframe width="420" height="345" src="https://www.youtube.com/embed/CigGvt3DXIw?t=5">
  </iframe>
</div>

### Augmented Reality

<div style="text-align:center">
  <iframe width="420" height="345" src="https://www.youtube.com/embed/z2gqshFr4AI?t=10">
  </iframe>
</div>

<div style="text-align:center">
  <iframe width="420" height="345" src="https://www.youtube.com/embed/wwmmgAw8ZAE?t=3">
  </iframe>
</div>

## Elements of Visual Perception

### Structure of the Human Eye

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/0_eye.png" />
  <div>Simplified diagram of a cross section of the human eye. [Gonzalez02]</div>
</div>

* The **Cornea** is a tough, transparent tissue that covers the anterior surface of the eye.
* The **Sclera** is an opaque membrane that encloses the remainder of the optic globe.
* The **Choroid** contrarians the blood vessels, which are the major source of nutrition to the eye.
* The **lens** is made up ofs concentric layer of fibers cells and is supported by fibers that attach to the ciliary body.
* The **Retina** lines the inside of the wall’s entire posterior portion. Its surface include two classes of light receptors: cones and rods.
* The **cones** lies on the fovea and highly sensitive to color (6-7 million in each eye). They solve fine details because each one them is connected to its own nerve end.
* The **rods** (75-150 million), which are distributed over the retinal surface and serves to give general overall picture of the field of view and are sensitive to low level illumination. Are connected to a unique nerve.

The following image shows the density of rods and cones for a cross section of the right eye passing through the region of emergence of the optic nerve from the eye.

<div class="picture">
  <img style="width:70%;" src ="/cstopics/assets/img/vision/0_rods_cones.png" />
  <div>Distribution of rods and cones in the retina. [Gonzalez02]</div>
</div>

### Image Formation in the Eye

<div class="picture">
  <img style="width:70%;" src ="/cstopics/assets/img/vision/0_image_formation.png" />
  <div>Graphical representation of the eye looking at a palm tree. Point C is the optical center of the lens. [Gonzalez02]</div>
</div>

Distance between the center of the lens and the retina: 14mm to 17mm (latter when focusing objects at 3 meters).

Size of the image projected on the retina:

  <img class="eq" src="https://latex.codecogs.com/gif.latex?
    \frac{15}{100}=\frac{h}{17} \rightarrow h=2.55mm
  "/>

### Human Perception Phenomena

Mach bands:

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/0_ph1.png" />
  <div>Illustration of the Mach band effect. Perceived intensity is not a simple function of actual intensity. [Gonzalez02]</div>
</div>

Simultaneous Contrast:

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/0_ph2.png" />
  <div>Examples of simultaneous contrast. All the inner squares have the same intensity, but they appear progressively darker as the background becomes lighter. [Gonzalez02]</div>
</div>

The eye fills in nonexisting information or wrongly perceives geometrical properties of objects. Optical illusions are a characteristic of the human visual system that is not fully understood.

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/0_ph3.png" />
  <div>Some well-known optical illusions. [Gonzalez02]</div>
</div>

## Image Sampling and Quantization

### Light and the Electromagnetic Spectrum

<div class="picture">
  <img style="width:100%;" src ="/cstopics/assets/img/vision/0_spectrum.png" />
  <div>Visible light is only a small portion of the electromagnetic spectrum. (https://en.wikipedia.org/wiki/Visible_light_communication)</div>
</div>

### Image Sensing and Acquisition

Below is shown the basic structure of an image sensor, or camera. The filter element can allow the pass of the complete visible spectrum (400nm to 700nm) for monochromatic sensing, or can filter the red, green or blue component.

<div class="picture">
  <img style="width:90%;" src ="/cstopics/assets/img/vision/0_sensor.png" />
  <div>Image sensor structure. [Gonzalez02]</div>
</div>

### Image Formation Model

Image acquisition process:

<div class="picture">
  <img style="width:80%;" src ="/cstopics/assets/img/vision/0_acq.png" />
  <div>Image sensor structure. [Gonzalez02]</div>
</div>

An image is described as a two dimensional function of the next form:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  f(x,y)
"/>

### Sampling and Quantization

Sampling: Spatial.
Quantization: Intensity.

<div class="picture">
  <img style="width:60%;" src ="/cstopics/assets/img/vision/0_sampling.png" />
  <div>Generating a digital image. [Gonzalez02]</div>
</div>

<br>

<div class="picture">
  <img style="width:60%;" src ="/cstopics/assets/img/vision/0_sampling2.png" />
  <div>(a) Continuous image projected onto a sensor array. (b) Result of image sampling and quantization. [Gonzalez02]</div>
</div>

We have *f(x,y)* as a discrete function, containing *M* rows and *N* columns, and *(x,y)* being discrete coordinates. In this way, *x* can be *0, 1, 2, ..., M-1* and *y* can be *0, 1, 2, ..., N-1*.

In general *(x, y)* are integers, and are referred to as spatial variables or spatial coordinates. Below are shown are three basic ways to represent *f(x,y)*.

<div class="picture">
  <img style="width:60%;" src ="/cstopics/assets/img/vision/0_representation.png" />
  <div>(a) Image plotted as a surface. (b) Image displayed as a visual intensity array. (c) Image shown as a 2-D numerical array (0, .5, and 1 represent black, gray, and white, respectively). [Gonzalez02]</div>
</div>

In addition, numerical representation can be expressed as:

<div class="picture">
  <img style="width:50%;" src ="/cstopics/assets/img/vision/0_math1.png" />
</div>

Or:

<div class="picture">
  <img style="width:40%;" src ="/cstopics/assets/img/vision/0_math2.png" />
</div>

Considering the hardware storage woking, when quantization is performed, the number of intensity levels are usually an integer power of 2:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  L=2^k
"/>

Where *k* is the amount of bits. Intensities are in the range *[0, L-1]*.

### Spatial Resolution

When we include spatial units, and relation them with the amount of pixels, we get the spatial resolution, that indicates the number of pixels per spatial unit. In the U.S. standard, it is used de dots per inch (dpi) unit. Below it is shown the effect of changing the spatial resolution.

<div class="picture">
  <img style="width:60%;" src ="/cstopics/assets/img/vision/0_spatial_resoulution.png" />
  <div>Typical effects of reducing spatial resolution. Images shown at: (a) 1250 dpi, (b) 300 dpi, (c) 150 dpi, and (d) 72 dpi. The thin black borders were added for clarity. They are not part of the data. [Gonzalez02]</div>
</div>

### Intensity Resolution

It is related to the number of intensity levels. The following image shows the effect of changing the Intensity Resolution. (Reducing the number of bits from k = 7 to k = 1).

<div class="picture">
  <img style="width:60%;" src ="/cstopics/assets/img/vision/0_intensity1.png" />
</div>
<div class="picture">
  <img style="width:60%;" src ="/cstopics/assets/img/vision/0_intensity2.png" />
  <div>(a) 452 * 374, 256-level image. (b)–(d) Image displayed in 128, 64, and 32 intensity levels, while keeping the image size constant. (e)–(h) Image displayed in 16, 8, 4, and 2 intensity levels. (Original courtesy of Dr. David R. Pickens, Department of Radiology & Radiological Sciences, Vanderbilt University Medical Center.)[Gonzalez02]</div>
</div>

### Relationship Between Spatial Resolution and Intensity Resolution

Test images:

<div class="picture">
  <img style="width:100%;" src ="/cstopics/assets/img/vision/0_test_images.png" />
  <div>(a) Image with a low level of detail. (b) Image with a medium level of detail. (c) Image with a relatively large amount of detail. (Image (b) courtesy of the Massachusetts Institute of Technology.))[Gonzalez02]</div>
</div>

Isopreference curve (Subjective test results, where people choose the preferred combination of *N* and *k*):

<div class="picture">
  <img style="width:30%;" src ="/cstopics/assets/img/vision/0_isopreference.png" />
  <div>Typical isopreference curves for the three types of images[Gonzalez02]</div>
</div>

## References

* [Gonzalez02] Gonzalez R. C., Woods R. E. Digital Image Processing. 2nd Ed. Prentice Hall. 2002.
