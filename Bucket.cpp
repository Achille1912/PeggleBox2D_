#include "Bucket.h"
#include "Game.h"
#include "Sprites.h"


using namespace PGG;

Bucket::Bucket(QPointF pos)
{
    _texture_bucket = Sprites::instance()->get("bucket");
    //setPixmap(_texture_bucket);

    _acc_x = 300.0;

}
