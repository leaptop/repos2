from PIL import Image

img = Image.open("sample.bmp")
width = img.size[0]
height = img.size[1]

newMatrix = []
matrix = img.load()
for col in range(width):
    newMatrix += [matrix[col, i] for i in range(height)]

newImg = Image.new('RGB', (height, width))
newImg.putdata(newMatrix)
newImg.save("res.bmp")  
newImg.show()
