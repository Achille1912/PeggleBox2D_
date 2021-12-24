#include "Button.h"
#include "Game.h"
#include "Sounds.h"
#include "Sprites.h"

#include <QKeyEvent>

using namespace PGG;



Button::Button(QRect pos, ButtonType bt) : QLabel(0)
{

	connect(this, SIGNAL(clicked()), this, SLOT(slotLabelClicked()), Qt::QueuedConnection);

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


 



 void Button::slotLabelClicked()   // Implementation of Slot which will consume signal
 {
	 if (_buttonType == ButtonType::SINGLE) {
		 Game::instance()->play();
	 }
	 else if (_buttonType == ButtonType::DUEL) {

		 printf("DUEL");
	 }
	 else if (_buttonType == ButtonType::CPU) {
		 printf("CPU");
	 }
 }

 void Button::mousePressEvent(QMouseEvent* e) {
	 emit clicked();
 }