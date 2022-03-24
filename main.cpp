#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <termios.h>    //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO



#include <math.h>
//#include "portaudio.h"
#include <stdint.h>
#include <unistd.h> // for usleep()


using namespace std;

class nervioso{
    public:

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

void principal(){
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
};


class guess{
public:
void lista(){
printf("OPCIONES DISPONIBLES \n");
printf("1=do \n");
printf("2=re \n");
printf("3=mi \n");
printf("4=fa \n");
printf("5=sol \n");
printf("6=la \n");
printf("7=si \n");
printf("¿cual es la nota que está sonando? \n");

}
class numero_aleatorio{
        public:
        int m=0;
	int x=0;
	int gen(){
        srand(time(NULL));
        x = 1 + rand() % (7-1);
	return (x);
}
        //int freqes[7]={262,294,330,349,392,440,494};
       // string nombres[7]={"DO","RE","MI","FA","SOL","LA","SI"};
};

void principal(){
int x;
int a=0;
int nta;
int resp;
while (a!=1){
printf("\n iniciar juego: \n");
printf("1. si \n");
printf("2. no");
printf("\n");
scanf("%i",&a);
if (a==1){
numero_aleatorio aleat;
nta=aleat.gen();
lista();
//notas_musicales notas;
switch(nta) //donde opción es la variable a comparar
{
    case 1: //do ;
/*	notas.buzzer_start();
  	notas.buzzer_set_freq(262);
	notas.msleep(time);
	notas.buzzer_stop();
*/	scanf("%i",&resp);  
	printf("nota do \n");
	if (resp==1){
	printf("ganaste");
	} 
	else {
	printf("perdiste ");}
  break;
    case 2: //re;
 /*notas.buzzer_start();
        notas.buzzer_set_freq(294);
        notas.msleep(time);
        notas.buzzer_stop();
*/ scanf("%i",&resp);
printf("nota re \n");   
 if (resp==2){
        printf("ganaste");
        } 
        else {
        printf("perdiste ");}
 break;
    case 3: //mi;
 /*notas.buzzer_start();
        notas.buzzer_set_freq(330);
        notas.msleep(time);
        notas.buzzer_stop();
*/ scanf("%i",&resp);
printf("nota mi \n"); 
 if (resp==3){
        printf("ganaste");
        } 
        else {
        printf("perdiste ");}   
 break;
    case 4: //fa ;
 /*notas.buzzer_start();
        notas.buzzer_set_freq(349);
        notas.msleep(time);
        notas.buzzer_stop();
*/ scanf("%i",&resp);
printf("nota fa \n"); 
 if (resp==4){
        printf("ganaste");
        } 
        else {
        printf("perdiste ");}   
 break;
    case 5: //sol;
/* notas.buzzer_start();
        notas.buzzer_set_freq(392);
        notas.msleep(time);
        notas.buzzer_stop();
*/
 scanf("%i",&resp);
printf("nota sol \n"); 
 if (resp==5){
        printf("ganaste");
        } 
        else {
        printf("perdiste ");}   
 break;
    case 6: //la;
/* notas.buzzer_start();
        notas.buzzer_set_freq(440);
        notas.msleep(time);
        notas.buzzer_stop();
*/ scanf("%i",&resp);
printf("nota la \n");
if (resp==6){
        printf("ganaste");
        } 
        else {
        printf("perdiste ");}    
    break;
    case 7: //si;
/* notas.buzzer_start();
        notas.buzzer_set_freq(494);
        notas.msleep(time);
        notas.buzzer_stop();
*/ scanf("%i",&resp);
printf("nota si \n"); 
 if (resp==7){
        printf("ganaste");
        } 
        else {
        printf("perdiste ");}   
 break;
}
a=0;
}
else {
printf("\n ADIOS \n");
break;
 
 }
}
}
};



class rulet{public:
//ATRIBUTOS
int mayor = -1, numero, ganador;
        int ruleta[10];
        string colores[6] = {"Verde", "Azul", "Morado", "Rojo", "Amarillo", "Naranja"};

//METODOS
    void generar(){
        srand(time(NULL));

        for(int i = 0; i < 10; i++){
            ruleta[i] = 0;
        }


        for(int i = 0; i < 20; i++){
            numero = rand() %10;
            ruleta[numero] = ruleta[numero]+1;
            cout << colores[rand() % 5] << " " << numero+1 << endl;
        }
        for(int i = 0; i < 10; i++){
            if(ruleta[i] > mayor)
                mayor = ruleta[i];

        }
    }
    void ganar(){
        cout << ("/ / / / / / / / / // / / / / / / / / / / / // / / \n");
	cout << ("/           G A N A   O   P I E R D E           / \n");
	cout << ("/     R U L E T A     D E     C O L O R E S     / \n");
	cout << ("**************************************************\n");
	cout << ("                           \n");
	cout << ("*******   *      *  *      ****** ******* ******* \n");
	cout << ("*     *   *      *  *      *         *    *     * \n");
	cout << ("*******   *      *  *      *         *    *     * \n");
	cout << ("*   *     *      *  *      ****      *    * * * * \n");
	cout << ("*    *    *      *  *      *         *    *     * \n");
        cout << ("*     *    ******   ****** ******    *    *     *   ");
        cout << ("                           \n");
        cout << ("**************************************************\n");
        cout << ("/ / / / / / / / / / / / / / / / / / / / / / / / / \n");
        cout << ("\n");
        cout << "\nINGRASE EL POSIBLE NUMERO GANADOR DE LOS 20 GIROS:";
        cin >> ganador;

        if(ganador >= 0 && ganador <= 10){
            if(ruleta[ganador - 1] == mayor)
                cout << "\n  (/*w*)/ FELICIDADES HAS GANADO (/*w*)/ \n";
            else
                cout << "\n   (X__X#) SUERTE LA PROXIMA (X__X#) \n";
        }
        
        cout << "     !!!!!NO PARES DE JUGAR!!!!!" << endl;
        cout << ("\n")<< endl;
        cout << "LOS 20 NUMEROS QUE SALIERON EN LOS GIROS" << endl;
        
    }

};



class blackjack{
    public:


void imprimir_vec(int v[],int n){
    srand(time(NULL));
    for(int i=1;i<=n;i++){
        cout << v[i]<<",";
    }
    cout << endl;
}





class cartas{
    public:
    int maso=21;
	int num[21];
	//string color="color";
	
	
    
    
   
    
 void al_ram_vec1(int v[],int n,int n1,int n2)
{
    srand(time(NULL));
    srand(time(NULL));
    cout << "Ingresando elementos:";
    for(int i=0;i<n;i++){
        
         v[i]=n1+rand()%(n2+1-n1);
    }
}





 void al_ram_vec2(int v[],int n,int n1,int n2)
{
    srand(time(NULL));
    cout << "Ingresando elementos:";
    srand(time(NULL));
    for(int i=0;i<n;i++){
         v[i]=(n1+rand()%(n2+1-n1))*1.56666;
    }
}






};






int DifsumaCartas(int carta1,int carta2){
    
        int a=((carta1+carta2)-21);
        if(a<0){
            return (a*-1);
        }
        else{
            return a;
        }

    }



void round_G(int Nronda, int &score1,int &score2, int carta1, int carta2,int carta3,int carta4){
    //se preciona team1 IF
    int ScTeam1=DifsumaCartas(carta1,carta2);
    //se preciona team2 ELSE IF
    int ScTeam2=DifsumaCartas(carta3,carta4);

    cout<<ScTeam1<<endl;
    cout<<ScTeam2<<endl;

    

    if(ScTeam1<ScTeam2){

        cout<<endl;
        cout<<endl;
        cout<<"gana el jugador 1"<<endl;
        
        score1=score1+10;

        cout<<"pierde el jugador 2 "<<endl;
        
        score2=score2-5;
    }

    else if (ScTeam1>ScTeam2){
        cout<<endl;
        cout<<endl;
        cout<<"gana el jugador 2"<<endl;
        
        score2=score2+10;

        cout<<"pierde el jugador 1 "<<endl;
        
        score1=score1-5;
    }


    else if ((carta1+carta2)>21&&(carta3+carta4)>21){
        cout<<endl;
        cout<<endl;
        cout<<"pierden ambos jugadores "<<endl;
        
        score1=score1-5;
        score2=score2-5;
    }


    else if ((carta1+carta2)>21){
        cout<<endl;
        cout<<endl;
        cout<<"pierde el jugador 1 "<<endl;
        
        score1=score1-5;

        cout<<"gana el jugador 2"<<endl;
        
        score2=score2+10;

    }

    else if ((carta3+carta4)>21){
        cout<<endl;
        cout<<endl;
        cout<<"pierde el jugador 2 "<<endl;
        
        score2=score2-5;

        cout<<"gana el jugador 1"<<endl;
        
        score1=score1+10;
    }

    else{

        cout<<endl;
        cout<<"GANA LA MESA"<<endl;
        cout<<endl;
    }

}



void main(){

cout<<"|             BIENVENIDO A BLACKJACK      |"<<endl;
cout<<"1. Jugar"<<endl;
cout<<"2. SALIR"<<endl;
int opc;
cin>>opc;
cartas team1;
        //crear(team1.num);
         cartas team2;
         int sc1=0,sc2=0;



switch(opc){
		case 1:
		
    srand(time(NULL));
		srand(time(NULL));


        
         //crear(team2.num);

    //setCartas(NumeroJugadores);
    cout<<"se comenzara a barajar"<<endl;
    int c1[21];
    //crear(team1.num);
    		srand(time(NULL));

    team1.al_ram_vec1(team1.num,20,1,14);
    cout<<"baraja del jugador1: "<<endl;
    imprimir_vec(team1.num,19);

    cout<<endl;

    
    

    int c2[20];
    
    //crear(team2.num);
    srand(time(NULL));
    team2.al_ram_vec2(team2.num,20,1,14);
    cout<<"baraja del jugador2: "<<endl;

    imprimir_vec(team2.num,19);

int a;
    cout<<"se reparten cartas"<<endl;
    for (int x=1;x<10;x++){
        cout<<"Lanzando las cartas: "<<endl;
        
        int carta1=team1.num[2*x-1];
        int carta2=team1.num[2*x];
        int carta3=team2.num[2*x-1];
        int carta4=team2.num[2*x];

        round_G(x,sc1,sc2,carta1,carta2,carta3,carta4);
        cout<<"La puntuacion del jugador 1 es: "<<sc1<<"  "<<"La puntuacion del jugador 2 es: "<<sc2<<endl<<endl<<endl; 
    }
			break;

		case 2:
			
			break;

		
		}

}
};




int main(){
    nervioso nervio;
    guess guess1;
    nervio.principal();
    guess1.principal();
    rulet my_ruleta;//llamar a la clase
    //my_ruleta.generar();//llamado a la funcion generar
    my_ruleta.ganar();//llamado a la funcion ganar
    my_ruleta.generar();//llamado a la funcion generar

    blackjack black1;
    black1.main();
	return 0;
}