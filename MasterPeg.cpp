#include "MasterPeg.h"
#include "Game.h"
#include "Sprites.h"

using namespace PGG;

/*int ciao = -45;
bool sortbysec(const std::tuple<int, int>& a,
    const std::tuple<int, int>& b)
{
    return (std::get<1>(a) < std::get<1>(b));
}*/

MasterPeg::MasterPeg(QPoint pos) : QGraphicsPixmapItem(0)
{
	setPos(pos);
	setPixmap(Sprites::instance()->get("master_peg").scaled(20, 20));
	Game::instance()->world()->addItem(this);

}

void MasterPeg::advance(b2Body* box) {
	
	this->setPos(box->GetPosition().x * 30.0, box->GetPosition().y * 30.0);

    if (box->GetPosition().y > 35)
    {
        if (!Game::instance()->simulation) {

            if (Game::instance()->getPower()) {
                switch (Game::instance()->getCharacter()) {
                case Character::BEAVER:
                {
                    if (Game::instance()->secondMasterPegBox->GetPosition().y > 35)
                    {
                        Game::instance()->secondMasterPegGraphics->setVisible(false);
                        Game::instance()->secondMasterPegBox->DestroyFixture(Game::instance()->secondMasterPegBox->GetFixtureList());
                        Game::instance()->setPower(false);
                    }
                    return;
                }
                break;
                case Character::PUMPKIN:
                    box->SetTransform(b2Vec2(box->GetPosition().x, 0), box->GetAngle());
                    Game::instance()->setPower(false);
                    return;
                    break;
                case Character::DRAGON:
                {
                    Game::instance()->cannon->setPixmap(Sprites::instance()->get("cannon_fired"));
                    Game::instance()->getMasterPegGraphic()->setPixmap(Sprites::instance()->get("master_peg_fired").scaled(20, 20));
                    Game::instance()->getMasterPegGraphic()->setVisible(false);
                    box->GetFixtureList()->SetSensor(true);

                    Game::instance()->setPower(false);
                    this->setFire(false);
                    Game::instance()->clearHittedPeg();
                    Game::instance()->remainingBall--;
                    
                    Game::instance()->lateral_mp[9 - (Game::instance()->remainingBall)]->setVisible(false);

                    Game::instance()->printRemainingBall(Game::instance()->remainingBall);
                    QPointF center(720, 100);


                    QLineF v2(center, QCursor::pos());
                    v2.setLength(200.0);
                    box->SetTransform(b2Vec2(v2.p2().x() / 30.0, v2.p2().y() / 30.0), box->GetAngle());
                    box->SetLinearVelocity(b2Vec2(0, 0));
                    box->SetAngularVelocity(0);
                    Game::instance()->getWorld2d()->SetGravity(b2Vec2(0, 0));
                    Game::instance()->bandOne->setY(924);
                    Game::instance()->bandTwo->setY(924);


                   
                    return;
                }
                break;
                }
            }
            if (Game::instance()->getGameMode() == GameMode::DUEL || Game::instance()->getGameMode() == GameMode::CPU) {
                if (Game::instance()->turn == true) {
                    Game::instance()->turn = false;
                    switch (Game::instance()->getSecondCharacter()) {
                    case Character::UNICORN:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("unicorn_face_right")));
                        break;
                    case Character::BEAVER:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("beaver_face_right")));
                        break;
                    case Character::CRAB:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("crab_face_right")));
                        break;
                    case Character::FLOWER:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("flower_face_right")));
                        break;
                    case Character::PUMPKIN:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("pumpkin_face_right")));
                        break;
                    case Character::ALIEN:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("alien_face_right")));
                        break;
                    case Character::OWL:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("owl_face_right")));
                        break;
                    case Character::DRAGON:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("dragon_face_right")));
                        break;
                    }
                }
                else {
                    Game::instance()->turn = true;
                    switch (Game::instance()->getCharacter()) {
                    case Character::UNICORN:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("unicorn_face_right")));
                        break;
                    case Character::BEAVER:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("beaver_face_right")));
                        break;
                    case Character::CRAB:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("crab_face_right")));
                        break;
                    case Character::FLOWER:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("flower_face_right")));
                        break;
                    case Character::PUMPKIN:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("pumpkin_face_right")));
                        break;
                    case Character::ALIEN:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("alien_face_right")));
                        break;
                    case Character::OWL:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("owl_face_right")));
                        break;
                    case Character::DRAGON:
                        Game::instance()->character_face->setPixmap(QPixmap(Sprites::instance()->get("dragon_face_right")));
                        break;
                    }
                }
            }

            
            Game::instance()->getMasterPegGraphic()->setPixmap(Sprites::instance()->get("master_peg").scaled(20, 20));
            box->GetFixtureList()->SetSensor(false);
            this->setFire(false);
            Game::instance()->clearHittedPeg();
            Game::instance()->remainingBall--;
            Game::instance()->lateral_mp[9 - (Game::instance()->remainingBall)]->setVisible(false);

            Game::instance()->printRemainingBall(Game::instance()->remainingBall);
            QPointF center(720, 100);


            QLineF v2(center, QCursor::pos());
            v2.setLength(200.0);
            box->SetTransform(b2Vec2(v2.p2().x() / 30.0, v2.p2().y() / 30.0), box->GetAngle());
            box->SetLinearVelocity(b2Vec2(0, 0));
            box->SetAngularVelocity(0);
            Game::instance()->getWorld2d()->SetGravity(b2Vec2(0, 0));
            Game::instance()->bandOne->setY(924);
            Game::instance()->bandTwo->setY(924);
            Game::instance()->getMasterPegGraphic()->setVisible(false);
            Game::instance()->cannon->setPixmap(Sprites::instance()->get("cannon"));

            if (Game::instance()->remainingBall == 0) {

                emit Game::instance()->gameOver();
                return;
            }

            if (Game::instance()->getGameMode() == GameMode::CPU && !(Game::instance()->turn)) {
               
                int alfa = rand() % 181;
                QPoint midPos((Game::instance()->sceneRect().width() / 2), 130);

                QLineF p = QLineF(midPos, QPointF((Game::instance()->sceneRect().width() / 2), 500));
                QLineF f = QLineF(midPos, QPointF((Game::instance()->sceneRect().width() / 2), 300));
                QLineF c = p;

                p.setAngle(-alfa);
                f.setAngle(-alfa);

                Game::instance()->cannon->setTransformOriginPoint(QPoint(30, -65));
                Game::instance()->cannon->setRotation(-c.angleTo(p));
                if (!Game::instance()->getMasterPegGraphic()->getFire())
                    Game::instance()->getMasterPegBox()->SetTransform(b2Vec2(f.p2().x() / 30.0, f.p2().y() / 30.0), Game::instance()->getMasterPegBox()->GetAngle());
                Game::instance()->getMasterPegBox()->SetLinearVelocity(b2Vec2((p.dx() - (Game::instance()->getMasterPegBox()->GetPosition().x / 30.0)) * 0.05, (p.dy() - (Game::instance()->getMasterPegBox()->GetPosition().y) / 30.0) * 0.05));
                Game::instance()->getWorld2d()->SetGravity(b2Vec2(0, 25.0f));
                Game::instance()->getMasterPegGraphic()->setFire(true);
                Game::instance()->getMasterPegGraphic()->setVisible(true);
                Game::instance()->cannon->setPixmap(Sprites::instance()->get("cannon_without_ball"));
            }

        }
        /*else {
            printf("Prova");
            QPointF center(720, 100);
            QLineF v2(center, QCursor::pos());
            v2.setLength(200.0);
            box->SetTransform(b2Vec2(v2.p2().x() / 30.0, v2.p2().y() / 30.0), box->GetAngle());
            box->SetLinearVelocity(b2Vec2(0, 0));
            box->SetAngularVelocity(0);
            Game::instance()->getWorld2d()->SetGravity(b2Vec2(0, 0));
            Game::instance()->alpha--;
            if (Game::instance()->alpha < -89) {

                printf("Finitooo");
                //Game::instance()->getEngine().setInterval(1000 / GAME_FPS);
                this->setFire(false);
                Game::instance()->getBucketBox()->SetTransform(b2Vec2((Game::instance()->sceneRect().width() / 2) / 30.0, (Game::instance()->sceneRect().height() - 530) / 30.0), box->GetAngle());

                if (Game::instance()->simulation) {
                    std::sort(Game::instance()->simulationScore.begin(), Game::instance()->simulationScore.end(), sortbysec);
                    for (int i = 0; i < (Game::instance()->simulationScore.size() - 1); i++) {
                        printf("Alpha: ");
                        printf("%d", std::get<0>(Game::instance()->simulationScore[i]));

                        printf(" Score: ");
                        printf("%d", std::get<1>(Game::instance()->simulationScore[i]));
                        printf("\n");
                    }

                    QPoint midPos((Game::instance()->sceneRect().width() / 2), 130);

                    QLineF p = QLineF(midPos, QPointF((Game::instance()->sceneRect().width() / 2), 500));
                    QLineF f = QLineF(midPos, QPointF((Game::instance()->sceneRect().width() / 2), 300));
                    QLineF c = p;

                    printf("%d", std::get<0>(Game::instance()->simulationScore[176]));

                    p.setAngle((std::get<0>(Game::instance()->simulationScore[176])));
                    f.setAngle((std::get<0>(Game::instance()->simulationScore[176])));
                    ciao = (std::get<0>(Game::instance()->simulationScore[176]));
                    Game::instance()->cannon->setTransformOriginPoint(QPoint(30, -65));
                    Game::instance()->cannon->setRotation(-c.angleTo(p));
                    if (!this->getFire())
                        box->SetTransform(b2Vec2(f.p2().x() / 30.0, f.p2().y() / 30.0), box->GetAngle());
                    box->SetLinearVelocity(b2Vec2((p.dx() - (box->GetPosition().x / 30.0)) * 0.05, (p.dy() - (box->GetPosition().y) / 30.0) * 0.05));
                    this->setFire(true);
                    Game::instance()->getWorld2d()->SetGravity(b2Vec2(0, 25.0f));


                    Game::instance()->world()->addLine(p, QPen(Qt::green));
                }
                Game::instance()->simulation = false;
            }
            else {
                Game::instance()->simulationScore.emplace_back(Game::instance()->alpha - 90, Game::instance()->_simulationScore);
                Game::instance()->_simulationScore = 0;
                Game::instance()->fire(Game::instance()->alpha, false);

            }

        }
    */
    }
}
