#include "Peg.h"
#include "Game.h"
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
	_hitted = true;
	//Game::instance()->Hudd()->addScore(10, pos());
	if (_color == PegColor::BLUE) {
		setPixmap(Sprites::instance()->get("peg_blue_hit").scaled(30, 30));
		Game::instance()->setScore(Game::instance()->getScore() + 100);
	}
	else{
		setPixmap(Sprites::instance()->get("peg_red_hit").scaled(30, 30));
		Game::instance()->setScore(Game::instance()->getScore() + 200);
		Game::instance()->addMolt();
	}

	printf("Score: ");
	printf("%d", Game::instance()->getScore());
	printf("\n");
}