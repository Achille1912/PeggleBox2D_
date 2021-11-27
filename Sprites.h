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
    QPixmap pegles;
    QPixmap fonts;
    QPixmap sprites;

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

    //QPixmap getScore(int);
};
