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
    
    /*Variable global this-> para referirme a la variable declarada en los atributos.*/
    this -> jugadores = jugadores;
    
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



void Partida::repartirCartas(){

    /*vector con los 100 espacios para las cartas*/
    vector<int> mazo(100); 
    
    /*Se organiza los números del 1 al 100 en el vector mazo*/
    iota(mazo.begin(), mazo.end(), 1); 
    
    /*Se obtiene semilla del pc, y generar aleatoriedad*/
    random_device rd; 
    
    /*Se genera los números aleatorios*/
    mt19937 g(rd()); 
    
    /*Se baraja el vector mazo para reorganizar los números en diferentes posiciones*/
    shuffle(mazo.begin(), mazo.end(), g); 
    
    /*vector de vectores para asignar cada mano*/
    vector<vector<int>> mano(jugadores); 
    
    
    
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
    
    bool validador = true;

    int carta = nameJugadores[nroJugador - 1].lanzarCarta();

    cartasJugando.push_back(carta);


    /*validar si es menor en alguno de los otros y descartar esos valores*/

    vector<int> menores;
    vector<int> mayores;

    for(Jugador& x: nameJugadores){
        for(int y:x.getLasCartas()){
            if(y<carta){
                menores.push_back(y);
            }else{
                mayores.push_back(y);
            }
        }

        if(menores.size() > 0){
            validador = false;
            menores.clear();
            x.recibirCarta(mayores);
            mayores.clear();
        }else{
            menores.clear();
            mayores.clear();
        }

    }
    
    return validador;

};


bool Partida::verificacionPartida(bool validador){







};
