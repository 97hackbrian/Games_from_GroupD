#include<iostream>
#include<cstdlib>
#include<cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;


void imprimir_vec(int v[],int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
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
         v[i]=(n1+rand()%(n2+1-n1))*1;
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

    cout<<carta1<<endl;
    cout<<carta2<<endl;
    cout<<carta3<<endl;
    cout<<carta4<<endl;

    

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


    if ((carta1+carta2)>21&&(carta3+carta4)>21){
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



int main(){

    srand(time(NULL));
    /*
    int cantidad=2;
if(cantidad>=1){
        cartas team1;
        team1.crear();
    }
    else if(cantidad>=2){
        cartas team2;
        team2.crear();
        
    }
    else if(cantidad==3){
        cartas team3;
        team3.crear();
    }


KERNEL(team1.num,team2.num);


*/
		srand(time(NULL));

int sc1=0,sc2=0;
/*
    int NumeroJugadores=0;
    cout<<"iniciar"<<endl;
    cout<<"Ingrese el numero de jugadores"<<endl;
    cin>>NumeroJugadores;

if(NumeroJugadores>=1){
        cartas team1;
        crear(team1.num);
    }
    else if(NumeroJugadores>=2){
        cartas team2;
         crear(team2.num);
        
    }
    else if(NumeroJugadores==3){
        cartas team3;
         crear(team3.num);
    }
*/

        cartas team1;
        //crear(team1.num);
         cartas team2;
         //crear(team2.num);

    //setCartas(NumeroJugadores);
    cout<<"se comenzara a barajar"<<endl;
    int c1[21];
    //crear(team1.num);
    		srand(time(NULL));

    team1.al_ram_vec1(team1.num,20,1,14);
    cout<<"baraja del jugador1: "<<endl;
    imprimir_vec(team1.num,20);

    cout<<endl;

    
    

    int c2[20];
    
    //crear(team2.num);
    srand(time(NULL));
    team2.al_ram_vec2(team2.num,20,1,14);
    cout<<"baraja del jugador2: "<<endl;

    imprimir_vec(team2.num,20);

    cout<<"se reparten cartas"<<endl;
    for (int x=0;x<18;x++){
        int carta1=team1.num[2*x-1];
        int carta2=team1.num[2*x];
        int carta3=team2.num[2*x-1];
        int carta4=team2.num[2*x];

        round_G(x,sc1,sc2,carta1,carta2,carta3,carta4);
        cout<<"La puntuacion del jugador 1 es: "<<sc1<<"  "<<"La puntuacion del jugador 2 es: "<<sc2<<endl<<endl<<endl; 
    }
return 0;
}