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
    
    
    void BeginContact(b2Contact* contact)override {
        printf("Start");
      /*  //check if fixture A was a ball
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<MasterPeg*>(bodyUserData)->startContact();

        //check if fixture B was a ball
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<MasterPeg*>(bodyUserData)->startContact();
            */
    }

    void EndContact(b2Contact* contact)override {
        printf("End");
        //check if fixture A was a ball
       /* void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<MasterPeg*>(bodyUserData)->endContact();

        //check if fixture B was a ball
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<MasterPeg*>(bodyUserData)->endContact();
            */
    }
};
