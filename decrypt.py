inv_sbox = [
    74,  252, 195, 85,  38,  40,  63,  216, 20,  158, 90,  171, 28,  150, 242,
    13,  115, 179, 152, 227, 18,  27,  138, 207, 192, 167, 12,  135, 165, 87,
    203, 89,  251, 52,  211, 253, 97,  95,  220, 250, 241, 33,  160, 210, 247,
    15,  248, 221, 14,  189, 139, 209, 193, 151, 146, 202, 110, 11,  56,  164,
    236, 79,  57,  157, 219, 218, 205, 94,  103, 16,  200, 170, 0,   39,  75,
    102, 105, 240, 154, 232, 166, 186, 231, 226, 180, 254, 91,  21,  32,  73,
    86,  47,  1,   128, 228, 120, 6,   149, 30,  121, 156, 129, 201, 130, 118,
    108, 217, 62,  206, 34,  181, 233, 159, 224, 132, 127, 145, 42,  24,  96,
    68,  48,  197, 204, 98,  191, 125, 214, 190, 4,   55,  72,  137, 163, 69,
    26,  111, 235, 239, 123, 81,  119, 25,  147, 182, 5,   10,  143, 8,   45,
    185, 3,   245, 59,  112, 53,  237, 88,  136, 43,  196, 131, 19,  238, 113,
    54,  99,  36,  222, 213, 106, 78,  144, 7,   23,  65,  67,  134, 176, 198,
    215, 76,  22,  194, 225, 58,  93,  46,  2,   122, 37,  49,  92,  107, 183,
    83,  155, 162, 174, 80,  31,  35,  173, 9,   148, 223, 212, 70,  199, 255,
    244, 243, 71,  168, 177, 187, 133, 208, 50,  126, 116, 153, 17,  100, 230,
    140, 172, 82,  234, 84,  114, 29,  188, 169, 117, 51,  184, 249, 246, 142,
    60,  101, 66,  124, 141, 61,  229, 175, 178, 109, 41,  161, 64,  44,  77,
    104]

xor = [0xaa, 0xbb, 0xcc, 0xdd, 0xee]


def inv_wash(cipher_text):
    cipher_text = cipher_text[::-1]

    for i in range(len(cipher_text) - 1, 0, -1):
        cipher_text[i] ^= cipher_text[i - 1]

    return cipher_text


def inv_runnnn(cipher_text):
    for i in range(0, len(cipher_text)):
        for j in range(9, -1, -1):
            cipher_text[i] = (((cipher_text[i] >> 3) | (cipher_text[i] << 5)) & 0xff)
            cipher_text[i] ^= xor[j % 5]
            cipher_text[i] = inv_sbox[cipher_text[i]]
            cipher_text[i] = (((cipher_text[i] << 3) | (cipher_text[i] >> 5)) & 0xff)

    return cipher_text


def glyph_to_num(glyph, hieroglyphs):
    for i in enumerate(hieroglyphs):
        if glyph in i:
            return i[0]


def main():
    cipher_text = []
    
    with open("message.txt", 'r') as m:
        message = m.read()

    with open("hieroglyphs.txt", 'r') as h:
        glyphs = h.read().splitlines()

    for i in range(0, len(message)):
        cipher_text.append(glyph_to_num(message[i], glyphs))

    cipher_text = inv_wash(cipher_text)
    cipher_text = inv_runnnn(cipher_text)
    cipher_text = inv_wash(cipher_text)

    print(bytes(cipher_text))


if __name__=='__main__':
    main()
