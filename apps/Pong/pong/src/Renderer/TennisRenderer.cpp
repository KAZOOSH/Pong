#include "TennisRenderer.h"

TennisRenderer::TennisRenderer(GameElements * gameElements, string name) :BasicRenderer(gameElements, name) {
	court.load("images/court.jpg");
	tennis_ball.load("images/tennis_ball.png");	
}

void TennisRenderer::render() {
	court.draw(0, 0, gameElements->getWidth(),gameElements->getHeigth());

	drawScore();

	gameElements->paddleRight.draw();
	gameElements->paddleLeft.draw();

	for (auto&& ball : gameElements->balls) {
		float r = ball->radius;
		ofPushMatrix();
		ofTranslate(ball->position.x, ball->position.y);
		ofPushMatrix();
			ofRotate(ofGetElapsedTimef());
		tennis_ball.draw(0,0, 2 * r, 2 * r);
		ofPopMatrix();
		ofPopMatrix();

		//ofDrawCircle(ball->position.x + r*.5, ball->position.y + r*.5, r);
	}
}
