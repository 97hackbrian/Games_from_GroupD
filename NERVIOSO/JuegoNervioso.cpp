//Juego NERVIOSO
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <termios.h>    //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO
using namespace std;

bool leerLetra(char letraLeida){
	int c;   
    static struct termios oldt, newt;

    /* tcgetattr obtiene la configuración actual del terminal
       STDIN_FILENO se utiliza para escribir la configuración en oldt */
    tcgetattr( STDIN_FILENO, &oldt);
    /* se hace una copia de la configuración */
    newt = oldt;

    /* se deshabilita el flag ICANON */
    newt.c_lflag &= ~(ICANON);          

    /* se envia la nueva configuración a STDIN
       usamos TCSANOW para modificar la configuración. */
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    /* En este caso se usa la tecla 'e' para salir */
    while((c=getchar())!= letraLeida){      
        putchar(c);   
                     
    }
	return 1;
    /* se restaura la configuración original */
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}

void ronda( int &carLan,int i, char letra1,char letra2){
	cout<<endl<<"Para Lanzar carta: ";
	cout<<endl<<"jugador 1 lanza con (z) 		jugador 2 lanza con (n)";
cout<<endl<<"Para aplastar carta con mano: ";
	cout<<endl<<"jugador 1 aplasta con (x)			jugador 2 aplasta con (m)";

	if(leerLetra(letra1)){
		carLan=rand()%(14-1+1)+1;
		cout<<endl<<endl<<"				"<<carLan<<endl;
		cout<<endl<<"			¿La carta lanzada es "<<i<<"?"<<endl;

	}

	

	else if(leerLetra(letra2)){
		cout<<endl<<"				¡SI! la carta lanzada "<<carLan<<" SI es "<<i<<endl;
		cout<<endl<<"				¡GANASTE!";
	}
	
}

int main(){
	int opc,num,jugadorAlea, cartaLanzada=0,cantidadCartas,verificacionCarta,segundos=0;
	string jugador1,jugador2,jugador3,jugador4,random;
	char lanzarCarta,let;
	cout<<endl<<"				Bienvenido al juego NERVIOSO"<<endl;
	cout<<endl<<"				Seleccione una opcion: ";
	cout<<endl<<"				1. Dos jugadores";
	cout<<endl<<"				2. Salir";
	cout<<endl<<"				Digite una opcion: ";
	cin>>opc;

	switch(opc){
		case 1:
			cout<<"Ingrese el nombre del primer jugador: "<<endl;
			cin>>jugador1;
			cout<<"Ingrese el nombre del segundo jugador: "<<endl;
			cin>>jugador2;

			for(int i=1;i<=6;i++){
			
			cout<<endl<<"				Ronda numero "<<i<<endl<<endl;

			cout<<endl<<"			juega jugador "<<jugador1;
			ronda(cartaLanzada,2*i-1,'z','x');
			cout<<endl<<endl;

			cout<<endl<<"			juega jugador "<<jugador2;
			ronda(cartaLanzada,2*i,'n','m');
			cout<<endl<<endl;
			
			}
			break;

		case 2: break;
	}

}