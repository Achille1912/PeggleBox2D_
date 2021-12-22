#include "Button.h"
#include "Game.h"
#include "Sounds.h"
#include "Sprites.h"

#include <QKeyEvent>

using namespace PGG;



Button::Button(QRect pos, ButtonType bt) : QLabel(0)
{
	_buttonType = bt;
	if (_buttonType == ButtonType::SINGLE) {
		setPixmap(QPixmap(Sprites::instance()->get("single_button")));
	}else if (_buttonType == ButtonType::DUEL) {
		setPixmap(QPixmap(Sprites::instance()->get("duel_button")));
	}
	else if (_buttonType == ButtonType::CPU) {
		setPixmap(QPixmap(Sprites::instance()->get("cpu_button")));
	}
	setGeometry(pos);
	setStyleSheet("background-color: transparent;");
	Game::instance()->world()->addWidget(this);
}

bool Button::eventFilter(QObject* object, QEvent* event)
{
	printf("Catturato");
	if (object == Game::instance() && event->type() == QEvent::GraphicsSceneMousePress) {
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
		printf("Catturato");
		return true;
	}
	return false;
}

 void Button::mousePressEvent(QMouseEvent* e) {
	 printf("Ciao");
	 if (_buttonType == ButtonType::SINGLE) {
		 printf("Ciao");
	 }
	 else if (_buttonType == ButtonType::DUEL) {
		 Game::instance()->play();
	 }
	 else if (_buttonType == ButtonType::CPU) {
		 printf("Ciaoo");
	 }
	 
}