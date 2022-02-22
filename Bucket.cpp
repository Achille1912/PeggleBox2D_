#include "Bucket.h"
#include "Game.h"
#include "Sounds.h"
#include "Sprites.h"

#include <QMediaPlayer>

using namespace PGG;

Bucket::Bucket(QPoint pos) : QGraphicsPixmapItem(0)
{
    setPos(pos);
    setPixmap(Sprites::instance()->get("bucket"));
    setScale(1.8);

    Game::instance()->world()->addItem(this);

}

void Bucket::advance(b2Body* box) {
    setPos((box->GetPosition().x * 30.0)-100, (box->GetPosition().y * 29.75));
    if (box->GetPosition().x > 35)
        box->SetLinearVelocity(b2Vec2(-15, 0));
    else if (box->GetPosition().x < 10)
        box->SetLinearVelocity(b2Vec2(15, 0));
}


void Bucket::goal() {
    Game::instance()->_gameSounds->get("goal")->play();
    Game::instance()->clearHittedPeg();
    Game::instance()->setRemainingBall((Game::instance()->getRemainingBall())+1);
    Game::instance()->printRemainingBall(Game::instance()->getRemainingBall());
    Game::instance()->getMasterPegGraphic()->down();
}
