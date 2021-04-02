from PIL import Image

img = Image.open("sample.bmp")
width = img.size[0]
height = img.size[1]
print("format: {0}\nsize: {1}\nmode: {2}".format(img.format, img.size, img.mode))

i = 0
matrix = img.load()
for line in range(width):
    for col in range(height):
        mean = (matrix[line, col][0] + matrix[line, col][1] + matrix[line, col][2]) // 3
        matrix[line, col] = (mean, mean, mean, 0)
img.save("res.bmp", "bmp")