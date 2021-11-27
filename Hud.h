#pragma once

#include <QWidget>
#include <QPainter>
#include <QTimer>

#include "Sprites.h"


namespace PGG
{
class Hud;
class ScoreItem;
}

class PGG::Hud : public QWidget
{
    Q_OBJECT

private:
    QPixmap _background;

public:
    Hud(int w, int h, QWidget *parent);

};
