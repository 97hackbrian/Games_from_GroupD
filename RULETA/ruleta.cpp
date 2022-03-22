// BIBLIOTECAS / //
#include <iostream> 
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Funciones
using namespace std;
int main(){
	srand(time(NULL));
	int mayor = -1, numero, ganador;
	int ruleta[10];
	string colores[6] = {"Verde", "Azul", "Morado", "Rojo", "Amarillo", "Naranja"};
	
	for(int i = 0; i < 10; i++)
		ruleta[i] = 0;
		
	for(int i = 0; i < 20; i++){
		numero = rand() %10;
		ruleta[numero] = ruleta[numero]+1;
		cout << colores[rand() % 5] << " " << numero+1 << endl;
	}
	for(int i = 0; i < 10; i++){
		if(ruleta[i] > mayor)
			mayor = ruleta[i];

	}
	cout << "\nFavor ingresar la posible ruleta mas ganadora:";
	cin >> ganador;

	if(ganador >= 0 && ganador <= 10){
		if(ruleta[ganador - 1] == mayor)
			cout << "\nAcertaste la ruleta mas ganadora\n";
		else
			cout << "\nVuelve a intentarlo\n";
	}
	for(int i = 0; i < 10; i++)
		cout << ruleta[i] << " ";
	
	return 0;
}