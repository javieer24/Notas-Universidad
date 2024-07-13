

from tkinter import messagebox as MessageBox


#Variables

tokens = []
linea = 1
columna = 1
listaerrores = []
listadocaracteresbuscados = ['{','}',':','[',']',',','(',')',';','=','"',"'",'#','_','-','.']
listaabecedario = ['A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z','Ñ','ñ']

flagcomillas = False



def evaluartexto(texto):
    global tokens, linea, columna, listaerrores, listadocaracteresbuscados, flagcomillas
    #IDtoken
    id = -1
    #Iterador
    c=0
    #Numero maximo de iteraciones
    maxiter = len(texto)
    while c < maxiter:
        id += 1
        #Obtener caracter
        caracter = texto[c]
        #Evaluar
        
        if caracter == '"' or caracter == "'":
            #Guardar inicio
            templinea = linea
            tempcolumna = columna
            #Evaluar si es un comentario multilinea
            caractersig = texto[c+1:c+2]
            if caractersig == '"' or caractersig == "'":
                caractersig2 = texto[c+2:c+3]
                if caractersig2 == '"' or caractersig2 == "'":
                    print('Comentario multilinea')
                    #obtener texto entre comillas
                    textoaevaluar = texto[c+3:]
                    string, pos, lineasextra, columnastring = obtenercomentariomultilinea(textoaevaluar, c,columna)
                    #Aumentar contador y columna
                    c = pos + 4
                    columna = columnastring
                    linea = linea + lineasextra
                    #Almacenar token
                    tokens.append([id,string,templinea,tempcolumna,'Comentario_multilinea',linea, columna])
                    print('token: ', string, ' linea:', linea,' columna: ',columna)
            else:
                #Almacena token
                tokens.append([id,caracter,linea,columna,'token'])
                print('token: ', caracter, ' linea:', linea,' columna: ',columna)
                columna += 1
                c += 1
                #Activar bandera
                if flagcomillas == False:
                    flagcomillas = True
                else:
                    flagcomillas = False
       
        elif caracter == '#':
            #Guardar inicio
            templinea = linea
            tempcolumna = columna
            #Si es un texto un posible token
            textoaevaluar = texto[c+1:]
            string, pos = obtenercomentario(textoaevaluar, c)
            string = '#'+string
            #Aumentar contador y columna
            c = pos + 1
            columna = len(string) + 1
            #Almacenar token
            tokens.append([id,string,templinea,tempcolumna,'Comentario_simple',linea, columna])
            print('token: ', string, ' linea:', linea,' columna: ',columna)
        
        elif caracter == '\n':
            #Almacena token
            tokens.append([id,caracter,linea,columna,'salto_linea'])
            print('token: ', caracter, ' linea:', linea,' columna: ',columna)
            #Si es un Salto de linea | Aumenta la linea | Reinicia columnas
            linea += 1
            columna = 1
            c += 1
        
        elif caracter.isspace():
            #Si es algun tipo de espacio
            if caracter == '\t':
                #Si es un Tabulador | Aumenta la columna en 4
                columna += 4
            else:
                #Si es un espacio | Aumenta la columna
                #Validar si esta dentro de comillas
                if flagcomillas == True:
                    #Almacena token
                    tokens.append([id,caracter,linea,columna,'espacio'])
                columna += 1
            #Contador
            c += 1
        
        elif caracter in listadocaracteresbuscados:
            #Almacena token
            tokens.append([id,caracter,linea,columna,'token'])
            print('token: ', caracter, ' linea:', linea,' columna: ',columna)
            #Aumenta columna
            columna += 1
            #Contador
            c += 1
        
        elif caracter in listaabecedario:
            #Almacena token
            tokens.append([id,caracter,linea,columna,'token'])
            print('token: ', caracter, ' linea:', linea,' columna: ',columna)
            #Aumenta columna
            columna += 1
            #Contador
            c += 1
       
        elif caracter.isdigit():
            #Almacenar token
            tokens.append([id,caracter,linea, columna,'Numero'])
            print('token: ', caracter, ' linea:', linea,' columna: ',columna)
            #Aumenta columnas
            columna += 1
            #Contador
            c += 1
       
        else:
            #Caracter Desconocido
            print("\033[1;31;40m Error: caracter desconocido:", caracter," |Linea:",linea," |Columna:",columna,"\033[0m")
            #Almacenar error
            listaerrores.append([caracter, linea, columna,'error lexico'])
            #Aumentar contador y columna
            c += 1
            columna += 1



def obtenercomentariomultilinea(text, a, columna):
    #Texto
    string = ''
    lineasextra = 0
    #Evaluar caracter por carcater
    c = 0
    for newcaracter in text:
        columna += 1
        if newcaracter == "\n":
            lineasextra +=1
            columna = 1
        elif newcaracter == '"' or newcaracter == "'":
            caractersig = text[c+1:c+2]
            if caractersig == '"' or caractersig == "'":
                caractersig2 = text[c+2:c+3]
                if caractersig2 == '"' or caractersig2 == "'":
                    columna += 1
                    a += 2            
                    return [string, a, lineasextra, columna]
        #Forma el texto
        string += newcaracter
        a += 1
        c += 1
    print("Error: No se encontraron comillas doble que cerraran el texto.")



def obtenercomentario(text, a):
    #Texto
    string = ''
    #Evaluar caracter por carcater
    for caracter in text:
        if caracter == '\n':
            return [string, a]
        #Forma el texto
        string += caracter
        a += 1
    print("Error: Al obtenrecomentario().")



def obtenernumero(texto, a):
    numero = ""
    isDecimal = False
    for newcaracter in texto:
        if newcaracter.isdigit():
            numero += newcaracter
            a += 1
        elif newcaracter == "." and not isDecimal:
            numero += newcaracter
            a += 1
            isDecimal = True
        else:
            break
    if isDecimal:
        return [float(numero), a]
    return [int(numero), a]




def enumerartokens():
    global tokens
    for i in range(0,len(tokens)):
        Token = tokens[i]
        #Cambiar ID
        tokens[i][0] = i
        Token = tokens[i]


def imprimirerroreslexicos():
    print('--------- [ ERRORES LEXICOS ] ---------\n')
    for i in listaerrores:
        print(i)



def imprimirlistatokens():
    print('--------- [ TOKENS ] ---------\n')
    for i in tokens:
        print(i)
        
        
def GetErrores():
    return listaerrores


def GetTokens(texto):
    #Valida el tamaño del texto
    if len(texto) < 0:
        MessageBox.showerror('Error - lexico()','No hay informacion necesarioa para procesarlo')
        return
    #Reinicia los valores
    global tokens, linea, columna, listaerrores, flagcomillas
    tokens = []
    linea = 1
    columna = 1
    listaerrores = []
    flagcomillas = False
    #Analiza el Texto
    evaluartexto(texto)
    
    #Pone un ID CORRECTO
    enumerartokens()
    
    return tokens
