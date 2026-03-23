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
    
        /*define los atributos de la clase partida, define el vector de jugadores 
        (crea la cantidad de jugadores que va a tener)*/    
        Partida(int jugadores);
        
        /*Asigna los números aleatorios sin repetir a cada jugador, recibe el numero de nivel*/
        void repartirCartas(); 
        
        /*verifica que la carta lanzada si sea la menor entre todas las 
        cartas de los jugadores. Si no es menor, descarta las cartas menores, 
        resta una vida, y agrega la carta lanzada al array de cartas jugando*/
        bool cartaLanzada(int nroJugador);
        
        /*Se recibe el  
        y se verifica que esté en orden ascendente y retorna true o false 
        para ganada o perdida la partida*/
        bool verificacionPartida(bool validador); 
        
        /*Se descartan la carta de menor valor del mazo de cada jugador, modificando 
        el vector de las cartas de los jugadores*/
        vector<int> usarShuriken();
        
        /*suma nivel set&get*/
        void modificacionNivel();
        
        /*suma o resta de vidas set&get*/
        int modificacionVidas(bool validador);
        
        /*suma o resta de shuriken set&get*/
        void modificacionShuriken(bool validador);

        /**/
        void finalizarPartida(bool finalizar);

        /**/
        void vaciarCartasJugadas();

        /**/
        void generarJugadores(string n, int num);

        /**/
        vector<int> devolverCartar(int n);

        /**/
        string devolverNombre(int n);

        /**/
        int getJugadores();

        /**/
        int getNivel();

        /**/
        int getVidas();

        /**/
        int getShuriken();

        /**/
        vector<int> getCartasJugando();

        /**/
        void setJugadores(int j);

        /**/
        bool aunEnpartida();


};

# endif
