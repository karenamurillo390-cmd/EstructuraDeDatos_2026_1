#include "Partida.h"
#include <vector> //1
#include <string>  //2
#include <numeric> //para función iota
#include <algorithm> //para funciones shuffle, sort, copy
#include <random> //para funciones random_device, mt19937, 
using namespace std; //3

vector<Jugador> nameJugadores;
/*Vector donde se van a guardar los nombres de los jugadores como un dato global*/

Partida::Partida(int jugadores){

    nivel = 1;
    
    this -> jugadores = jugadores;
    //Variable global this-> para referirme a la variable declarada en los atributos.
    
    switch (jugadores)
    {
    case 2:
        vidas=2;
        break;
    case 3:
        vidas=3;
        break;
    case 4:
        vidas=4;
        break;
    
    default:
        vidas=2;
        break;
    };
        
    shuriken = 1;

};



void Partida::repartirCartas(int jugadores,int nivel){

    vector<int> mazo(100); 
    //vector con los 100 espacios para las cartas 
    
    iota(mazo.begin(), mazo.end(), 1); 
    //organiza los números del 1 al 100 en el vector mazo
    
    random_device rd; 
    //obtiene semilla del pc, y generar aleatoriedad
    
    mt19937 g(rd()); 
    //genera los números aleatorios
    
    shuffle(mazo.begin(), mazo.end(), g); 
    //baraja el vector mazo para reorganizar los números en diferentes posiciones

    vector<vector<int>> mano(jugadores); 
    //vector de vectores para asignar cada mano
    
    
    /*Bucle for para repartir las cartas*/

    int cartaActual = 0; 
    
    for (int i = 0; i < jugadores; ++i) {
        for (int j = 0; j < nivel; ++j) {
            mano[i].push_back(mazo[cartaActual]);
            cartaActual++;
        }
    }    

    for (int i = 0; i < jugadores; ++i){

        nameJugadores[i].recibirCarta(mano[i]);
    }

};



bool Partida::cartaLanzada(int nroJugador){
    
    int carta = nameJugadores[nroJugador - 1].lanzarCarta();

    cartasJugando.push_back(carta);


    /*validar si es menor en alguno de los otros y descartar esos valores*/

    
    




};