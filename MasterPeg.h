#pragma once

#include <QPoint>
#include <QPainter>
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
    
public:
    MasterPeg(QPoint pos);

    void advance(b2Body* box);


};
