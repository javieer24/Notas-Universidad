import PySimpleGUI as sp

#1. Definir un tema de color
sp.theme('DarkGreen4')
#otros temas: NeutralBlue', 'Purple', 'Python', 'Reds', 'SandyBeach',

#2. Definir plantilla de controles.
layout = [
        #Agregar etiquetas
        [sp.Text('Ingrese su correo electronico:')],
        [sp.Text('Email: '), sp.InputText( size=(28,1), key='mail') ], #Ancho y Alto
        #Agrega etiqueta
        [sp.Text('Mensaje: '),
        #crea un control textBox multiLínea
        sp.Multiline(size=(30, 4), key='mensaje')],
        #Agrega 10 espacios en blanco y luego un botón
        [sp.Text('               '), sp.Button('Imprimir'),
        #Agrega el botón Cancelar
        sp.Button('Cancelar')],
        ]

#3. Crear la ventana con titulo y plantilla
window = sp.Window('Interfaz GUI Python', layout)

#4. Bucle para procesar "eventos" y capturar los "valores" ingresados
while True:
    event, values = window.read()
   #si se hace clic en cerrar ventana
    if (event == sp.WIN_CLOSED) or (event == 'Cancelar'):
       break
    print('El texto ingresado es:')
    #imprime el contenido de los controles
    print(" Email:", values['mail'])
    print(" Mensaje:",values['mensaje'])

#5. Cerrar ventana
window.close()

