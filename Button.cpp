#include "Button.h"
#include "Game.h"
#include "Sounds.h"
#include "Sprites.h"
#include <QMediaPlayer>


using namespace PGG;


Button::Button(QRect pos, ButtonType bt) : QLabel(0)
{
	_buttonType = bt;
	connect(this, SIGNAL(clicked()), this, SLOT(slotLabelClicked()), Qt::QueuedConnection);
	Game::instance()->getCharacterHandler()->initButton(_buttonType, this);

	setGeometry(pos);
	setStyleSheet("background-color: transparent;");
	Game::instance()->world()->addWidget(this);
	
}


 void Button::slotLabelClicked()   
 {
	 Game::instance()->_gameSounds->get("button")->play();
	 Game::instance()->getCharacterHandler()->clickButton(_buttonType, this);
 }

 void Button::mousePressEvent(QMouseEvent* e) {
	 if (Game::instance()->getState() == GameState::PLAYING)
		 if (!Game::instance()->getMasterPegGraphic()->getFire())
			 Game::instance()->setAiCheck(true);
	 QLabel::mousePressEvent(e);
	 emit clicked();
 }
