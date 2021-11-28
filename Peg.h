#pragma once

#include <QPoint>
#include <QPainter>
#include <QGraphicsPixmapItem>

namespace PGG
{
class Peg;
enum class PegColor
{
    BLUE,
    RED,
    PURPLE,
    GREEN,
};
}

class PGG::Peg : public QGraphicsPixmapItem
{
private:
    PegColor _color;
    bool _hitted;
public:
    Peg(QPoint pos, PegColor color);
    void hit();
    bool getHitted() { return _hitted; }
};
