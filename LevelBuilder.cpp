#include "LevelBuilder.h"
#include "MyContactListener.h"

#include "Game.h"
#include "Sprites.h"

#include <random>
#include <iostream>


using namespace PGG;

// Utility Function
bool isIn(int x, int arr[]) {
	for (int i = 0; i < 25; i++) {
		if (x == arr[i])
			return true;
	}
	return false;
}

void LevelBuilder::load(const QString& level_name)
{
	if (level_name == "level_1")
	{

		
	// BACKGROUND
		QGraphicsPixmapItem* level = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("Hud_Unicorn")));
		Game::instance()->remainingBallPixmap = Game::instance()->world()->addPixmap(Sprites::instance()->get("9"));
		Game::instance()->remainingBallPixmap->setPos(QPoint(45, 180));
		Game::instance()->remainingBallPixmap->setScale(1.8);
		Game::instance()->fitInView(level, Qt::KeepAspectRatio);
		Game::instance()->cannon = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("cannon")));
		Game::instance()->cannon->setPos(Game::instance()->sceneRect().width() / 2, 300);
		double screenHeight = Game::instance()->sceneRect().height();
		Game::instance()->bandOne= Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("band")));
		Game::instance()->bandOne->setZValue(-2);
		Game::instance()->bandOne->setPos(10, Game::instance()->height());
		Game::instance()->bandOne->setScale(1.5);
		Game::instance()->bandTwo = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("band").transformed(QTransform().scale(-1, 1))));
		Game::instance()->bandTwo->setZValue(-2);
		Game::instance()->bandTwo->setPos(110, Game::instance()->height());
		Game::instance()->bandTwo->setScale(1.5);
		
		Game::instance()->molt.resize(25);
		for (int i = 0; i < 25; i++) {
			Game::instance()->molt[i] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt")));
			Game::instance()->molt[i]->setScale(1.75);
			Game::instance()->molt[i]->setPos(1325, 915 - (25 * i));
			Game::instance()->molt[i]->setVisible(false);
		}
	


	// CREATE PHYSICS WORLD
		b2Vec2 gravity(0.0f, 6.0f);
		Game::instance()->setWorld2d(new b2World(gravity));
		//MyContactListener myContactListenerInstance;
		//Game::instance()->getWorld2d()->SetContactListener(&myContactListenerInstance);
		Game::instance()->getWorld2d()->SetAllowSleeping(false);


	// CREATE PEGS
		Game::instance()->PegBox.resize(96);

		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, 95);
		int randomRed[25];
		for (int i = 0; i < 25; i++)
			randomRed[i] = (distr(gen));

			// Definition
		b2BodyDef pegDef;
		pegDef.type = b2_staticBody;
		pegDef.linearDamping = 0.3;

			// Shape
		b2CircleShape pegShape;
		pegShape.m_p.Set(0, 0);
		pegShape.m_radius = 0.4;

			// Fixture
		b2FixtureDef shapeFixtureDef;
		shapeFixtureDef.restitution = 1;
		shapeFixtureDef.shape = &pegShape;
		shapeFixtureDef.density = 13.0f;

		int j = 0;
		int k = 1;
		PegColor color = PegColor::BLUE;

		for (int i = 0; i < 48; i++)
		{
			color = PegColor::BLUE;
			if (k == 13) {
				k = 1;
				j++;
			}
			if (isIn(i, randomRed))
				color = PegColor::RED;
			pegDef.position.Set((810 + (100 * k)) / 2 / 30.0, (330 + (120 * j)) / 30.0);
			Game::instance()->PegBox[i] = Game::instance()->getWorld2d()->CreateBody(&pegDef);

			Game::instance()->setPegGraphic( new Peg(QPoint(pegDef.position.x * 30.0, (pegDef.position.y * 30.0)), color));

			Game::instance()->PegBox[i]->CreateFixture(&shapeFixtureDef);

			Game::instance()->PegBox[i]->SetUserData(Game::instance()->getPegGraphic());
			k++;
		}

		k = 0;
		j = 0;
		for (int i = 48; i <= 95; i++)
		{
			color = PegColor::BLUE;
			if (k == 12) {
				k = 0;
				j++;
			}
			if (isIn(i, randomRed))
				color = PegColor::RED;
			pegDef.position.Set((860 + (100 * k)) / 2 / 30.0, (390 + (120 * j)) / 30.0);
			Game::instance()->PegBox[i] = Game::instance()->getWorld2d()->CreateBody(&pegDef);

			Game::instance()->setPegGraphic( new Peg(QPoint(pegDef.position.x * 30.0, (pegDef.position.y * 30.0)), color));

			Game::instance()->PegBox[i]->CreateFixture(&shapeFixtureDef);

			Game::instance()->PegBox[i]->SetUserData(Game::instance()->getPegGraphic());
			k++;
		}


	// CREATE MASTER PEG
			// Definition
		b2BodyDef ballDef;
		ballDef.type = b2_dynamicBody;
		ballDef.linearDamping = 0.1;
		ballDef.position.Set((Game::instance()->sceneRect().width() / 2) / 30.0, 0 / 30.0);

		Game::instance()->setMasterPegBox(Game::instance()->getWorld2d()->CreateBody(&ballDef));

		Game::instance()->setMasterPegGraphic(new MasterPeg(QPoint(ballDef.position.x * 30.0, ballDef.position.y * 30.0)));

		Game::instance()->getMasterPegBox()->SetUserData((Game::instance()->getMasterPegGraphic()));

			// Shape
		b2CircleShape ballShape;
		ballShape.m_p.Set(0, 0);
		ballShape.m_radius = 0.2;

			// Fixture
		b2FixtureDef ballFixtureDef;
		ballFixtureDef.restitution = 0.2;
		ballFixtureDef.shape = &ballShape;
		ballFixtureDef.density = 50.0f;

		Game::instance()->getMasterPegBox()->CreateFixture(&ballFixtureDef);


	// CREATE MASTER PEG

		// Definition
		b2BodyDef bucketDef;
		bucketDef.type = b2_kinematicBody;
		bucketDef.linearDamping = 0.1;
		bucketDef.position.Set((Game::instance()->sceneRect().width() / 2) / 30.0, (screenHeight-32) / 30.0);
		
		Game::instance()->setBucketBox(Game::instance()->getWorld2d()->CreateBody(&bucketDef));

		Game::instance()->setBucketGraphic(new Bucket(QPoint(bucketDef.position.x * 30.0, bucketDef.position.y * 30.0)));

		// Shape
		b2PolygonShape groundShape;
		groundShape.m_radius = 0.3;
		groundShape.SetAsBox(168 / 2 / 30.0, 24 / 2 / 30.0);

		// Fixture
		b2FixtureDef buckFixture;
		buckFixture.restitution = 0.2;
		buckFixture.shape = &groundShape;
		buckFixture.density = 50.0f;

		Game::instance()->getBucketBox()->CreateFixture(&buckFixture);
		Game::instance()->getBucketBox()->SetLinearVelocity(b2Vec2(10, 0));
		Game::instance()->getBucketBox()->SetUserData((Game::instance()->getBucketGraphic()));


	// CREATE PANELS
		// Definition
		b2BodyDef panel;
		b2Body* realPanelLeft;
		b2Body* realPanelRight;
		panel.type = b2_staticBody;
		panel.linearDamping = 0.1;
		panel.position.Set(0 / 30.0, 0 / 30.0);

		realPanelLeft = Game::instance()->getWorld2d()->CreateBody(&panel);
		panel.position.Set(Game::instance()->sceneRect().width() / 30.0, 0 / 30.0);
		realPanelRight = Game::instance()->getWorld2d()->CreateBody(&panel);

		// Shape
		b2PolygonShape panelShape;
		panelShape.m_radius = 0.2;
		panelShape.SetAsBox(125 / 30.0, Game::instance()->sceneRect().height() / 30.0);

		// Fixture
		b2FixtureDef panelFixture;
		panelFixture.restitution = 0.2;
		panelFixture.shape = &panelShape;
		panelFixture.density = 50.0f;

		realPanelLeft->CreateFixture(&panelFixture);
		realPanelRight->CreateFixture(&panelFixture);

	}
	else
	{
		std::cerr << "Cannot load level: level " << level_name.toStdString() << " not found\n";
		
	}
}