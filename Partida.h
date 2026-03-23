# ifndef PARTIDA_H
# define PARTIDA_H
#include <vector>
#include "Jugador.h"
using namespace std;


class Partida{
    
    //Atributos


    private:
        int nivel;
        vector<int> cartasJugando; //cartas en juego en la partida
        int jugadores;
        int vidas;
        int shuriken;
    
    //Métodos

    public:
        Partida(int jugadores);
        /*define los atributos de la clase partida, define el vector de jugadores 
        (crea la cantidad de jugadores que va a tener)*/
        void repartirCartas(int jugadores,int nivel); 
        // Asigna los números aleatorios sin repetir a cada jugador, recibe el numero de nivel
        bool cartaLanzada(int nroJugador);
        /*verifica que la carta lanzada si sea la menor entre todas las 
        cartas de los jugadores. Si no es menor, descarta las cartas menores, 
        resta una vida, y agrega la carta lanzada al array de cartas jugando*/
        bool verificacionPartida(const vector<int>& cartasJugando); 
        /*Se recibe el vector de las cartas lanzadas por los jugadores 
        y se verifica que esté en orden ascendente y retorna true o false 
        para ganada o perdida la partida*/
        bool usarShuriken(int usoShuriken);
        /*Se descartan la carta de menor valor del mazo de cada jugador, modificando 
        el vector de las cartas de los jugadores*/
        int modificacionNivel(bool validador);
        /*suma nivel set&get*/
        int modificacionVidas(bool validador);
        /*suma o resta de vidas set&get*/
        int modificacionShuriken(bool validador);
        /*suma o resta de shuriken set&get*/


};

# endif
