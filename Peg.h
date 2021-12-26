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
    
    bool _hitted;
public:
    PegColor _color;
    Peg(QPoint pos, PegColor color);
    void hit();
    bool getHitted() { return _hitted; }
    void changeColor(PegColor color);

};
