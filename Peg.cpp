#include "Peg.h"
#include "Game.h"
#include "Sprites.h"
#include "Sounds.h"
#include "Scheduler.h"
#include <QMediaPlayer>

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
		Game::instance()->_gameSounds->get("pegHit")->play();


		_hitted = true;

		if (_color == PegColor::BLUE) {
			setPixmap(Sprites::instance()->get("peg_blue_hit").scaled(30, 30));
;			Game::instance()->getTurn() ?
				Game::instance()->setScore(Game::instance()->getScore() + 10) :
				Game::instance()->setSecondScore(Game::instance()->getSecondScore() + 10);
			if (Game::instance()->getBandOne()->scenePos().y() >= 300) {
				Game::instance()->getBandOne()->setY(Game::instance()->getBandOne()->scenePos().y() - 40);
				Game::instance()->getBandTwo()->setY(Game::instance()->getBandTwo()->scenePos().y() - 40);
			}
		}
		else if (_color == PegColor::RED) {
			setPixmap(Sprites::instance()->get("peg_red_hit").scaled(30, 30));
			Game::instance()->getTurn() ?
			Game::instance()->setScore(Game::instance()->getScore() + 100) :
			Game::instance()->setSecondScore(Game::instance()->getSecondScore() + 100);
			Game::instance()->addMolt();
			if (Game::instance()->getRedPegHit() == 24) {
				Game::instance()->centerOn(this->scenePos());
				Game::instance()->scale(4.1, 4.1);
				emit Game::instance()->changeEngine();
				Game::instance()->_gameSounds->get("applause")->play();


			
				Game::instance()->schedule("fever", 10, [this]() {
					Game::instance()->resetMatrix();
					Game::instance()->scale(1,1);
					for (auto el : Game::instance()->PegBox) {
						if (!(static_cast<Peg*>(el->GetUserData())->getHitted())) {
							(Game::instance()->getTurn() ?
								Game::instance()->setScore(Game::instance()->getScore() + 1000) :
								Game::instance()->setSecondScore(Game::instance()->getSecondScore() + 1000));
						}
					}
					emit Game::instance()->gameOver();
					
					});
			}
			if (Game::instance()->getBandOne()->scenePos().y() >= 300) {
				Game::instance()->getBandOne()->setY(Game::instance()->getBandOne()->scenePos().y() - 50);
				Game::instance()->getBandTwo()->setY(Game::instance()->getBandTwo()->scenePos().y() - 50);
			}
		}
			
		else {
			setPixmap(Sprites::instance()->get("peg_green_hit").scaled(30, 30));
			Game::instance()->getTurn() ?
			Game::instance()->setScore(Game::instance()->getScore() + 10) :
				Game::instance()->setSecondScore(Game::instance()->getSecondScore() + 10);
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
		if (_color == PegColor::BLUE) {
			Game::instance()->setSimulationScore(Game::instance()->getSimulationScore() + 10);
		}
		else {
			if (Game::instance()->getRedPegHit() == 23) 
				feverNext = true;
			
			if (feverNext) {
				Game::instance()->setSimulationScore(Game::instance()->getSimulationScore() + 400);
				feverNext = false;
			}
			else {
				Game::instance()->setSimulationScore(Game::instance()->getSimulationScore() + 100);
			}
		}
		
	}
}

void Peg::changeColor(PegColor color) {
	_color = color;
	setPixmap(Sprites::instance()->get("peg_green").scaled(30, 30));
}