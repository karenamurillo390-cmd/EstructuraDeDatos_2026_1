#include <iostream>
using namespace std;

class Partida{
    
    //Atributos

    private:
        int nivel;
        int cartasJugando; //cartas en juego en la partida
        int jugadores;
        int vidas;
        int shuriken;
    
    //Métodos

    public:
        Partida();
        int repartirCartas();
        bool verificacionPartida();
        int modificacionNivel(int nivel_);
        int modificacionVidas(int vidas_);
        int modificacionShuriken(int shuriken_);


};




class Jugador{

    //Atributos
    private:
        string nombre;
        int cantCartas;
        int lasCartas; //Exactamente las cartas que tiene el jugador (qué numeros tiene en las cartas de su mano)
    
    //Métodos
    public:
        Jugador();
        int lanzarCarta();
        int recibirCarta();


};