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
	else if (_buttonType == ButtonType::MAIN_MENU) {
		setPixmap(QPixmap(Sprites::instance()->get("main_menu_button")));
	}
	else if (_buttonType == ButtonType::RETURN) {
		setPixmap(QPixmap(Sprites::instance()->get("return_button")));
	}
	else if (_buttonType == ButtonType::NORMAL_MODE) {
		setPixmap(QPixmap(Sprites::instance()->get("normal_mode_button")));
	}
	else if (_buttonType == ButtonType::HARD_MODE) {
		setPixmap(QPixmap(Sprites::instance()->get("hard_mode_button")));
	}
	else if (_buttonType == ButtonType::CONTINUE) {
		setPixmap(QPixmap(Sprites::instance()->get("continue_button")));
	}
	else if (_buttonType == ButtonType::NEXT) {
		setPixmap(QPixmap(Sprites::instance()->get("next_button")));
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
	else if (_buttonType == ButtonType::PLAY_NOW) {
		setPixmap(QPixmap(Sprites::instance()->get("play_now_button")));
	}
	setGeometry(pos);
	setStyleSheet("background-color: transparent;");
	Game::instance()->world()->addWidget(this);
	
}


 



 void Button::slotLabelClicked()   
 {
	 if (_buttonType == ButtonType::SINGLE) {
		 Game::instance()->setGameMode(GameMode::SINGLE);
		 Game::instance()->getWindow()->load("select_single_character");
	 }
	 else if (_buttonType == ButtonType::DUEL) {
		 Game::instance()->setGameMode(GameMode::DUEL);
		 Game::instance()->getWindow()->load("select_first_character");
		 
	 }
	 else if (_buttonType == ButtonType::CPU) {
		 Game::instance()->setGameMode(GameMode::CPU);
		 Game::instance()->getWindow()->load("select_difficulty");
	 }
	 else if (_buttonType == ButtonType::MAIN_MENU) {
		 Game::instance()->menuDuel();
	 }
	 else if (_buttonType == ButtonType::NEXT) {
		 if(Game::instance()->getCharacter()!=Character::NONE)
			 Game::instance()->getWindow()->load("select_second_character");
	 }
	 else if (_buttonType == ButtonType::CONTINUE) {
		 Game::instance()->getWindow()->load("select_first_character");
	 }
	 else if (_buttonType == ButtonType::NORMAL_MODE) {
		 setWindowOpacity(0.5);
		 Game::instance()->hardMode=false;
	 }
	 else if (_buttonType == ButtonType::HARD_MODE) {
		 setWindowOpacity(0.5);
		 Game::instance()->hardMode = true;
	 }

	 else if (_buttonType == ButtonType::UNICORN) {
		 for (auto el : (Game::instance()->world()->children())) {
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 }
		 setWindowOpacity(0.5);
		 Game::instance()->getState()==GameState::SELECT_SECOND_CHARACTER? 
			 Game::instance()->setSecondCharacter(Character::UNICORN):
			 Game::instance()->setCharacter(Character::UNICORN);
	 }
	 else if (_buttonType == ButtonType::BEAVER) {
		 for (auto el : (Game::instance()->world()->children())) {
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 }
			 
		 
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::BEAVER) :
			 Game::instance()->setCharacter(Character::BEAVER);
		 setWindowOpacity(0.5);

	 }
	 else if (_buttonType == ButtonType::CAT) {
		 for (auto el : (Game::instance()->world()->children())) {
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 }
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::CAT) :
			 Game::instance()->setCharacter(Character::CAT);
		 setWindowOpacity(0.5);
	 }
	 else if (_buttonType == ButtonType::ALIEN) {
		 for (auto el : (Game::instance()->world()->children())) {
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 }
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::ALIEN) :
			 Game::instance()->setCharacter(Character::ALIEN);
		 setWindowOpacity(0.5);
	 }
	 else if (_buttonType == ButtonType::CRAB) {
		 for (auto el : (Game::instance()->world()->children())) {
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 }
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::CRAB) :
			 Game::instance()->setCharacter(Character::CRAB);
		 setWindowOpacity(0.5);
	 }
	 else if (_buttonType == ButtonType::PUMPKIN) {
		 for (auto el : (Game::instance()->world()->children())) {
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 }
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::PUMPKIN) :
			 Game::instance()->setCharacter(Character::PUMPKIN);		 
		 setWindowOpacity(0.5);
	 }
	 else if (_buttonType == ButtonType::FLOWER) {
		 for (auto el : (Game::instance()->world()->children())) {
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 }
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::FLOWER) :
			 Game::instance()->setCharacter(Character::FLOWER);
		 setWindowOpacity(0.5);
	 }
	 else if (_buttonType == ButtonType::DRAGON) {
		 for (auto el : (Game::instance()->world()->children())) {
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 }
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::DRAGON) :
			 Game::instance()->setCharacter(Character::DRAGON);
		 setWindowOpacity(0.5);
	 }
	 else if (_buttonType == ButtonType::OWL) {
		 for (auto el : (Game::instance()->world()->children())) {
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 }
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::OWL) :
			 Game::instance()->setCharacter(Character::OWL);
		 setWindowOpacity(0.5);
	 }
	 else if (_buttonType == ButtonType::PLAY_NOW) {
		 if (Game::instance()->getState() != GameState::SELECT_SECOND_CHARACTER) {
			 if (Game::instance()->getCharacter() != Character::NONE)
				 Game::instance()->play();
		 }
		 else {
			 if (Game::instance()->getSecondCharacter() != Character::NONE)
				 Game::instance()->play();
		 }
	 }
	 else if (_buttonType == ButtonType::NEXT) {
	 if (Game::instance()->getCharacter() != Character::NONE)
		 Game::instance()->play();
	 }
	 else if (_buttonType == ButtonType::RETURN) {
		 Game::instance()->init();
	 }
 }

 void Button::mousePressEvent(QMouseEvent* e) {
	 QLabel::mousePressEvent(e);
	 emit clicked();
 }
