# first 8 characters from alphabet
original = bytearray(b'ABCDEFGH')

# first 8 hex values from the encrypted file
encrypted = bytearray(b'\x0F\xCE\x60\xBC\xE6\x2F\x46\xEA')

# add operation function


def add(value, add):
    # modulus 256 to make sure it does not go above 255
    return value + add % 256

# rotate right function


def rot_right(value, rotate):
    return (value >> rotate) | ((value << (8 - rotate)) & 255)


for i in range(0, 8):
    original[i] = rot_right(add(original[i], i), i) ^ encrypted[i]

print(original)
