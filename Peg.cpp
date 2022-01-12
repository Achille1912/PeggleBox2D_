#include "Peg.h"
#include "Game.h"
#include "Sprites.h"
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
		QMediaPlayer* player = new QMediaPlayer;
		player->setVolume(50);
		if (Game::instance()->me)
			player->setMedia(QUrl::fromLocalFile("C:/Users/achil/Desktop/peggle2D/PeggleBox2D_/sounds/peghit.wav"));
		else
			player->setMedia(QUrl::fromLocalFile(":/sounds/peghit.wav"));

		player->play();

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
			if (Game::instance()->getRedPegHit() == 24) {
				Game::instance()->centerOn(this->scenePos());
				Game::instance()->scale(4.1, 4.1);
				emit Game::instance()->changeEngine();
				QMediaPlayer* player = new QMediaPlayer;
				player->setVolume(50);
				if (Game::instance()->me)
					player->setMedia(QUrl::fromLocalFile("C:/Users/achil/Desktop/peggle2D/PeggleBox2D_/sounds/applause.wav"));
				else
					player->setMedia(QUrl::fromLocalFile(":/sounds/applause.wav"));

				player->play();
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