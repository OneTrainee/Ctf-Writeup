import base64
encryptedString = "e3nifIH9b_C@n@dH"
newString = ""
for index, char in enumerate(encryptedString):
    newString += chr(ord(char) - index)
decodedBytes  = base64.b64decode(newString)
print(decodedBytes.decode('utf-8'))