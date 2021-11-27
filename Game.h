#pragma once

#include <QGraphicsView>
#include <QTimer>
#include <QLabel>
#include <QPainterPath>

#include "Bucket.h"
#include "Hud.h"

#include "box2d/include/box2d/b2_settings.h"
#include "box2d/include/box2d/box2d.h"

namespace PGG
{
class Game;

enum class GameState
{
    MENU_DUEL,
    PLAYING,
    PAUSED,
    //gameover
};

// game parameters
static int GAME_FPS = 60;

static float timeStep = 1.0f / 60.0f;
static int32 velocityIterations = 6;
static int32 positionIterations = 2;
}

class PGG::Game : public QGraphicsView
{
    Q_OBJECT

private:
    // attributes
    QTimer _engine;
    GameState _state;
    QGraphicsScene *_world;

    Bucket *_bucket;
    Hud *_hud;

    // FPS measuring and display
    int _frame_count;
    QTimer _FPS_timer;
    QLabel *_FPS_label;

    //box2d
    b2World* world2d;
    b2Body* MasterPeg;
    b2Body* bucket;
    QVector<b2Body*> pegBall;

    // singleton
    static Game *_uniqueInstance;
    Game();

public:
    static Game *instance();
    QPainterPath myPath;
    // getters / setters
    QGraphicsScene *world() { return _world; }
    b2Vec2 getTrajectoryPoint(b2Vec2& startingPosition, b2Vec2& startingVelocity, float n);
    Hud *Hudd() { return _hud; }

    QPolygon pol;
    int remainingBall = 9;
    QGraphicsPixmapItem* remainingBallPixmap;


    // utility
    void printRemainingBall(int b);


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
    void menuDuel();

    void buildLevel();
    void play();
    void nextFrame();

    void togglePause();
    void toggleColliders();

    void updateFPS();
};
