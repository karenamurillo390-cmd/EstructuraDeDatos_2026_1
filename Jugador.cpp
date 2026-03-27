#include "Jugador.h"
#include <vector>
using namespace std;

//nombre del jugador
Jugador::Jugador(string i, int numJugador){
	
	nombre=i;//ingreso de nombre del jugador
	
	cantidad=0;

	this -> numJugador = numJugador;

}

/*Se reciben las cartas que proviene del método repartirCartas*/
void Jugador::recibirCarta(vector<int> mano){
	
	lasCartas = mano;
	
	cantidad =lasCartas.size();//Declaramos la cantidad de cartas que hay actualmente en la mano
	
}


int Jugador::lanzarCarta(){
	
	if(cantidad==0){
		return -1;
	}

	int menor =lasCartas[0];

	int posicion=0;
	
	for(int i=1; i<cantidad; i++){
		if(lasCartas[i]<menor){
			menor=lasCartas[i];
			posicion=i;
		}
	}
	
	/*Se hace una copia del último valor del vector a la posición donde está el menor*/
	lasCartas[posicion] = lasCartas[cantidad-1];
	
	/*Se elimina la última posición del vector, que en este punto, se encuentra duplicada*/
	lasCartas.pop_back();

	cantidad--;//recucimos la cantidad de cartas del vector
	
	return menor;
}


vector<int> Jugador::getLasCartas(){
	
	return this -> lasCartas;

}


string Jugador::getNombre(){
	
	return nombre;

};
