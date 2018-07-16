#
# image2bitmap.py
#
# Copyright 2018 Murata Tetsuya
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
#  limitations under the License.

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

f.close()
