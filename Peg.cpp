#include "Peg.h"
#include "Game.h"
#include "Sprites.h"

using namespace PGG;



Peg::Peg(QPoint pos, PegColor color= PegColor::BLUE): QGraphicsPixmapItem(0)
{
	setPos(pos);
	color==PegColor::BLUE?setPixmap(Sprites::instance()->get("peg_blue").scaled(30, 30)): setPixmap(Sprites::instance()->get("peg_red").scaled(30, 30));
	Game::instance()->world()->addItem(this);

}
