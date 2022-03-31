#include <SFML/Graphics.hpp>
#include <time.h>//
using namespace sf;
//const:variables que no puuede cambiar a lo largo del programa.
const int W=1200;//ancho de grafico
const int H=680;//largo de grafico
int speed = 4;//velocidad del juego
bool field[W][H]={0};//bool nos permite comparar
//¿    ue es una estructura?:coleccion de uno o mas tipos de elementos denominados campos,cadauno de los cuales puede ser un tipo de dato diferente
struct player//player:nombre de la estructura
{ int x,y,dir;//int:tipo de dato ; x,y,dir:nombre de los campos
  Color color;
  player(Color c)
  {
    x=rand() % W;// x es un numero randomico limitado por W-1 que es el numero superior que puede llegar gracias a %
    y=rand() % H;//y es un numero randomico limitado por H-1 que es el numero superior que puede llegar gracias a %
    color=c;
    dir=rand() % 4;//dir es un numero aleatorio maximo hasta 3
  }
  void tick()//marcador
  {
    if (dir==0) y+=1;
    if (dir==1) x-=1;
    if (dir==2) x+=1;
    if (dir==3) y-=1;

    if (x>=W) x=0;  if (x<0) x=W-1;
    if (y>=H) y=0;  if (y<0) y=H-1;
  }

  Vector3f getColor()
  {return Vector3f(color.r,color.g,color.b);}
};

int main()
{
    srand(time(0));//NUMEROS RANDOMICOS

    RenderWindow window(VideoMode(W, H), "EL JUEGO DEL TRON!");//titulo del juego
    window.setFramerateLimit(60);//stablecer el límite de fotogramas para una ventana a través de SetFramerateLimit().

    Texture texture;
    texture.loadFromFile("background.jpg");//fonoo de juego
    Sprite sBackground(texture);

    player p1(Color::Blue), p2(Color::Green); //colores de los jugadores 1 y 2

    Sprite sprite;
    RenderTexture t;//proceso para generar una imagen o un objeto ya existenete
    t.create(W, H);
    t.setSmooth(true);
    sprite.setTexture(t.getTexture());
    t.clear();  t.draw(sBackground);
    
    Font font; font.loadFromFile("sansation.ttf");
    Text text("GANASTE,AHORA A MIMIR:v",font,35);
    text.setPosition(W/2-80,20);
    /*
    Shader* shader = new Shader;
    shader->loadFromFile("shader.frag",Shader::Fragment);
    shader->setParameter("frag_ScreenResolution",Vector2f(W,H));
    shader->setParameter("frag_LightAttenuation",100);
    RenderStates states; states.shader =shader;
    */
    bool Game=1;

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) if (p1.dir!=2) p1.dir=1;
        if (Keyboard::isKeyPressed(Keyboard::Right)) if (p1.dir!=1)  p1.dir=2;
        if (Keyboard::isKeyPressed(Keyboard::Up)) if (p1.dir!=0) p1.dir=3;
        if (Keyboard::isKeyPressed(Keyboard::Down)) if (p1.dir!=3) p1.dir=0;

        if (Keyboard::isKeyPressed(Keyboard::A)) if (p2.dir!=2) p2.dir=1;
        if (Keyboard::isKeyPressed(Keyboard::D)) if (p2.dir!=1)  p2.dir=2;
        if (Keyboard::isKeyPressed(Keyboard::W)) if (p2.dir!=0) p2.dir=3;
        if (Keyboard::isKeyPressed(Keyboard::S)) if (p2.dir!=3) p2.dir=0;

        if (!Game){
            window.draw(text);
            window.display();
            continue;
        }

        for(int i=0;i<speed;i++)
        {
            p1.tick(); p2.tick();
            if (field[p1.x][p1.y]==1) {Game=0; text.setColor(p2.color);}
            if (field[p2.x][p2.y]==1) {Game=0; text.setColor(p1.color);}
            field[p1.x][p1.y]=1; 
            field[p2.x][p2.y]=1;
    
            CircleShape c(3);
            c.setPosition(p1.x,p1.y); c.setFillColor(p1.color);    t.draw(c);
            c.setPosition(p2.x,p2.y); c.setFillColor(p2.color);    t.draw(c);
            
            t.display();  
            
            /*
            shader->setParameter("frag_LightOrigin",Vector2f(p1.x,p1.y)) ;
            shader->setParameter("frag_LightColor",p1.getColor());
            t.draw(sprite,states);
            shader->setParameter("frag_LightOrigin",Vector2f(p2.x,p2.y));
            shader->setParameter("frag_LightOrigin",p2.getColor());
            t.draw(sprite,states);
            */
        }

       ////// draw  ///////
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

