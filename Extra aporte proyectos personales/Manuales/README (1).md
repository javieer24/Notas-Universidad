# MIA_1S2025_P1_202100081
 Este proyecto consiste en una aplicación web para la gestión e interacción con un sistema de archivos EXT2. El backend corre en una distribución Linux, procesando las solicitudes del frontend, permitiendo administrar el sistema de archivos de manera local desde cualquier dispositivo.

## Requisitos de instalación

### Instalación de Go en Ubuntu

1. **Actualizar paquetes**:
   ```bash
   sudo apt update
   ```

2. **Instalar Go**:
   ```bash
   sudo apt install golang
   ```

3. **Verificar instalación**:
   ```bash
   go version
   ```

### Instalación de Node.js y React en Ubuntu

1. **Actualizar paquetes**:
   ```bash
   sudo apt update
   ```

2. **Instalar Node.js** (incluye npm):
   ```bash
   sudo apt install nodejs npm
   ```

3. **Verificar instalación**:
   ```bash
   node -v
   npm -v
   ```

## Ejecución del proyecto

### Backend (Go)

1. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/javieer24/MIA_1S2025_P1_202100081.git
   ```

2. **Ejecutar**:
   ```bash
   cd backend
   go run main.go
   ```

### Frontend (React)

1. **Instalar dependencias**:
   ```bash
   cd my-react-frontend
   npm install
   ```

2. **Ejecutar**:
   ```bash
   npm start
   ```

La aplicación estará disponible en `http://localhost:3000/`.

## Comandos del sistema de archivos

### Creación de discos (`mkdisk`)

- `-size`: Tamaño del disco a crear en KB o MB (obligatorio).
- `-fit`: Método de ajuste de las particiones (`BF`, `FF`, `WF`); opcional, por defecto `FF`.
- `-unit`: Unidad de medida para el tamaño (`K` para KB, `M` para MB); opcional, por defecto `M`.
- `-path`: Ruta donde se creará el archivo que simula el disco (obligatorio).

```bash
mkdisk -size=3000 -unit=K -path="/home/user/disco1.smia"
```

### Eliminación de discos (`rmdisk`)

- `-path`: Ruta del archivo que simula el disco a eliminar (obligatorio).

```bash
rmdisk -path="/home/user/disco1.smia"
```

### Creación, eliminación y modificación de particiones (`fdisk`)

- `-size`: Tamaño de la partición en KB o MB (obligatorio al crear).
- `-unit`: Unidad de medida para el tamaño (`B`, `K`, `M`); opcional, por defecto `K`.
- `-path`: Ruta del archivo que simula el disco donde se creará la partición (obligatorio).
- `-type`: Tipo de partición (`P` primaria, `E` extendida, `L` lógica); opcional, por defecto `P`.
- `-fit`: Método de ajuste de la partición (`BF`, `FF`, `WF`); opcional, por defecto `WF`.
- `-name`: Nombre de la partición (obligatorio).

```bash
fdisk -size=500 -path="/home/user/disco1.smia" -name=Part1
```

### Montar particiones (`mount`)

- `-path`: Ruta del archivo que simula el disco que contiene la partición (obligatorio).
- `-name`: Nombre de la partición a montar (obligatorio).

```bash
mount -path="/home/user/disco1.smia" -name=Part1
```

### Formateo de particiones (`mkfs`)

- `-id`: ID generado al montar la partición (obligatorio).
- `-type`: Tipo de formateo (`full` para formateo completo); opcional, por defecto `full`.

```bash
mkfs -id=341A -type=full
```

### Login (`login`)

- `-user`: Nombre del usuario (obligatorio).
- `-pass`: Contraseña del usuario (obligatorio).
- `-id`: ID de la partición montada (obligatorio).

```bash
login -user=root -pass=123 -id=341A
```

### Logout (`logout`)

Este comando no tiene parámetros.

```bash
logout
```

### Creación de grupos (`mkgrp`)

- `-name`: Nombre del grupo a crear (obligatorio).

```bash
mkgrp -name=usuarios
```

### Creación de usuarios (`mkusr`)

- `-user`: Nombre del usuario a crear (obligatorio).
- `-pass`: Contraseña del usuario (obligatorio).
- `-grp`: Nombre del grupo al que pertenecerá el usuario (obligatorio).

```bash
mkusr -user=user1 -pass=pass123 -grp=usuarios
```

### Generación de reportes (`rep`)

- `-name`: Nombre del reporte a generar (`mbr`, `disk`, `inode`, `block`, `bm_inode`, `bm_block`, `sb`, `file`, `ls`).
- `-path`: Ruta donde se guardará el reporte (obligatorio).
- `-id`: ID de la partición (obligatorio).
- `-path_file_ls`: Nombre del archivo o carpeta del que se mostrará el reporte (opcional).

```bash
rep -id=341A -path="/home/user/reports/reporte_mbr.jpg" -name=mbr
```

## Estructura del proyecto

```
MIA_1S2025_P1_202100081/
│
├── backend/
│   ├── Analyzer/
│   │   └── ...
│   ├── Commands/
│   │   └── ...
│   ├── Global/
│   │   └── ...
│   ├── Structs/
│   │   └── ...
│   ├── tmp/
│   │   └── ...
│   ├── ...
│   └── main.go
│
├── my-react-frontend/
│   ├── ...
│   └── src/
│       ├── app.js/
│       ├── app.css/
│       └── ...
├── Pruebas/
└── Reportes/
```

## Consideraciones adicionales

- **Graphviz**: Es necesario para la generación de reportes. Asegúrate de tenerlo instalado.
- **Extensión .smia**: Los archivos que simulan discos usan esta extensión.
- **Sistema EXT2**: Todas las operaciones y reportes se basan en este sistema simulado.

## Créditos

Proyecto desarrollado para el curso de Manejo e Implementación de Archivos, impartido en la Universidad de San Carlos de Guatemala.



