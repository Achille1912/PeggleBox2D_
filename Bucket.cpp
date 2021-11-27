#include "Bucket.h"
#include "Game.h"
#include "Sprites.h"

using namespace PGG;



Bucket::Bucket(QPoint pos) : QGraphicsPixmapItem(0)
{
	setPos(pos);
	setPixmap(Sprites::instance()->get("bucket"));
	Game::instance()->world()->addItem(this);

}

void Bucket::advance(b2Body* box) {

	this->setPos(box->GetPosition().x * 30.0, box->GetPosition().y * 30.0);

}