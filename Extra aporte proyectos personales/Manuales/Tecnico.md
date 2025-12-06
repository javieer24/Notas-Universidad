# Manual Técnico

## 0. Arquitectura del sistema

El sistema implementa una arquitectura de dos capas que interactúan de la siguiente manera:

* **Frontend (React NodeVite)**: Aplicación web que se ejecuta en el navegador del usuario. Brinda una interfaz interactiva para la escritura, envío y visualización de código. Permite observar la salida de consola, visualizar la tabla de símbolos, el AST (en construcción) y los errores léxicos, sintácticos y semánticos. 
* **Backend (Python)**: API REST que corre localmente, encargada de recibir código fuente desde el frontend, procesarlo mediante un analizador construido con PLY (Python Lex-Yacc) e interpretar las instrucciones. Soporta estructuras como vectores multidimensionales, control de flujo (if, while, for, do-while, switch), operaciones aritméticas, relacionales, lógicas y estructuras de datos complejas, asi mismo como procedimientos. Responde al frontend con la salida del programa, la tabla de símbolos y los reportes de errores de forma estructurada.
---

## 0. Requisitos del sistema

Antes de clonar y ejecutar el proyecto, asegúrate de contar con:

* **Sistema operativo**: Windows 10 o superior
* **Python**: versión 3.10 o superior.
* ***Libreria requeridas***
  ```bash
  pip install flask flask-cors ply
  go version  # debe mostrar >= go1.18
  ```
* *Node.js y npm*: Node.js 16.x o superior.

  ```bash
  node -v  # >= v16.x
  npm -v
  ```

## 1. Backend

### 1.1 Visión general

El backend está implementado en Go y expone una API REST para:

* Procesar comandos de gestión de sistema de archivos simulado (ext2/3).
* Listar particiones de un disco montado.

Se organiza en los siguientes paquetes:

* **Analizador** (Analizador.go): parseo de scripts `.smia` y despacho de comandos.
* **ManejadorDisco** (ManejadorDisco.go): creación, eliminación, montaje y modificación de particiones.
* **ManejadorArchivo** (ManejadorArchivo.go): formateo (`mkfs`), creación de archivos/dirs e inodos.
* **ManejoRoot** (ManejoRoot.go): administración de usuarios y grupos sobre `/users.txt`.
* **Reportes** (Reportes.go): generación de gráficos (Graphviz) para MBR, superblock, bitmaps.
* **Usuario** (Usuario.go): login/logout y estado de sesión.
* **Utilidades** (Utilidades.go): I/O binario (lectura/escritura de estructuras en disco simulado).
* **Estructura** (Estructura.go): definición de estructuras (MBR, EBR, SuperBlock, Inode, FileBlock).
* **main** (main.go): servidor HTTP, enrutamiento y configuración CORS.

### 1.2 Estructura de carpetas

  ```bash
    backend/
    │
    ├── app.py                     # Archivo principal de ejecución del servidor Flask (API REST general)
    ├── generar.py                 # Archivo de ejecución de pruebas y evaluación directa del parser
    ├── main.py                    # API Flask para el módulo central de interpretación y endpoints
    ├── requirements.txt           # Dependencias necesarias del entorno (Flask, flask-cors, ply)
    │
    ├── lexer/                     # Módulo del análisis léxico
    │   ├── lexer.py               # Contiene reglas de tokens y expresiones regulares
    │   └── errors.py              # Definición y manejo de errores léxicos personalizados
    │
    ├── parser/                    # Módulo del análisis sintáctico y semántico
    │   ├── parser.py              # Reglas de gramática PLY (parser)
    │   ├── parsertab.py           # Tabla generada automáticamente por PLY
    │   ├── parser.out             # Archivo de salida generado por PLY
    │   ├── astNodes.py            # Definición de nodos del AST y lógica de interpretación
    │   └── utils.py               # Utilidades: tipos de datos válidos, compatibilidades y validaciones semánticas
    │
    ├── tabla_simbolos/            # Gestión de entornos y símbolos
    │   ├── tabla_simbolos.py      # Tabla de símbolos con soporte de entornos anidados
    │   ├── simbolo.py             # Clase `Symbol`, representación de variables y funciones
    │   └── instancia.py           # Singleton que expone una única instancia global de la tabla de símbolos
    │
    └── Report/                    # Módulo de reportes (en proceso de integración al flujo principal)
        ├── Advertency.py          # Advertencias semánticas
        ├── Memory.py              # Reportes de memoria o estructuras de almacenamiento
        └── Vector.py              # Lógica relacionada con vectores multidimensionales
  ```ain.go
```

### Componentes Principales Backend 

#### Lexer (lexer.py)

- Define los tokens del lenguaje, incluyendo palabras reservadas, operadores, delimitadores y tipos de datos. Usa expresiones regulares para identificar:

- Palabras clave: if, while, do, for, int, float, etc.

- Literales: enteros, flotantes, booleanos, caracteres y cadenas

- Operadores: aritméticos, relacionales, lógicos

#### Parser (parser.py)

- Define la gramatical del lenguaje y construye el AST usando clases definidas en astNodes.py. Las reglas utilizan precedencias y acciones semánticas para modelar la lógica del lenguaje.

#### AST Nodes (astNodes.py)

Contiene las clases que representan cada nodo del árbol sintáctico abstracto:

- Operadores: Suma, Resta, Mult, Div, And, Or, etc.

- Control de flujo: If, While, Dowhile, For*, Switch, Break, Continue

- Literales: IntLiteral, FloatLiteral, BoolLiteral, CharLiteral, StringLiteral

- Manejo de vectores: Declaracion_Vectores, Asignacion_Vector, AccesoVector

#### Tabla de Símbolos

La tabla de símbolos mantiene el estado actual del programa, incluyendo entornos y variables.

- Clase Symbol: representa una variable o función con metadatos

- Clase SymbolTable: implementa un singleton para gestionar los entornos

#### Flask Backend (main.py)

Provee endpoints REST para:

- /api/interprete: Ejecuta código fuente y retorna la salida

- /api/error: Retorna la lista de errores detectados

- /api/simbolos: Retorna la tabla de símbolos en JSON

- /api/ast: Retorna una estructura DOT (prototipo de AST)

#### Características Soportadas

- Expresiones aritméticas, lógicas y relacionales
- Condicionales y ciclos: if, while, do while, for, switch
- Instrucciones de flujo: break, continue
- Vectores de 1 a 4 dimensiones con acceso por posiciones y asignaciones
- Procedimientos: Declaración, Llamada.
- Gestor de entornos y ambitos
- Sistema de tipos y validaciones semánticas
- Reporte en consola y visualización por interfaz REST

#### Ejemplo de Código de Entrada

int a = 0;
while (a < 5) {
    println(a);
    if (a == 3) {
        break;
    }
    a++;
}

#### Extensiones y Mejoras Posibles

- Soporte para funciones y procedimientos
- Visualización gráfica del AST
- Reportes HTML de errores y símbolos
- Persistencia en base de datos para ejecuciones
---

### Código:
🔍 Funciones y Clases Principales por Archivo
`core/main.py – API Flask`
- `ejecutar_codigo(codigo)`
Interpreta el código fuente recibido como string, captura la salida por print, maneja errores semánticos y actualiza la tabla de símbolos.

- `@app.route('/api/interprete')`
Endpoint que recibe código fuente por POST, lo ejecuta y retorna la salida o error.

- `@app.route('/api/error')`
Devuelve los errores semánticos/sintácticos en formato JSON.

- `@app.route('/api/simbolos')`
Devuelve la tabla de símbolos actual (variables, funciones, vectores, etc.).

- `@app.route('/api/ast')`
Prototipo de visualización del AST como string DOT.

`parser/astNodes.py` – Árbol de Sintaxis Abstracta (AST)
- Literales:
  - `IntLiteral,` `FloatLiteral,` `BoolLiteral,` `CharLiteral,` `StringLiteral`
Devuelven directamente el valor que representan al interpretarse.

-  Operadores Aritméticos:
    - `Suma,` `Resta,` `Mult,` `Div,` `Pow,` `Mod`
Evalúan dos operandos, validan tipos y devuelven el resultado.

- Operadores Relacionales y Lógicos:
    - `Igual,` `Diferente,` `MenorQue,` `MayorQue,` `And,` `Or,` `Not`
Evalúan condiciones booleanas entre operandos.

- Control de Flujo:
    - `If,` `While`, `Dowhile,` `Break,` `Continue`
Implementan la lógica condicional y cíclica. El BreakException permite salir de ciclos.

Ciclos For:
    - `ForAsignacionIncremento,` `ForAsignacionDecremento,` `ForDeclaracionIncremento,` `ForDeclaracionDecremento`
Ejecutan ciclos con control de variable iteradora. Soportan break.

Vectores:
    - `Declaracion_Vectores,` `Asignacion_Vector,` `AccesoVector`
Manejan estructuras unidimensionales, bidimensionales y tridimensionales en formato row-major. Permiten declarar, modificar y acceder a vectores.

Instrucciones múltiples:
    - `ListaInstrucciones`
Estructura que permite ejecutar bloques de instrucciones en orden.

`parser/parser.py` y `parser/lexer.py`
- Reglas PLY para el análisis sintáctico y léxico.
- Definen tokens como INTT, FLOATT, IF, WHILE, BREAK, PRINTLN, etc.
- Reglas para estructuras de control, operaciones y vectores.

`tabla_simbolos/simbolo.py`
- `class Symbol`
Representa una variable, función o vector. Contiene nombre, tipo, valor, entorno, línea y columna.

### `tabla_simbolos/tabla_simbolos.py`

**Clase `SymbolTable`**  
Singleton que administra todos los entornos (alcances) y símbolos del programa.

- `nuevo_entorno(nombre)`: crea un nuevo ámbito  
- `salir_entorno()`: regresa al entorno anterior  
- `add_variable(...)`: guarda una nueva variable  
- `add_funcion(...)`: guarda una función  
- `add_vector(...)`: guarda un vector con dimensiones  
- `get_variable(nombre)`: retorna el símbolo correspondiente  
- `actualizar_variable(...)`: cambia el valor de una variable existente  
- `printTable()`: imprime la tabla de símbolos  



`utils/utils.py`
Diccionarios de compatibilidad entre tipos:

`AritmeticsSuma,` `AritmeticsResta,` `Relational`,`AritmeticsUnario,` etc.

Validan que las operaciones entre tipos sean correctas.

`generar.py`
Script de pruebas locales.
Ejecuta una entrada estática sin servidor Flask, mostrando la tabla de símbolos y tokens reconocidos.

`Report/Vector.py,` `Memory.py,` `Advertency.py`
Aunque no compartiste detalles completos, son módulos preparados para reportes o funciones adicionales como advertencias, administración de memoria o vectores.



## 2. Frontend Técnico

### 2.1 Visión general

El frontend está desarrollado en React con Vite y ofrece:

- Interfaz de carga y ejecución de scripts `.smia`
- Visualización de resultados de consola
- Visualización de la tabla de símbolos y errores
- Separación en componentes reutilizables
- Comunicación con el backend vía `fetch` usando `services/api.ts`

### 2.2 Estructura de carpetas

```
    /src
    ├── assets/                 # Recursos como imágenes o íconos
    ├── components/             # Componentes reutilizables
    │   ├── barraNavegacion.tsx
    │   ├── editorCodigo.tsx
    │   ├── reportes.tsx
    │   └── salidaConsola.tsx
    ├── pages/                  # Vistas principales de la app
    │   └── paginaPrincipal.tsx
    ├── services/               # Módulo de comunicación con backend
    │   └── api.ts
    ├── App.tsx                 # Componente raíz
    ├── main.tsx                # Entrada principal
    ├── index.css               # Estilos globales
    └── vite-env.d.ts           # Tipado global de Vite
```

### 2.3 Servicios y Comunicación
api.ts: Define funciones async para acceder a endpoints del backend:

`/api/interprete`

`/api/simbolos`

`/api/error`

`/api/ast`

Usa fetch con configuración JSON y manejo de errores.

Todas las funciones devuelven promesas y son utilizadas desde los componentes principales.

### 2.4 Componentes Relevantes
`editorCodigo.tsx:` Editor principal del script de entrada. Permite escribir o cargar archivos .smia.

`salidaConsola.tsx:` Muestra la salida textual que retorna el backend tras la interpretación.

`reportes.tsx:` Renderiza las tablas de errores semánticos/sintácticos y la tabla de símbolos.

`barraNavegacion.tsx:` Barra superior que permite cambiar entre vistas (estilo SPA).

`paginaPrincipal.tsx:` Página principal que orquesta los componentes anteriores en una interfaz única.

### 2.5 Estilos y Responsividad
`index.css`: Contiene reglas globales y estilos base.

Componentes como reportes y editorCodigo usan clases locales con diseño responsivo.

El diseño está pensado para ejecutarse en pantallas de tamaño medio a grande (desktop-first).

### 2.6 Requisitos de ejecución del frontend
- Sistema operativo: Windows / Linux / macOS
- Dependencias instaladas:
  - Node.js >= v18.x
  - npm o yarn
Instalación de paquetes:
    ```
        npm install
        npm run dev
    ```
