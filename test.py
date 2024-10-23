# import cv2 as cv

# print("hello world!")
# print("how about you?")

# img = cv.imread('plane.jpg')
# cv.imshow('Plane', img)

# gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
# cv.imshow('Plane GRAY', gray)

# cv.waitKey(0)

import torch
print(torch.__version__)
print(torch.cuda.is_available())
device = "cuda" if torch.cuda.is_available() else "cpu"
print(torch.cuda.get_device_name(device))