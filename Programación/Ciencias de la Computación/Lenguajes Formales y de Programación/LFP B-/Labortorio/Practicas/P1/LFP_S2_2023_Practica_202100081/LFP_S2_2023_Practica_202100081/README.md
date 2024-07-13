# Lenguajes Formales y de Programación
## LFP_S2_2023_Practica_202100081
### Segundo Semestre
```js
Universidad San Carlos de Guatemala
Programador: Javier Andrés Monjes Solórzano 
Carne: 202100081
Correo:3020696740101@ingenieria.usac.edu.gt
### Practica 1 - Lenguajes Formales de Programacion
```
---
## Descripción del Proyecto
Este proyecto es un programa de gestión de inventario. El código está dividido en varios archivos, cada uno con funciones específicas relacionadas con el menú principal, la gestión del inventario y el código principal del programa. El programa permite al usuario cargar el inventario inicial y las instrucciones de movimientos desde archivos externos, así como crear un informe de inventario. El menú principal muestra las opciones disponibles y permite al usuario seleccionar la acción que desea realizar. El programa continúa ejecutándose hasta que el usuario selecciona la opción “Salir” en el menú principal.

## Objetivos
* Objetivo General
    * Proporcionar una herramienta para la gestión de inventario.
* Objetivos Específicos
    * Proporcionar una forma fácil y eficiente de cargar el inventario inicial y las instrucciones de movimientos desde archivos externos.
    * Permitir al usuario crear un informe detallado del inventario en un archivo .txt para su posterior análisis y revisión.

---
## Estructura del programa
El código del programa está dividido en varios archivos: menu.py, inventario.py y main.py. Cada archivo contiene funciones y código relacionado con una parte específica del programa.

![Screenshot 2023-08-18 122631](https://github.com/javieer24/LFP_S2_2023_Practica_202100081/assets/74402782/2d387939-4b7a-40f4-9122-49973a331bdd)


### Librerias Utilizadas
![Screenshot 2023-08-18 120419](https://github.com/javieer24/LFP_S2_2023_Practica_202100081/assets/74402782/110140fe-68ff-473d-9701-02ea01ab6f9f)


La biblioteca os es una biblioteca estándar de Python que proporciona una forma de utilizar la funcionalidad dependiente del sistema operativo de manera portátil. Permite interactuar con el sistema operativo subyacente, incluyendo el acceso y manipulación del sistema de archivos, variables de entorno e incluso procesos.

El módulo filedialog es parte de la biblioteca tkinter, que es la interfaz estándar de Python para el kit de herramientas GUI Tk. El módulo filedialog proporciona clases y funciones para crear ventanas de selección de archivos/directorios. Estos diálogos tienen un aspecto y comportamiento nativo y proporcionan varias opciones de configuración para personalizar su comportamiento.

En este proyecto, parece que la biblioteca os se utiliza para interactuar con el sistema operativo, mientras que el módulo filedialog se utiliza para crear cuadros de diálogo para seleccionar archivos y directorios. Esto permite al usuario cargar fácilmente el inventario inicial y las instrucciones de movimientos desde archivos externos.

### menu.py
![Screenshot 2023-08-18 120304](https://github.com/javieer24/LFP_S2_2023_Practica_202100081/assets/74402782/725b139b-12a2-408f-9251-97c541988ace)

Este archivo contiene la función mostrar_menu(), que se utiliza para mostrar el menú principal del programa y obtener la opción seleccionada por el usuario. La función mostrar_menu() utiliza la entrada estándar para mostrar las opciones disponibles y obtener la opción seleccionada por el usuario. La función mostrar_menu() devuelve la opción seleccionada por el usuario como una cadena.
Las opciones del menú principal son las siguientes:
    * Cargar el inventario inicial
    * Cargar las instrucciones de los movimientos
    * Crear informe de inventario
    * Salir




### inventario.py
Este archivo contiene varias funciones relacionadas con la gestión del inventario. La función cargar_inventario_inicial() se utiliza para cargar el inventario inicial desde un archivo .inv. Esta función muestra un cuadro de diálogo para seleccionar el archivo .inv y luego lee cada línea del archivo para crear el inventario inicial.

La función cargar_instrucciones_movimientos(inventario) se utiliza para cargar instrucciones de movimientos desde un archivo .mov. Esta función muestra un cuadro de diálogo para seleccionar el archivo .mov y luego lee cada línea del archivo para registrar los movimientos de productos en el inventario.

La función crear_informe_inventario(inventario) se utiliza para crear un informe de inventario en un archivo .txt. Esta función muestra un cuadro de diálogo para guardar el archivo .txt y luego escribe información sobre cada producto en el inventario en el archivo.

La función mostrar_inventario(inventario) se utiliza para mostrar el inventario actual en la consola. Esta función muestra el nombre, la cantidad y el precio de cada producto en el inventario.

![Screenshot 2023-08-18 120527](https://github.com/javieer24/LFP_S2_2023_Practica_202100081/assets/74402782/bee5574b-85e4-4daa-9c4e-4105ed84eddf)
![Screenshot 2023-08-18 120559](https://github.com/javieer24/LFP_S2_2023_Practica_202100081/assets/74402782/4a2b1199-e977-4ba8-be48-b77d26f88beb)



### main.py 
![Screenshot 2023-08-18 120234](https://github.com/javieer24/LFP_S2_2023_Practica_202100081/assets/74402782/5ec44c30-95f8-4ebb-9fd8-9f01db8bebd3)

Este archivo contiene el código principal del programa. El bucle principal del programa utiliza la función mostrar_menu() para mostrar el menú principal y obtener la opción seleccionada por el usuario. Dependiendo de la opción seleccionada por el usuario, se invoca una de las funciones del archivo inventario.py para realizar la acción correspondiente. El bucle principal continúa hasta que el usuario selecciona la opción “Salir” en el menú principal.

