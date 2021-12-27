#pragma once

#include <QPoint>
#include <QLabel>
#include <QGraphicsPixmapItem>

namespace PGG
{
    class Button;
    enum class ButtonType
    {
        SINGLE,
        DUEL,
        CPU,
        MAIN_MENU,
        PLAY_NOW,

        UNICORN,
        BEAVER,
        CAT,
        ALIEN,
        CRAB,
        PUMPKIN,
        FLOWER,
        DRAGON,
        OWL
    };
}

class PGG::Button : public QLabel
{
    Q_OBJECT
private:

    
public:
    ButtonType _buttonType;
    Button(QRect pos, ButtonType bt);

    
    // override
    virtual void mousePressEvent(QMouseEvent* e) override;
 
signals:
    void clicked();
    
public slots:
    void slotLabelClicked();

};
