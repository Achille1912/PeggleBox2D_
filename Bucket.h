#pragma once

#include <QPixmap>

namespace PGG
{
class Bucket;
}

class PGG::Bucket
{
private:

    // physics parameters
    float _acc_x;

    // animations
    /*Direction _moving_dir;*/
    QPixmap _texture_bucket;

public:
    Bucket(QPointF pos);


};
