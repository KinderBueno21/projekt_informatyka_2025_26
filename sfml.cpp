#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paletka.h"
#include "Pilka.h"
using namespace std;

const float WIDTH = 640;
const float HEIGHT = 480;
int punkty = 0;
int main()
{
    sf::RenderWindow window(sf::VideoMode({ 640, 480 }), "Arkanoid Test");
    window.setFramerateLimit(60);
    Paletka pal(320.f, 440.f, 100.f, 20.f, 8.f); // x,y,szer,wys, predkosc 
    Pilka pilka(320.f, 200.f, 4.f, 3.f, 8.f); // x,y,vx,vy,radius

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            pal.moveLeft();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            pal.moveRight();


        pal.clampToBounds(WIDTH);
        pilka.move();
       
        pilka.collideWalls(WIDTH, HEIGHT);
        if (pilka.collidePaddle(pal)) {
            std::cout << "HIT PADDLE!  ";
            punkty += 10;
            std::cout << "Liczba punktow: " << punkty << endl;
        }

        if (pilka.getY() - pilka.getPromien() > HEIGHT)
        { std::cout << "MISS! KONIEC GRY\n"; window.close();}

        window.clear(sf::Color(20, 20, 30));
        pal.draw(window);
        pilka.draw(window);
        window.display();
    }
}