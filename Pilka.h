#pragma once
#include <SFML/Graphics.hpp>
#include <cmath> 
#include "Paletka.h" 
#include "Paletka.h"

class Pilka {
private:
	float x;
	float y;
	float promien;
	float predkoscX;
	float predkoscY;
	sf::CircleShape shape;
public:
	Pilka(float startX, float startY, float vx, float vy, float promien1) {
		x = startX;
		y = startY;
		predkoscX = vx;
		predkoscY = vy;
		promien = promien1;
		shape.setRadius(promien1);
		shape.setOrigin({ promien1, promien1 });
		shape.setPosition({ startX, startY });
		shape.setFillColor(sf::Color::White);
	};
	void move() {
		x += predkoscX;
		y += predkoscY;
		shape.setPosition({ x, y });
	};
	void bounceX() {
		predkoscX = -predkoscX;
	};
	void bounceY() {
		predkoscY = -predkoscY;
	};
	void collideWalls(float width, float height) {
		if (x - promien <= 0 || x + promien >= width)
		{
			bounceX();
			shape.setPosition({ x, y });
		}
		if (y - promien <= 0)
		{
			bounceY();
			shape.setPosition({ x, y - 3 });
		}
	};
	bool collidePaddle(const Paletka& p)
	{

		if (p.getX() - p.getSzerokosc() / 2 <= x && y + promien >= p.getY() - p.getWysokosc() / 2 && y - promien < p.getY() - p.getWysokosc() / 2 && (p.getX() + p.getSzerokosc() / 2 >= x)) {

			predkoscY = -std::abs(predkoscY);
			y = p.getY() - p.getWysokosc() / 2 - promien;
			shape.setPosition({ x, y });
			return true;
		}
		else
			return false;
	};
	void draw(sf::RenderTarget& target) {
		target.draw(shape);
 	};
	float getX() const { return x; }
	float getY() const { return y; }
	float getPromien() const { return promien; }
	float getPredkoscX() const { return predkoscX; }
	float getPredkoscY() const { return predkoscY; }

};

