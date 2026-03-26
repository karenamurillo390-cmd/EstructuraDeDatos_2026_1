#include <iostream>
#include <vector>
#include <string>
#include <thread> // Para sleep_for
#include <chrono> // Para las unidades de tiempo
#include <fstream> // Para manejo de archivos

#include "Partida.h"
using namespace std;

Partida juego(0);

void crearJugadores(int jugador);
void bienvenida();
void mostrarCartas();
void barajarCartas();
void lanzarShuriken();
void lanzarCarta();
void mostrarEstado();
void mostrarCartasDelTablero();
void guardarEstado();
void cargarEstado();


void crearJugadores(int jugador){
    string nombre;
    juego.setJugadores(jugador);
    for(int i = 0; i < jugador; i++) {
        std::cout << "Ingrese el nombre del jugador " << (i + 1) << endl;
        std::cin >> nombre;
        juego.generarJugadores(nombre, i + 1);
    }
};


void bienvenida(){
    
    int jugador;
    do {
        std::cout << endl;
        std::cout << "Indique cuantos jugadores van a jugar min 2 - max 4: " << endl;
        std::cin >> jugador;
        if (jugador >= 2 && jugador <= 4) {
            crearJugadores(jugador);
            break;
        } else {
            std::cout << "Cantidad incorrecta de jugadores, intente nuevamente por favor" << endl;
        }
        
    } while (true);
}; 

void barajarCartas(){
        juego.repartirCartas();
        mostrarCartas();   
}

void mostrarCartas(){
    
    char opcion = 's';
    int opcionJugador;
    do
    {
        system("clear");
        std::cout << "Indicar jugador a mostrar las cartas: " << endl;
        for(int i =0; i < juego.getJugadores();i++){
            std::cout << i+1 << ":" << juego.devolverNombre(i+1) << std::endl;
        }
        cin >> opcionJugador;
            vector<int> cartas = juego.devolverCartar(opcionJugador);
            for (int carta : cartas) {
                cout << "  | " << carta << " |  ";
            }
            cout << endl;
        cout << "¿Desea mostrar las cartas de otro jugador? (s/n): " << endl;
        cin >> opcion;
        opcion = tolower(opcion);
        
    } while (opcion != 'n');
};


void menuNivel(){
        int opc;
        do {
            system("clear");
            std::cout << "_________ Estamos en el  nivel " << juego.getNivel() << " _________ " << endl;
            std::cout << endl;
       
            std::cout << "Seleccione que desea realizar";
            std::cout << endl;
            std::cout << "1. Lanzar carta" << endl;
            std::cout << "2. Usar shuriken" << endl;
            std::cout << "3. Mostrar cartas del jugador" << endl;
            std::cout << "4. Mostrar el estado de partida" << endl;
            std::cout << "5. Mostrar cartas en juego" << endl;
            std::cout << "6. Guardar estado de partida" << endl;
            std::cout << "7. Cargar estado de partida" << endl;
            std::cin >> opc;
            switch (opc) {
                case 1:
                    lanzarCarta();
                    break;
                case 2: 
                    lanzarShuriken();
                    break;
                case 3:
                    mostrarCartas();
                    break;
                case 4:
                    mostrarEstado();
                    break;
                case 5 :
                    mostrarCartasDelTablero();
                    break;
                case 6:
                    guardarEstado();
                    break;
                case 7:
                    cargarEstado();
                    break;
                default:
                    
                    break;
            }

        } while (juego.aunEnpartida());
};


void lanzarShuriken(){
    system("clear");
    if (juego.getShuriken() > 0) {
        std::vector<int> cartas;
        cartas = juego.usarShuriken();
        std::cout << "Se ha usado el shuriken correctamente" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Las cartas eliminadas son: " << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        for (int x : cartas) {
            std::cout << "  | " << x << " |  ";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    } else {
        std::cout << "No hay shurikens disponibles" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
};



void lanzarCarta(){
    int opc;
    do {
        system("clear");
        std::cout << "Indique el número del jugador que va a lanzar la carta" << std::endl;
        for (int i = 0; i < juego.getJugadores(); i++) {
            std::cout << (i + 1) << ". " << juego.devolverNombre(i + 1) << std::endl;
        }

        std::cin >> opc;

        if (opc >= 1 && opc <= juego.getJugadores()) {
            bool turno = juego.cartaLanzada(opc);
            
            if(!turno){
                std::cout << "Lanzamiento incorrecto, pierden una vida, descartando cartas menores" << endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));

            }

            if (juego.verificacionPartida(turno)) {
                std::cout << "Se ha superado el nivel con éxito" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                std::cout << endl;
                std::cout << "El siguiente nivel es ________ " << juego.getNivel() << " ________" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
            } else {
                std::cout << "Se agrega la carta al tablero" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(3));
                mostrarCartasDelTablero();
            }
            break;
        }else{
            std::cout << "Opción incorrecta";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    } while (opc < juego.getJugadores());
}


void mostrarCartasDelTablero() {
    std::vector<int> cartas;
    cartas = juego.getCartasJugando();
    std::cout << "Las cartas en el tablero son: ";
    for (int x : cartas) {
        std::cout << "  | " << x << " |  ";
    }
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
};


void mostrarEstado() {
    std::cout << std::endl;
    std::cout << "________ Estado de la partida ________" << std::endl;
    std::cout << "Estamos en el nivel " << juego.getNivel() << std::endl;
    std::cout << "Tenemos " << juego.getVidas() << " Vidas" << std::endl;
    std::cout << "Tenemos " << juego.getShuriken() << " shurikens" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));
};

void guardarEstado() {
    ofstream archivo("estado_partida.txt");
    if (archivo.is_open()) {
        archivo << "Nivel: " << juego.getNivel() << endl;
        archivo << "Vidas: " << juego.getVidas() << endl;
        archivo << "Shurikens: " << juego.getShuriken() << endl;
        archivo.close();
        std::cout << "Estado de partida guardado correctamente" << endl;
    } else {
        std::cout << "No se pudo guardar el estado de partida" << endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
};

void cargarEstado() {
    ifstream archivo("estado_partida.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
        std::cout << "Estado de partida cargado correctamente" << endl;
    } else {
        std::cout << "No se pudo cargar el estado de partida" << endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(4));
};

int main(){
    
    std::cout << "Hola, bienvenido al juego The Mind" << endl;
    bienvenida();
    barajarCartas();
    menuNivel();
    
};    





