#include "CharacterHandler.h"
#include "Game.h"
#include "Sprites.h"



using namespace PGG;

void CharacterHandler::initButton(ButtonType t, Button* b)
{
	switch (t) {
	case ButtonType::CLICK_TO_PLAY:
		b->setPixmap(QPixmap(Sprites::instance()->get("clickToPlay")));
		break;
	case ButtonType::AI:
		b->setPixmap(QPixmap(Sprites::instance()->get("aiButton")));
		
		break;
	case ButtonType::MENU_BUTTON:
		b->setPixmap(QPixmap(Sprites::instance()->get("menuButton")));
		
		break;
	case ButtonType::SINGLE:

		b->setPixmap(QPixmap(Sprites::instance()->get("single_button")));
		break;
	case ButtonType::DUEL:
		b->setPixmap(QPixmap(Sprites::instance()->get("duel_button")));
		break;
	case ButtonType::CPU:
		b->setPixmap(QPixmap(Sprites::instance()->get("cpu_button")));
		break;
	case ButtonType::MAIN_MENU:
		b->setPixmap(QPixmap(Sprites::instance()->get("main_menu_button")));
		break;
	case ButtonType::RETURN:
		b->setPixmap(QPixmap(Sprites::instance()->get("return_button")));
		break;
	case ButtonType::TOTAL_SCORE:
		b->setPixmap(QPixmap(Sprites::instance()->get("total_score")));
		break;
	case ButtonType::FIRST_PLAYER_SCORE:
		b->setPixmap(QPixmap(Sprites::instance()->get("first_player_score")));
		break;
	case ButtonType::SECOND_PLAYER_SCORE:
		b->setPixmap(QPixmap(Sprites::instance()->get("second_player_score")));
		break;
	case ButtonType::FIRST_PLAYER:
		b->setPixmap(QPixmap(Sprites::instance()->get("first_player")));
		break;
	case ButtonType::SECOND_PLAYER:
		b->setPixmap(QPixmap(Sprites::instance()->get("second_player")));
		break;
	case ButtonType::THE_WINNER_IS:
		b->setPixmap(QPixmap(Sprites::instance()->get("the_winner_is")));
		break;
	case ButtonType::NORMAL_MODE:
		b->setPixmap(QPixmap(Sprites::instance()->get("normal_mode_button")));
		break;
	case ButtonType::HARD_MODE:
		b->setPixmap(QPixmap(Sprites::instance()->get("hard_mode_button")));
		break;
	case ButtonType::CONTINUE:
		b->setPixmap(QPixmap(Sprites::instance()->get("continue_button")));
		break;
	case ButtonType::NEXT:
		b->setPixmap(QPixmap(Sprites::instance()->get("next_button")));
		break;
	case ButtonType::UNICORN:
		b->setObjectName("Unicorn");
		b->setPixmap(QPixmap(Sprites::instance()->get("unicorn_button")));
		break;
	case ButtonType::BEAVER:
		b->setPixmap(QPixmap(Sprites::instance()->get("beaver_button")));
		break;
	case ButtonType::CAT:
		b->setPixmap(QPixmap(Sprites::instance()->get("cat_button")));
		break;
	case ButtonType::ALIEN:
		b->setObjectName("Alien");
		b->setPixmap(QPixmap(Sprites::instance()->get("alien_button")));
		break;
	case ButtonType::CRAB:
		b->setPixmap(QPixmap(Sprites::instance()->get("crab_button")));
		break;
	case ButtonType::PUMPKIN:
		b->setPixmap(QPixmap(Sprites::instance()->get("pumpkin_button")));
		break;
	case ButtonType::FLOWER:
		b->setPixmap(QPixmap(Sprites::instance()->get("flower_button")));
		break;
	case ButtonType::DRAGON:
		b->setPixmap(QPixmap(Sprites::instance()->get("dragon_button")));
		break;
	case ButtonType::OWL:
		b->setPixmap(QPixmap(Sprites::instance()->get("owl_button")));
		break;
	case ButtonType::RABBIT:
		b->setPixmap(QPixmap(Sprites::instance()->get("rabbit_button")));
		break;
	case ButtonType::PLAY_NOW:
		b->setPixmap(QPixmap(Sprites::instance()->get("play_now_button")));
		break;
	}
}


void CharacterHandler::clickButton(ButtonType t, Button* b)
{
	switch (t) {
	case ButtonType::CLICK_TO_PLAY:
		Game::instance()->setState(GameState::MODE);
		Game::instance()->getWindow()->load("mode");
		break;
	case ButtonType::AI:
		
		if (!Game::instance()->getMasterPegGraphic()->getFire()) {
			Game::instance()->uni = false;
			Game::instance()->simulationScore.clear();
			Game::instance()->setAlpha(89);
			Game::instance()->fire(Game::instance()->getAlpha());
			Game::instance()->setAiCheck(false);
		}
		break;
	case ButtonType::MENU_BUTTON:
		Game::instance()->_gameSounds->get("theme")->stop();
		Game::instance()->init();
		break;
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
		Game::instance()->deselectButtons();
		b->setWindowOpacity(0.5);
		Game::instance()->setHardMode(false);
		break;

	case ButtonType::HARD_MODE:
		Game::instance()->deselectButtons();
		b->setWindowOpacity(0.5);
		Game::instance()->setHardMode(true);
		break;

	case ButtonType::UNICORN:
		Game::instance()->deselectButtons();

		b->setWindowOpacity(0.5);
		Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			Game::instance()->setSecondCharacter(Character::UNICORN) :
			Game::instance()->setCharacter(Character::UNICORN);
		break;

	case ButtonType::BEAVER:

		Game::instance()->deselectButtons();

		Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			Game::instance()->setSecondCharacter(Character::BEAVER) :
			Game::instance()->setCharacter(Character::BEAVER);
		b->setWindowOpacity(0.5);
		break;

	case ButtonType::CAT:
		Game::instance()->deselectButtons();

		Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			Game::instance()->setSecondCharacter(Character::CAT) :
			Game::instance()->setCharacter(Character::CAT);
		b->setWindowOpacity(0.5);
		break;

	case ButtonType::ALIEN:
		Game::instance()->deselectButtons();

		Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			Game::instance()->setSecondCharacter(Character::ALIEN) :
			Game::instance()->setCharacter(Character::ALIEN);
		b->setWindowOpacity(0.5);
		break;

	case ButtonType::CRAB:
		Game::instance()->deselectButtons();

		Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			Game::instance()->setSecondCharacter(Character::CRAB) :
			Game::instance()->setCharacter(Character::CRAB);
		b->setWindowOpacity(0.5);
		break;

	case ButtonType::PUMPKIN:
		Game::instance()->deselectButtons();

		Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			Game::instance()->setSecondCharacter(Character::PUMPKIN) :
			Game::instance()->setCharacter(Character::PUMPKIN);
		b->setWindowOpacity(0.5);
		break;

	case ButtonType::FLOWER:
		Game::instance()->deselectButtons();

		Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			Game::instance()->setSecondCharacter(Character::FLOWER) :
			Game::instance()->setCharacter(Character::FLOWER);
		b->setWindowOpacity(0.5);
		break;

	case ButtonType::DRAGON:
		Game::instance()->deselectButtons();

		Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			Game::instance()->setSecondCharacter(Character::DRAGON) :
			Game::instance()->setCharacter(Character::DRAGON);
		b->setWindowOpacity(0.5);
		break;

	case ButtonType::OWL:
		Game::instance()->deselectButtons();

		Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			Game::instance()->setSecondCharacter(Character::OWL) :
			Game::instance()->setCharacter(Character::OWL);
		b->setWindowOpacity(0.5);
		break;

	case ButtonType::RABBIT:
		Game::instance()->deselectButtons();

		Game::instance()->getState() == GameState::SELECT_SECOND_CHARACTER ?
			Game::instance()->setSecondCharacter(Character::RABBIT) :
			Game::instance()->setCharacter(Character::RABBIT);
		b->setWindowOpacity(0.5);
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


void CharacterHandler::swapFace(QPointF curr, QPointF mid) {
	switch (Game::instance()->getTurn() ? Game::instance()->getCharacter() : Game::instance()->getSecondCharacter()) {
	case Character::UNICORN:
		if (curr.x() < mid.x())
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("unicorn_face_left")));
		else
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("unicorn_face_right")));
		break;
	case Character::BEAVER:
		if (curr.x() < mid.x())
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("beaver_face_left")));
		else
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("beaver_face_right")));
		break;
	case Character::CRAB:
		if (curr.x() < mid.x())
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("crab_face_left")));
		else
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("crab_face_right")));
		break;
	case Character::FLOWER:
		if (curr.x() < mid.x())
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("flower_face_left")));
		else
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("flower_face_right")));
		break;
	case Character::PUMPKIN:
		if (curr.x() < mid.x())
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("pumpkin_face_left")));
		else
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("pumpkin_face_right")));
		break;
	case Character::ALIEN:
		if (curr.x() < mid.x())
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("alien_face_left")));
		else
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("alien_face_right")));
		break;
	case Character::OWL:
		if (curr.x() < mid.x())
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("owl_face_left")));
		else
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("owl_face_right")));
		break;
	case Character::DRAGON:
		if (curr.x() < mid.x())
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("dragon_face_left")));
		else
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("dragon_face_right")));
		break;
	case Character::RABBIT:
		if (curr.x() < mid.x())
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("rabbit_face_left")));
		else
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("rabbit_face_right")));
		break;
	}
}


void CharacterHandler::changeTurnFace() {
	if (Game::instance()->getTurn() == true) 
		Game::instance()->setTurn(false);
	else
		Game::instance()->setTurn(true);


	switch (Game::instance()->getTurn()? Game::instance()->getCharacter():Game::instance()->getSecondCharacter()) {
		case Character::UNICORN:
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("unicorn_face_right")));
			break;
		case Character::BEAVER:
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("beaver_face_right")));
			break;
		case Character::CRAB:
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("crab_face_right")));
			break;
		case Character::FLOWER:
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("flower_face_right")));
			break;
		case Character::PUMPKIN:
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("pumpkin_face_right")));
			break;
		case Character::ALIEN:
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("alien_face_right")));
			break;
		case Character::OWL:
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("owl_face_right")));
			break;
		case Character::DRAGON:
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("dragon_face_right")));
			break;
		case Character::RABBIT:
			Game::instance()->getCharacterFace()->setPixmap(QPixmap(Sprites::instance()->get("rabbit_face_right")));
			break;
	}

}
