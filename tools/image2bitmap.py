import numpy as np
import cv2
import sys

argvs = sys.argv
argc = len(argvs)

if (argc != 2):
    print('Usage: python image2bitmap.py "target.png"')
    # output filename is "target_<width>x_<height>.csv"
    exit(0)

targetFileName = argvs[1]
img = cv2.imread(targetFileName)
srcImageWidth = img.shape[1]
srcImageHeight = img.shape[0]

# rotate 90 degrees
# dst width is multiples of 8
dstImageWidth = srcImageHeight // 8
if ((srcImageHeight % 8) > 0):
    dstImageWidth += 1
dstImageWidth = dstImageWidth * 8 
# diff = dstImageWidth - srcImageHeight

dstImageHeight = srcImageWidth

dstFileName = targetFileName.rstrip('.png') + '_' + str(dstImageWidth) + '_' + str(dstImageHeight) + '.csv'
print(dstFileName)
f = open(dstFileName, mode='w')

data = 0
count = 0
for x in range(srcImageWidth): # 0~srcImageWidth-1
    for y in range(srcImageHeight): # 0~srcImageHeight-1
        data = (data << 1)
        if (img[srcImageHeight - (y + 1), x, 2] > 0):
            data += 0
        else:
            data += 1

        if (y == srcImageHeight - 1):
            data = (data << (dstImageWidth - srcImageHeight)) | (0xff >> (8 - (dstImageWidth - srcImageHeight)))
            count = 8

        count += 1
        if count >= 8:
            f.write(hex((data & 0xff)) + ',')
            # f.write(hex((0x00)) + ',')
            data = 0
            count = 0

# red
# for i in range(img.shape[0]):
#     for j in range(img.shape[1]):
#         x = x + 1
#         data = (data << 1)
#         if (img[i, j, 2] > 0):
#             data += 0
#         else:
#             data += 1
#         count += 1
#         if (x >= 73):
#             data = data << 7
#             data += 0x7f
#             count = 8
#             x = 0

#         if count >= 8:
#             f.write(hex((data & 0xff)) + ',')
#             # f.write(hex((0x00)) + ',')
#             data = 0
#             count = 0

#         # print(img[i,j,2])

#         # f.write((img[i,j,0]).tostring())

# # cv2.imshow('test', img)
# # cv2.waitKey(0)
# # cv2.destroyAllWindows()
f.close()