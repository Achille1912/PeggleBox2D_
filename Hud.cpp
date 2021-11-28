#include "Hud.h"
#include "Game.h"
#include "Sprites.h"
#include "Sounds.h"
#include <QPainter>

using namespace PGG;

HUD::HUD(int w, int h, QWidget* parent) : QWidget(parent)
{
	//_background = Sprites::instance()->get("hud");

	resize(w, h);

	reset();
}

void HUD::start()
{
	_time = 400;
}

void HUD::reset()
{
	_score = 0;
	
	_time = -1;
	_fps = 0;
	_last_digit = 0;
}

void HUD::togglePause()
{

}

void HUD::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);

	painter.setBackgroundMode(Qt::TransparentMode);
	painter.setWindow(0, +2, 800 * 16, 800 * 15);
	
	


	for (auto& s : _score_items)
		s.draw(&painter);
}




void HUD::addScore(int s, QPointF pos)
{
	this->_score += s;
	if (pos != QPointF(-1, -1))
		_score_items.push_back(ScoreItem(s, pos));
	update();
}


void HUD::advance()
{
	for (auto& s : _score_items)
		s++;

	

	update();
}

ScoreItem::ScoreItem(int score, QPointF pos)
{
	_expired = false;
	_origin = Game::instance()->mapFromScene(pos);
	_origin.setX(_origin.x() / Game::instance()->transform().m11());
	_origin.setY(_origin.y() / Game::instance()->transform().m22());

	
	_age = 0;
	_texture = Sprites::instance()->getScore(score);
}

void ScoreItem::operator++(int)
{
	if (!_expired)
		_expired = ++_age == 120;
}

void ScoreItem::draw(QPainter* painter)
{
	if (!_expired)
		painter->drawPixmap(_origin + QPointF(0, -_age * 0.5f), _texture);
}

