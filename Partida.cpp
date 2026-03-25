#include <iostream>
#include "Partida.h"
#include <vector> //1
#include <string>  //2
#include <numeric> //para función iota
#include <algorithm> //para funciones shuffle, sort, copy
#include <random> //para funciones random_device, mt19937,
#include <thread> // Para sleep_for
#include <chrono> // Para las unidades de tiempo 
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
    
    /*Verifica si la carta lanzada es correcta = true (es la menor de todas las que tienen los jugadores)*/
    bool validador = true;

    int carta = nameJugadores[nroJugador - 1].lanzarCarta();

    cartasJugando.push_back(carta);


    /*validar si es menor en alguno de los otros y descartar esos valores*/

    vector<int> menores;
    vector<int> mayores;

    /*Recorrer el vector de jugadores*/
    for(auto &x: nameJugadores){
        /*Recorro las cartas de los jugadores*/
        for(int y:x.getLasCartas()){
            /*Valido las cartas menores y las ingreso a "menores", y si no, a "mayores"*/
            if(y<carta){
                menores.push_back(y);
            }else{
                mayores.push_back(y);
            }
        }

        /*Valido si hay 1 o más cartas menores. Si hay cartas menores
        que la lanzada, la carta no es correcta = false (validador cambia)*/
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



bool Partida::verificacionPartida(bool validador) {
    
        
    bool partida = false;
    bool turno = true;

    /**/
    for (Jugador &x : nameJugadores) {
        if (x.getLasCartas().size() > 0) {
            turno = false;
            break;
        }
    }

    if (turno) {
        if (validador) {
            switch (jugadores) {
                case 2:
                    if (nivel >= 12) {
                        this->finalizarPartida(true);
                    } else {
                        modificacionNivel();
                        partida = true;
                    }
                    break;
                case 3:
                    if (nivel >= 10) {
                        this->finalizarPartida(true);
                    } else {
                        modificacionNivel();
                        partida = true;
                    }
                    break;
                case 4:
                    if (nivel >= 8) {
                        this->finalizarPartida(true);
                    } else {
                        modificacionNivel();
                        partida = true;
                    }
                    break;
            }
        } else {
            modificacionVidas(false);
            if (vidas < 1) {
                finalizarPartida(false);
            } else {
                switch (jugadores) {
                    case 2:
                        if (nivel >= 12) {
                            this->finalizarPartida(true);
                        } else {
                            modificacionNivel();
                            partida = true;
                        }
                        break;
                    case 3:
                        if (nivel >= 10) {
                            this->finalizarPartida(true);
                        } else {
                            modificacionNivel();
                            partida = true;
                        }
                        break;
                    case 4:
                        if (nivel >= 8) {
                            this->finalizarPartida(true);
                        } else {
                            modificacionNivel();
                            partida = true;
                        }
                        break;
                }
            }
        }
    } else {
        if (!validador) {
            modificacionVidas(false);
            if (vidas < 1) {
                finalizarPartida(false);
            } else {
                
            }
        }
    }

    return partida;
};



void Partida::finalizarPartida(bool finalizar){

    if(finalizar){
        cout << "¡Felicidades! Han ganado el juego\n";
    }else{
        cout << "Fin del juego\n";}
    exit(0);

};



void Partida::modificacionNivel(){

    nivel++;
    if (nivel % 2 == 0) {
        if (vidas <= 4) modificacionVidas(true);
        else if (shuriken <= 2) modificacionShuriken(true);
    }
    repartirCartas();
    vaciarCartasJugadas();

};



void Partida::modificacionVidas(bool validador){

    if(validador){ 
        vidas++; 
        cout << "Se ha sumado una vida\n";
        std::this_thread::sleep_for(std::chrono::seconds(2)); 
    }else{
        vidas--;
    }
       
};



void Partida::modificacionShuriken(bool validador){
    if(validador){
        shuriken++;
    }else{
        shuriken--;
    }
};



void Partida::vaciarCartasJugadas(){
    
    cartasJugando.clear(); 

};



vector<int> Partida::usarShuriken(){
    
    vector<int> eliminadas;
    
    for(auto &x : nameJugadores) {
        int y = x.lanzarCarta();
        if(y > 0) eliminadas.push_back(y);
    }
    
    modificacionShuriken(false);
    
    return eliminadas;

};



void Partida::generarJugadores(string n, int num){
     
    nameJugadores.push_back(Jugador(n, num));

};



vector<int> Partida::devolverCartar(int n){
    
    return nameJugadores[n-1].getLasCartas(); 

};



string Partida::devolverNombre(int n){
    
    return nameJugadores[n-1].getNombre();

};



int Partida::getJugadores(){
    
    return jugadores;

};



int Partida::getNivel(){
    
    return nivel;

};



int Partida::getVidas(){
    
    return vidas;

};



int Partida::getShuriken(){
    
    return shuriken;

};



vector<int> Partida::getCartasJugando(){
    
    return cartasJugando;

};



void Partida::setJugadores(int j){
    
    jugadores = j; 
    vidas = j;

};



bool Partida::aunEnpartida(){
    
    for(auto &x : nameJugadores){

        if(!x.getLasCartas().empty())
            return true;
        }

    return false;
}