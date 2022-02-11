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
    QPixmap action_buttons;
    QPixmap character_face;
    QPixmap results_label;

    //da fare nella classe Hud
    QPixmap Hud_Unicorn;
    QPixmap bottom_zvalue;
    //QPixmap Hud_Crab;
    //...

    Sprites();

public:
    // singleton
    static Sprites *instance();

    // extract texture from sprites using the given id
    QPixmap get(const std::string &id);

};
