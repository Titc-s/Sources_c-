import cv2
import numpy as np
img =cv2.imread("C:\\Users\\12401\\Desktop\\re\\information\\me.jpg")

kernel = np.ones((5,5),np.uint8)
#灰度图像
imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
#高斯模糊
imgBlur = cv2.GaussianBlur(imgGray,(7,7),0)
#边缘
imgCanny = cv2.Canny(img,100,100)    #后面两个数字越小，边缘越多
#膨胀图像
imgDialation = cv2.dilate(imgCanny,kernel,iterations=1)
#侵蚀图像
imgEroded = cv2.erode(imgDialation,kernel,iterations=1)

#cv2.imshow("Gray Image",imgGray)
#cv2.imshow("Blur Image",imgBlur)
cv2.imshow("Canny Image",imgCanny)
cv2.imshow("Dialation Image",imgDialation)
cv2.imshow("eroded Image",imgEroded)

cv2.waitKey(0)
