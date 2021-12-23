#include "LevelBuilder.h"


#include "Game.h"
#include "Sprites.h"

#include <random>
#include <iostream>
#include <set>


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
		Game::instance()->centerOn(level);
		Game::instance()->remainingBallPixmap = Game::instance()->world()->addPixmap(Sprites::instance()->get("9"));
		Game::instance()->remainingBallPixmap->setPos(QPoint(45, 180));
		Game::instance()->remainingBallPixmap->setScale(1.8);
		Game::instance()->fitInView(level, Qt::KeepAspectRatio);
		Game::instance()->cannon = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("cannon")));
		Game::instance()->cannon->setScale(1.5);
		Game::instance()->cannon->setPos((Game::instance()->sceneRect().width() / 2)-(20), 205);
		double screenHeight = Game::instance()->sceneRect().height();
		Game::instance()->bandOne= Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("band")));
		Game::instance()->bandOne->setZValue(-2);
		Game::instance()->bandOne->setPos(10, 924);
		Game::instance()->bandOne->setScale(1.5);
		Game::instance()->bandTwo = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("band").transformed(QTransform().scale(-1, 1))));
		Game::instance()->bandTwo->setZValue(-2);
		Game::instance()->bandTwo->setPos(110, 924);
		Game::instance()->bandTwo->setScale(1.5);
		

		Game::instance()->molt_x.resize(4);
		Game::instance()->molt_x[0] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt-x2")));
		Game::instance()->molt_x[1] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt-x3")));
		Game::instance()->molt_x[2] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt-x5")));
		Game::instance()->molt_x[3] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt-x10")));
		
		for (int i = 0; i < 4; i++) {
			
			Game::instance()->molt_x[i]->setScale(1.8);
			Game::instance()->molt_x[i]->setVisible(false);
		}
		Game::instance()->molt_x[0]->setPos(1344, 667);
		Game::instance()->molt_x[1]->setPos(1344, 543);
		Game::instance()->molt_x[2]->setPos(1344, 440);
		Game::instance()->molt_x[3]->setPos(1344, 369);


		Game::instance()->molt.resize(25);
		for (int i = 0; i < 25; i++) {
			Game::instance()->molt[i] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt")));
			Game::instance()->molt[i]->setScale(1.75);
			Game::instance()->molt[i]->setPos(1325, (915 - (25 * i)));
			Game::instance()->molt[i]->setVisible(false);
			Game::instance()->molt[i]->setZValue(-2);
		}

		Game::instance()->paused = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("paused")));
		Game::instance()->paused->setScale(1.5);
		Game::instance()->paused->setPos(QPointF((720 - (Game::instance()->paused->boundingRect().width()/2 )), 540 - (Game::instance()->paused->boundingRect().height() / 2)));
		Game::instance()->paused->setVisible(false);
		Game::instance()->paused->setZValue(10);


		Game::instance()->bjorn = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("unicorn")));
		Game::instance()->bjorn->setScale(1.6);
		Game::instance()->bjorn->setPos(660,70);


 // CREATE PHYSICS WORLD
	//
		b2Vec2 gravity(0.0f, 0.0f);
		Game::instance()->setWorld2d(new b2World(gravity));
		//MyContactListener myContactListenerInstance;
		//Game::instance()->getWorld2d()->SetContactListener(&myContactListenerInstance);
		Game::instance()->getWorld2d()->SetAllowSleeping(false);


	// CREATE PEGS
		Game::instance()->PegBox.resize(96);

		std::set<int> randomRed;
		while (randomRed.size() < 25)
			randomRed.insert(rand() % 95);
		
	
			// Definition
		b2BodyDef pegDef;
		pegDef.type = b2_staticBody;
		pegDef.linearDamping =0;

			// Shape
		b2CircleShape pegShape;
		pegShape.m_p.Set(0, 0);
		pegShape.m_radius = 0.5;

			// Fixture
		b2FixtureDef shapeFixtureDef;
		shapeFixtureDef.restitution = 0;
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
			if (randomRed.find(i) != randomRed.end())
				color = PegColor::RED;
			pegDef.position.Set((810 + (100 * k)) / 2 / 30.0, (360 + (120 * j)) / 30.0);
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
			if (randomRed.find(i) != randomRed.end())
				color = PegColor::RED;
			pegDef.position.Set((860 + (100 * k)) / 2 / 30.0, (420 + (120 * j)) / 30.0);
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
		ballDef.linearDamping = 0;
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
		ballFixtureDef.restitution = 0.7;
		ballFixtureDef.shape = &ballShape;
		ballFixtureDef.density = 50.0f;

		Game::instance()->getMasterPegBox()->CreateFixture(&ballFixtureDef);
		Game::instance()->getMasterPegBox()->SetLinearVelocity(b2Vec2(0, 0));
		Game::instance()->getMasterPegBox()->SetAngularVelocity(0);


	// CREATE BUCKET

		// Definition
		b2BodyDef bucketDef;
		bucketDef.type = b2_kinematicBody;
		bucketDef.linearDamping = 0;
		bucketDef.position.Set((Game::instance()->sceneRect().width() / 2) / 30.0, (screenHeight-50) / 30.0);
		
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
		panel.linearDamping = 0;
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
		panelFixture.restitution = 0;
		panelFixture.shape = &panelShape;
		panelFixture.density = 50.0f;

		realPanelLeft->CreateFixture(&panelFixture);
		realPanelRight->CreateFixture(&panelFixture);


		// CREATE PLATFORMS
		b2PolygonShape shape;
		b2BodyDef bd;
		b2FixtureDef fdf;
		bd.type = b2_staticBody;
		shape.SetAsBox(161 / 30.0, .3 / 30.0);
		fdf.shape = &shape;
		fdf.restitution =0;
		fdf.density = 20.0;
		// Left side
		bd.position.Set(142/30.0, 475/30.0);
		bd.angle = 20 * 3.14 / 180;
		b2Body* bodyA = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyA->CreateFixture(&fdf);

		bd.position.Set(142 / 30.0, 610 / 30.0);
		b2Body* bodyB = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyB->CreateFixture(&fdf);

		bd.position.Set(142 / 30.0, 740 / 30.0);
		b2Body* bodyC = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyC->CreateFixture(&fdf);

		// Right side
		bd.angle = -20 * 3.14 / 180;
		
		bd.position.Set(1295 / 30.0, 400 / 30.0);
		b2Body* bodyD = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyD->CreateFixture(&fdf);

		bd.position.Set(1295 / 30.0, 540 / 30.0);
		b2Body* bodyE = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyE->CreateFixture(&fdf);

		bd.position.Set(1295 / 30.0, 685 / 30.0);
		b2Body* bodyF = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyF->CreateFixture(&fdf);

	}
	else
	{
		std::cerr << "Cannot load level: level " << level_name.toStdString() << " not found\n";
		
	}
}