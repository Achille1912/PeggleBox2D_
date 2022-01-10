#include "Peg.h"
#include "Game.h"
#include "Sounds.h"
#include "Sprites.h"

using namespace PGG;

Peg::Peg(QPoint pos, PegColor color= PegColor::BLUE): QGraphicsPixmapItem(0)
{
	_hitted = false;
	_simulHit = false;
	setPos(pos);
	_color = color;

	if (_color == PegColor::BLUE)
		setPixmap(Sprites::instance()->get("peg_blue").scaled(30, 30));
	else if (_color == PegColor::RED)
		setPixmap(Sprites::instance()->get("peg_red").scaled(30, 30));
	else
		setPixmap(Sprites::instance()->get("peg_green").scaled(30, 30));
	
	Game::instance()->world()->addItem(this);
}


void Peg::hit() {
	if (!Game::instance()->getSimulation()) {
		QSound::play(":/sounds/peghit.wav");
		_hitted = true;

		if (_color == PegColor::BLUE) {
			setPixmap(Sprites::instance()->get("peg_blue_hit").scaled(30, 30));
;			Game::instance()->getTurn() ?
				Game::instance()->setScore(Game::instance()->getScore() + 100) :
				Game::instance()->setSecondScore(Game::instance()->getSecondScore() + 100);
			if (Game::instance()->getBandOne()->scenePos().y() >= 300) {
				Game::instance()->getBandOne()->setY(Game::instance()->getBandOne()->scenePos().y() - 40);
				Game::instance()->getBandTwo()->setY(Game::instance()->getBandTwo()->scenePos().y() - 40);
			}
		}
		else if (_color == PegColor::RED) {
			setPixmap(Sprites::instance()->get("peg_red_hit").scaled(30, 30));
			Game::instance()->getTurn() ?
			Game::instance()->setScore(Game::instance()->getScore() + 200) :
			Game::instance()->setSecondScore(Game::instance()->getSecondScore() + 200);
			Game::instance()->addMolt();
			if (Game::instance()->getBandOne()->scenePos().y() >= 300) {
				Game::instance()->getBandOne()->setY(Game::instance()->getBandOne()->scenePos().y() - 50);
				Game::instance()->getBandTwo()->setY(Game::instance()->getBandTwo()->scenePos().y() - 50);
			}
		}
			
		else {
			setPixmap(Sprites::instance()->get("peg_green_hit").scaled(30, 30));
			Game::instance()->getTurn() ?
			Game::instance()->setScore(Game::instance()->getScore() + 200) :
				Game::instance()->setSecondScore(Game::instance()->getSecondScore() + 200);
			Game::instance()->activePower((Game::instance()->getTurn() ? Game::instance()->getCharacter() : Game::instance()->getSecondCharacter()));
			Game::instance()->setRestoreGreen(true);
			if (Game::instance()->getBandOne()->scenePos().y() >= 300) {
				Game::instance()->getBandOne()->setY(Game::instance()->getBandOne()->scenePos().y() - 50);
				Game::instance()->getBandTwo()->setY(Game::instance()->getBandTwo()->scenePos().y() - 50);
			}
		}
		Game::instance()->printScore();
	}
	else {
		_simulHit = true;
		if (_color == PegColor::BLUE) 
			Game::instance()->setSimulationScore(Game::instance()->getSimulationScore()+100);
		else 
			Game::instance()->setSimulationScore(Game::instance()->getSimulationScore() + 200);
		
	}
}

void Peg::changeColor(PegColor color) {
	_color = color;
	setPixmap(Sprites::instance()->get("peg_green").scaled(30, 30));
}