import qrcode

link = "https://wa.link/ubgpqk"
qr = qrcode.make(link)

# Ruta para guardar en Downloads
qr_path = "C:\\Users\\javie\\Downloads\\qr_whats_jose_monjes.png"
qr.save(qr_path)
