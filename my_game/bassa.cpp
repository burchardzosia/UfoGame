
#include "ball.h"
ball::ball(float x, float y,float ballRadious) {
	circle.setPosition(x, y);
	circle.setRadius = ballRadious;
	circle.setFillColor(Color::Red);
	circle.setOrigin(ballRadius,ballRadious);

}
void ball::draw(RenderTarget& target, RenderStates state)const {
	target.draw(this->circle, state);
}
