import cv2

img = cv2.imread("vllCR.png")

imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

ret, thresh = cv2.threshold(imgGray, 240, 255, cv2.THRESH_BINARY)

contours, hierarchy = cv2.findContours(thresh, mode=cv2.RETR_TREE, method= cv2.CHAIN_APPROX_SIMPLE)


for contour in contours:
    approx = cv2.approxPolyDP(contour, 0.01 * cv2.arcLength(contour, True), True)
    cv2.drawContours(img, [contour], 0, color=(0, 255, 0), thickness=5)
    x = approx.ravel()[0]
    y = approx.ravel()[1] - 5
    if len(approx) == 3:
        print('Triangle')
        cv2.putText( img, "Triangle", (x, y), cv2.FONT_HERSHEY_COMPLEX, 0.5, (0, 0, 0) )
    elif len(approx) == 4:
        x, y , w, h = cv2.boundingRect(approx)
        aspectRatio = float(w)/h
        if aspectRatio >= 0.95 and aspectRatio < 1.05:
            print('Square')
            cv2.putText(img, "square", (x, y), cv2.FONT_HERSHEY_COMPLEX, 0.5, (0, 0, 0))

        else:
            print('Rectangle')
            cv2.putText(img, "rectangle", (x, y), cv2.FONT_HERSHEY_COMPLEX, 0.5, (0, 0, 0))
    elif len(approx) == 5 :
        print('Pentagon')
        cv2.putText(img, "pentagon", (x, y), cv2.FONT_HERSHEY_COMPLEX, 0.5, (0, 0, 0))
    else:
        print('Circle')
        cv2.putText(img, "circle", (x, y), cv2.FONT_HERSHEY_COMPLEX, 0.5, (0, 0, 0))

cv2.imshow("origin", img)
# cv2.imshow("thresh", thresh)
cv2.imwrite("imaEdge.png", img)
cv2.waitKey(0)
cv2.destroyAllWindows()