import numpy as np
import cv2
import collections
from functools import *

cap = cv2.VideoCapture(0)

buffer = collections.deque(maxlen=50)


while(True):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    buffer.append(gray.astype(float))
    mean = reduce(lambda x, y: x + y, buffer) / len(buffer)



    # Display the resulting frame
    cv2.imshow('frame',gray)
    cv2.imshow('mean',mean.astype('uint8'))
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
