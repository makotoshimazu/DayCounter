import numpy as np
import cv2

img = cv2.imread('../res/rancher_days.png')
# print(img[1])
# print(img[2])
# print(img[3])
# print(img[4])
# img = cv2.imread('filename', cv2.IMREAD_GRAYSCALE)

f = open('./test.txt', mode='w')

# <class '_io.TextIOWrapper'>


data = 0
count = 0
x = 0
# red
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        x = x + 1
        data = (data << 1)
        if (img[i, j, 2] > 0):
            data += 0
        else:
            data += 1
        count += 1
        if (x >= 73):
            data = data << 7
            data += 0x7f
            count = 8
            x = 0

        if count >= 8:
            f.write(hex((data & 0xff)) + ',')
            # f.write(hex((0x00)) + ',')
            data = 0
            count = 0

        # print(img[i,j,2])

        # f.write((img[i,j,0]).tostring())

# cv2.imshow('test', img)
# cv2.waitKey(0)
# cv2.destroyAllWindows()
f.close()