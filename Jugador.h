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
        vector<int> lasCartas; 
        /*Exactamente las cartas que tiene el jugador (qué numeros tiene en las cartas de su mano)*/
    
    //Métodos
    public:
        Jugador(string i);
        /*defino el nombre del jugador y el número del jugador*/
        int lanzarCarta();
        /*Retorna la menor carta del mazo del jugador*/
        void recibirCarta(vector<int> mano);
        /*Recibe el vector con los números repartidos y se asigna al vector lasCartas*/


};

#endif
