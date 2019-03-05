---
layout: default
title: Lab 2
permalink: /vision/assignments/2019-1/lab2
---

# Lab 2

In the [camera.py](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/vision/assignments/2019-1/lab2/camera.py){:target="blank"} file you will find a class named *Camera*, it emulates a camera that changes its focus every 5 seconds.

You can create the *Camera* object as follows:

``` python
cam = camera.Camera(camera_file=0)
```

The parameter *camera_file* is the index of the camera, if you do not have camera, you can use it with a video file:

``` python
cam = camera.Camera(camera_file="./video.mp4")
```

Then, you can get a frame:

``` python
frame = cam.get_frame(focus=0.5)
```

Where *focus* is a number between *0.0* and *1.0* (with 1 decimal number). The camera has a hidden predefined number that is the correct focus, the closer the focus you choose  is to the focus of the camera, the sharp the image is. That hidden number changes every 5 seconds.

You can test it through this [test script](https://github.com/cstopics/cstopics/blob/gh-pages/assets/code/vision/assignments/2019-1/lab2/test.py){:target="blank"}.

You have to modify the test file to make it able to select the correct focus automatically, changing it every time that the camera changes its focus.

When the practice is ready, compress all the files and upload them to the appropriate link in *moodle*.

Deadline:
* Mar 7, 23:59. Max 5.0
* Mar 8, 23:59. Max 4.0
