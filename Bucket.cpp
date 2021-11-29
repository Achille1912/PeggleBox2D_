#include "Bucket.h"
#include "Game.h"
#include "Sprites.h"

using namespace PGG;



Bucket::Bucket(QPoint pos) : QGraphicsPixmapItem(0)
{
	setPos(pos);
	setPixmap(Sprites::instance()->get("bucket"));
    setScale(1.8);
	Game::instance()->world()->addItem(this);

}

void Bucket::advance(b2Body* box) {

	this->setPos(box->GetPosition().x * 30.0, box->GetPosition().y * 30.0);

}


void Bucket::goal() {
    Game::instance()->clearHittedPeg();
    Game::instance()->remainingBall--;
   
    Game::instance()->printRemainingBall(Game::instance()->remainingBall);

    Game::instance()->getMasterPegBox()->SetTransform(b2Vec2((Game::instance()->sceneRect().width() / 2) / 30.0, 0 / 30.0), Game::instance()->getMasterPegBox()->GetAngle());
    Game::instance()->getMasterPegBox()->SetLinearVelocity(b2Vec2(0, 0));
    Game::instance()->getMasterPegBox()->SetAngularVelocity(0);
    Game::instance()->Game::instance()->getWorld2d()->SetGravity(b2Vec2(0, 0));
    Game::instance()->bandOne->setY(924);
    Game::instance()->bandTwo->setY(924);
}