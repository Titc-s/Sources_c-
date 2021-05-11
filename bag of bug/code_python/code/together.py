import cv2
import numpy as np

img =cv2.imread("C:\\Users\\12401\\Desktop\\re\\information\\me.jpg")

imgStack=stackImages(0.5,([img,img,img]))

cv2.imshow("Img",imgStack)
#imgHor = np.hstack((img,img)) #水平堆叠
#imgVer = np.vstack((img,img)) #垂直堆叠
#
#cv2.imshow("Horizontal",imgHor)
 
cv2.waitKey(0)