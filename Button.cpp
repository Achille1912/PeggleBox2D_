#include "Button.h"
#include "Game.h"

#include "Sprites.h"
#include <QMediaPlayer>
#include <QKeyEvent>

using namespace PGG;


Button::Button(QRect pos, ButtonType bt) : QLabel(0)
{
	_buttonType = bt;
	connect(this, SIGNAL(clicked()), this, SLOT(slotLabelClicked()), Qt::QueuedConnection);
	
	switch (_buttonType) {
	case ButtonType::SINGLE:
		setPixmap(QPixmap(Sprites::instance()->get("single_button")));
		break;
	case ButtonType::DUEL:
		setPixmap(QPixmap(Sprites::instance()->get("duel_button")));
		break;
	case ButtonType::CPU:
		setPixmap(QPixmap(Sprites::instance()->get("cpu_button")));
		break;
	case ButtonType::MAIN_MENU:
		setPixmap(QPixmap(Sprites::instance()->get("main_menu_button")));
		break;
	case ButtonType::RETURN:
		setPixmap(QPixmap(Sprites::instance()->get("return_button")));
		break;
	case ButtonType::TOTAL_SCORE:
		setPixmap(QPixmap(Sprites::instance()->get("total_score")));
		break;
	case ButtonType::FIRST_PLAYER_SCORE:
		setPixmap(QPixmap(Sprites::instance()->get("first_player_score")));
		break;
	case ButtonType::SECOND_PLAYER_SCORE:
		setPixmap(QPixmap(Sprites::instance()->get("second_player_score")));
		break;
	case ButtonType::FIRST_PLAYER:
		setPixmap(QPixmap(Sprites::instance()->get("first_player")));
		break;
	case ButtonType::SECOND_PLAYER:
		setPixmap(QPixmap(Sprites::instance()->get("second_player")));
		break;
	case ButtonType::THE_WINNER_IS:
		setPixmap(QPixmap(Sprites::instance()->get("the_winner_is")));
		break;
	case ButtonType::NORMAL_MODE:
		setPixmap(QPixmap(Sprites::instance()->get("normal_mode_button")));
		break;
	case ButtonType::HARD_MODE:
		setPixmap(QPixmap(Sprites::instance()->get("hard_mode_button")));
		break;
	case ButtonType::CONTINUE:
		setPixmap(QPixmap(Sprites::instance()->get("continue_button")));
		break;
	case ButtonType::NEXT:
		setPixmap(QPixmap(Sprites::instance()->get("next_button")));
		break;
	case ButtonType::UNICORN:
		setPixmap(QPixmap(Sprites::instance()->get("unicorn_button")));
		break;
	case ButtonType::BEAVER:
		setPixmap(QPixmap(Sprites::instance()->get("beaver_button")));
		break;
	case ButtonType::CAT:
		setPixmap(QPixmap(Sprites::instance()->get("cat_button")));
		break;
	case ButtonType::ALIEN:
		setObjectName("Alien");
		setPixmap(QPixmap(Sprites::instance()->get("alien_button")));
		break;
	case ButtonType::CRAB:
		setPixmap(QPixmap(Sprites::instance()->get("crab_button")));
		break;
	case ButtonType::PUMPKIN:
		setPixmap(QPixmap(Sprites::instance()->get("pumpkin_button")));
		break;
	case ButtonType::FLOWER:
		setPixmap(QPixmap(Sprites::instance()->get("flower_button")));
		break;
	case ButtonType::DRAGON:
		setPixmap(QPixmap(Sprites::instance()->get("dragon_button")));
		break;
	case ButtonType::OWL:
		setPixmap(QPixmap(Sprites::instance()->get("owl_button")));
		break;
	case ButtonType::RABBIT:
		setPixmap(QPixmap(Sprites::instance()->get("rabbit_button")));
		break;
	case ButtonType::PLAY_NOW:
		setPixmap(QPixmap(Sprites::instance()->get("play_now_button")));
		break;
	}

	
	setGeometry(pos);
	setStyleSheet("background-color: transparent;");
	Game::instance()->world()->addWidget(this);
	
}


 void Button::slotLabelClicked()   
 {
	 QMediaPlayer* player = new QMediaPlayer;
	 player->setVolume(50);
	 if (Game::instance()->me)
		 player->setMedia(QUrl::fromLocalFile("C:/Users/achil/Desktop/peggle2D/PeggleBox2D_/sounds/buttonclick.wav"));
	 else
		 player->setMedia(QUrl::fromLocalFile(":/sounds/buttonclick.wav"));

	 player->play();
	 switch (_buttonType) {
	 case ButtonType::SINGLE:
		 Game::instance()->setGameMode(GameMode::SINGLE);
		 Game::instance()->getWindow()->load("select_single_character");
		 break;

	 case ButtonType::DUEL:
		 Game::instance()->setGameMode(GameMode::DUEL);
		 Game::instance()->getWindow()->load("select_first_character");
		 break;

	 case ButtonType::CPU:
		 Game::instance()->setGameMode(GameMode::CPU);
		 Game::instance()->getWindow()->load("select_difficulty");
		 break;

	 case ButtonType::MAIN_MENU:
		 Game::instance()->init();
		 break;

	 case ButtonType::NEXT:
		 if (Game::instance()->getCharacter() != Character::NONE)
			 Game::instance()->getWindow()->load("select_second_character");
		 break;

	 case ButtonType::CONTINUE:
		 Game::instance()->getWindow()->load("select_first_character");
		 break;

	 case ButtonType::NORMAL_MODE:
		 setWindowOpacity(0.5);
		 Game::instance()->setHardMode(false);
		 break;

	 case ButtonType::HARD_MODE:
		 setWindowOpacity(0.5);
		 Game::instance()->setHardMode(true);
		 break;

	 case ButtonType::UNICORN:
		 for (auto el : (Game::instance()->world()->children())) 
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);

		 setWindowOpacity(0.5);
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::UNICORN) :
			 Game::instance()->setCharacter(Character::UNICORN);
		 break;

	 case ButtonType::BEAVER:
		 
		 Game::instance()->deselectButtons();
		 
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::BEAVER) :
			 Game::instance()->setCharacter(Character::BEAVER);
		 setWindowOpacity(0.5);
		 break;

	 case ButtonType::CAT:
		 for (auto el : (Game::instance()->world()->children())) 
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::CAT) :
			 Game::instance()->setCharacter(Character::CAT);
		 setWindowOpacity(0.5);
		 break;

	 case ButtonType::ALIEN:
		 for (auto el : (Game::instance()->world()->children())) 
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::ALIEN) :
			 Game::instance()->setCharacter(Character::ALIEN);
		 setWindowOpacity(0.5);
		 break;

	 case ButtonType::CRAB:
		 for (auto el : (Game::instance()->world()->children())) 
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::CRAB) :
			 Game::instance()->setCharacter(Character::CRAB);
		 setWindowOpacity(0.5);
		 break;

	 case ButtonType::PUMPKIN:
		 for (auto el : (Game::instance()->world()->children())) 
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::PUMPKIN) :
			 Game::instance()->setCharacter(Character::PUMPKIN);
		 setWindowOpacity(0.5);
		 break;

	 case ButtonType::FLOWER:
		 for (auto el : (Game::instance()->world()->children())) 
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::FLOWER) :
			 Game::instance()->setCharacter(Character::FLOWER);
		 setWindowOpacity(0.5);
		 break;

	 case ButtonType::DRAGON:
		 for (auto el : (Game::instance()->world()->children())) 
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::DRAGON) :
			 Game::instance()->setCharacter(Character::DRAGON);
		 setWindowOpacity(0.5);
		 break;

	 case ButtonType::OWL:
		 for (auto el : (Game::instance()->world()->children())) 
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::OWL) :
			 Game::instance()->setCharacter(Character::OWL);
		 setWindowOpacity(0.5);
		 break;

	 case ButtonType::RABBIT:
		 for (auto el : (Game::instance()->world()->children())) 
			 if (dynamic_cast<Button*>(el))
				 (dynamic_cast<Button*>(el))->setWindowOpacity(1);
		 
		 Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			 Game::instance()->setSecondCharacter(Character::RABBIT) :
			 Game::instance()->setCharacter(Character::RABBIT);
		 setWindowOpacity(0.5);
		 break;

	 case ButtonType::PLAY_NOW:
		 if (Game::instance()->getState() != GameState::SELECT_SECOND_CHARACTER) {
			 if (Game::instance()->getCharacter() != Character::NONE)
				 Game::instance()->play();
		 }
		 else {
			if (Game::instance()->getSecondCharacter() != Character::NONE)
				Game::instance()->play();
			
		 }
		 break;

	 case ButtonType::RETURN:
		 Game::instance()->reset();
		 Game::instance()->init();
		 break;
	 }
 }

 void Button::mousePressEvent(QMouseEvent* e) {
	 QLabel::mousePressEvent(e);
	 emit clicked();
 }
