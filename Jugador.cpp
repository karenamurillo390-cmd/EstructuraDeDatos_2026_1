#include "Jugador.h"
#include <vector>
using namespace std;

//nombre del jugador
Jugador::Jugador(string i){
	nombre=i;//ingreso de nombre del jugador
	cantidad=0;
}

//Se reciben las cartas que proviene del método repartirCartas*/
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
	lasCartas[posicion]= lasCartas[cantidad-1];//posicionamos como ultima carta para que se elimine en el vector
	lasCartas.pop_back();//lanzamos ultima carta

	cantidad--;//recucimos la cantidad de cartas del vector
	
	return menor;
}
