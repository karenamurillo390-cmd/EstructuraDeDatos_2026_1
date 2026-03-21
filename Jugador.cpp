#include "Jugador.h"
<<<<<<< HEAD
#include <vector>
=======
>>>>>>> 80778cf019d24a813c7e51d7cefea29f5801a704
using namespace std;

//nombre del jugador
Jugador::Jugador(string i){
	nombre=i;//ingreso de nombre del jugador
}

//recibir cartas
void Jugador::recibirCarta(int carta){
		lasCartas.push_back(carta);
	
}
int Jugador::lanzarCarta(){
	int carta = lasCartas.back();//guardamos carta
	lasCartas.pop_back();//quitamos la carta que lanzamos del vector
}
