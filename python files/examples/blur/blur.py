from PIL import Image,ImageFilter

before = Image.open("/home/albarogyaassem/python.py/examples/blur/image.jpg")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("out.jpg")