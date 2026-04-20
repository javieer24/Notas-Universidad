import qrcode

# Número de teléfono
telefono = "+50257396830"

# Crear el enlace para realizar la llamada
url_llamada = f"tel:{telefono}"

# Generar el código QR
qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_L,
    box_size=10,
    border=4,
)
qr.add_data(url_llamada)
qr.make(fit=True)

# Crear la imagen del código QR
img = qr.make_image(fill_color="black", back_color="white")

# Guardar la imagen del código QR
img.save("qr_llamada.png")

print("Código QR generado y guardado como 'qr_llamada.png'.")
