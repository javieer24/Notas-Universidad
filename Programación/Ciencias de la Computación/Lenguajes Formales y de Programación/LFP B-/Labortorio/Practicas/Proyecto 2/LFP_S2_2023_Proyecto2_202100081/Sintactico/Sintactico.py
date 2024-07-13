

listaSintactico = []
listaErroresSintactico = []
listatokens = []
listaClaves = []
templistaClaves = []
templistatokens = []
listaRegistros = []
templistaRegistros = []
templista = []
frenogramaticaR = False
listasimbolos = ['{','}',':','[',']',',','(',')',';','=','"',"'",'#','_','-','.']
listaletras = ['A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z','Ñ','ñ']
listanumeros = ['0','1','2','3','4','5','6','7','8','9','.']


def imprimirErrores():
    print('\n----------------------------- [ Errores | Sintactico]----------------------------- \n')
    for i in listaErroresSintactico: 
        print(i)


def imprimirlistaSintactico():
    print('\n----------------------------- [ Lista Sintactico | Instrucciones]----------------------------- \n')
    for i in listaSintactico:
        print(i)
    print('\n')


def enumerarlistatokens():
    global listatokens
    print('\n-----------------------------  [ NUEVA LISTA TOKENS] ----------------------------- \n')
    for i in range(0,len(listatokens)):
        Token = listatokens[i]
        #Cambiar ID
        listatokens[i][0] = i
        Token = listatokens[i]
        print(Token)
    print('\n-----------------------------  [ FIN ] ----------------------------- \n')


def obtenernumero(a):
    global listatokens, listanumeros
    inicio = a
    fin = a
    txtnumero = ''
    #-----
    maxiteraciones = len(listatokens)
    while a < maxiteraciones:
        token = listatokens[a][1]
        #Busca si esta en el listado de numeros
        if token in listanumeros:
            txtnumero += token
            a += 1
            fin = a
        else:
            fin = a
            a = maxiteraciones 
    #-----
    #Convierte txtnumero
    if len(txtnumero) <= 0:
        return [None,fin]
    else:
        try:
            numero = float(txtnumero)
            return [numero, fin]
        except:
            return [None, fin]



def obtenertexto(a):
    global listatokens
    inicio = a
    texto = ''
    #-----
    maxiteraciones = len(listatokens)
    while a < maxiteraciones:
        token = listatokens[a][1]
        if token == '"' or token == "'":
            a += 1
            return [texto,a]
        else:
            texto += token
            a += 1


def fininstruccion(a,tokenesperado):
    global listatokens, listaErroresSintactico
    inicio = a
    maxiteraciones = len(listatokens)
    while a < maxiteraciones:
        token = listatokens[a][1]
        if token == ';' or token == '\n':
            a += 1
            #Validador para que no se salga de lista 
            if a >= maxiteraciones:
                a -= 1
            #Agregar a errores
            listaErroresSintactico.append([listatokens[inicio][1],str(tokenesperado),listatokens[inicio][2],listatokens[inicio][3],'error Sintactico',listatokens[a-1][2],listatokens[a-1][3]])
            
    
            return a
        else:
            a += 1

def fininstruccionPornumero(start,a,tokenesperado,fin):
    global listatokens, listaErroresSintactico
    inicio = start
    #Obtener numero
    txtnumero=''
    for i in range(start,fin,1):
        txtnumero += listatokens[i][1]
    

    maxiteraciones = len(listatokens)
    while a < maxiteraciones:
        token = listatokens[a][1]
        if token == ';' or token == '\n':
            a += 1
            #Agregar a errores
            listaErroresSintactico.append([str(txtnumero),str(tokenesperado),listatokens[inicio][2],listatokens[inicio][3],'error Sintactico',listatokens[inicio][2],listatokens[a-1][3]])
            return a
        else:
            a += 1


def obtenertextoentrecomillasLista(c):
    global templistaClaves
    Token = listatokens[c][1]
    if Token == '"':
        AFDTexto = AFDTextoentrecomillas(c)
        if AFDTexto == True:
            texto, a = obtenertexto(c+1)
            c = a
            templistaClaves.append(texto)
            token = listatokens[c][1]
            if listatokens[c][1] == ']':
                return c
            elif listatokens[c][1] == ',':
                if listatokens[c+1][1] == '"':
                    c = obtenertextoentrecomillasLista(c+1)
                else:
                    c = fininstruccion(c+1,'"')  
            else:
                # c = fininstruccion(c,',')
                return c
        else:
            c = ErrorAFDTextoentrecomillas(c+1,'"')
            #Validar si es el ultimo dato de la fila
            token = listatokens[c-1][1]
            if token == ']':
                c = c
            else:
                # c = fininstruccion(c,']')  
                c = c
    else:
        c = fininstruccion(c,'"')
    return c


def quitarespaciosysaltosdelinea(c,tokenabuscarparaparar):
    global templistatokens
    #Agregar tokens a nueva lista
    for i in listatokens:
        templistatokens.append(i)
    # templistatokens = listatokens
    inicio = c
    fin = 0
    maxiteraciones = len(templistatokens)
    while c < maxiteraciones:
        token = templistatokens[c][1]
        #Break
        if token == tokenabuscarparaparar:
            fin = c
            c = maxiteraciones
        elif token.isspace():
            #Remover
            templistatokens.pop(c)
            maxiteraciones -= 1
        else:
            #Aumentar contador
            c += 1


    #Validar
    if fin <= 0:
        return [False, fin]
    else:
        return [True, fin]


def ErrorAFDTextoentrecomillas(a,tokenesperado):
    global listatokens, listaErroresSintactico
    inicio = a
    maxiteraciones = len(listatokens)
    while a < maxiteraciones:
        token = listatokens[a][1]
        #Salida
        if token == ')' or token == ';' or token == '\n' or token == ']' or token == ',':
            a += 1
            #Agregar a errores
            listaErroresSintactico.append([listatokens[a-1][1],str(tokenesperado),listatokens[a-1][2],listatokens[a-2][3],'error Sintactico',listatokens[a-1][2],listatokens[a-1][3]])
            return a
        else:
            a += 1



def AFDTextoentrecomillas(c):
    global listatokens
    #iterador
    maxiteraciones = len(listatokens)
    #TEXTO
    texto = ''
    #Estados
    #q1,q2,q3,q4,q5
    inicio = 0
    final = 5
    estado = inicio

    if listatokens[c][1] == '"':
        estado = 1
        c+=1
        while c < maxiteraciones:
            #Token
            token = listatokens[c][1]
            #Salida
            if token == ')' or token == ';' or token == '\n' or token == ']' or token == ',':
                return False
            elif token == '"':
                estado = 5
                c+=1
                return True
            elif token in listaletras:
                estado = 2
                c+=1
            elif token in listasimbolos:
                estado = 3
                c+=1
            elif token.isdigit():
                estado = 4
                c+=1
            else:
                c+=1
        
        return False


def AFDListaTexto(c):
    global listatokens
    #iterador
    maxiteraciones = len(listatokens)
    #TEXTO
    texto = ''
    #Estados
    #q1,q2,q3,q4,q5,q6,q7,q8,q9
    inicio = 1
    final = 7
    estado = inicio

    if listatokens[c][1] == '[':
        estado = 2
        texto += '['
        c+=1
        if listatokens[c][1] == '"':
            estado = 3
            texto += '"'
            c+=1
            while c < maxiteraciones:
                #Token
                token = listatokens[c][1]
                if token == ')' or token == ';' or token == '\n':
                    return False
                elif token == '"':
                    estado = 5
                    texto += '"'
                    c+=1
                    break
                elif token in listaletras or token in listasimbolos or token in listanumeros:
                    estado = 4
                    texto += token
                    c+=1
                else:
                    c+=1
        
        token2 = listatokens[c][1]
        if token2 == ']':
            estado = 7
            texto += ']'
            c+=1
            return True
        elif listatokens[c][1] == ',':
            estado = 6
            texto += ','
            c+=1
            if listatokens[c][1] == '"':
                estado = 8
                texto += '"'
                c+=1
                while c < maxiteraciones:
                    token = listatokens[c][1]
                    if token == '"':
                        estado = 5
                        texto += '"'
                        c+=1
                        break
                    elif token in listaletras or token in listasimbolos or token in listanumeros:
                        estado = 9
                        texto += token
                        c+=1
                    else:
                        c+=1

        token2 = listatokens[c][1]
        if token2 == ']':
            estado = 7
            texto += ']'
            c+=1
            return True 
        
    return False


def getTextoentrecomillas(c):
    global listatokens
    #iterador
    maxiteraciones = len(listatokens)
    #TEXTO
    texto = ''
    if listatokens[c][1] == '"':
        c+=1
        while c < maxiteraciones:
            #Token
            token = listatokens[c][1]
            if token == '"':
                c+=1
                return texto, c
            elif token in listaletras or token in listasimbolos:
                #Añadir token
                texto += token
                c+=1
            else:
                c+=1


def Gramaticatokeni(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'i':
        if listatokens[c+1][1] == 'm':
            if listatokens[c+2][1] == 'p':
                if listatokens[c+3][1] == 'r':
                    if listatokens[c+4][1] == 'i':
                        if listatokens[c+5][1] == 'm':
                            if listatokens[c+6][1] == 'i':
                                if listatokens[c+7][1] == 'r':
                                    if listatokens[c+8][1] == '(':
                                        c = GramaticaEspecialtextoentreparentesisycomillas(c+8,'imprimir')
                                    else:
                                        if listatokens[c+8][1] == 'l':
                                            if listatokens[c+9][1] == 'n':
                                                if listatokens[c+10][1] == '(':
                                                    c = GramaticaEspecialtextoentreparentesisycomillas(c+10,'imprimirln')
                                                else:
                                                    c = fininstruccion(c+10,'(')
                                            else:
                                                c = fininstruccion(c+9,'n')
                                        else:
                                            c = fininstruccion(c+8,'( | l ')
                                else:
                                    c = fininstruccion(c+7,'r')
                            else:
                                c = fininstruccion(c+6,'i')
                        else:
                            c = fininstruccion(c+5,'m')
                    else:
                        c = fininstruccion(c+4,'i')
                else:
                    c = fininstruccion(c+3,'r')
            else:
                c = fininstruccion(c+2,'p')
        else:
            c = fininstruccion(c+1,'m')
    
    return c


def GramaticatokenC(c):
    global listaSintactico, listatokens, listaClaves, templistaClaves

    #Remover espacios, tabulaciones y saltos de linea
    flagsinespacios, fin = quitarespaciosysaltosdelinea(c,']')
    #Nueva lista
    if flagsinespacios == True:
        #Remplazar lista sin espacios y saltos de linea para la gramatica C
        listatokens = templistatokens
        #Cambiar id listas
        enumerarlistatokens()

    #Evaluar
    if listatokens[c][1] == 'C':
        if listatokens[c+1][1] == 'l':
            if listatokens[c+2][1] == 'a':
                if listatokens[c+3][1] == 'v':
                    if listatokens[c+4][1] == 'e':
                        if listatokens[c+5][1] == 's':
                            if listatokens[c+6][1] == '=':
                                if listatokens[c+7][1] == '[':
                                    c = GramaticaEspecialListadeTextoentrecorchetes(c+7,'Claves')
                                else:
                                    c = fininstruccion(c+7,'[')
                            else:
                                c = fininstruccion(c+6,'s')
                        else:
                            c = fininstruccion(c+5,'e')
                    else:
                        c = fininstruccion(c+4,'v')
                else:
                    c = fininstruccion(c+3,'a')
            else:
                c = fininstruccion(c+2,'l')
        else:
            c = fininstruccion(c+1,'C')
    return c


def Gramaticatokenc(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'c':
        if listatokens[c+1][1] == 'o':
            if listatokens[c+2][1] == 'n':
                if listatokens[c+3][1] == 't':
                    if listatokens[c+4][1] == 'e':
                        if listatokens[c+5][1] == 'o':
                            if listatokens[c+6][1] == '(':
                                if listatokens[c+7][1] == ')':
                                    if listatokens[c+8][1] == ';':
                                        c = c+9
                                        listaSintactico.append(['conteo',None])
                                    else:
                                        c = fininstruccion(c+7,')')
                                else:
                                    c = fininstruccion(c+7,')')
                            else:
                                c = fininstruccion(c+6,'(')
                        else:
                            c = fininstruccion(c+5,'d')
                    else:
                        if listatokens[c+4][1] == 'a':
                            if listatokens[c+5][1] == 'r':
                                if listatokens[c+6][1] == 's':
                                    if listatokens[c+7][1] == 'i':
                                        if listatokens[c+8][1] == '(':
                                            if listatokens[c+9][1] == '"':
                                                AFDTexto = AFDTextoentrecomillas(c+9)
                                                if AFDTexto == True:
                                                    texto, a = obtenertexto(c+10)
                                                    c = a
                                                    if listatokens[c][1] == ',':
                                                        numero, a = obtenernumero(c+1)
                                                        inicio = c
                                                        c = a
                                                        if numero != None:  
                                                            if listatokens[c][1] == ')':
                                                                if listatokens[c+1][1] == ';':
                                                                    c=c+2
                                                                    print('\nexportarsi○\n')
                                                                    listaSintactico.append(['contarsi',[texto, numero]])
                                                                else:
                                                                    c = fininstruccion(c+1,';')    
                                                            else:
                                                                c = fininstruccion(c,')')    
                                                        else:
                                                            if listatokens[c][1] == '"':
                                                                AFDTexto = AFDTextoentrecomillas(c)
                                                                if AFDTexto == True:
                                                                    texto2, a = obtenertexto(c+1)
                                                                    c = a
                                                                    if listatokens[c][1] == ')':
                                                                        if listatokens[c+1][1] == ';':
                                                                            c += 2
                                                                            print('\nexportarsi○\n')
                                                                            listaSintactico.append(['contarsi',[texto, texto2]])
                                                                        else:
                                                                            c = fininstruccion(c+1,';')
                                                                    else:
                                                                        c = fininstruccion(c,')')
                                                                else:
                                                                    c = ErrorAFDTextoentrecomillas(c,'"')
                                                                    c = fininstruccion(c,'"')  
                                                            
                                                            # c = fininstruccionPornumero(inicio+1,c,'"|NUMERO',c)
                                                    else:
                                                        c = fininstruccion(c,',')
                                                else:
                                                    c = ErrorAFDTextoentrecomillas(c+9,'"')
                                                    c = fininstruccion(c,')')
                                            else:
                                                c = fininstruccion(c+9,'"')
                                        else:
                                            c = fininstruccion(c+8,'(')
                                    else:
                                        c = fininstruccion(c+7,'i')
                                else:
                                    c = fininstruccion(c+6,'s')
                            else:
                                c = fininstruccion(c+5,'r')
                        else:
                            c = fininstruccion(c+4,'e|a')
                else:
                    c = fininstruccion(c+3,'m')
            else:
                c = fininstruccion(c+2,'o')
        else:
            c = fininstruccion(c+1,'r')
    return c


def Gramaticatokend(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'd':
        if listatokens[c+1][1] == 'a':
            if listatokens[c+2][1] == 't':
                if listatokens[c+3][1] == 'o':
                    if listatokens[c+4][1] == 's':
                        if listatokens[c+5][1] == '(':
                            if listatokens[c+6][1] == ')':
                                if listatokens[c+7][1] == ';':
                                    c = c+8
                                    listaSintactico.append(['datos',None])
                                else:
                                    c = fininstruccion(c+7,';')
                            else:
                                c = fininstruccion(c+6,')')
                        else:
                            c = fininstruccion(c+5,'(')
                    else:
                        c = fininstruccion(c+4,'s')
                else:
                    c = fininstruccion(c+3,'o')
            else:
                c = fininstruccion(c+2,'t')
        else:
            c = fininstruccion(c+1,'a')
    return c


def Gramaticatokene(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'e':
        if listatokens[c+1][1] == 'x':
            if listatokens[c+2][1] == 'p':
                if listatokens[c+3][1] == 'o':
                    if listatokens[c+4][1] == 'r':
                        if listatokens[c+5][1] == 't':
                            if listatokens[c+6][1] == 'a':
                                if listatokens[c+7][1] == 'r':
                                    if listatokens[c+8][1] == 'R':
                                        if listatokens[c+9][1] == 'e':
                                            if listatokens[c+10][1] == 'p':
                                                if listatokens[c+11][1] == 'o':
                                                    if listatokens[c+12][1] == 'r':
                                                        if listatokens[c+13][1] == 't':
                                                            if listatokens[c+14][1] == 'e':
                                                                if listatokens[c+15][1] == '(':
                                                                    c = GramaticaEspecialtextoentreparentesisycomillas(c+15,'exportarReporte')
                                                                else:
                                                                    c = fininstruccion(c+8,'(')
                                                            else:
                                                                c = fininstruccion(c+14,'e')
                                                        else:
                                                            c = fininstruccion(c+13,'t')
                                                    else:
                                                        c = fininstruccion(c+12,'r')
                                                else:
                                                    c = fininstruccion(c+11,'o')
                                            else:
                                                c = fininstruccion(c+10,'p')
                                        else:
                                            c = fininstruccion(c+9,'e')
                                    else:
                                        c = fininstruccion(c+8,'R')
                                else:
                                    c = fininstruccion(c+7,'r')
                            else:
                                c = fininstruccion(c+6,'a')
                        else:
                            c = fininstruccion(c+5,'t')
                    else:
                        c = fininstruccion(c+4,'r')
                else:
                    c = fininstruccion(c+3,'o')
            else:
                c = fininstruccion(c+2,'p')
        else:
            c = fininstruccion(c+1,'x')
    return c


def Gramaticatokenm(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'm':
        if listatokens[c+1][1] == 'a':
            if listatokens[c+2][1] == 'x':
                if listatokens[c+3][1] == '(':
                    c = GramaticaEspecialtextoentreparentesisycomillas(c+3,'maximo')
                else:
                    c = fininstruccion(c+3,'(')
            else:
                c = fininstruccion(c+2,'x')
        else:
            if listatokens[c+1][1] == 'i':
                if listatokens[c+2][1] == 'n':
                    if listatokens[c+3][1] == '(':
                        c = GramaticaEspecialtextoentreparentesisycomillas(c+3,'minimo')
                    else:
                        c = fininstruccion(c+3,'(')
                else:
                    c = fininstruccion(c+2,'n')
            else:
                c = fininstruccion(c+1,'a|i')
    return c


def Gramaticatokenp(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 'p':
        if listatokens[c+1][1] == 'r':
            if listatokens[c+2][1] == 'o':
                if listatokens[c+3][1] == 'm':
                    if listatokens[c+4][1] == 'e':
                        if listatokens[c+5][1] == 'd':
                            if listatokens[c+6][1] == 'i':
                                if listatokens[c+7][1] == 'o':
                                    if listatokens[c+8][1] == '(':
                                        c = GramaticaEspecialtextoentreparentesisycomillas(c+8,'promedio')
                                    else:
                                        c = fininstruccion(c+8,'(')
                                else:
                                    c = fininstruccion(c+7,'o')
                            else:
                                c = fininstruccion(c+6,'i')
                        else:
                            c = fininstruccion(c+5,'d')
                    else:
                        c = fininstruccion(c+4,'e')
                else:
                    c = fininstruccion(c+3,'m')
            else:
                c = fininstruccion(c+2,'o')
        else:
            c = fininstruccion(c+1,'r')
    return c


def GramaticatokenR(c):
    global listaSintactico, listatokens, listaClaves, templistaClaves, templistaRegistros, listaRegistros, frenogramaticaR
    #Reiniciar Valor
    frenogramaticaR = False
    #Remover espacios, tabulaciones y saltos de linea
    flagsinespacios, fin = quitarespaciosysaltosdelinea(c,']')
    #Nueva lista
    if flagsinespacios == True:
        #Remplazar lista sin espacios y saltos de linea para la gramatica C
        listatokens = templistatokens
        #Cambiar id listas
        enumerarlistatokens()

    #Evaluar
    if listatokens[c][1] == 'R':
        if listatokens[c+1][1] == 'e':
            if listatokens[c+2][1] == 'g':
                if listatokens[c+3][1] == 'i':
                    if listatokens[c+4][1] == 's':
                        if listatokens[c+5][1] == 't':
                            if listatokens[c+6][1] == 'r':
                                if listatokens[c+7][1] == 'o':
                                    if listatokens[c+8][1] == 's':
                                        if listatokens[c+9][1] == '=':
                                            if listatokens[c+10][1] == '[':
                                                c = Gramaticallaves(c+11)
                                                #Salida
                                                if frenogramaticaR == True:
                                                    return c
                                                if listatokens[c][1] == ']':
                                                    c += 1
                                                    print('OK')
                                                    print('Registros: ', templistaRegistros)
                                                    #Añadir registros
                                                    for i in templistaRegistros:
                                                        listaRegistros.append(i)
                                                    #Guardar instruccion
                                                    listaSintactico.append(['Registros',listaRegistros])
                                                else:
                                                    c = fininstruccion(c,']')
                                            else:
                                                c = fininstruccion(c+10,'[')
                                        else:
                                            c = fininstruccion(c+9,'=')
                                    else:
                                        c = fininstruccion(c+8,'s')
                                else:
                                    c = fininstruccion(c+7,'o')
                            else:
                                c = fininstruccion(c+6,'r')
                        else:
                            c = fininstruccion(c+5,'t')
                    else:
                        c = fininstruccion(c+4,'s')
                else:
                    c = fininstruccion(c+3,'i')
            else:
                c = fininstruccion(c+2,'g')
        else:
            c = fininstruccion(c+1,'e')
    return c


def Gramaticatokens(c):
    global listaSintactico, listatokens
    if listatokens[c][1] == 's':
        if listatokens[c+1][1] == 'u':
            if listatokens[c+2][1] == 'm':
                if listatokens[c+3][1] == 'a':
                    if listatokens[c+4][1] == 'r':
                        if listatokens[c+5][1] == '(':
                            c = GramaticaEspecialtextoentreparentesisycomillas(c+5,'sumar')
                        else:
                            c = fininstruccion(c+5,'(')
                    else:
                        c = fininstruccion(c+4,'r')
                else:
                    c = fininstruccion(c+3,'a')
            else:
                c = fininstruccion(c+2,'m')
        else:
            c = fininstruccion(c+1,'u')
    return c




def GramaticaEspecialtextoentreparentesisycomillas(c,funcion):
    global listaSintactico, listatokens
    if listatokens[c][1] == '(':
        if listatokens[c+1][1] == '"':
            AFDTexto = AFDTextoentrecomillas(c+1)
            if AFDTexto == True:
                texto, a = obtenertexto(c+2)
                c = a
                if listatokens[c][1] == ')':
                    if listatokens[c+1][1] == ';':
                        c += 2
                        listaSintactico.append([funcion,texto])
                    else:
                        c = fininstruccion(c+1,';')
                else:
                    c = fininstruccion(c,')')
            else:
                c = ErrorAFDTextoentrecomillas(c+6,'"')
                c = fininstruccion(c,')')  
        else:
            c = fininstruccion(c+1,'"')
    else:
        c = fininstruccion(c,'(')
    
    return c


def GramaticaEspecialListadeTextoentrecorchetes(c,funcion):
    if listatokens[c][1] == '[':
        if listatokens[c+1][1] == '"':
            c = obtenertextoentrecomillasLista(c+1)
            if listatokens[c][1] == ']' and listatokens[c-1][1] != ',':
                c +=1
                print('\n Claves',templistaClaves,'\n')
                #Almacenar Claves
                listaClaves = templistaClaves
                #Agregar a lista instrucciones
                listaSintactico.append([funcion,listaClaves])
            else:
                c = fininstruccion(c,']')
        else:
            c = fininstruccion(c+1,'"')
    else:
        c = fininstruccion(c,'[')
    
    return c


def Gramaticallaves(c):
    if listatokens[c][1] == '{':
        c = GramaticaEspecialListadeRegistro(c+1)
        #Salida
        if frenogramaticaR == True:
            return c
        if listatokens[c][1] == '}':
            if listatokens[c+1][1] == '{':
                c=c+1
                c = Gramaticallaves(c)
            elif listatokens[c+1][1] == ']':
                #Salida
                c=c+1
            else:
                c = fininstruccion(c,'{|]')             
        else:
            c = fininstruccion(c,'}')        
    
    else:
        c = fininstruccion(c,'{')
    return c


def obtenertextoentrecomillasRegistro(c):
    global frenogramaticaR
    Token = listatokens[c][1]
    texto, a = ['',c]
    if Token == '"':
        AFDTexto = AFDTextoentrecomillas(c)
        if AFDTexto == True:
            texto, a = obtenertexto(c+1)
            c = a
            return [texto, c]
        else:
            c = ErrorAFDTextoentrecomillas(c+1,'"')
            #Validar si es el ultimo dato de la fila
            token = listatokens[c-1][1]
            token2 = listatokens[c][1]
            c = fininstruccion(c,'"|,')
            frenogramaticaR = True
    else:
        c = fininstruccion(c,'"')
    
    return [texto, c]




def GramaticaEspecialListadeRegistro(c):
    global templista, templistaRegistros, frenogramaticaR
    Token = listatokens[c][1]
    #[ CASO 1] [TEXTO ENTRE COMILLAS]----------------------------- 
    if Token == '"':
        texto, a = obtenertextoentrecomillasRegistro(c)
        #Añadir registro
        templista.append(texto)
        c = a
        token3 = listatokens[c][1]
        #Salida
        if frenogramaticaR == True:
            return c
        if token3 == '}':   
            #Añadir registro
            templistaRegistros.append(templista)
            #Limpiar
            templista = []
        elif token3 == ',':
            token4 = listatokens[c+1][1]
            if token4 == '"' or token4 in listanumeros:
                c = GramaticaEspecialListadeRegistro(c+1)
            else:
                c = fininstruccion(c+1,'"|NUMERO')
    #[ CASO 2] [NUMERO] ----------------------------- 
    elif Token in listanumeros:
        token2 = listatokens[c][1]
        inicio = c
        numero, a = obtenernumero(c)
        #Añadir registro
        templista.append(numero)
        c = a
        token3 = listatokens[c][1]
        #Salida
        if frenogramaticaR == True:
            return c
        if numero == None:
            c = inicio
            c = fininstruccion(c,'NUMERO_VALIDO')
            frenogramaticaR = True
            return c
        if token3 == '}':   
            #Añadir registro
            templistaRegistros.append(templista)
            #Limpiar
            templista = []
        elif token3 == ',':
            token4 = listatokens[c+1][1]
            if token4 == '"' or token4 in listanumeros:
                c = GramaticaEspecialListadeRegistro(c+1)
            else:
                c = fininstruccion(c+1,'"|NUMERO')

    else:
        frenogramaticaR = True
        c = fininstruccion(c+1,'"|NUMERO')
    
    return c


def evaluartokens(tokens):
    global listaSintactico, listatokens
    #Almacenar Tokens
    listatokens = tokens
    print('\n-----------------------------  [ EVALUAR TOKENS ] ----------------------------- ')
    #Iterador
    c = 0
    maxiteraciones = len(listatokens)
    while c < maxiteraciones:
        Token = listatokens[c][1]

        #Ignorar Comentarios
        if listatokens[c][4] == 'Comentario_multilinea' or listatokens[c][3] == 'Comentario_simple':
            c += 1    
        #[ c ] 
        elif Token == 'C':
            c = GramaticatokenC(c)
            #Se actualizo la lista quitando algunos espacios y saltos de linea
            maxiteraciones = len(listatokens)
        #[ c ]
        elif Token == 'c':
            c = Gramaticatokenc(c)
        #[ m ] 
        elif Token == 'm':
            c = Gramaticatokenm(c)
        #[ d ] 
        elif Token == 'd':
            c = Gramaticatokend(c)
        #[ e ] 
        elif Token == 'e':
            c = Gramaticatokene(c)
        #[ i ] 
        elif Token == 'i':
            c = Gramaticatokeni(c)
        #[ p ] 
        elif Token == 'p':
            c = Gramaticatokenp(c)
        #[ p ] 
        elif Token == 'R':
            #Reiniciar valores
            global templistaClaves, templistatokens, templistaRegistros, templista, frenogramaticaR
            templistaClaves = []
            templistatokens = []
            templistaRegistros = []
            templista = []
            frenogramaticaR = False
            #Evaluar
            c = GramaticatokenR(c)
            #Se actualizo la lista quitando algunos espacios y saltos de linea
            maxiteraciones = len(listatokens)
        #[ s ] 
        elif Token == 's':
            c = Gramaticatokens(c)
        #
        else:
            print('Token:', listatokens[c])
            c += 1
    

def GetErrores():
    return listaErroresSintactico



def GetInstrucciones(tokens):
    global listaSintactico, listaErroresSintactico, listaClaves, templistaClaves,templistatokens, listatokens, listaRegistros,templistaRegistros,templista,frenogramaticaR
    listaSintactico = []
    listaErroresSintactico = []
    listatokens = []
    listaClaves = []
    templistaClaves = []
    templistatokens = []
    listaRegistros = []
    templistaRegistros = []
    templista = []
    frenogramaticaR = False
    

    

    #Evaluar tokens
    evaluartokens(tokens)

    return listaSintactico

