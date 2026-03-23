#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include <vector>
using namespace std;


class Jugador{

    //Atributos
    private:
        string nombre;

        int numJugador;
        
        /*Exactamente las cartas que tiene el jugador (qué numeros tiene en las cartas de su mano)*/
        vector<int> lasCartas; 
        
    
    //Métodos
    public:
        /*defino el nombre del jugador y el número del jugador*/
        Jugador(string i, int numJugador);
        
        /*Retorna la menor carta del mazo del jugador*/
        int lanzarCarta();

        /*Recibe el vector con los números repartidos y se asigna al vector lasCartas*/
        void recibirCarta(vector<int> mano);
        
        int cantidad;

        /*Mostrar el vector que contenga las cartas de cada jugador*/
        vector<int> getLasCartas();


};

#endif
