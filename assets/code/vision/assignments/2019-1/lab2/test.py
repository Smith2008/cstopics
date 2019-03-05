import numpy as np
import cv2

import camera

def nothing(x):
  pass

cam = camera.Camera(camera_file=0)

cv2.namedWindow('Camera')
cv2.createTrackbar("10*Focus", "Camera",0,10,nothing)

while(True):
    focus = cv2.getTrackbarPos("10*Focus", "Camera") / 10.0
    frame = cam.get_frame(focus=focus)

    cv2.putText(frame,
        'Press Q to exit',
        (5,20),
        cv2.FONT_HERSHEY_SIMPLEX,
        0.5,
        (255,255,255))
    cv2.imshow('Camera', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()
