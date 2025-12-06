import java.util.ArrayList;
import java.util.Scanner;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Practicanumero1_de_IPC1 {

    // Clase Personaje
    static class Personaje {
        private static int contadorId = 1;
        private int id;
        private String nombre;
        private String arma;
        private ArrayList<String> habilidades;
        private int nivelPoder;
        
        public Personaje(String nombre, String arma, ArrayList<String> habilidades, int nivelPoder) {
            this.id = contadorId++;
            this.nombre = nombre;
            this.arma = arma;
            this.habilidades = new ArrayList<>(habilidades);
            this.nivelPoder = nivelPoder;
        }
        
        public int getId() { return id; }
        public String getNombre() { return nombre; }
        public void setNombre(String nombre) { this.nombre = nombre; }
        public String getArma() { return arma; }
        public void setArma(String arma) { this.arma = arma; }
        public ArrayList<String> getHabilidades() { return new ArrayList<>(habilidades); }
        public void setHabilidades(ArrayList<String> habilidades) { this.habilidades = new ArrayList<>(habilidades); }
        public int getNivelPoder() { return nivelPoder; }
        public void setNivelPoder(int nivelPoder) { this.nivelPoder = nivelPoder; }
        
        @Override
        public String toString() {
            return "ID: " + id + 
                   "\nNombre: " + nombre + 
                   "\nArma: " + arma + 
                   "\nHabilidades: " + String.join(", ", habilidades) + 
                   "\nNivel de poder: " + nivelPoder;
        }
        
        public String toShortString() {
            return "ID: " + id + " | Nombre: " + nombre + " | Nivel: " + nivelPoder;
        }
    }

    // Clase Pelea
    static class Pelea {
        private Personaje personaje1;
        private Personaje personaje2;
        private LocalDateTime fechaHora;
        
        public Pelea(Personaje personaje1, Personaje personaje2) {
            this.personaje1 = personaje1;
            this.personaje2 = personaje2;
            this.fechaHora = LocalDateTime.now();
        }
        
        public Personaje getPersonaje1() { return personaje1; }
        public Personaje getPersonaje2() { return personaje2; }
        public LocalDateTime getFechaHora() { return fechaHora; }
        
        @Override
        public String toString() {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
            return "Pelea entre " + personaje1.getNombre() + " (ID: " + personaje1.getId() + 
                   ") y " + personaje2.getNombre() + " (ID: " + personaje2.getId() + 
                   ") - Fecha: " + fechaHora.format(formatter);
        }
    }

    // Clase Sistema
    static class Sistema {
        private ArrayList<Personaje> personajes;
        private ArrayList<Pelea> peleas;
        private Scanner scanner;
        
        public Sistema() {
            personajes = new ArrayList<>();
            peleas = new ArrayList<>();
            scanner = new Scanner(System.in);
        }
        
        public void iniciar() {
            mostrarMenu();
        }
        
        private void mostrarMenu() {
            while (true) {
                System.out.println("\n--- MENÚ PRINCIPAL ---");
                System.out.println("1. Agregar personaje");
                System.out.println("2. Modificar personaje");
                System.out.println("3. Eliminar personaje");
                System.out.println("4. Ver datos de un personaje");
                System.out.println("5. Ver listado de personajes");
                System.out.println("6. Realizar pelea entre personajes");
                System.out.println("7. Ver historial de peleas");
                System.out.println("8. Ver datos del estudiante");
                System.out.println("9. Salir");
                System.out.print("Seleccione una opción: ");
                
                try {
                    int opcion = Integer.parseInt(scanner.nextLine());
                    
                    switch (opcion) {
                        case 1: agregarPersonaje(); break;
                        case 2: modificarPersonaje(); break;
                        case 3: eliminarPersonaje(); break;
                        case 4: verDatosPersonaje(); break;
                        case 5: verListadoPersonajes(); break;
                        case 6: realizarPelea(); break;
                        case 7: verHistorialPeleas(); break;
                        case 8: mostrarDatosEstudiante(); break;
                        case 9:
                            System.out.println("Saliendo del sistema...");
                            return;
                        default:
                            System.out.println("Opción no válida. Intente nuevamente.");
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Error: Debe ingresar un número válido.");
                }
            }
        }
        
        private void agregarPersonaje() {
            System.out.println("\n--- AGREGAR PERSONAJE ---");
            
            String nombre;
            while (true) {
                System.out.print("Nombre del personaje: ");
                nombre = scanner.nextLine().trim();
                
                if (nombre.isEmpty()) {
                    System.out.println("Error: El nombre no puede estar vacío.");
                    continue;
                }
                
                if (buscarPersonajePorNombre(nombre) != null) {
                    System.out.println("Error: Ya existe un personaje con ese nombre.");
                } else {
                    break;
                }
            }
            
            System.out.print("Arma del personaje: ");
            String arma = scanner.nextLine().trim();
            
            ArrayList<String> habilidades = new ArrayList<>();
            System.out.println("Ingrese hasta 5 habilidades (deje vacío para terminar):");
            for (int i = 0; i < 5; i++) {
                System.out.print("Habilidad " + (i+1) + ": ");
                String habilidad = scanner.nextLine().trim();
                if (habilidad.isEmpty()) break;
                habilidades.add(habilidad);
            }
            
            int nivelPoder = 0;
            while (true) {
                try {
                    System.out.print("Nivel de poder (1-100): ");
                    nivelPoder = Integer.parseInt(scanner.nextLine());
                    
                    if (nivelPoder < 1 || nivelPoder > 100) {
                        System.out.println("Error: El nivel de poder debe estar entre 1 y 100.");
                    } else {
                        break;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Error: Debe ingresar un número válido.");
                }
            }
            
            Personaje nuevoPersonaje = new Personaje(nombre, arma, habilidades, nivelPoder);
            personajes.add(nuevoPersonaje);
            System.out.println("Personaje agregado exitosamente con ID: " + nuevoPersonaje.getId());
        }
        
        private void modificarPersonaje() {
            System.out.println("\n--- MODIFICAR PERSONAJE ---");
            
            if (personajes.isEmpty()) {
                System.out.println("No hay personajes registrados.");
                return;
            }
            
            Personaje personaje = buscarPersonaje();
            if (personaje == null) {
                System.out.println("Personaje no encontrado.");
                return;
            }
            
            System.out.println("\nDatos actuales del personaje:");
            System.out.println(personaje);
            
            System.out.println("\nIngrese los nuevos datos (deje vacío para mantener el valor actual):");
            
            System.out.print("Nueva arma [" + personaje.getArma() + "]: ");
            String nuevaArma = scanner.nextLine().trim();
            if (!nuevaArma.isEmpty()) {
                personaje.setArma(nuevaArma);
            }
            
            System.out.println("Habilidades actuales: " + String.join(", ", personaje.getHabilidades()));
            ArrayList<String> nuevasHabilidades = new ArrayList<>();
            System.out.println("Ingrese las nuevas habilidades (una por línea, hasta 5, deje vacío para terminar):");
            for (int i = 0; i < 5; i++) {
                System.out.print("Habilidad " + (i+1) + ": ");
                String habilidad = scanner.nextLine().trim();
                if (habilidad.isEmpty()) break;
                nuevasHabilidades.add(habilidad);
            }
            if (!nuevasHabilidades.isEmpty()) {
                personaje.setHabilidades(nuevasHabilidades);
            }
            
            while (true) {
                try {
                    System.out.print("Nuevo nivel de poder (1-100) [" + personaje.getNivelPoder() + "]: ");
                    String input = scanner.nextLine().trim();
                    if (input.isEmpty()) break;
                    
                    int nuevoNivel = Integer.parseInt(input);
                    if (nuevoNivel < 1 || nuevoNivel > 100) {
                        System.out.println("Error: El nivel de poder debe estar entre 1 y 100.");
                    } else {
                        personaje.setNivelPoder(nuevoNivel);
                        break;
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Error: Debe ingresar un número válido.");
                }
            }
            
            System.out.println("Personaje modificado exitosamente.");
        }
        
        private void eliminarPersonaje() {
            System.out.println("\n--- ELIMINAR PERSONAJE ---");
            
            if (personajes.isEmpty()) {
                System.out.println("No hay personajes registrados.");
                return;
            }
            
            Personaje personaje = buscarPersonaje();
            if (personaje == null) {
                System.out.println("Personaje no encontrado.");
                return;
            }
            
            System.out.println("\n¿Está seguro que desea eliminar al personaje " + personaje.getNombre() + "? (s/n)");
            String confirmacion = scanner.nextLine().trim().toLowerCase();
            
            if (confirmacion.equals("s")) {
                personajes.remove(personaje);
                System.out.println("Personaje eliminado exitosamente.");
            } else {
                System.out.println("Operación cancelada.");
            }
        }
        
        private void verDatosPersonaje() {
            System.out.println("\n--- VER DATOS DE PERSONAJE ---");
            
            if (personajes.isEmpty()) {
                System.out.println("No hay personajes registrados.");
                return;
            }
            
            Personaje personaje = buscarPersonaje();
            if (personaje == null) {
                System.out.println("Personaje no encontrado.");
                return;
            }
            
            System.out.println("\nDatos del personaje:");
            System.out.println(personaje);
        }
        
        private void verListadoPersonajes() {
            System.out.println("\n--- LISTADO DE PERSONAJES ---");
            
            if (personajes.isEmpty()) {
                System.out.println("No hay personajes registrados.");
                return;
            }
            
            System.out.println("\nPersonajes registrados:");
            for (Personaje p : personajes) {
                System.out.println(p.toShortString());
            }
        }
        
        private void realizarPelea() {
            System.out.println("\n--- REALIZAR PELEA ---");
            
            if (personajes.size() < 2) {
                System.out.println("Error: Se necesitan al menos 2 personajes registrados para realizar una pelea.");
                return;
            }
            
            System.out.println("Seleccione el primer personaje:");
            Personaje p1 = buscarPersonaje();
            if (p1 == null) {
                System.out.println("Personaje no encontrado.");
                return;
            }
            
            System.out.println("Seleccione el segundo personaje:");
            Personaje p2 = buscarPersonaje();
            if (p2 == null) {
                System.out.println("Personaje no encontrado.");
                return;
            }
            
            if (p1.getId() == p2.getId()) {
                System.out.println("Error: No puede pelear un personaje consigo mismo.");
                return;
            }
            
            Pelea nuevaPelea = new Pelea(p1, p2);
            peleas.add(nuevaPelea);
            System.out.println("Pelea registrada exitosamente:");
            System.out.println(nuevaPelea);
        }
        
        private void verHistorialPeleas() {
            System.out.println("\n--- HISTORIAL DE PELEAS ---");
            
            if (peleas.isEmpty()) {
                System.out.println("No hay peleas registradas.");
                return;
            }
            
            System.out.println("\nPeleas registradas:");
            for (Pelea pelea : peleas) {
                System.out.println(pelea);
            }
        }
        
        private void mostrarDatosEstudiante() {
            System.out.println("\n--- DATOS DEL ESTUDIANTE ---");
            System.out.println("Nombre: [TU NOMBRE COMPLETO]");
            System.out.println("Carnet: [TU NÚMERO DE CARNET]");
            System.out.println("Curso: Introducción a la Programación y Computación 1");
            System.out.println("Sección: [TU SECCIÓN]");
        }
        
        private Personaje buscarPersonaje() {
            System.out.print("Ingrese ID o nombre del personaje: ");
            String input = scanner.nextLine().trim();
            
            try {
                int id = Integer.parseInt(input);
                for (Personaje p : personajes) {
                    if (p.getId() == id) {
                        return p;
                    }
                }
            } catch (NumberFormatException e) {
                return buscarPersonajePorNombre(input);
            }
            
            return null;
        }
        
        private Personaje buscarPersonajePorNombre(String nombre) {
            for (Personaje p : personajes) {
                if (p.getNombre().equalsIgnoreCase(nombre)) {
                    return p;
                }
            }
            return null;
        }
    }

    public static void main(String[] args) {
        Sistema sistema = new Sistema();
        sistema.iniciar();
    }
}