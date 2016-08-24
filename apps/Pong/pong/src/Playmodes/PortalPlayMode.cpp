/*
*  PortalPlayMode.cpp
*  emptyExample
*
*  Created by Brian Eschrich on 19.08.16
*  Copyright 2016 __MyCompanyName__. All rights reserved.
*
*/

#include "PortalPlayMode.h"

//Portal
Portal::Portal(ofRectangle dimensions_) {
	dimensions = dimensions_;
}

bool Portal::portalHittest(Ball* ball) {

	int b_x_min = ball->position.x - ball->radius;
	int b_x_max = ball->position.x + ball->radius;
	int b_y_min = ball->position.y - ball->radius;
	int b_y_max = ball->position.y + ball->radius;

	int w_x_min = dimensions.x;
	int w_x_max = dimensions.x + dimensions.width;
	int w_y_min = dimensions.y;
	int w_y_max = dimensions.y + dimensions.height;

	//edge side
	if (b_x_max >= w_x_min && b_x_max <= w_x_max) {
		if ((b_y_max >= w_y_min && b_y_max <= w_y_max) ||
			(b_y_min >= w_y_min && b_y_min <= w_y_max))

		{
			return true;
		}
	}

	if (b_x_min <= w_x_max && b_x_min >= w_x_min) {
		if ((b_y_max >= w_y_min && b_y_max <= w_y_max) ||
			(b_y_min >= w_y_min && b_y_min <= w_y_max))

		{
			return true;
		}
	}


	return false;
}


//Portal PLAYMODE

PortalPlayMode::PortalPlayMode(GameElements* gameElements, string name) :BasicRenderer(gameElements, name), BasicRules(gameElements, name) {

	portals.push_back(Portal(ofRectangle(gameElements->getWidth()*0.25, gameElements->getHeigth()*0.5, 10, 10)));
	portals.push_back(Portal(ofRectangle(gameElements->getWidth()*0.5, gameElements->getHeigth()*0.5, 10, 10)));
	portalicon.load("images/portalicon.png");

}

//------------------------------------------------------------------
void PortalPlayMode::begin() {
	BasicRenderer::begin();
	BasicRules::begin();
	updatePortals();
}

void PortalPlayMode::updatePortals() {
	GameElements* gameElements = BasicRules::gameElements;

	int wFirst = 50;
	int hFirst = 200;
	int xFirst = ofRandom(gameElements->getWidth()*.1, gameElements->getWidth()*0.4);
	int yFirst = ofRandom(hFirst,gameElements->getHeigth() - hFirst);

	portals[0].dimensions = ofRectangle(xFirst, yFirst, wFirst, hFirst);

	int wSecond = 50;
	int hSecond = 200;
	int xSecond = ofRandom(gameElements->getWidth()*.6, gameElements->getWidth()*0.9);
	int ySecond = ofRandom(hSecond,gameElements->getHeigth()-hSecond);

	portals[1].dimensions = ofRectangle(xSecond, ySecond, wSecond, hSecond);

}

//------------------------------------------------------------------
void PortalPlayMode::applyRules() {
	BasicRules::applyRules();

	int new_x;
	int new_y;

	int ct_portal = 0;
	for (auto ball : BasicRules::gameElements->balls) {
		new_x = ball->position.x;
		new_y = ball->position.y;
		for (auto portal : portals) {
			if (portal.portalHittest(ball)) {
				BasicRules::gameElements->notifyGameEvent(CONTACT_WALL);
				if (ct_portal == 0) {
					if (ball->velocity.x > 0) {
						new_x = portals[1].dimensions.x + portals[1].dimensions.width*1.01 + ball->radius;
					}
					else {
						new_x = portals[1].dimensions.x - portals[1].dimensions.width*0.01 - ball->radius;
					}
					new_y += portals[1].dimensions.y-portals[0].dimensions.y;
				}
				else {
					if (ball->velocity.x > 0) {
						new_x = portals[0].dimensions.x + portals[0].dimensions.width*1.01 + ball->radius;
					}
					else {
						new_x = portals[0].dimensions.x - portals[0].dimensions.width*0.01 - ball->radius;
					}
					new_y += portals[0].dimensions.y - portals[1].dimensions.y;
				}

			}
			ct_portal++;
		}		
		ball->position.x = new_x;
		ball->position.y = new_y;

	}
}


//------------------------------------------------------------------
void PortalPlayMode::render() {
	BasicRenderer::render();

	for (auto portal : portals) {
		portalicon.draw(portal.dimensions);
	}
}
