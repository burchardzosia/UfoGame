#pragma once
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Myball: public sf::Drawable
{
public:

	explicit Myball(int b);
	~Myball() override = default;
	void update();
	int randomPose(int x,int y)const;
	Vector2f getspeed(int x, int y, int radious);
	Vector2f getCenter();
   int  getRadious();
	CircleShape getCircle();
	
	

private:
	CircleShape circle;
	Vector2f speed_vector;
	int x;
	int y;
	int radious;
	int speed_;
	void draw(RenderTarget&, RenderStates state) const override;
};

