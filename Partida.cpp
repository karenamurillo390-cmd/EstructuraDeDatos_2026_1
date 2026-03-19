#include "Partida.h"

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

int Partida::repartirCartas(int nivel,vector<Jugador>& jugadores){

    vector<vector<int>> matriz(jugadores.size(),vector<int>(nivel));
    


    return 0;

};