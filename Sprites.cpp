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
static QRect score(4, 280, 46,70);

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
    peggles = loadTexture(":/sprites/peggles.png", QColor(255, 255, 255));
    fonts = loadTexture(":/sprites/Peggle_Fonts.png");
    sprites = loadTexture(":/sprites/sprites.png");
    gameMode_buttons = loadTexture(":/sprites/gameMode_buttons.png", QColor(255, 255, 255));
    character_buttons= loadTexture(":/sprites/character_buttons.png", QColor(255, 255, 255));
    action_buttons= loadTexture(":/sprites/action_buttons.png", QColor(255, 255, 255));
    character_face= loadTexture(":/sprites/character_face.png", QColor(255, 255, 255));
    results_label= loadTexture(":/sprites/results_label.png", QColor(255, 255, 255));
}

QPixmap Sprites::get(const std::string &id)
{
    if (id == "peggle_title")
        return title_screen;

    else if (id == "Hud_Unicorn")
        return Hud_Unicorn;

    else if (id == "gameMode")
        return loadTexture(":/sprites/gameMode.png", QColor(255, 0, 255));
    else if (id == "select_character")
        return loadTexture(":/sprites/select_single_character.png", QColor(255, 0, 255));
    else if (id == "select_difficulty")
        return loadTexture(":/sprites/select_difficulty.png", QColor(255, 0, 255));
    else if (id == "results")
        return loadTexture(":/sprites/results.png", QColor(255, 0, 255));

    else if (id == "single_button")
        return gameMode_buttons.copy(QRect(0, 254, 211, 127));
    else if (id == "duel_button")
        return gameMode_buttons.copy(QRect(0, 128, 211, 127));
    else if (id == "cpu_button")
        return gameMode_buttons.copy(QRect(0, 0, 211, 127));
    else if (id == "normal_mode_button")
        return gameMode_buttons.copy(QRect(0, 514, 211, 127));
    else if (id == "hard_mode_button")
        return gameMode_buttons.copy(QRect(0, 384, 211, 127));

    else if (id == "unicorn_button")
        return character_buttons.copy(QRect(0, 729, 89, 90));
    else if (id == "owl_button")
        return character_buttons.copy(QRect(0, 547, 89, 90));
    else if (id == "dragon_button")
        return character_buttons.copy(QRect(0, 365, 89, 90));
    else if (id == "alien_button")
        return character_buttons.copy(QRect(0, 0, 89, 90));
    else if (id == "cat_button")
        return character_buttons.copy(QRect(0, 183, 89, 90));
    else if (id == "flower_button")
        return character_buttons.copy(QRect(0, 456, 89, 90));
    else if (id == "pumpkin_button")
        return character_buttons.copy(QRect(0, 638, 89, 90));
    else if (id == "crab_button")
        return character_buttons.copy(QRect(0, 274, 89, 90));
    else if (id == "beaver_button")
        return character_buttons.copy(QRect(0, 92, 89, 90));

    else if (id == "main_menu_button")
        return action_buttons.copy(QRect(0, 0, 155, 55));
    else if (id == "play_now_button")
        return action_buttons.copy(QRect(0, 57, 155, 54));
    else if (id == "continue_button")
        return action_buttons.copy(QRect(0, 175, 155, 54));
    else if (id == "next_button")
        return action_buttons.copy(QRect(0, 237, 155, 54));
    else if (id == "return_button")
        return action_buttons.copy(QRect(0, 116, 155, 54));
    else if (id == "total_score")
        return results_label.copy(QRect(0, 0, 228, 54));
    else if (id == "the_winner_is")
        return results_label.copy(QRect(0, 63, 228, 54));
    else if (id == "first_player_score")
        return results_label.copy(QRect(0, 130, 228, 54));
    else if (id == "second_player_score")
        return results_label.copy(QRect(0, 190, 228, 54));
    else if (id == "first_player")
        return results_label.copy(QRect(0, 315, 228, 54));
    else if (id == "second_player")
        return results_label.copy(QRect(0, 250, 228, 54));

    else if (id == "master_peg")
        return sprites.copy(343, 10, 54, 54);
    else if (id == "master_peg_fired")
        return sprites.copy(424, 77, 22, 22);
    else if (id == "bucket")
        return stage_elements.copy(bucket);
    else if (id == "unicorn_face_right")
        return character_face.copy(0, 0, 66, 89);
    else if (id == "unicorn_face_left")
        return character_face.copy(0, 98, 66, 89);
    else if (id == "beaver_face_right")
        return character_face.copy(0, 257, 92, 79);
    else if (id == "beaver_face_left")
        return character_face.copy(0, 180, 92, 79);
    else if (id == "crab_face_right")
        return character_face.copy(0, 421, 66, 84);
    else if (id == "crab_face_left")
        return character_face.copy(0, 339, 66, 84);
    else if (id == "flower_face_right")
        return character_face.copy(0, 590, 86, 83);
    else if (id == "flower_face_left")
        return character_face.copy(0, 507, 86, 83);
    else if (id == "pumpkin_face_right")
        return character_face.copy(0, 757, 83, 80);
    else if (id == "pumpkin_face_left")
        return character_face.copy(0, 675, 83, 80);
    else if (id == "alien_face_right")
        return character_face.copy(0, 921, 72, 82);
    else if (id == "alien_face_left")
        return character_face.copy(0, 839, 72, 82);
    else if (id == "owl_face_right")
        return character_face.copy(0, 1101, 89, 96);
    else if (id == "owl_face_left")
        return character_face.copy(0, 1006, 89, 96);
    else if (id == "dragon_face_right")
        return character_face.copy(0, 1298, 79, 95);
    else if (id == "dragon_face_left")
        return character_face.copy(0, 1200, 79, 95);

    // Remaining Balls
    else if (id == "0")
        return fonts.copy(remainingBallNumber);
    else if (id == "1")
        return fonts.copy(moveBy(remainingBallNumber, 1, 0, 30 * 1));
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
    return (fonts.copy(5, 296, 47, 40));

    else if (id == "cannon")
        return sprites.copy(384, 327, 50, 80);
    else if (id == "cannon_without_ball")
    return sprites.copy(384, 327, 50, 50);
    else if (id == "cannon_fired")
    return sprites.copy(459, 327, 50, 100);

    else if (id == "peg_blue_hit")
        return peggles.copy(pegle);
    else if (id == "peg_red_hit")
        return peggles.copy(moveBy(pegle, 1, 0, 200));
    else if (id == "peg_green_hit")
        return peggles.copy(QRect(405, 0, 200, 200));
    else if (id == "peg_blue")
        return peggles.copy(moveBy(pegle, 0, 1, 0, 200));
    else if (id == "peg_red")
        return peggles.copy(moveBy(pegle, 1, 1, 200, 200));
    else if (id == "peg_green")
        return peggles.copy(QRect(405,204,200,200));

    else if (id == "band")
        return sprites.copy(91, 528, 15, 422);
    else if (id == "molt")
        return sprites.copy(535, 355, 50, 16);
    else if (id == "molt-x2")
        return sprites.copy(673, 324, 25, 20);
    else if (id == "molt-x3")
        return sprites.copy(673, 344, 25, 20);
    else if (id == "molt-x5")
        return sprites.copy(673, 364, 25, 20);
    else if (id == "molt-x10")
        return sprites.copy(673, 384, 25, 20);

    else if (id == "0-score")
        return fonts.copy(794, 327, 22, 26);
    else if (id == "1-score")
    return fonts.copy(816, 327, 22, 26);
    else if (id == "2-score")
    return fonts.copy(838, 327, 22, 26);
    else if (id == "3-score")
    return fonts.copy(860, 327, 22, 26);
    else if (id == "4-score")
    return fonts.copy(882, 327, 22, 26);
    else if (id == "5-score")
    return fonts.copy(904, 327, 22, 26);
    else if (id == "6-score")
    return fonts.copy(926, 327, 22, 26);
    else if (id == "7-score")
    return fonts.copy(948, 327, 22, 26);
    else if (id == "8-score")
    return fonts.copy(970, 327, 22, 26);
    else if (id == "9-score")
    return fonts.copy(992, 327, 22, 26);

    else if (id == "paused")
        return sprites.copy(700, 1258, 230, 59);
    else if (id == "unicorn")
        return loadTexture(":/sprites/scaricati/Peggle2PegglePS3LeftoverGraphic5.png").copy(520, 660, 60, 86);
    else
    {
        std::cerr << "Cannot find sprite texture with id \"" << id << "\"\n";
        return QPixmap();
    }
}

QPixmap Sprites::getNumber(int n, int fill)
{
    std::string text = std::to_string(n);

    // fill with 0s on the left
    if (fill)
        while (text.size() != fill)
            text = '0' + text;

    // create collage texture
    QPixmap collage(8 * int(text.size()), 8);
    QPainter painter(&collage);

    // add numbers
    for (int i = 0; i < text.size(); i++)
        painter.drawPixmap(8 * i, 0, Sprites::instance()->get(std::string("number-") + text[i]));

    // end painting (necessary for setMask)
    painter.end();

    // make background transparent
    collage.setMask(collage.createMaskFromColor(QColor(147, 187, 236)));

    return collage;
}

QPixmap Sprites::getString(std::string text, int fill)
{
    // fill with 0s on the left
    if (fill)
        while (text.size() != fill)
            text = ' ' + text;

    // create collage texture
    QPixmap collage(8 * int(text.size()), 8);
    QPainter painter(&collage);

    // add letters
    for (int i = 0; i < text.size(); i++)
        if (text[i] != ' ')
            painter.drawPixmap(8 * i, 0, Sprites::instance()->get(std::string("char-") + text[i]));

    // end painting (necessary for setMask)
    painter.end();

    // make background transparent
    collage.setMask(collage.createMaskFromColor(QColor(147, 187, 236)));

    return collage;
}

// score composite from sprite single score pieces
QPixmap Sprites::getScore(int s)
{
    bool thousands = s >= 1000;
    int base_score = s / (thousands ? 100 : 10);

    QPixmap collage(16, 8);
    QPainter painter(&collage);

    // add 0s
    

    // add base number
    //if (base_score == 10)
        painter.drawPixmap(0, 0, fonts.copy(score));
   /* else if (base_score == 20)
        painter.drawPixmap(0, 0, _stage_tiles.copy(moveBy(score, 1, 0, 8, 8)));
    else if (base_score == 40)
        painter.drawPixmap(0, 0, _stage_tiles.copy(moveBy(score, 2, 0, 8, 8)));
    else if (base_score == 50)
        painter.drawPixmap(0, 0, _stage_tiles.copy(moveBy(score, 3, 0, 8, 8)));
    else if (base_score == 80)
        painter.drawPixmap(0, 0, _stage_tiles.copy(moveBy(score, 4, 0, 8, 8)));
    else // 1 up
        painter.drawPixmap(0, 0, _stage_tiles.copy(QRect(718, 185, 16, 8)));
        */
    // end painting (necessary for setMask)
    painter.end();

    // make background transparent
    collage.setMask(collage.createMaskFromColor(QColor(147, 187, 236)));

    return collage;
}


// score 325,794,23,30