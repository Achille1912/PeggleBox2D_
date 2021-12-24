#include "Button.h"
#include "Game.h"
#include "Sounds.h"
#include "Sprites.h"

#include <QKeyEvent>

using namespace PGG;



Button::Button(QRect pos, ButtonType bt) : QLabel(0)
{
_buttonType = bt;
	connect(this, SIGNAL(clicked()), this, SLOT(slotLabelClicked()), Qt::QueuedConnection);

	
	if (_buttonType == ButtonType::SINGLE) {
		setPixmap(QPixmap(Sprites::instance()->get("single_button")));
	}else if (_buttonType == ButtonType::DUEL) {
		setPixmap(QPixmap(Sprites::instance()->get("duel_button")));
	}
	else if (_buttonType == ButtonType::CPU) {
		setPixmap(QPixmap(Sprites::instance()->get("cpu_button")));
	}
	else if (_buttonType == ButtonType::UNICORN) {
		setPixmap(QPixmap(Sprites::instance()->get("unicorn_button")));
	}
	else if (_buttonType == ButtonType::BEAVER) {
		setPixmap(QPixmap(Sprites::instance()->get("beaver_button")));
	}
	else if (_buttonType == ButtonType::CAT) {
		setPixmap(QPixmap(Sprites::instance()->get("cat_button")));
	}
	else if (_buttonType == ButtonType::ALIEN) {
		setPixmap(QPixmap(Sprites::instance()->get("alien_button")));
	}
	else if (_buttonType == ButtonType::CRAB) {
		setPixmap(QPixmap(Sprites::instance()->get("crab_button")));
	}
	else if (_buttonType == ButtonType::PUMPKIN) {
		setPixmap(QPixmap(Sprites::instance()->get("pumpkin_button")));
	}
	else if (_buttonType == ButtonType::FLOWER) {
		setPixmap(QPixmap(Sprites::instance()->get("flower_button")));
	}
	else if (_buttonType == ButtonType::DRAGON) {
		setPixmap(QPixmap(Sprites::instance()->get("dragon_button")));
	}
	else if (_buttonType == ButtonType::OWL) {
		setPixmap(QPixmap(Sprites::instance()->get("owl_button")));
	}
	setGeometry(pos);
	setStyleSheet("background-color: transparent;");
	Game::instance()->world()->addWidget(this);
	
}


 



 void Button::slotLabelClicked()   // Implementation of Slot which will consume signal
 {
	 if (_buttonType == ButtonType::SINGLE) {
		 Game::instance()->select_single_character();
	 }
	 else if (_buttonType == ButtonType::DUEL) {

		 printf("DUEL");
	 }
	 else if (_buttonType == ButtonType::CPU) {
		 printf("CPU");
	 }
	 else if (_buttonType == ButtonType::ALIEN) {
		 //setWindowOpacity(0.5);
		 printf("Alien");
	 }
	 else if (_buttonType == ButtonType::UNICORN) {
		 //setWindowOpacity(0.5);
		 printf("Unicorn");
	 }

	 
 }

 void Button::mousePressEvent(QMouseEvent* e) {
	 emit clicked();
 }

