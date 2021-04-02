import tkinter
import binascii
from PIL import Image, ImageTk, ImageColor

import io

img = Image.open("200001.PCX")
imgBytes = io.BytesIO()
img.save(imgBytes, format='PCX')
imgBytes = bytes(imgBytes.getvalue())

XSize = int.from_bytes(imgBytes[8:10], "little") + 1
YSize = int.from_bytes(imgBytes[10:12], "little") + 1

bytesPerLine = int.from_bytes(imgBytes[66:68], "little")
NPlanes = imgBytes[65]
TBytes = bytesPerLine * NPlanes

decodedImagePixels = []

pallete = [(imgBytes[i], imgBytes[i + 1], imgBytes[i + 2]) for i in range(len(imgBytes) - 768, len(imgBytes), 3)]

root = tkinter.Tk()

canvas = tkinter.Canvas(root, height = YSize, width = XSize)
canvas.pack()

written = 0
ind = 128
while ind < len(imgBytes) - 768:
    if (imgBytes[ind] & 192) == 192:
        samePixelsCount = imgBytes[ind] & 63
        written += samePixelsCount
        for _ in range(samePixelsCount):
            decodedImagePixels.append(pallete[imgBytes[ind + 1]])
        ind += 2
    else:
        decodedImagePixels.append(pallete[imgBytes[ind + 1]])
        written += 1
        ind += 1

for lineInd in range(YSize):
    for colInd in range(XSize):
        color = '#%02x%02x%02x' % decodedImagePixels[lineInd * XSize + colInd]
        canvas.create_rectangle((colInd, lineInd)*2, outline=color)

root.mainloop()