---
layout: default
title: Background & Foreground Extraction
permalink: /vision/7_background
---

<h1 style="text-align: center;">Background & Foreground Extraction</h1>

## Foreground extraction logic

The idea of extracting the foreground is to identify the objects that are not part of the background, i.e., the objects different from those present in the static scene.

To identify the foreground, you must have a model of the background, and calculate the difference between this one and the current frame:

<div class="picture">
  <img style="width:70%;" src ="/cstopics/assets/img/vision/7_process.png" />
  <div>https://docs.opencv.org/3.2.0/d1/dc5/tutorial_background_subtraction.html</div>
</div>

When a new frame is computed, the background model is updated and the process is repeated every frame.

The challenge of BS (Background Subtraction) is to model the background correctly.

## Background modeling

### Average concept

If we think about background, you could assume that it is static, and the camera will capture it always with the same pixels, with similar values, and at the same position, i.e., the background has always DC component. When a moving object is detected by a pixel, it will be observed as a 'high frequency component', because it is going to be there for a short time, and the pixel will come back to the original 'DC' or 'Background' value.

<div class="picture">
  <img style="width:80%;" src ="/cstopics/assets/img/vision/7_1D_example.png" />
</div>

Check the following code:

``` python
import numpy as np
import cv2
import collections
from functools import *

cap = cv2.VideoCapture(0)

# Create circular buffer
buffer = collections.deque(maxlen=500)
th = 50

while(True):
	# Capture frame and convert it to gray scale
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    # Append new frame to buffer
    buffer.append(gray.astype(float))
    # Calculate background model
    mean = (reduce(lambda x, y: x + y, buffer) / len(buffer)).astype('uint8')
    # Compute difference
    diff = np.abs(gray.astype('int')-mean.astype('int')).astype('uint8')
    # Calculate mask
    mask = np.zeros(gray.shape).astype('uint8')
    mask[diff>50] = 255
    # Compute foreground (input masked)
    foreground = cv2.bitwise_and(frame, frame, mask=mask)

    cv2.imshow('frame',gray)
    cv2.imshow('background',mean)
    cv2.imshow('difference',diff)
    cv2.imshow('mask',mask)
    cv2.imshow('foreground',foreground)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

```
