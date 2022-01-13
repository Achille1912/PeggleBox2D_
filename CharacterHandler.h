#pragma once

#include "Button.h"
#include "MasterPeg.h"
#include <QString>


namespace PGG
{
	class CharacterHandler;
}


class PGG::CharacterHandler
{
public:

	void initButton(ButtonType t, Button* b);
	void clickButton(ButtonType t, Button* b);

	void swapFace(QPointF curr, QPointF mid);

	void changeTurnFace();

};