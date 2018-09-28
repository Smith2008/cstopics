---
layout: default
title: Kalman Filter
permalink: /vision/8_kalman
---

<h1 style="text-align: center;">Kalman Filter</h1>

Kalman filter is an estimation algorithm that is able to predict the discrete state of a linear process, from the previous samples of the state.

The state to be estimated is <img src=" https://latex.codecogs.com/gif.latex? x_k "/>, and me measurement <img src=" https://latex.codecogs.com/gif.latex? z_k "/>, where <img src=" https://latex.codecogs.com/gif.latex? k "/> is the discrete time.

The process is represented by the *process equation*:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  x_k = Ax_{k-1} + w_{k-1}
"/>

Where <img src=" https://latex.codecogs.com/gif.latex? A "/> is the transition matrix and <img src=" https://latex.codecogs.com/gif.latex? w "/> is the process noise, modeled by a normal distribution <img src=" https://latex.codecogs.com/gif.latex? p(w)\sim(0,Q) "/>.

The measurement is represented by:

<img class="eq" src="https://latex.codecogs.com/gif.latex?
  z_k = Hx_k + v_k
"/>

Where <img src=" https://latex.codecogs.com/gif.latex? H "/> is the measurement matrix and <img src=" https://latex.codecogs.com/gif.latex? v "/> is the measurement noise, modeled by the normal distribution <img src=" https://latex.codecogs.com/gif.latex? p(v)\sim(0,R) "/>.

The process is shown in the following figure:

<div class="picture">
    <img style="width:50%;" src ="/cstopics/assets/img/vision/8_kalman.png" />
</div>

The *prediction* process is performed in each frame, where <img src=" https://latex.codecogs.com/gif.latex? P "/> is the error covariance and <img src=" https://latex.codecogs.com/gif.latex? K "/> is  the *Kalman gain*. The "-" superscript indicates a priori value.

Note that the correction process is only performed if there is measurement for the time *k*.

## OpenCV Example

``` python
import cv2, numpy as np

meas=[]
pred=[]
frame = np.zeros((400,400,3), np.uint8) # drawing canvas
mp = np.array((2,1), np.float32) # measurement
tp = np.zeros((2,1), np.float32) # tracked / prediction
mx = 0
my = 0

inputFlag = True

def onmouse(k,x,y,s,p):
    global mp,meas, inputFlag, mx, my
    mx = x
    my = y

def paint():
    global frame,meas,pred
    for i in range(len(meas)-1):
        cv2.circle(frame, meas[i], 2, (0,100,0), -1)
        # cv2.line(frame, meas[i],meas[i+1],(0,100,0))
    for i in range(len(pred)-1):
        cv2.line(frame,pred[i],pred[i+1],(0,0,200))

def reset():
    global meas,pred,frame
    meas=[]
    pred=[]
    frame = np.zeros((400,400,3), np.uint8)

cv2.namedWindow("kalman")
cv2.setMouseCallback("kalman",onmouse);
kalman = cv2.KalmanFilter(4,2)
kalman.measurementMatrix = np.array([[1,0,0,0],[0,1,0,0]],np.float32)
kalman.transitionMatrix = np.array([[1,0,1,0],[0,1,0,1],[0,0,1,0],[0,0,0,1]],np.float32)
kalman.processNoiseCov = np.array([[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]],np.float32) * 0.03
#kalman.measurementNoiseCov = np.array([[1,0],[0,1]],np.float32) * 0.00003

while True:
    if inputFlag:
        mp1 = np.array([[np.float32(mx)],[np.float32(my)]])
        meas.append((mx,my))
        kalman.correct(mp1)
    tp = kalman.predict()
    pred.append((int(tp[0]),int(tp[1])))
    paint()
    cv2.imshow("kalman",frame)
    k = cv2.waitKey(30) &0xFF
    if k == 27: break # Esc
    if k == 32: reset() # Space
    if k == ord('p'): inputFlag = not inputFlag;
```
