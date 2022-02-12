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
    int contaHit = 0;
    bool _simulHit;
    bool feverNext=false;
public:
    Peg(QPoint pos, PegColor color);
    Peg() {}
    
    // getters
    PegColor getPegColor() { return _color; }
    bool getHitted() { return _hitted; }
    int getContaHit() { return contaHit; }
    bool getSimulHit() { return _simulHit; }
    // setters
    void setPegColor(PegColor pg) { _color = pg; }
    void setSimulHit(bool b) { _simulHit = b; }

    void hit();
    int foundGreen();
    
    void changeColor(PegColor color);

};
