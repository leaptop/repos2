from random import randint
from PIL import Image

def randPixel():
    return (randint(0, 256), randint(0, 256), randint(0, 256))

img = Image.open("sample.bmp")
width = img.size[0]
height = img.size[1]

upperLine = [randPixel() for _ in range(width + 30) for _ in range(15)]
bottomLine = [randPixel() for _ in range(width + 30) for _ in range(15)]

newMatrix = []
matrix = img.load()
for line in range(height):
    newMatrix += [randPixel() for _ in range(15)] + [matrix[i, line] for i in range(width)] + [randPixel() for _ in range(15)]

newMatrix = upperLine + newMatrix + bottomLine
newImg = Image.new('RGB', (width + 30, height + 30))
newImg.putdata(newMatrix)
newImg.save("res.bmp") 
newImg.show()

