#include "Sprites.h"
#include <QBitmap>
#include <iostream>
#include <QPainter>

using namespace PGG;

// load texture with transparency using the given color as mask
static QPixmap loadTexture(const std::string &file, QColor mask_color = Qt::magenta)
{
    QPixmap pixmap(file.c_str());
    pixmap.setMask(pixmap.createMaskFromColor(mask_color));
    return pixmap;
}

// moving within sprite utility function //ci servirà per i font credo
QRect moveBy(QRect rect, int x, int y, int dx = 16, int dy = 16, int border_x = 0, int border_y = 0)
{
    rect.moveTo(QPoint(rect.x() + x * dx + x * border_x, rect.y() + y * dy + y * border_y));
    return rect;
}

// main object positions within sprites //non ha senso da togliere perché non ci serve
static QRect player(467, 259, 93, 93);
static QRect pegle(0, 0, 200, 200);
static QRect bucket(168, 200, 168, 24);
static QRect remainingBallNumber(479, 305, 30, 54);

Sprites *Sprites::instance()
{
    static Sprites uniqueInstance;
    return &uniqueInstance;
}

Sprites::Sprites() //load in RAM
{
    title_screen = loadTexture(":/sprites/peggle_title.png", QColor(255, 0, 255));

    Hud_Unicorn = loadTexture(":/sprites/krita.png"); // da fare prob. nell'altra classe Hud
    //Hud_Drake ...

    //dynamic Hud da fare

    stage_elements = loadTexture(":/sprites/stage_elements.png", QColor(255, 0, 255));
    pegles = loadTexture(":/sprites/peggles.png", QColor(255, 255, 255));
    fonts = loadTexture(":/sprites/Peggle_Fonts.png");
    sprites = loadTexture(":/sprites/sprites.png");
}

QPixmap Sprites::get(const std::string &id)
{
    if (id == "peggle_title")
        return title_screen;

    else if (id == "Hud_Unicorn")
        return Hud_Unicorn;

    else if (id == "player")
        return sprites.copy(403,82,9,12);
    else if (id == "bucket")
        return stage_elements.copy(bucket);

    // Remaining Balls
    else if (id == "0")
        return fonts.copy(remainingBallNumber);
    else if (id == "1")
        return fonts.copy(moveBy(remainingBallNumber, 1, 0, 30*1));
    else if (id == "2")
        return fonts.copy(moveBy(remainingBallNumber, 1, 0, (30 * 2)));
    else if (id == "3")
        return fonts.copy(moveBy(remainingBallNumber, 1, 0, (30 * 3)));
    else if (id == "4")
        return fonts.copy(moveBy(remainingBallNumber, 1, 0, (30 * 4)));
    else if (id == "5")
        return fonts.copy(moveBy(remainingBallNumber, 1, 0, (30 * 5)));
    else if (id == "6")
        return fonts.copy(moveBy(remainingBallNumber, 1, 0, (30 * 6)));
    else if (id == "7")
        return fonts.copy(moveBy(remainingBallNumber, 1, 0, (35 * 6)));
    else if (id == "8") 
        return fonts.copy(moveBy(remainingBallNumber, 1, 0, (35 * 7)));
    else if (id == "9")
        return fonts.copy(moveBy(remainingBallNumber, 1, 0, (35 * 8)));
    else if (id == "10")
        return (fonts.copy(478, 305, 52, 54).transformed(QTransform().scale(-1,1)));
    // else if (id == "cannon")
    //    return stage_elements.copy(cannon);

    
    else if (id == "peg_blue_hit")
        return pegles.copy(pegle);
    else if (id == "peg_red_hit")
        return pegles.copy(moveBy(pegle, 1, 0, 200));
    else if (id == "peg_blue")
        return pegles.copy(moveBy(pegle, 0, 1, 0, 200));
    else if (id == "peg_red")
        return pegles.copy(moveBy(pegle, 1, 1, 200, 200));

    else
    {
        std::cerr << "Cannot find sprite texture with id \"" << id << "\"\n";
        return QPixmap();
    }
}

//QPixmap Sprites::getScore(int s)
//{
//}
