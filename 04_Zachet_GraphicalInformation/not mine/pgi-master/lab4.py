import tkinter
from PIL import Image, ImageTk, ImageColor

root = tkinter.Tk()

image = Image.open('_Carib16.bmp').convert("RGB") #_Carib16.bmp  _Carib256.bmp _сarib_TC.bmp
width = image.size[0]
height = image.size[1]
canvas = tkinter.Canvas(root, height = height, width = width)
canvas.pack()

matrix = image.load()
for lineInd in range(height):
    for colInd in range(width):
        color = '#%02x%02x%02x' % matrix[colInd, lineInd]
        canvas.create_rectangle((colInd, lineInd)*2, outline=color)

root.mainloop()