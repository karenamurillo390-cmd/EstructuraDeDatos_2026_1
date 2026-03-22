#include "Jugador.h"
using namespace std;

//nombre del jugador
Jugador::Jugador(string i){
	nombre=i;//ingreso de nombre del jugador
	cantidad=0;
}

//recibir cartas
void Jugador::recibirCarta(int carta){
		lasCartas.push_back(carta);
		cantidad++;
	
}
int Jugador::lanzarCarta(){
	if(cantidad==0){
		return;
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
