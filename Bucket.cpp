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
    if (box->GetPosition().x > 32)
        box->SetLinearVelocity(b2Vec2(-15, 0));
    else if (box->GetPosition().x < 5)
        box->SetLinearVelocity(b2Vec2(15, 0));

}


void Bucket::goal() {
    if (!Game::instance()->simulation) {
        Game::instance()->clearHittedPeg();
        Game::instance()->remainingBall--;

        Game::instance()->printRemainingBall(Game::instance()->remainingBall);


        QPointF center(720, 100);


        QLineF v2(center, QCursor::pos());
        v2.setLength(200.0);
        if (!(Game::instance()->getMasterPegGraphic()->getFire())) {
            Game::instance()->getMasterPegBox()->SetTransform(b2Vec2(v2.p2().x() / 30.0, v2.p2().y() / 30.0), Game::instance()->getMasterPegBox()->GetAngle());
            Game::instance()->getMasterPegGraphic()->setFire(false);
        }
        Game::instance()->getMasterPegBox()->SetLinearVelocity(b2Vec2(0, 0));
        Game::instance()->getMasterPegBox()->SetAngularVelocity(0);
        Game::instance()->Game::instance()->getWorld2d()->SetGravity(b2Vec2(0, 0));
        Game::instance()->bandOne->setY(924);
        Game::instance()->bandTwo->setY(924);
    }
    else {
        QPointF center(720, 100);


        QLineF v2(center, QCursor::pos());
        v2.setLength(200.0);
        if (!(Game::instance()->getMasterPegGraphic()->getFire())) {
            Game::instance()->getMasterPegBox()->SetTransform(b2Vec2(v2.p2().x() / 30.0, v2.p2().y() / 30.0), Game::instance()->getMasterPegBox()->GetAngle());
            Game::instance()->getMasterPegGraphic()->setFire(false);
        }
        Game::instance()->getMasterPegBox()->SetLinearVelocity(b2Vec2(0, 0));
        Game::instance()->getMasterPegBox()->SetAngularVelocity(0);
        Game::instance()->Game::instance()->getWorld2d()->SetGravity(b2Vec2(0, 0));

    }
}