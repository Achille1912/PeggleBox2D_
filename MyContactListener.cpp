#include "MyContactListener.h"
#include "Game.h"

using namespace PGG;



void MyContactListener::BeginContact(b2Contact* contact) {

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


void MyContactListener:: EndContact(b2Contact* contact){
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