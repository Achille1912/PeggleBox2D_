#include "MasterPeg.h"
#include "Game.h"
#include "Sprites.h"

using namespace PGG;



MasterPeg::MasterPeg(QPoint pos) : QGraphicsPixmapItem(0)
{
	setPos(pos);
	setPixmap(Sprites::instance()->get("player").scaled(18, 18));
	Game::instance()->world()->addItem(this);

}

void MasterPeg::advance(b2Body* box) {
	
	this->setPos(box->GetPosition().x * 30.0, box->GetPosition().y * 30.0);

}
