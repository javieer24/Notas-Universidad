from tkinter import *
from tkinter import messagebox as MessageBox

from lexico import *
from Sintactico import *


listainstrucciones = []
txtresultado = ''

Claves = []
Registros = []
flagClavesyRegistros = False
tempLista = []
listaAcciones = []



def agregar_claves(listaclaves):
    global Claves
    #Limpiar Clave anteriores
    Claves = []
    #Agregar claves
    for i in listaclaves:
        Claves.append(i)
    #Imprimir Resultado
    print('\n---[Claves]---')
    print(Claves,'\n')


def agregar_registros(listaregistros):
    global Registros, flagClavesyRegistros
    #Validar
    if len(Claves) <= 0:
        MessageBox.showerror('Error - instrucciones','No hay claves que evaluar')
    else:
        #Limpiar
        Registros = []
        #Filtrar 
        templista = []
        #Obtener elemento lista
        for registro in listaregistros:
            #Almacenar registro en variable temporal
            #Recorrer item por item y almacenar los necesarios
            for i in range(0,len(Claves)):
                item = registro[i]
                templista.append(item)
            #Se obtubo un nuevo listao agregarlo al registro
            Registros.append(templista)
            templista = []
        #Imprimir Resultado
        print('\n---[Registros]---')
        print(Registros)
        flagClavesyRegistros = True


def funcion_conteo():
    global flagClavesyRegistros,listaAcciones
    mensaje = ''
    if flagClavesyRegistros == True:
        mensaje += '\nconteo();\n'
        Registrosnumeros = len(Registros)
        mensaje += str(Registrosnumeros)+'\n'
        listaAcciones.append('conteo();<br>'+str(Registrosnumeros))
    
    return mensaje


def funcion_promedio(filtro):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        mensaje += 'promedio("'+str(filtro)+'");\n'
        #Buscar si existe el Filtro en las Claves
        if filtro in Claves:
            #Buscar cual fila esta ubicado filtro en la lista Claves
            c = 0 
            for i in Claves:
                if i == filtro:
                    break
                c += 1
            print(Claves[c] + ': '+ str(c))
            #Almacenar registros en lista temporal
            for item in Registros:
                tempLista.append(item[c])

            #Obtener promedio
            #formula:   [lista(0)+lista(1)...lista(n)]/n
            # Numerador / Denominador
            bandera = True
            numerador = 0
            for i in tempLista:
                numero = 0
                try:
                    numero = float(i)
                except:
                    bandera = False
                    MessageBox.showerror('Error | promedio','Error al convertir este valor: '+str(i)+' en valor numerico')        
                    break
                numerador += numero
            if bandera == True:
                #Denominador
                denominador = len(tempLista)
                #Promedio
                promedio = numerador / denominador
                promedio = round(promedio, 2)
                #Agregar mensaje
                mensaje += str(promedio)+'\n'
                listaAcciones.append('promedio("'+str(filtro)+'");<br>'+str(promedio))
            else:
                mensaje += '-[ Error promedio ]-\n'

                
        else:
            MessageBox.showerror('Error | promedio','NO se encontro el valor '+str(filtro)+' entre las Claves, por lo tanto no se puede filtrar y promediar')


    return mensaje


def funcion_contarsi(informacion):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    filtro, valor = informacion
    if flagClavesyRegistros == True:
        mensaje += 'contarsi("'+str(filtro)+'",'+str(valor)+');\n'
        #Buscar si existe el Filtro en las Claves
        if filtro in Claves:
            #Buscar cual fila esta ubicado filtro en la lista Claves
            c = 0 
            for i in Claves:
                if i == filtro:
                    break
                c += 1
            print(Claves[c] + ': '+ str(c))
            #Almacenar registros en lista temporal
            for item in Registros:
                tempLista.append(item[c])

            #Contar si
            contador = 0
            for objetivo in tempLista:
                if  objetivo == valor:
                    contador += 1
            
            #Resultado
            mensaje += str(contador)+'\n'
            listaAcciones.append('contarsi("'+str(filtro)+'",'+str(valor)+');<br>'+str(contador))
                
        else:
            MessageBox.showerror('Error | contar si','NO se encontro el valor -->| '+str(filtro)+' |<-- entre las Claves, por lo tanto no se puede filtrar')


    return mensaje


def funcion_datos():
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        try:
            mensaje += '\n' + '-- [ datos(); ] --\n\n'
            
            #Titulo
            espaciado = '{:>0}'
            for i in range(0,len(Claves)):
                #Obtener tamaño
                largo = len(Claves[i])
                #Validar
                if largo <= 15:
                    espaciado += "{:>"+str(largo+3)+"}"
                else:
                    espaciado += "{:>18}"
            #Asignar formato
            row_format ="{:>12}" * (len(Claves)+1)
            row_format = espaciado 
            titular = row_format.format("", *Claves)
            mensaje += str(titular) + '\n'
            #Filas
            for i in range(0,len(Registros)):
                fila = row_format.format("", *Registros[i])
                mensaje += str(fila) + '\n'



            mensaje += '\n------------------------\n'
        
        except Exception:
            MessageBox.showerror('Error | datos()','Error al mostrar los datos();')


    return mensaje


def funcion_sumar(filtro):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        mensaje += 'sumar("'+str(filtro)+'");\n'
        #Buscar si existe el Filtro en las Claves
        if filtro in Claves:
            #Buscar cual fila esta ubicado filtro en la lista Claves
            c = 0 
            for i in Claves:
                if i == filtro:
                    break
                c += 1
            print(Claves[c] + ': '+ str(c))
            #Almacenar registros en lista temporal
            for item in Registros:
                tempLista.append(item[c])

            #sumar
            bandera = True
            suma = 0
            for i in tempLista:
                numero = 0
                try:
                    numero = float(i)
                except:
                    bandera = False
                    MessageBox.showerror('Error | sumar','Error al convertir este valor: '+str(i)+' en valor numerico')        
                    break
                suma += numero
            if bandera == True:
                suma = round(suma, 2)
                #Agregar mensaje
                mensaje += str(suma)+'\n'
                listaAcciones.append('sumar("'+str(filtro)+'");<br>'+str(suma))
            else:
                mensaje += '-[ Error Suma ]-\n'

                
        else:
            MessageBox.showerror('Error | sumar','NO se encontro el valor -->| '+str(filtro)+' |<-- entre las Claves, por lo tanto no se puede filtrar')


    return mensaje


def funcion_maximo(filtro):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        mensaje += 'maximo("'+str(filtro)+'");\n'
        #Buscar si existe el Filtro en las Claves
        if filtro in Claves:
            #Buscar cual fila esta ubicado filtro en la lista Claves
            c = 0 
            for i in Claves:
                if i == filtro:
                    break
                c += 1
            print(Claves[c] + ': '+ str(c))
            #Almacenar registros en lista temporal
            for item in Registros:
                tempLista.append(item[c])

            #Validar numeros
            bandera = True
            suma = 0
            for i in tempLista:
                numero = 0
                try:
                    numero = float(i)
                except:
                    bandera = False
                    MessageBox.showerror('Error | maximo','Error al convertir este valor: '+str(i)+' en valor numerico')        
                    break
                
            if bandera == True:
                #Obtener numero maximo
                maximo = max(tempLista)
                maximo = round(maximo,2)
                
                #Agregar mensaje
                mensaje += str(maximo)+'\n'
                listaAcciones.append('maximo("'+str(filtro)+'");<br>'+str(maximo))
            else:
                mensaje += '-[ Error maximo ]-\n'

                
        else:
            MessageBox.showerror('Error | maximo','NO se encontro el valor -->| '+str(filtro)+' |<-- entre las Claves, por lo tanto no se puede filtrar')


    return mensaje


def funcion_minimo(filtro):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        mensaje += 'minimo("'+str(filtro)+'");\n'
        #Buscar si existe el Filtro en las Claves
        if filtro in Claves:
            #Buscar cual fila esta ubicado filtro en la lista Claves
            c = 0 
            for i in Claves:
                if i == filtro:
                    break
                c += 1
            print(Claves[c] + ': '+ str(c))
            #Almacenar registros en lista temporal
            for item in Registros:
                tempLista.append(item[c])

            #Validar numeros
            bandera = True
            suma = 0
            for i in tempLista:
                numero = 0
                try:
                    numero = float(i)
                except:
                    bandera = False
                    MessageBox.showerror('Error | minimo','Error al convertir este valor: '+str(i)+' en valor numerico')        
                    break
                
            if bandera == True:
                #Obtener numero maximo
                minimo = min(tempLista)
                minimo = round(minimo,2)
                
                #Agregar mensaje
                mensaje += str(minimo)+'\n'
                listaAcciones.append('minimo("'+str(filtro)+'");<br>'+str(minimo))
            else:
                mensaje += '-[ Error minimo ]-\n'

                
        else:
            MessageBox.showerror('Error | minimo','NO se encontro el valor -->| '+str(filtro)+' |<-- entre las Claves, por lo tanto no se puede filtrar')


    return mensaje


def funcion_exportarReporte(nombre):
    global flagClavesyRegistros, tempLista, listaAcciones
    tempLista = []
    mensaje = ''
    if flagClavesyRegistros == True:
        try:
            nombre = str(nombre)
            #Crear Cuadro HTML
            txthtml = crearTextoHTML(nombre)
                       
            #Crear Archivo HTML
            ruta = 'Reporte.html'
            archivo = open(ruta,'w')
            archivo.write(txthtml)
            archivo.close()

            mensaje += '¡Reporte creado exitosamente!\nReporte.html'
            

        except Exception as e:
            mensaje += '--[Error al crear Reporte]--'
            MessageBox.showerror('Error | Reporte','Ocurrio un error al crear el reporte ver CMD.')
            print('Error:')
            print(e)
    else:
        mensaje += '--[Error al crear Reporte]--'
    return mensaje


def crearTextoHTML(nombre):
    
    txthtml = ''
    if flagClavesyRegistros == True:
        #Inicio
        txthtml = '''<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.4.1/dist/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    <title>Proyecto 2 - BizData</title>
  </head>
  <body>
    <div class="container" style="justify-content:center;">
        <h1> '''+str(nombre)+'''</h1>
        <h5> Javier Monjes - 202100081</h5>
        <br>
    </div>
    <div class="container">
        <table class="table table-bordered">
            <thead class="thead-light">
            <tr>'''

        #----------------------------------------------------------------
        #Titulo Tabla [ CLAVES ]
        for titulo in Claves:
            txthtml += '''                <th scope="col" style="text-align:center;">'''+str(titulo)+'''</th>'''

        txthtml += '''</tr>
            </thead>'''
        #----------------------------------------------------------------


        #----------------------------------------------------------------
        #Filas Tabla
        txthtml += '''<tbody>'''
        
        for registro in Registros:
            txthtml += '''<tr>'''
            for valor in registro:
                txthtml += '''<th scope="row" style="text-align:center;">'''+str(valor)+'''</th>'''
            txthtml += '''</tr>'''

        txthtml += '''</tbody>
        </table>
    </div>
    <br>'''
        #----------------------------------------------------------------


        #----------------------------------------------------------------
        #Funciones
        txthtml += '''<div class="container">'''

        for accion in listaAcciones:
            txthtml += '''<div class="row">
                <div class="alert alert-secondary col" role="alert">
                    '''+str(accion)+'''
                </div>
            </div>'''

        txthtml += '''</div>'''

        #----------------------------------------------------------------

        #Final
        txthtml += '''</body>
</html>'''
    return txthtml


def imprimir(texto):
    print(texto)


def imprimirInstrucciones():
    print('\n----------------------------- [ Instrucciones ] ----------------------------- ')
    for i in listainstrucciones: 
        print(i)


def evaluarinstrucciones():
    try:
        global listainstrucciones, txtresultado
        c = 0
        maxiteraciones = len(listainstrucciones)
        print('\n-----------------------------  [ EVALUANDO... ]  ----------------------------- ')
        while c < maxiteraciones:
            instruccion = listainstrucciones[c] 
            print('•Instruccion: ',instruccion[0], 'Contenido: ', instruccion[1])
            #[ imprimir ] 
            if instruccion[0] == 'imprimir':
                print('♦ Imprimir: ', instruccion[1])
                txtresultado +=  instruccion[1] + ' '
            #[ imprimirln ]
            elif instruccion[0] == 'imprimirln':
                print('♦ Imprimirln: ', instruccion[1])
                txtresultado +=  instruccion[1]+' \n'
            #[ Claves ]
            elif instruccion[0] == 'Claves':
                print('♦ Claves=', instruccion[1])
                #Añadir CLAVES
                agregar_claves(instruccion[1])
                txtlista = '['
                contador = 0
                for i in Claves:
                    if contador < len(Claves) - 1:
                        txtlista += str(i)+', '
                    else:
                        txtlista += str(i)
                    contador += 1

                txtlista += ']\n'
                
                txtresultado += 'Claves=' + txtlista
            #[ contar si ] 
            elif instruccion[0] == 'contarsi':
                print('♦ Contarsi: '+instruccion[1][0]+' valor:'+str(instruccion[1][1]))
                txtresultado += funcion_contarsi(instruccion[1])
            #[ conteo ] 
            elif instruccion[0] == 'conteo':
                print('♦ Conteo')
                txtresultado += funcion_conteo()
                
            #[ datos ] 
            elif instruccion[0] == 'datos':
                print('♦ Mostrar Datos:')
                txtresultado += funcion_datos()
            #[ exportarReporte ]
            elif instruccion[0] == 'exportarReporte':
                print('♦ ExportarReporte("'+instruccion[1]+'")')
                txtresultado += funcion_exportarReporte(instruccion[1])
            #[ maximo ] 
            elif instruccion[0] == 'maximo':
                print('♦ Maximo("'+instruccion[1]+'")')
                txtresultado += funcion_maximo(instruccion[1])
            #[ Minimo ] 
            elif instruccion[0] == 'minimo':
                print('♦ Maximo("'+instruccion[1]+'")')
                txtresultado += funcion_minimo(instruccion[1])
            #[ promedio ] 
            elif instruccion[0] == 'promedio':
                print('♦ Promedio("'+instruccion[1]+'")')
                txtresultado += str(funcion_promedio(instruccion[1]))
                
            #[ Registros ] 
            elif instruccion[0] == 'Registros':
                print('♦Registros=',instruccion[1])
                agregar_registros(instruccion[1])
                txtresultado += '\n----[ Registros ]----\n'
                for i in Registros:
                    txtresultado += str(i)+'\n'
                txtresultado += '\n---------------------\n'
            #[ sumar ] 
            elif instruccion[0] == 'sumar':
                print('♦ Sumar("'+instruccion[1]+'")')
                txtresultado += funcion_sumar(instruccion[1])
                


            c += 1
    except Exception as e:
        print("\033[1;31;40m Error: Ocurrio un error al ejecutar alguna instruccion \033[0m")
        MessageBox.showerror('Error - instrucciones','Ocurrio un error al ejecutar alguna instruccion, favor ver consola CMD')
        print(e)



def ejecutar(oldlistainstrucciones):
    global listainstrucciones, txtresultado, Claves, Registros, flagClavesyRegistros, tempLista, listaAcciones
    txtresultado = ''
    listainstrucciones = oldlistainstrucciones
    

    #Reinicar valores
    Claves = []
    Registros = []
    flagClavesyRegistros = False
    tempLista = []
    listaAcciones = []
    
    #Evaluar
    evaluarinstrucciones()

    


    return txtresultado





