#include "Sounds.h"
#include "Game.h"
#include <iostream>
#include <QDir>
#include <QMediaPlayer>

using namespace PGG;



Sounds* Sounds::instance()
{
    static Sounds uniqueInstance;
    return &uniqueInstance;
}

Sounds::Sounds()
{

    
    buttonSound = new QMediaPlayer();
    themeSound = new QMediaPlayer();
    bucketSound = new QMediaPlayer();
    fanfareSound = new QMediaPlayer();
    applauseSound = new QMediaPlayer();
    powerUp = new QMediaPlayer();
    powerUpFlower = new QMediaPlayer();
    powerUpRabbit = new QMediaPlayer();
    powerUpPumpkin = new QMediaPlayer();
    cannonShot = new QMediaPlayer();
    extra = new QMediaPlayer();
   
    for (int i = 0; i < 96; i++) {
        pegHitSound[i]= new QMediaPlayer();
        pegHitSound[i]->setMedia(QUrl::fromLocalFile("./sounds/peghit.wav"));
        pegHitSound[i]->setVolume(50);
    }

    buttonSound->setMedia(QUrl::fromLocalFile("./sounds/buttonClick.wav"));
    buttonSound->setVolume(50);
    themeSound->setMedia(QUrl::fromLocalFile("./sounds/theme.wav"));
    themeSound->setVolume(30);
    bucketSound->setMedia(QUrl::fromLocalFile("./sounds/extraball.wav"));
    bucketSound->setVolume(40);
    fanfareSound->setMedia(QUrl::fromLocalFile("./sounds/fanfare.wav"));
    fanfareSound->setVolume(40);
    applauseSound->setMedia(QUrl::fromLocalFile("./sounds/applause.wav"));
    applauseSound->setVolume(40);

    powerUp->setMedia(QUrl::fromLocalFile("./sounds/powerup.wav"));
    powerUp->setVolume(50);
    powerUpFlower->setMedia(QUrl::fromLocalFile("./sounds/powerup_flower.wav"));
    powerUpFlower->setVolume(50);
    powerUpRabbit->setMedia(QUrl::fromLocalFile("./sounds/powerup_rabbit.wav"));
    powerUpRabbit->setVolume(50);
    powerUpPumpkin->setMedia(QUrl::fromLocalFile("./sounds/powerup_pumpkin.wav"));
    powerUpPumpkin->setVolume(50);

    cannonShot->setMedia(QUrl::fromLocalFile("./sounds/cannonshot.wav"));
    cannonShot->setVolume(50);
}


QMediaPlayer* Sounds::get(const std::string& id)
{
    if (id == "pegHit") {
        pegs++;
        if (pegs == 96)
            pegs = 0;
        return pegHitSound[pegs];

    }


    else if (id == "cannonShot")
        return cannonShot;

    else if (id == "button")
        return buttonSound;

    else if (id == "theme")
        return themeSound;
    else if (id == "goal")
        return bucketSound;
    else if (id == "fanfare")
        return fanfareSound;
    else if (id == "applause")
        return applauseSound;
    else if (id == "powerUp")
        return powerUp;
    else if (id == "powerUpFlower")
        return powerUpFlower;
    else if (id == "powerUpRabbit")
        return powerUpRabbit;
    else if (id == "powerUpPumpkin")
        return powerUpPumpkin;
    else {
       
        return NULL;
    }

}
