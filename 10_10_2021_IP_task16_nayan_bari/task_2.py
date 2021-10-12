import cv2
import numpy as np

img = cv2.imread('masking.jpg')

hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
# Red
lower_red_1 = np.array([0, 100, 20])
upper_red_1 = np.array([10, 255, 255])
lower_red_2 = np.array([160,100,20])
upper_red_2 = np.array([179,255,255])
lower_mask = cv2.inRange(hsv, lower_red_1, upper_red_1)
upper_mask = cv2.inRange(hsv, lower_red_2, upper_red_2)
mask1 = lower_mask + upper_mask
redResult = cv2.bitwise_and(img,img, mask = mask1)
# Green
lower_green = np.array([36, 50, 70])
upper_green = np.array([89, 255, 255]) 
mask2 = cv2.inRange(hsv, lower_green, upper_green)
greenResult = cv2.bitwise_and(img,img, mask = mask2)
# Blue
lower_blue = np.array([90, 50, 70])
upper_blue = np.array([128, 255, 255])
mask3 = cv2.inRange(hsv, lower_blue, upper_blue)
blueResult = cv2.bitwise_and(img,img, mask = mask3)
cv2.imshow('Original',img)
cv2.imshow('Red',redResult)
cv2.imshow('Green',greenResult)
cv2.imshow('Blue',blueResult)

cv2.waitKey(0)
cv2.destroyAllWindows()