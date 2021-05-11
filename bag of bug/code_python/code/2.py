import cv2 
src=cv2.imread('sc.jpg',cv2.IMREAD_GRAYSCALE)

cv2.imshow('input_image',src)
cv2.waitKey(0)
cv2.destoryALLWindows()