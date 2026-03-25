#include <iostream>
#include <vector>
#include <string>

#include "Partida.h"
using namespace std;

Partida juego(0);

void crearJugadores(int jugador);
void bienvenida();
void mostrarCartas();
void barajarCartas();



void crearJugadores(int jugador) {
    string nombre;
    juego.setJugadores(jugador);
    for(int i = 0; i < jugador; i++) {
        std::cout << "Ingrese el nombre del jugador " << (i + 1) << endl;
        std::cin >> nombre;
        juego.generarJugadores(nombre, i + 1);
    }
};


void bienvenida() {
    
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

void barajarCartas() {
        juego.repartirCartas();
        mostrarCartas();   
}

void mostrarCartas() {
    
    char opcion = 's';
    int opcionJugador;
    do
    {
        system("cls");
        std::cout << "Indicar jugador a mostrar las cartas: " << endl;
        for(int i =0; i < juego.getJugadores();i++){
            std::cout << i+1 << ":" << juego.devolverNombre(i+1) << std::endl;
        }
        cin >> opcionJugador;
            vector<int> cartas = juego.devolverCartar(opcionJugador);
            for (int carta : cartas) {
                cout << carta << " | ";
            }
            cout << endl;
        cout << "¿Desea mostrar las cartas de otro jugador? (s/n): " << endl;
        cin >> opcion;
        opcion = tolower(opcion);
        
    } while (opcion != 'n');
};

/*

*/

/*

*/



/*

*/

/*

*/

int main(){
    
    std::cout << "Hola, bienvenido al juego The Mind" << endl;
    bienvenida();
    barajarCartas();
    
};    



    /* 
    std::cout << "¿Cuántos jugadores van a participar? ";
    std::cin >> numJugadores;

    vector<Jugador> jugadores;

    std::cin.ignore(); // importante

    for (int i = 0; i < numJugadores; i++) {
        string nombre;

        std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        getline(std::cin, nombre);

        // Crear objeto Jugador con tu constructor
        Jugador j(nombre, i + 1);

        // Guardarlo en el vector
        jugadores.push_back(j);
    }

    return 0;
}
    */



    /*
    - std::cout Hola ¿cuántos jugadores van a participar?
        Este valor se va a guardar en la variable jugadores
    - con el número de jugadores creo el vector jugadores que se va a usar en la clase Jugador
    - Se asignan las cartas y se muestra para cada jugador sus cartas
    - Lanzar carta (1) o usar sguriken(0)
    - Preguntar qué jugador va a lanzar
    - Mostrar carta lanzada (verificando la menor del mazo)
    
    
    */





