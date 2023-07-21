#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Myball.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
using namespace sf;
using namespace std;


float calculateDistance(sf::Vector2f point1, sf::Vector2f point2)
{
	float dx = point2.x - point1.x;
	float dy = point2.y - point1.y;
	float distance = std::sqrt(dx * dx + dy * dy);
	return distance;
}

int main()
{
	int result=0;
	RenderWindow window{ VideoMode{ 800,800 }, "game" };
	window.setFramerateLimit(90);
	Event event;
	vector<Myball> balls;
	Clock clock;
	float timeSinceLastBall = 0.0f;
	float timeToSpeed = 0.0f;
	const float ballCreationInterval = 2.0f;
	sf::Texture texture;
	if (!texture.loadFromFile("kosmos.jpg")) {
		return 1;
	}
	sf::Sprite background(texture);
	background.setScale(window.getSize().x / background.getLocalBounds().width,
		window.getSize().y / background.getLocalBounds().height);
	float elapsedTime = 0.0f;
	float speedIncreaseInterval = 15.0f;
	int speed = 3;



	sf::Font font;
	if (!font.loadFromFile("font.ttf")) {
		// B³¹d wczytywania czcionki
		return -1;
	}

	sf::Text text;
	text.setFont(font);
	text.setString("Right-click on the ufo ");
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(100, 275);
	

	sf::Font font2;
	if (!font2.loadFromFile("font2.ttf")) {
		// B³¹d wczytywania czcionki
		return -1;
	}

	sf::Text text2;
	text2.setFont(font2);
	text2.setString("Score:0");
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(650, 40);


	sf::Text text3;
	text3.setFont(font2);
	text3.setString("Lives:0");
	text3.setCharacterSize(30);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(60, 40);
	int kule = 0;
	int licznik = 0;



	while (window.isOpen()) {
		window.clear(Color::Black);
		window.draw(background);
		window.draw(text);
		window.draw(text2);
		window.draw(text3);
		window.pollEvent(event);
		if (event.type == Event::Closed) {
			window.close();
			break;
		}
		int flag = 1;
		
		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && balls.size()!=0) {
			auto mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
			    Myball& lastBall = balls[balls.size() - 1];
				if (lastBall.getCircle().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
					balls.pop_back();
					result += 1;
					std::string variableText = "Score: " + std::to_string(result);
					text2.setString(variableText);
					licznik += 1;
					
				
					
				}
				
				
		}
		else {
			flag = 0;
		}
		
		
		
		
		
		
		
		

		if (balls.size() > 3) {
			std::string variableText = "You lost! Score: " + std::to_string(result);
			window.clear();
			text2.setPosition(200, 300);
			text2.setCharacterSize(80);
			text2.setString(variableText);
			window.draw(text2);
			window.display();
			std::chrono::seconds duration(2);
		
			
			std::this_thread::sleep_for(duration);
			window.close();

			break;
			
		}

		float deltaTime = clock.restart().asSeconds();
		timeSinceLastBall += deltaTime;
		elapsedTime += deltaTime;
		if (timeSinceLastBall >= ballCreationInterval) {
			if (elapsedTime >= speedIncreaseInterval) {
				speed+=1;
				elapsedTime = 0.0f;
			}
			Myball newBall(speed);
			balls.push_back(newBall);
			timeSinceLastBall = 0.0f;
			kule += 1;
			
				int result = 3-(kule - licznik-1);
				std::string variableText2 = "Lives: " + std::to_string(result);
				text3.setString(variableText2);
			
		}
		for (auto& ball : balls) {
			ball.update();
			window.draw(ball);
		}

		window.display();
		
	}

};