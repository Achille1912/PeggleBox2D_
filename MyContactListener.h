#pragma once

#include <QPoint>
#include <QPainter>
#include <QGraphicsPixmapItem>

#include "box2d/include/box2d/b2_settings.h"
#include "box2d/include/box2d/box2d.h"

namespace PGG
{
    class MyContactListener;

}

class PGG::MyContactListener : public b2ContactListener 
{
private:

public:
    
    
    void BeginContact(b2Contact* contact) override;
     
    

    void EndContact(b2Contact* contact) override;
    
};
