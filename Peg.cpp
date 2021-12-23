#include "Peg.h"
#include "Game.h"
#include "Sounds.h"
#include "Sprites.h"

using namespace PGG;



Peg::Peg(QPoint pos, PegColor color= PegColor::BLUE): QGraphicsPixmapItem(0)
{
	_hitted = false;
	setPos(pos);
	color==PegColor::BLUE?setPixmap(Sprites::instance()->get("peg_blue").scaled(30, 30)): setPixmap(Sprites::instance()->get("peg_red").scaled(30, 30));
	_color = color;
	Game::instance()->world()->addItem(this);

}


void Peg::hit() {
	if (!Game::instance()->simulation) {
		QSound::play("sounds/peghit.wav");
		//Sounds::instance()->play("peghit");
		_hitted = true;
		//Game::instance()->Hudd()->addScore(10, pos());
		if (_color == PegColor::BLUE) {
			setPixmap(Sprites::instance()->get("peg_blue_hit").scaled(30, 30));
			Game::instance()->setScore(Game::instance()->getScore() + 100);
			if (Game::instance()->bandOne->scenePos().y() >= 300) {
				Game::instance()->bandOne->setY(Game::instance()->bandOne->scenePos().y() - 40);
				Game::instance()->bandTwo->setY(Game::instance()->bandTwo->scenePos().y() - 40);
			}
		}
		else {
			setPixmap(Sprites::instance()->get("peg_red_hit").scaled(30, 30));
			Game::instance()->setScore(Game::instance()->getScore() + 200);
			Game::instance()->addMolt();
			if (Game::instance()->bandOne->scenePos().y() >= 300) {
				Game::instance()->bandOne->setY(Game::instance()->bandOne->scenePos().y() - 50);
				Game::instance()->bandTwo->setY(Game::instance()->bandTwo->scenePos().y() - 50);
			}
		}
	}
	else {
		if (_color == PegColor::BLUE) {

			Game::instance()->_simulationScore+=100;
		}
		else {

			Game::instance()->_simulationScore += 200;
		}
	}

}