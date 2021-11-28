#pragma once

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include "Sprites.h"


namespace PGG
{
	class HUD;
	class ScoreItem;
}


class PGG::HUD : public QWidget
{
	Q_OBJECT

private:

	//QPixmap _background;
	int _score;
	int _time;
	int _fps;
	std::list< ScoreItem > _score_items;
	int _last_digit;

public:

	HUD(int w, int h, QWidget* parent);

	void togglePause();
	void start();
	void reset();
	void addScore(int s, QPointF pos = QPointF(-1, -1));
	void setFPS(int v) { _fps = v; update(); }
	
	void advance();

	virtual void paintEvent(QPaintEvent* event) override;


};


class PGG::ScoreItem
{
private:

	QPixmap _texture;
	QPointF _origin;
	int _age;
	bool _expired;

public:

	ScoreItem(int score, QPointF pos);
	void operator++(int);
	void draw(QPainter* painter);
	bool expired() { return _expired; }
};