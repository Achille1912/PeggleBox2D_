#pragma once

#include <QPixmap>

namespace PGG
{
class Sprites;
}

class PGG::Sprites
{
private:
    // sprites
    QPixmap background_level;
    QPixmap stage_elements;
    QPixmap title_screen;
    QPixmap peggles;
    QPixmap fonts;
    QPixmap sprites;
    QPixmap gameMode_buttons;
    QPixmap character_buttons;

    //da fare nella classe Hud
    QPixmap Hud_Unicorn;
    //QPixmap Hud_Crab;
    //...

    Sprites();

public:
    // singleton
    static Sprites *instance();

    // extract texture from sprites using the given id
    QPixmap get(const std::string &id);


    // score composite from sprite single score pieces
    QPixmap getScore(int);

    // number composite from sprite single characters
    QPixmap getNumber(int n, int fill = 0);

    // string composite from sprite single characters
    QPixmap getString(std::string text, int fill = 0);
};
