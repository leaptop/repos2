from PIL import Image
import io

img = Image.open("sample.bmp")
imgBytes = io.BytesIO()
img.save(imgBytes, format='BMP')
imgBytes = bytearray(imgBytes.getvalue())

file = open("file.txt", 'r')
text = file.readline()
file.close()

textBits = ''.join([bin(ord(c))[2:].zfill(8) for c in text])
textBitsCount = len(textBits)
textBitsCountBinary = bin(textBitsCount)[2:].zfill(64)

for ind in range(64):
    imgBytes[ind + 64] &= ~1
    imgBytes[ind + 64] |= int(textBitsCountBinary[ind])
 
freeBytesCount = len(imgBytes) - 128

for ind in range(textBitsCount):
    imgBytesInd = 128 + ind * freeBytesCount // textBitsCount
    imgBytes[imgBytesInd] &= ~1
    imgBytes[imgBytesInd] |= int(textBits[ind])

newImg = Image.open(io.BytesIO(imgBytes))
newImg.save("res.bmp", format = 'BMP')
    
    
    
img = Image.open("res.bmp")
imgBytes = io.BytesIO()
img.save(imgBytes, format='BMP')
imgBytes = bytearray(imgBytes.getvalue())

messageSizeBits = ""
for ind in range(64):
    messageSizeBits += str(imgBytes[ind + 64] & 1)
messageSize = int(messageSizeBits, 2)
print(messageSize)

freeBytesCount = len(imgBytes) - 128

messageBits = ""
for ind in range(messageSize):
    imgBytesInd = 128 + ind * freeBytesCount // messageSize
    messageBits += str(imgBytes[imgBytesInd] & 1)
    
message = ''.join([chr(int(messageBits[ind*8:(ind+1)*8], 2)) for ind in range(messageSize//8)])
print(message)