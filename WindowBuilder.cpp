#include "WindowBuilder.h"
#include "Sprites.h"
#include "Game.h"
#include <random>
#include <iostream>
#include <set>


using namespace PGG;


void WindowBuilder::load(const QString& window_name)
{
     if (window_name == "mode") {
        Game::instance()->world()->clear();
        Game::instance()->setState(GameState::MODE);
        Game::instance()->setBackground(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("gameMode"))));
        Game::instance()->fitInView(Game::instance()->getBackground(), Qt::KeepAspectRatio);
        Game::instance()->setSceneRect(0, 0, Game::instance()->getBackground()->sceneBoundingRect().width(), Game::instance()->getBackground()->sceneBoundingRect().height());

        new Button(QRect(100, 200, 300, 150), ButtonType::SINGLE);
        new Button(QRect(370, 200, 300, 150), ButtonType::DUEL);
        new Button(QRect(650, 200, 300, 150), ButtonType::CPU);

        new Button(QRect(((Game::instance()->sceneRect().width() / 2) - 78), 500, 500, 150), ButtonType::MAIN_MENU);
        Game::instance()->showNormal();
		
    }
    else if (window_name == "select_single_character") {
        
        Game::instance()->world()->clear();
        Game::instance()->setState(GameState::SELECT_SINGLE_CHARACTER);

        Game::instance()->setBackground(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("select_character"))));
        Game::instance()->fitInView(Game::instance()->getBackground(), Qt::KeepAspectRatio);
        new Button(QRect(120, 100, 89, 89), ButtonType::UNICORN);
        new Button(QRect(120, 200, 89, 89), ButtonType::BEAVER);
        new Button(QRect(120, 300, 89, 89), ButtonType::OWL);
        new Button(QRect(120, 400, 89, 89), ButtonType::ALIEN);


        new Button(QRect(280, 100, 89, 89), ButtonType::FLOWER);
        new Button(QRect(280, 200, 89, 89), ButtonType::DRAGON);
        new Button(QRect(280, 300, 89, 89), ButtonType::RABBIT);
        new Button(QRect(280, 400, 89, 89), ButtonType::PUMPKIN);
        

        new Button(QRect(((Game::instance()->sceneRect().width() / 4) - 75), 480, 500, 150), ButtonType::PLAY_NOW);
        Game::instance()->setSceneRect(0, 0, Game::instance()->getBackground()->sceneBoundingRect().width(), Game::instance()->getBackground()->sceneBoundingRect().height());

    }
    else if (window_name == "select_difficulty") {
       
        Game::instance()->world()->clear();
        Game::instance()->setState(GameState::SELECT_DIFFICULTY);

        Game::instance()->setBackground(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("select_difficulty"))));
        Game::instance()->fitInView(Game::instance()->getBackground(), Qt::KeepAspectRatio);
        new Button(QRect((Game::instance()->sceneRect().width() / 2) - 105, 100, 250, 150), ButtonType::NORMAL_MODE);
        new Button(QRect((Game::instance()->sceneRect().width() / 2) - 105, 250, 250, 150), ButtonType::HARD_MODE);


        new Button(QRect(((Game::instance()->sceneRect().width() / 2) - 75), 480, 500, 150), ButtonType::CONTINUE);
        Game::instance()->setSceneRect(0, 0, Game::instance()->getBackground()->sceneBoundingRect().width(), Game::instance()->getBackground()->sceneBoundingRect().height());
    }
    else if (window_name == "select_first_character") {
        
        Game::instance()->world()->clear();
        Game::instance()->setState(GameState::SELECT_FIRST_CHARACTER);

        Game::instance()->setBackground(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("select_character"))));
        Game::instance()->fitInView(Game::instance()->getBackground(), Qt::KeepAspectRatio);
        new Button(QRect(120, 100, 89, 89), ButtonType::UNICORN);
        new Button(QRect(120, 200, 89, 89), ButtonType::BEAVER);
        new Button(QRect(120, 300, 89, 89), ButtonType::OWL);
        new Button(QRect(120, 400, 89, 89), ButtonType::ALIEN);


        new Button(QRect(280, 100, 89, 89), ButtonType::FLOWER);
        new Button(QRect(280, 200, 89, 89), ButtonType::DRAGON);
        new Button(QRect(280, 300, 89, 89), ButtonType::RABBIT);
        new Button(QRect(280, 400, 89, 89), ButtonType::PUMPKIN);
        

        new Button(QRect(((Game::instance()->sceneRect().width() / 4) - 75), 480, 500, 150), ButtonType::NEXT);
        Game::instance()->setSceneRect(0, 0, Game::instance()->getBackground()->sceneBoundingRect().width(), Game::instance()->getBackground()->sceneBoundingRect().height());

    }
    else if (window_name == "select_second_character") {
        Game::instance()->world()->clear();
        Game::instance()->setState(GameState::SELECT_SECOND_CHARACTER);

        Game::instance()->setBackground(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("select_character"))));
        Game::instance()->fitInView(Game::instance()->getBackground(), Qt::KeepAspectRatio);

        new Button(QRect(120, 100, 89, 89), ButtonType::UNICORN);
        new Button(QRect(120, 200, 89, 89), ButtonType::BEAVER);
        new Button(QRect(120, 300, 89, 89), ButtonType::OWL);
        new Button(QRect(120, 400, 89, 89), ButtonType::ALIEN);


        new Button(QRect(280, 100, 89, 89), ButtonType::FLOWER);
        new Button(QRect(280, 200, 89, 89), ButtonType::DRAGON);
        new Button(QRect(280, 300, 89, 89), ButtonType::RABBIT);
        new Button(QRect(280, 400, 89, 89), ButtonType::PUMPKIN);
        

        new Button(QRect(((Game::instance()->sceneRect().width() / 2) - 75), 480, 500, 150), ButtonType::PLAY_NOW);
        Game::instance()->setSceneRect(0, 0, Game::instance()->getBackground()->sceneBoundingRect().width(), Game::instance()->getBackground()->sceneBoundingRect().height());
    }
    else if (window_name == "result_single") {
        Game::instance()->world()->clear();
        Game::instance()->setState(GameState::RESULT_SINGLE);

        Game::instance()->setBackground(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("results"))));
        Game::instance()->fitInView(Game::instance()->getBackground(), Qt::KeepAspectRatio);

        new Button(QRect(((Game::instance()->sceneRect().width() / 3) - 110), 150, 200, 89), ButtonType::TOTAL_SCORE);

        Game::instance()->scoreGraphics.resize(6);
        for (int i = 0; i < 6; i++) {
            Game::instance()->scoreGraphics[i] = new QGraphicsPixmapItem();
            Game::instance()->scoreGraphics[i]->setPixmap(QPixmap(Sprites::instance()->get("0-score")).scaled(50, 50));
            Game::instance()->scoreGraphics[i]->setY(300);
            Game::instance()->scoreGraphics[i]->setX((int)600 - (i * 50));
            Game::instance()->scoreGraphics[i]->setScale(0.5);
            Game::instance()->world()->addItem(Game::instance()->scoreGraphics[i]);
        }
        Game::instance()->printScore();
        new Button(QRect(((Game::instance()->sceneRect().width() / 3) - 75), 480, 500, 150), ButtonType::RETURN);
        Game::instance()->setSceneRect(0, 0, Game::instance()->getBackground()->sceneBoundingRect().width(), Game::instance()->getBackground()->sceneBoundingRect().height());
    }
    else if (window_name == "result_double") {
        Game::instance()->world()->clear();
        Game::instance()->setState(GameState::RESULT_DOUBLE);

        Game::instance()->setBackground(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("results"))));
        Game::instance()->fitInView(Game::instance()->getBackground(), Qt::KeepAspectRatio);


        new Button(QRect(((Game::instance()->sceneRect().width() / 6) - 110), 150, 250, 89), ButtonType::FIRST_PLAYER_SCORE);
        new Button(QRect(((Game::instance()->sceneRect().width() / 2) - 80), 150, 250, 89), ButtonType::SECOND_PLAYER_SCORE);


        Game::instance()->scoreGraphics.resize(6);
        for (int i = 0; i < 6; i++) {
            Game::instance()->scoreGraphics[i] = new QGraphicsPixmapItem();
        
            Game::instance()->scoreGraphics[i]->setPixmap(QPixmap(Sprites::instance()->get("0-score")).scaled(50, 50));
            Game::instance()->scoreGraphics[i]->setY(250);
            Game::instance()->scoreGraphics[i]->setX((int)350 - ((i * 50)));
            Game::instance()->scoreGraphics[i]->setScale(0.5);
            Game::instance()->world()->addItem(Game::instance()->scoreGraphics[i]);

            Game::instance()->scoreGraphicsTwo[i] = new QGraphicsPixmapItem();   
            Game::instance()->scoreGraphicsTwo[i]->setPixmap(QPixmap(Sprites::instance()->get("0-score")).scaled(50, 50));
            Game::instance()->scoreGraphicsTwo[i]->setY(250);
            Game::instance()->scoreGraphicsTwo[i]->setX((int)850 - ((i * 50)));
            Game::instance()->scoreGraphicsTwo[i]->setScale(0.5);
            Game::instance()->world()->addItem(Game::instance()->scoreGraphicsTwo[i]);
        }   
        Game::instance()->printScore();

        new Button(QRect(((Game::instance()->sceneRect().width() / 3) - 110), 300, 250, 89), ButtonType::THE_WINNER_IS);

        if(Game::instance()->getScore()> Game::instance()->getSecondScore())
            new Button(QRect(((Game::instance()->sceneRect().width() / 3) - 110), 350, 250, 89), ButtonType::FIRST_PLAYER);
        else
            new Button(QRect(((Game::instance()->sceneRect().width() / 3) - 110), 350, 250, 89), ButtonType::SECOND_PLAYER);

        new Button(QRect(((Game::instance()->sceneRect().width() / 3) - 75), 480, 500, 150), ButtonType::RETURN);
        Game::instance()->setSceneRect(0, 0, Game::instance()->getBackground()->sceneBoundingRect().width(), Game::instance()->getBackground()->sceneBoundingRect().height());
    }
    else
    {
        std::cerr << "Cannot load window: window " << window_name.toStdString() << " not found\n";

    }
}