#pragma once

#include <QMediaPlayer>

namespace PGG
{
    class Sounds;
}

class PGG::Sounds
{
private:
    

    

public:
    Sounds();
    int pegs = -1;
    // singleton
    static Sounds* instance();

    // sounds
    QMediaPlayer* pegHitSound[96];
    QMediaPlayer *buttonSound;
    QMediaPlayer *themeSound;
    QMediaPlayer *bucketSound;
    QMediaPlayer *fanfareSound;
    QMediaPlayer* applauseSound;
    QMediaPlayer* cannonShot;

    QMediaPlayer* powerUp;
    QMediaPlayer* powerUpFlower;
    QMediaPlayer* powerUpRabbit;
    QMediaPlayer* powerUpPumpkin;

    QMediaPlayer* extra;

    QMediaPlayer* get(const std::string& id);


};
