#pragma once

#include <QGraphicsView>
#include <QTimer>
#include <QLabel>
#include <QPainterPath>
#include <Map>

#include "Bucket.h"
#include "Hud.h"
#include "MasterPeg.h"
#include "Peg.h"
#include "LevelBuilder.h"
#include "Hud.h"
#include "Button.h"

#include "box2d/include/box2d/b2_settings.h"
#include "box2d/include/box2d/box2d.h"

namespace PGG
{
class Game;

enum class GameState
{
    TITLE,
    MODE,
    SELECT_SINGLE_CHARACTER,
    PLAYING,
    PAUSED,
    //gameover
};

// game parameters
static int GAME_FPS = 60;

static float timeStep = 1.0f / 60.0f;
static int32 velocityIterations = 8;
static int32 positionIterations = 2;


}

class PGG::Game : public QGraphicsView
{
    Q_OBJECT

private:
    // game attributes
    QTimer _engine;
    GameState _state;
    QGraphicsScene *_world;
    HUD* _hud;
    LevelBuilder* _builder;
    int _score;
    int _redPegHit;

    // FPS measuring and display
    int _frame_count;
    QTimer _FPS_timer;
    QLabel *_FPS_label;

    // box2d obj
    b2World* world2d;
    b2Body* MasterPegBox;
    b2Body* BucketBox;
    
    // graphic obj
    QGraphicsPixmapItem* background;
    Peg* pegGraphic;
    MasterPeg* masterPegGraphic;
    Bucket* bucketGraphic;

    // singleton
    static Game *_uniqueInstance;
    Game();

public:
    static Game *instance();
    QVector<b2Body*> PegBox;
    QGraphicsPixmapItem* cannon;
    int remainingBall = 9;
    QGraphicsPixmapItem* remainingBallPixmap;
    QGraphicsPixmapItem* paused;
    QGraphicsPixmapItem* bjorn;

    // getters
    b2World* getWorld2d() { return world2d; }
    QGraphicsScene* world() { return _world; }
    HUD* Hudd() { return _hud; }
    int getScore() { return _score; }

    QVector<b2Body*>getPegBox() { return PegBox; }
    Peg* getPegGraphic() { return pegGraphic; }
   
    b2Body* getMasterPegBox() { return MasterPegBox; }
    MasterPeg* getMasterPegGraphic() { return masterPegGraphic; }

    b2Body* getBucketBox() { return BucketBox; }
    Bucket* getBucketGraphic() { return bucketGraphic; }

    QGraphicsPixmapItem* bandOne;
    QGraphicsPixmapItem* bandTwo;
    QVector<QGraphicsPixmapItem*> molt;
    QVector<QGraphicsPixmapItem*> molt_x;


    // setters
    void setWorld2d(b2World* b) { world2d = b; }
    void setScore(int s) { _score = s; }
    
    void setPegGraphic(Peg* p) { pegGraphic = p; }

    void setMasterPegBox(b2Body* b) { MasterPegBox = b; }
    void setMasterPegGraphic(MasterPeg* b) { masterPegGraphic = b; }

    void setBucketBox(b2Body* b) { BucketBox = b; }
    void setBucketGraphic(Bucket* b) { bucketGraphic = b; }

    void setState(GameState State) { _state = State; }
    
    // utility
    void addMolt();
    void printRemainingBall(int b);
    void clearHittedPeg();
    void save();
    

    b2Vec2 getTrajectoryPoint(b2Vec2& startingPosition, b2Vec2& startingVelocity, float n);
    float fire(float alfa, bool b);
    int alpha = 89;
    bool simulation = false;
    int _simulationScore=0;
    std::vector < std::tuple< int, int > >simulationScore;

    // event handlers
    virtual void mousePressEvent(QMouseEvent *e) override;
    virtual void mouseReleaseEvent(QMouseEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    virtual void wheelEvent(QWheelEvent *e) override;
    virtual void keyPressEvent(QKeyEvent *e) override;
    virtual void resizeEvent(QResizeEvent* e) override;

   
public slots:
   
    void init();
    void reset();
    void mode();
    void menuDuel();
    void select_single_character();

    void buildLevel();
    void play();
    void nextFrame();


    void togglePause();


    void updateFPS();
};
