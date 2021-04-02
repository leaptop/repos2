from PIL import Image

scale = float(input())

img = Image.open("sample.bmp")
width = img.size[0]
height = img.size[1]

matrix = img.load()


newHeight = round(height * scale)
newWidth = round(width * scale)
newMatrix = []

newImg = Image.new('RGB', (newWidth, newHeight))
print(width, height)
print(newWidth, newHeight)
newMatrix = [matrix[round(colInd / scale), round(lineInd / scale)] for lineInd in range(newHeight) for colInd in range(newWidth)]
newImg.putdata(newMatrix)
newImg.save("res.bmp") 
newImg.show()
