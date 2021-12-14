#include <QApplication>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QKeyEvent>
#include <QIcon>
#include <cmath>
#include <qDebug>

#include "Game.h"
#include "Peg.h"
#include "Bucket.h"
#include "MasterPeg.h"
#include "QJsonObject"
#include "QJsonDocument"



#include "Sounds.h"
#include "Sprites.h"

#include "box2d/include/box2d/b2_settings.h"
#include "box2d/include/box2d/box2d.h"

using namespace PGG;



// singleton
Game* Game::_uniqueInstance = 0;
Game* Game::instance()
{
    if (_uniqueInstance == 0)
        _uniqueInstance = new Game();
    return _uniqueInstance;
}

Game::Game() : QGraphicsView()
{
    // setup world/scene
    _world = new QGraphicsScene();
    _world->setBackgroundBrush(QBrush(QColor(0, 0, 0)));

    setScene(_world);

    setInteractive(true);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // setup game engine
    QObject::connect(&_engine, SIGNAL(timeout()),
                     this, SLOT(nextFrame()));
    _engine.setTimerType(Qt::PreciseTimer);
    _engine.setInterval(1000 / GAME_FPS);

    setWindowIcon(QIcon(":/icons/peggle.ico"));
    setWindowTitle("Peggle");

    _builder = new LevelBuilder();

    // install HUD
    //_hud = new HUD(width(), height(), this);
    _score = 0;
    _redPegHit = -1;

    reset();
    init();
}

void Game::reset()
{
    _engine.stop();
    _world->clear();

}

void Game::init()
{
    //video
    //suono
    //altro

    _world->addPixmap(QPixmap(Sprites::instance()->get("peggle_title")));
}

void Game::menuDuel()
{
    _world->clear();
    _state = GameState::MENU_DUEL;
    showNormal();
    fitInView(_world->addPixmap(QPixmap(Sprites::instance()->get("peggle_title"))), Qt::KeepAspectRatio);

    //dopo aver scelto tutti i parametri del duello
    //click sulla apposito bottone per andare in PLAYING
}

void Game::buildLevel()
{
    _world->clear();
    
    _builder->load("level_1");
}

void Game::play() //in gioco
{
    showFullScreen();

    buildLevel();
    _engine.start();

    //ENGINE START

    _state = GameState::PLAYING;
}

void Game::nextFrame()
{
    world2d->Step(timeStep, velocityIterations, positionIterations); //sarebbe l'advance

    
  for (b2ContactEdge* edge = MasterPegBox->GetContactList(); edge; edge = edge->next)
    {
      
      if (edge->contact->IsTouching()&& static_cast<Peg*>(edge->contact->GetFixtureA()->GetBody()->GetUserData())) {
          // if is a Peg
          if (edge->contact->GetFixtureA()->GetBody()->GetType() == b2BodyType::b2_staticBody) {
              Peg* tmp = static_cast<Peg*>(edge->contact->GetFixtureA()->GetBody()->GetUserData());
              if (!tmp->getHitted())
                  tmp->hit();
           // if is Bucket
          }else if (edge->contact->GetFixtureA()->GetBody()->GetType() == b2BodyType::b2_kinematicBody){
              Bucket* tmp = static_cast<Bucket*>(edge->contact->GetFixtureA()->GetBody()->GetUserData());
              tmp->goal();
          }

      }
    }

    //master peg
   
    masterPegGraphic->advance(MasterPegBox);

    if (MasterPegBox->GetPosition().y > 35)
    {
        masterPegGraphic->setFire(false);
        clearHittedPeg();
        remainingBall--;
        printf("%d",remainingBall);
        printRemainingBall(remainingBall);

        MasterPegBox->SetTransform(b2Vec2((sceneRect().width() / 2) / 30.0, 0 / 30.0), MasterPegBox->GetAngle());
        MasterPegBox->SetLinearVelocity(b2Vec2(0, 0));
        MasterPegBox->SetAngularVelocity(0);
        world2d->SetGravity(b2Vec2(0, 0));
        bandOne->setY(924);
        bandTwo->setY(924);
    }
    

    //bucket
    bucketGraphic->advance(BucketBox);
    if (BucketBox->GetPosition().x >32)
    {
        BucketBox->SetLinearVelocity(b2Vec2(-10, 0));
        
    }
    else if (BucketBox->GetPosition().x < 5)
    {
        BucketBox->SetLinearVelocity(b2Vec2(10, 0));
    }
    
}



// EVENTI
void Game::mousePressEvent(QMouseEvent* e)
{
    if (_state != GameState::PLAYING && _state != GameState::PAUSED &&_state != GameState::MENU_DUEL)
    {
        menuDuel();
        return;
    }

    if (_state == GameState::MENU_DUEL)
    {
        play();
        return;
    }

    if (e->button()==Qt::LeftButton && _state==GameState::PLAYING)
    {
        masterPegGraphic->setFire(true);
        world2d->SetGravity(b2Vec2(0, 6.0f));
        QPoint midPos((sceneRect().width() / 2), 0), currPos;

        currPos = QPoint(mapToScene(e->pos()).x(), mapToScene(e->pos()).y());
        double t = pow((4*(-((currPos.y()-midPos.y())* (currPos.y() - midPos.y()))+1-((currPos.x()-midPos.x())* (currPos.x() - midPos.x())))),(1/4))/36;
        QVector2D p = QVector2D(currPos.x() - midPos.x(), currPos.y() - midPos.y());
        p.normalize();
        MasterPegBox->SetLinearVelocity(b2Vec2(p.x() * 12, p.y()*12));
        
    }

    if (e->button() == Qt::RightButton)
    {
        _engine.setInterval(5);
        world2d->SetGravity(b2Vec2(0, 10.0f));
    }

}

void Game::mouseReleaseEvent(QMouseEvent* e)
{
    if (e->button() == Qt::RightButton)
        _engine.setInterval(1000 / GAME_FPS);
    
}

void Game::mouseMoveEvent(QMouseEvent* e)
{
    QPointF midPos((sceneRect().width() / 2), 0), currPos;

    currPos = QPoint(mapToScene(e->pos()).x(), mapToScene(e->pos()).y());
    setMouseTracking(true);

    QPointF center(720, 100);
    QLineF v1(center, QPoint(720, 500));

    QLineF v2(center, currPos);
    v2.setLength(200.0);
    if(!masterPegGraphic->getFire())
        MasterPegBox->SetTransform(b2Vec2(v2.p2().x() / 30.0, v2.p2().y() / 30.0), MasterPegBox->GetAngle());

    cannon->setTransformOriginPoint(QPoint(30, -65));
    cannon->setRotation(-v1.angleTo(v2));
}

void Game::wheelEvent(QWheelEvent* e)
{
    if (e->angleDelta().y() > 0)
        scale(1.1, 1.1);
    else
        scale(1 / 1.1, 1 / 1.1);
}

void Game::keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key_S && _state == GameState::MENU_DUEL)
    {
        play();
    }
    if (e->key() == Qt::Key_P && (_state == GameState::PLAYING || _state == GameState::PAUSED))
    {
        save();
        togglePause();
    }
    if (e->key() == Qt::Key_R && _state == GameState::PLAYING)
    {
        reset();
        menuDuel();
    }
}

void Game::resizeEvent(QResizeEvent* e)
{
    fitInView(0, 0, sceneRect().width(), sceneRect().height(), Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(e);
}

// UTILITY
void Game::togglePause()
{
    if (_state == GameState::PLAYING)
    {
        paused->setVisible(true);
        _engine.stop();
        _state = GameState::PAUSED;
    }
    else if (_state == GameState::PAUSED)
    {
        paused->setVisible(false);
        _engine.start();
        _state = GameState::PLAYING;
    }
}


void Game::updateFPS()
{
    _FPS_label->setText(QString("FPS = ") + QString::number(_frame_count));
    _frame_count = 0;

    // setup FPS display and measuring
    _FPS_label = new QLabel("FPS =           ", this);
    _FPS_label->setFont(QFont("Consolas", 10));
    _FPS_label->move(QPoint(40, 5));
    QObject::connect(&_FPS_timer, SIGNAL(timeout()), this, SLOT(updateFPS()));
    _FPS_timer.setTimerType(Qt::PreciseTimer);
    _FPS_timer.setInterval(1000);
    _FPS_timer.start();
}


b2Vec2 Game::getTrajectoryPoint(b2Vec2& startingPosition, b2Vec2& startingVelocity, float n)
{
    //velocity and gravity are given per second but we want time step values here
    float t = 1 / 60.0f; // seconds per time step (at 60fps)
    b2Vec2 stepVelocity = t * startingVelocity; // m/s
    b2Vec2 stepGravity = t * t * world2d->GetGravity(); // m/s/s

    return startingPosition + n * stepVelocity + 0.5f * (n * n + n) * stepGravity;
}


void Game::printRemainingBall(int b) { 
    std::string tmp = "";
    switch (b)
    {
    case 10:
        tmp = "10";
        break;
    case 9:
        tmp = "9";
        break;
    case 8:
        tmp = "8";
        break;
    case 7:
        tmp = "7";
        break;
    case 6:
        tmp = "6";
        break;
    case 5:
        tmp = "5";
        break;
    case 4:
        tmp = "4";
        break;
    case 3:
        tmp = "3";
        break;
    case 2:
        tmp = "2";
        break;
    case 1:
        tmp = "1";
        break;
    case 0:
        tmp = "0";
        break;
    };
    remainingBallPixmap->setPixmap(Sprites::instance()->get(tmp));
}


void Game::clearHittedPeg() {
    for (int i = 0; i < PegBox.size(); i++) {
       
        Peg* tmp = static_cast<Peg*>(PegBox[i]->GetUserData());
        if (tmp->getHitted()) {
            tmp->setVisible(false);
            PegBox[i]->DestroyFixture(PegBox[i]->GetFixtureList());
            
        }
    }

}

void Game::addMolt() {
    _redPegHit++; 
    molt[_redPegHit]->setVisible(true); 
    if (_redPegHit == 9)
        molt_x[0]->setVisible(true);
    else if(_redPegHit == 14) 
        molt_x[1]->setVisible(true);
    else if (_redPegHit == 18)//18
        molt_x[2]->setVisible(true);
    else if (_redPegHit == 21)
        molt_x[3]->setVisible(true);
}

void Game::save() {
    QJsonObject recordObject;
    recordObject.insert("RemainingBall", QJsonValue::fromVariant(remainingBall));
    recordObject.insert("RedPegHit", QJsonValue::fromVariant(_redPegHit));

    QJsonObject RemainingPeg;
    for (int i = 0; i < PegBox.size(); i++) {
        QJsonObject tmp;
        tmp.insert("X", PegBox[i]->GetPosition().x);
        tmp.insert("Y", PegBox[i]->GetPosition().y);
        tmp.insert("Color", static_cast<Peg*>(PegBox[i]->GetUserData())->_color==PegColor::RED?true:false);
        RemainingPeg.insert(QString::number(i), tmp);
    }
    recordObject.insert("RemainingPeg", RemainingPeg);

 
    QJsonDocument doc(recordObject);
    qDebug().noquote() << doc.toJson();

    QFile file("C:/Users/achil/Desktop/Prova.json");
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(doc.toJson());
    file.close();
}

