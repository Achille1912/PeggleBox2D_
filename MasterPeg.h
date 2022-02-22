#pragma once

#include <QPoint>
#include <QGraphicsPixmapItem>

#include "box2d/include/box2d/b2_settings.h"
#include "box2d/include/box2d/box2d.h"

namespace PGG
{
    class MasterPeg;
    
}

class PGG::MasterPeg : public QGraphicsPixmapItem
{
private:
    bool _fire=false;
public:
    MasterPeg(QPoint pos);

    void advance(b2Body* box);
    void simulAdvance(b2Body* box);
    void setFire(bool b);
    bool getFire() { return _fire; }
    void randomShot();
    void down();

    void restorePos(b2Body* box);

    void shot(QLineF c, QLineF p, QLineF f, QVector2D z);

};
