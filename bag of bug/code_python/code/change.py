import cv2
#import numpy as np
img =cv2.imread("C:\\Users\\12401\\Desktop\\re\\information\\me.jpg")
print(img.shape) # 打印出图像大小

imgResize = cv2.resize(img,(600,295)) #顺序颠倒
print(imgResize.shape)

imgCropped = img[0:200,100:159] #裁剪图像

cv2.imshow("Image",img)
cv2.imshow("Image Resize ",imgResize)
cv2.imshow("Image Cropped ",imgCropped)

cv2.waitKey(0)
