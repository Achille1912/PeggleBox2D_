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
    RABBIT,
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
    LevelBuilder* _builder;
    WindowBuilder* _window;
    int _score;
    int _secondScore;
    int _redPegHit;
    bool _power;
    int remainingBall = 10;
    bool restoreGreen = false;
    bool simulation = false;
    int _simulationScore = 0;
    bool hardMode = false;
    bool turn = true;

    // FPS measuring and display
    int _frame_count;
    QTimer _FPS_timer;
    QLabel *_FPS_label;

    // box2d obj
    b2World* world2d;
    b2Body* MasterPegBox;
    b2Body* BucketBox;
    b2Body* secondMasterPegBox;
    
    // graphic obj
    QGraphicsPixmapItem* background;
    MasterPeg* masterPegGraphic;
    Bucket* bucketGraphic;
    MasterPeg* secondMasterPegGraphics;
    Peg* pegGraphic;
    QGraphicsPixmapItem* cannon;
    QGraphicsPixmapItem* remainingBallPixmap;
    QGraphicsPixmapItem* paused;
    QGraphicsPixmapItem* character_face;
    QGraphicsPixmapItem* bandOne;
    QGraphicsPixmapItem* bandTwo;
    


    // singleton
    static Game *_uniqueInstance;
    Game();

public:
    static Game *instance();
    QVector<b2Body*> PegBox;
    QVector<QGraphicsPixmapItem*> lateral_mp;
    QVector< QGraphicsPixmapItem*> scoreGraphics;
    QVector< QGraphicsPixmapItem*> scoreGraphicsTwo;
    
// GETTERS

        // game attributes
    GameState getState() { return _state; }
    GameMode getGameMode() { return _mode; }
    Character getCharacter() { return _character; }
    Character getSecondCharacter() { return _secondCharacter; }
    WindowBuilder* getWindow() { return _window; }
    int getScore() { return _score; }
    int getSecondScore() { return _secondScore; }
    int getRedPegHit() { return _redPegHit; }
    bool getPower() { return _power; }
    int getRemainingBall() { return remainingBall; }
    bool getRestoreGreen() { return restoreGreen; }
    bool getSimulation() { return simulation; }
    int getSimulationScore() { return _simulationScore; }
    bool getHardMode() { return hardMode; }
    bool getTurn() { return turn; }

        // box2d obj
    b2Body* getMasterPegBox() { return MasterPegBox; }
    b2Body* getBucketBox() { return BucketBox; }
    b2Body* getSecondMasterPegBox() { return secondMasterPegBox; }
    b2World* getWorld2d() { return world2d; }

        // graphic obj
    QGraphicsScene* world() { return _world; }
    QGraphicsPixmapItem* getBackground() { return background; }
    MasterPeg* getMasterPegGraphic() { return masterPegGraphic; }
    Bucket* getBucketGraphic() { return bucketGraphic; }
    MasterPeg* getSecondMasterPegGraphics() { return secondMasterPegGraphics; }
    Peg* getPegGraphic() { return pegGraphic; }
    QGraphicsPixmapItem* getCannon() { return cannon; }
    QGraphicsPixmapItem* getRemainingBallPixmap() { return remainingBallPixmap; }
    QGraphicsPixmapItem* getPaused() { return paused; }
    QGraphicsPixmapItem* getCharacterFace() { return character_face; }
    QGraphicsPixmapItem* getBandOne() { return bandOne; }
    QGraphicsPixmapItem* getBandTwo() { return bandTwo; }
    
    
    
   
    


    QVector<b2Body*>getPegBox() { return PegBox; }
    QVector<MasterPeg*> trajcetory;
    
   
   

    QVector<QGraphicsPixmapItem*> molt;
    QVector<QGraphicsPixmapItem*> molt_x;


// SETTERS
        // game attributes
    void setState(GameState State) { _state = State; }
    void setGameMode(GameMode gm) { _mode = gm; }
    void setCharacter(Character c) { _character = c; }
    void setSecondCharacter(Character c) { _secondCharacter = c; }
    void setScore(int s) { _score = s; }
    void setSecondScore(int s) { _secondScore = s; }
    void setPower(bool b) { _power = b; }
    void setRemainingBall(int x) { remainingBall = x; }
    void setRestoreGreen(bool b) { restoreGreen = b; }
    void setSimulation(bool b) { simulation = b; }
    void setSimulationScore(int c) { _simulationScore = c; }
    void setHardMode(bool b) { hardMode = b; }
    void setTurn(bool b) { turn = b; }

        // box2d obj
    void setMasterPegBox(b2Body* b) { MasterPegBox = b; }
    void setBucketBox(b2Body* b) { BucketBox = b; }
    void setSecondMasterPegBox(b2Body* x) { secondMasterPegBox = x; }
    void setWorld2d(b2World* b) { world2d = b; }

        // graphic obj
    void setBackground(QGraphicsPixmapItem* px) { background = px; }
    void setMasterPegGraphic(MasterPeg* b) { masterPegGraphic = b; }
    void setBucketGraphic(Bucket* b) { bucketGraphic = b; }
    void setSecondMasterPegGraphics(MasterPeg* x) { secondMasterPegGraphics = x; }
    void setPegGraphic(Peg* p) { pegGraphic = p; }
    void setCannon(QGraphicsPixmapItem* x) { cannon = x; }
    void setRemainingBallPixmap(QGraphicsPixmapItem* x) { remainingBallPixmap = x; }
    void setPaused(QGraphicsPixmapItem* x) { paused = x; }
    void setCharacterFace(QGraphicsPixmapItem* x) { character_face = x; }
    void setBandOne(QGraphicsPixmapItem* x) { bandOne = x; }
    void setBandTwo(QGraphicsPixmapItem* x) { bandTwo = x; }


    // utility
    void addMolt();
    void printRemainingBall(int b);
    void clearHittedPeg();
    void save();
    void activePower(Character c);
    void printScore();
    b2Vec2 getTrajectoryPoint(b2Vec2& startingPosition, b2Vec2& startingVelocity, float n);
    float fire(float alfa, bool b);
    int alpha = 89;
    std::vector < std::tuple< int, int > >simulationScore;
    

    // event handlers
    virtual void mousePressEvent(QMouseEvent *e) override;
    virtual void mouseReleaseEvent(QMouseEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    virtual void wheelEvent(QWheelEvent *e) override;
    virtual void keyPressEvent(QKeyEvent *e) override;
    virtual void resizeEvent(QResizeEvent* e) override;


    void init();
    void reset();
    void menuDuel();
    void togglePause();
    void buildLevel();
    void play();

 signals:
    void gameOver();
   
public slots:
    void nextFrame();
    void updateFPS();
    void gameOverSlot();
};
