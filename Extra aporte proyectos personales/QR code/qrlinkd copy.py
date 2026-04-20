import qrcode

link = "meet.google.com/smx-adew-zcq "
qr = qrcode.make(link)

# Ruta para guardar en Downloads
qr_path = "C:\\Users\\javie\\Downloads\\qr__conferencia.png"
qr.save(qr_path)
