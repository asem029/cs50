import qrcode
import os


img= qrcode.make("https://maps.app.goo.gl/xRUXWNAdBamGFQji9")

img.save("wedding.png","PNG")
os.system("open wedding.png")