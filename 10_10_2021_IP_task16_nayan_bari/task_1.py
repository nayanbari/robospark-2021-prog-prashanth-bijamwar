import cv2
import numpy as np

#Morphology
img = cv2.imread('morphology.JPG',0)
kernel = np.ones((5,5),np.uint8)
erosion = cv2.erode(img,kernel,iterations = 1)
cv2.imshow("erosion", erosion)
cv2.imwrite('./result/erosion.jpg', erosion)
dilation = cv2.dilate(img,kernel,iterations = 1)
cv2.imshow("dilation", dilation)
cv2.imwrite('./result/dilation.jpg', dilation)
opening = cv2.morphologyEx(img, cv2.MORPH_OPEN, kernel)
cv2.imshow("opening", opening)
cv2.imwrite('./result/opening.jpg', opening)
closing = cv2.morphologyEx(img, cv2.MORPH_CLOSE, kernel)
cv2.imshow("closing", closing)
cv2.imwrite('./result/closing.jpg', closing)
gradient = cv2.morphologyEx(img, cv2.MORPH_GRADIENT, kernel)
cv2.imshow("gradient", gradient)
cv2.imwrite('./result/gradient.jpg', gradient)
tophat = cv2.morphologyEx(img, cv2.MORPH_TOPHAT, kernel)
cv2.imshow("tophat", tophat)
cv2.imwrite('./result/tophat.jpg', tophat)
blackhat = cv2.morphologyEx(img, cv2.MORPH_BLACKHAT, kernel)
cv2.imshow("blackhat", blackhat)
cv2.imwrite('./result/blackhat.jpg', blackhat)


# Threshold
image1 = cv2.imread('thresholding.jpeg')
 
img1 = cv2.cvtColor(image1, cv2.COLOR_BGR2GRAY)
 

ret, thresh1 = cv2.threshold(img1, 120, 255, cv2.THRESH_BINARY)
ret, thresh2 = cv2.threshold(img1, 120, 255, cv2.THRESH_BINARY_INV)
ret, thresh3 = cv2.threshold(img1, 120, 255, cv2.THRESH_TRUNC)
ret, thresh4 = cv2.threshold(img1, 120, 255, cv2.THRESH_TOZERO)
ret, thresh5 = cv2.threshold(img1, 120, 255, cv2.THRESH_TOZERO_INV)
 
cv2.imshow('Binary Threshold', thresh1)
cv2.imshow('Binary Threshold Inverted', thresh2)
cv2.imshow('Truncated Threshold', thresh3)
cv2.imshow('Set to 0', thresh4)
cv2.imshow('Set to 0 Inverted', thresh5)

cv2.imwrite('./result/binaryThresh.jpeg', thresh1)
cv2.imwrite('./result/binaryThreshInverted.jpeg', thresh2)
cv2.imwrite('./result/truncatedThresh.jpeg', thresh3)
cv2.imwrite('./result/threshToZerp.jpeg', thresh4)
cv2.imwrite('./result/threshToZeroInverted.jpeg', thresh5)

cv2.waitKey(0)
cv2.destroyAllWindows()