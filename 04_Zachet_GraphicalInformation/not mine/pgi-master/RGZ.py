import tkinter
from PIL import Image, ImageTk, ImageColor

def calcD(lRGB, rRGB):
    return sum([(x - y) ** 2 for x, y in zip(lRGB, rRGB)], 0)

def findClosest(lst, val):
    res = (0, 0, 0)
    for lval in lst:
        if calcD(res, val) > calcD(lval, val):
            res = lval
    return res


def findPalette(difColCount):
    left = 0
    right = 20000
    resPalette = set()
    while left <= right:
        D = (right + left) // 2
        print(D)
        palette = set()
        Dfits = True
        for color in difColCount:
            if all([calcD(color[0], insertedColor) >= D for insertedColor in palette]):
                palette.add(color[0])
            if len(palette) >= 256:
                Dfits = False
                break
        if Dfits:
            right = D - 1
        else:
            resPalette = palette
            left = D + 1
    return resPalette

img = Image.open("sample2.pcx")
colors = img.getdata()

difColCountDict = {}
for color in colors:
    difColCountDict[color] = difColCountDict[color] + 1 if color in difColCountDict else 1

difColCount = list(difColCountDict.items())
difColCount.sort(key = lambda x: x[1], reverse = True)
palette = findPalette(difColCount)
palette = list(palette)

colors = [findClosest(palette, color) for color in colors]
img.putdata(colors)

img.show()