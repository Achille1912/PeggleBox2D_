#include <QPainter>
#include "Hud.h"
#include "Game.h"
#include "Sprites.h"
#include "Sounds.h"

using namespace PGG;

Hud::Hud(int w, int h, QWidget *parent) : QWidget(parent)
{
    _background = Sprites::instance()->get("Hud");

    setFixedSize(w, h);

}
