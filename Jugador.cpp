#include "Jugador.h"
#include <vector>
using namespace std;

//nombre del jugador
Jugador::Jugador(string i){
	nombre=i;//ingreso de nombre del jugador
}

/*Se reciben las cartas que proviene del método repartirCartas*/
void Jugador::recibirCarta(vector<int> mano){
	
	lasCartas = mano;
	
}


int Jugador::lanzarCarta(){
	int carta = lasCartas.back();//guardamos carta
	lasCartas.pop_back();//quitamos la carta que lanzamos del vector
}
