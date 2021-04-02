from PIL import Image

img = Image.open("sample.bmp")
log = Image.open("logo.jpg")
width = img.size[0]
height = img.size[1]

widthLog = log.size[0]
heightLog = log.size[1]

matrix = img.load()
matrixLog = log.load()

for lineInd in range(heightLog):
    for colInd in range(widthLog):
        if matrixLog[colInd, lineInd] != (255, 255, 255):
            r = (matrix[colInd + 500, lineInd + 500][0] + matrixLog[colInd, lineInd][0]) // 2
            g = (matrix[colInd + 500, lineInd + 500][1] + matrixLog[colInd, lineInd][1]) // 2
            b = (matrix[colInd + 500, lineInd + 500][2] + matrixLog[colInd, lineInd][2]) // 2
            matrix[colInd + 500, lineInd + 500] = (r, g, b)

newImg = Image.new('RGB', (width, height))
newImg.putdata([matrix[colInd, lineInd] for lineInd in range(height) for colInd in range(width)])
newImg.save("res.bmp") 
newImg.show()
