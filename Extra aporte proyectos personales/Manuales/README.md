# MIA_1S_P2_202100081
Interfaz web para explorar y gestionar sistemas de archivos creados por comandos. Navega discos, particiones, carpetas y archivos; incluye soporte EXT3, búsqueda, operaciones básicas y autenticación. Despliegue en AWS (S3, EC2, IAM) para escalabilidad, seguridad y alta disponibilidad.

# Manual Técnico

## 0. Arquitectura del sistema

El sistema implementa una arquitectura de tres capas que interactúan de la siguiente manera:

* **Frontend (React)**: Aplicación web que se ejecuta en el navegador del usuario. Ofrece la interfaz de carga y ejecución de scripts `.smia`, gestión de sesión y visualización gráfica de discos y particiones.
* **Backend (Go)**: API REST desplegada en una instancia AWS EC2. Procesa las solicitudes del frontend, ejecuta comandos de gestión del sistema de archivos simulado y genera reportes mediante Graphviz.
* **Almacenamiento**:

  * **Local simulado**: Archivos `.smia` que representan discos, almacenados en el sistema de archivos de la instancia EC2.
  * **AWS S3**: Bucket para almacenar de forma persistente los discos simulados y los reportes (diagramas JPEG o PNG) generados por el backend.

La comunicación se realiza sobre HTTP/HTTPS, con CORS habilitado en el backend para permitir orígenes cruzados desde el dominio del frontend.

---

## 0. Requisitos del sistema

Antes de clonar y ejecutar el proyecto, asegúrate de contar con:

* **Sistema operativo**: Ubuntu 20.04 o superior (o equivalente Linux) sobre AWS EC2 o local.
* **Go**: versión 1.18 o superior.

  ```bash
  sudo apt update && sudo apt install golang
  go version  # debe mostrar >= go1.18
  ```
* **Node.js y npm**: Node.js 16.x o superior.

  ```bash
  sudo apt install nodejs npm
  node -v  # >= v16.x
  npm -v
  ```
* **Graphviz**: para generación de reportes.

  ```bash
  sudo apt install graphviz
  dot -V
  ```
* **AWS CLI**: para despliegue y gestión de recursos.

  ```bash
  sudo apt install awscli  # o pip install awscli
  aws --version
  ```
* **Cuenta AWS**: con permisos para administrar EC2 y S3.
* **Variables de entorno**:

  * `REACT_APP_API_URL`: URL base de la API (por ejemplo, `http://<EC2_IP>:8080`).
  * Credenciales AWS configuradas (`aws configure`).

---

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

```
/proyecto1
├─ Analizador/
│  └─ Analizador.go
├─ Estructura/
│  └─ Estructura.go
├─ ManejadorDisco/
│  └─ ManejadorDisco.go
├─ ManejadorArchivo/
│  └─ ManejadorArchivo.go
├─ ManejoRoot/
│  └─ ManejoRoot.go
├─ Reportes/
│  └─ Reportes.go
├─ Usuario/
│  └─ Usuario.go
├─ Utilidades/
│  └─ Utilidades.go
├─ main.go
```

### 1.3 Endpoints REST

| Método | Ruta                               | Entrada                         | Salida                               |
| ------ | ---------------------------------- | ------------------------------- | ------------------------------------ |
| POST   | `/AnalizadorGo/ProcesarComando`    | Texto plano (comandos `.smia`)  | Texto plano (resultado de ejecución) |
| POST   | `/AnalizadorGo/ObtenerParticiones` | `{ "path": "/ruta/del/disco" }` | `[{ id, name, start, size, type }]`  |

---

## 2. Frontend Técnico

### 2.1 Visión general

El frontend está desarrollado en React y ofrece:

* Interfaz de carga y ejecución de scripts `.smia`.
* Gestión de sesión de usuario (login/logout) mediante `localStorage`.
* Visualización gráfica de discos y particiones.
* Comunicación con el backend vía `fetch` y servicio `CommandService`.

### 2.2 Estructura de carpetas

```
/src
├─ index.js            # Punto de entrada, renderiza <Main />
├─ Main.js             # Configura rutas (React Router) y NavBar
├─ App.js              # Componente principal de carga/ejecución
├─ reportWebVitals.js  # Métricas de rendimiento
├─ CommandService.js   # Servicio HTTP para todos los comandos
├─ components/
│  └─ NavBar.js        # Barra de navegación global
├─ pages/
│  ├─ App.js           # Página de ejecución (uso de fetch POST)
│  ├─ Login.js         # Formulario de inicio de sesión
│  └─ Visualizador.js  # Muestra discos/particiones creados
├─ styles/
│  ├─ App.css
│  ├─ Login.css
│  └─ Visualizador.css
└─ NavBar.css          # Estilos de la barra de navegación
```

### 2.3 Detalle de módulos

#### 2.3.1 index.js

* Renderiza `Main` dentro de `BrowserRouter` para habilitar rutas. citeturn1file0

#### 2.3.2 Main.js

* Define rutas con `<Routes>` y `<Route>`:

  * `/` y `/execution` → `<App />`
  * `/login` → `<Login />`
  * `/visualizador` → `<Visualizador />` citeturn1file1

#### 2.3.3 CommandService.js

* Parseo de texto de comando: extrae parámetros con regex `-(\\w+)=([^ ]+)`.
* Construye objetos `{ url, method, body }` según el tipo: `mkdisk`, `fdisk`, `mount`, `mkfs`, `login`, `readmbr`, `rep`.
* Almacena rutas de discos en `localStorage` al crear (`mkdisk`).
* Envía peticiones HTTP y maneja errores de respuesta. citeturn1file3

#### 2.3.4 App.js (Página de ejecución)

* **Estado**: `inputText`, `outputText`, `usuario`.
* **useEffect**: carga usuario logueado de `localStorage`.
* **triggerFileSelect**: carga `.smia` desde explorador.
* **handleExecute**: POST a `/AnalizadorGo/ProcesarComando`, muestra resultado.
* **handleLogout**: envía `logout`, limpia `localStorage` y redirige. citeturn1file5

#### 2.3.5 Login.js

* Formulario controlado con `useState` para `userId`, `password`, `partitionId`.
* `handleLogin` envía comando `login`, guarda `loggedUser` en `localStorage` y muestra alerta. citeturn1file7

#### 2.3.6 Visualizador.js

* **useEffect**: ejecuta `obtenerdiscosruta` para listar rutas guardadas.
* **handleGetPathDisk**: recibe texto con rutas, separa por `\\n`, actualiza estado.
* **fetchPartitions**: POST a `/AnalizadorGo/ObtenerParticiones`, muestra lista en UI.
* Muestra disco y particiones con íconos FontAwesome. citeturn1file9

#### 2.3.7 NavBar.js

* Componente de navegación global basado en React.
* Importa `Link` de `react-router-dom` y estilos de `NavBar.css`.
* Define enlaces a las rutas `/execution`, `/login` y `/visualizador`. citeturn2file1

### 2.4 Estilos CSS

* **App.css**: modo noche, contenedor central, botones y textareas. citeturn1file4
* **Login.css** y **Visualizador.css**: estilos de formularios responsivos y tarjetas. citeturn1file6turn1file8
* **NavBar.css**: estilo de barra de navegación en modo noche, diseño responsivo, enlaces y efectos hover. citeturn2file0

### 2.5 Configuración y despliegue

* Asegurar CORS en backend (`*` permitidos) para `http://localhost:3000`.
* Variables de entorno:

  * `REACT_APP_API_URL=http://localhost:8080` (puede centralizarse).
* Dependencias principales:

  * `react-router-dom`, `sweetalert2`, `@fortawesome/fontawesome-free`.

---

## 3. Despliegue en AWS EC2

*Pendiente de configuración de instancia y despliegue*

## 4. Integración con AWS S3

*Pendiente de detalles de bucket y uso de SDK*
