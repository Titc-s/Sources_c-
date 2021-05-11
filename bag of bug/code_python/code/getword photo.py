import cv2
import numpy as np


img =cv2.imread("C:\\Users\\12401\\Desktop\\re\\information\\me.jpg")

pts1=np.float32([[111,123]])

cv2.imshow("Image",img)

cv2.waitKey(0)
45-50