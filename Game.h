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
#include "WindowBuilder.h"
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
    SELECT_FIRST_CHARACTER,
    SELECT_SECOND_CHARACTER,
    SELECT_DIFFICULTY,
    PLAYING,
    PAUSED,
    RESULT_SINGLE,
    RESULT_DOUBLE
  
};
enum class GameMode
{
   SINGLE,
   DUEL,
   CPU

};

enum class Character
{
    UNICORN,
    BEAVER,
    CAT,
    ALIEN,
    CRAB,
    PUMPKIN,
    FLOWER,
    DRAGON,
    OWL,
    NONE
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
    GameMode _mode;
    Character _character;
    Character _secondCharacter;
    QGraphicsScene *_world;
    HUD* _hud;
    LevelBuilder* _builder;
    WindowBuilder* _window;
    int _score;
    int _secondScore;
    int _redPegHit;
    bool _power;

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
    QVector< QGraphicsPixmapItem*> scoreGraphics;
    QVector< QGraphicsPixmapItem*> scoreGraphicsTwo;
    QGraphicsPixmapItem* cannon;
    int remainingBall = 10;
    QGraphicsPixmapItem* remainingBallPixmap;
    QGraphicsPixmapItem* paused;
    QGraphicsPixmapItem* character_face;

    // getters
    b2World* getWorld2d() { return world2d; }
    QGraphicsScene* world() { return _world; }
    HUD* Hudd() { return _hud; }
    int getScore() { return _score; }
    int getSecondScore() { return _secondScore; }
    Character getCharacter() { return _character; }
    bool getPower() { return _power; }
    int getRedPegHit() { return _redPegHit; }
    GameState getState() { return _state; }
    Character getSecondCharacter() { return _secondCharacter; }
    QGraphicsPixmapItem* getBackground() { return background; }
    WindowBuilder* getWindow() { return _window; }
    GameMode getGameMode() { return _mode; }

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
    void setSecondScore(int s) { _secondScore = s; }
    void setCharacter(Character c) { _character = c; }
    void setSecondCharacter(Character c) { _secondCharacter = c; }
    void setBackground(QGraphicsPixmapItem* px) { background = px; }
    void setPower(bool b) { _power=b; }
    void setGameMode(GameMode gm) { _mode = gm; }
    
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
    void activePower();
    QVector<int> getScoreNumbers(int x, QVector<int> vec);
    void printScore();
    bool restoreGreen = false;
    MasterPeg* secondMasterPegGraphics;
    b2Body* secondMasterPegBox;

    b2Vec2 getTrajectoryPoint(b2Vec2& startingPosition, b2Vec2& startingVelocity, float n);
    float fire(float alfa, bool b);
    int alpha = 89;
    bool simulation = false;
    int _simulationScore=0;
    bool hardMode=false;
    std::vector < std::tuple< int, int > >simulationScore;
    bool turn = true;

    // event handlers
    virtual void mousePressEvent(QMouseEvent *e) override;
    virtual void mouseReleaseEvent(QMouseEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    virtual void wheelEvent(QWheelEvent *e) override;
    virtual void keyPressEvent(QKeyEvent *e) override;
    virtual void resizeEvent(QResizeEvent* e) override;

 signals:
    void gameOver();
   
public slots:
   
    void init();
    void reset();
    void menuDuel();

    void buildLevel();
    void play();
    void nextFrame();

    void togglePause();

    void updateFPS();
    void gameOverSlot();
};
