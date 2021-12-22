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
    };
}

class PGG::Button : public QLabel
{
private:

    
public:
    ButtonType _buttonType;
    Button(QRect pos, ButtonType bt);

    
    // override
    virtual void mousePressEvent(QMouseEvent* e) override;
    bool eventFilter(QObject* object, QEvent* event) override;

};
