#include "Myball.h"
#include "Myball.h"
#include <iostream>
#include <random>

Myball::Myball(int speed) {
	

		
	
	x = randomPose(30, 700);
	y = randomPose(30, 500);
	circle.setPosition(x, y);
	radious = randomPose(30, 70);
	circle.setRadius(radious);
	circle.setOrigin(radious, radious);
	circle.setFillColor(sf::Color::Blue);
	speed_ = speed;
	speed_vector = getspeed(x, y, speed);


}
void Myball::draw(RenderTarget& target, RenderStates state)const {
	target.draw(this->circle, state);
}
void Myball::update() {
	x += getRadious();
	y += getRadious();
	circle.move(this->speed_vector);
}
int Myball::randomPose(int x, int y)const {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(x, y);
	int randomValue = distribution(generator);
	return randomValue;
}

Vector2f Myball::getspeed(int x, int y, int speed) {
	int speedX;
	int speedY;
	if (x < 400) {
		speedX = speed;
	}
	else {
		speedX = -speed;
	}
	if (y < 250) {
		speedY = speed;
	}
	else {
		speedY = -speed;
	}
	sf::Vector2f speedVector(speedX, speedY);
	return speedVector;


}
Vector2f Myball::getCenter() {
	sf::Vector2f center(x, y);
	return center;

}
int Myball::getRadious() {

	return radious;

}
CircleShape Myball :: getCircle() {
	return circle;
}




