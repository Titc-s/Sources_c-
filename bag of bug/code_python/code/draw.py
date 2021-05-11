import cv2
import numpy as np

img = np.zeros((512,512,3),np.uint8)
#print (img)
#img[200:300,100:400]=255,0,0   #着色

cv2.line(img,(0,0),(img.shape[1],img.shape[0]),(0,255,255),3) #线
cv2.rectangle(img,(0,0),(250,350),(255,2,3),2) #矩形
cv2.circle(img,(400,50),30,(255,255,0),5)#圆形
cv2.putText(img,"OPEN CV",(300,100),cv2.FONT_HERSHEY_COMPLEX,1,(0,150,0),5) #输入文本

cv2.imshow("Image",img)

cv2.waitKey(0)