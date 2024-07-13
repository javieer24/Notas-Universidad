
from Lexico import *
from Sintactico import *
from Funciones import *

AnalizadorErrores = []


def analizadorBizData(texto):
    global AnalizadorErrores
    print('Analizando la información...')
    print(texto)
    #Pasa por el analizador  Lexico y Obtiene los Tokens
    tokens = lexico.GetTokens(texto)
    lexico.imprimirlistatokens()
    lexico.imprimirerroreslexicos()
    
    if len(tokens) >0:
       #Pasar al analizador Sintactico y obtener Estructuras
        instrucciones = Sintactico.GetInstrucciones(tokens)
        Sintactico.imprimirErrores()
        Sintactico.imprimirlistaSintactico()
        #[A]Obtener Errores
        #[A1]Obtener Errores Lexicos
        erroresLexicos = Sintactico.GetErrores()
        #[A2]Obtener Errores Sintacticos
        erroresSintactico = Sintactico.GetErrores()
        #[A3]Unir Errores
        nuevalista = unirdoslistas(erroresLexicos, erroresSintactico) 
        AnalizadorErrores = nuevalista
        # imprimirErrores()

        #Ejecutar instrucciones
        txtconsola = funciones.ejecutar(instrucciones)
        #funciones.imprimirInstrucciones()
        #Retornar informacion consola
        return txtconsola
        



def imprimirErrores():
    global AnalizadorErrores
    print('\n------------[ ERRORES ]----------------\n')
    for i in AnalizadorErrores:
        print(i)
    print('\n---------------------------------------')


def unirdoslistas(lista1, lista2):
    newlist = []
    for i in lista1:
        newlist.append(i)
    for j in lista2:
        newlist.append(j)

    return newlist    