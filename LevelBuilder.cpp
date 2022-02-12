#include "LevelBuilder.h"
#include "Game.h"
#include "Sprites.h"
#include "Peg.h"

#include <random>
#include <iostream>
#include <set>


using namespace PGG;

// Utility Function
bool isIn(int x, int arr[]) {
	for (int i = 0; i < 25; i++)
		if (x == arr[i])
			return true;
	return false;
}

void LevelBuilder::load(const QString& level_name)
{
	if (level_name == "level_1")
	{
		// BACKGROUND

		QGraphicsPixmapItem* level = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("Hud_Unicorn")));

		QGraphicsPixmapItem* bottom = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("bottom_zvalue")));
		bottom->setZValue(10);

		Game::instance()->setSceneRect(0, 0, level->sceneBoundingRect().width(), level->sceneBoundingRect().height());
		Game::instance()->centerOn(level);
		Game::instance()->fitInView(level, Qt::KeepAspectRatio);


		Game::instance()->setRemainingBallPixmap(Game::instance()->world()->addPixmap(Sprites::instance()->get("10")));
		Game::instance()->getRemainingBallPixmap()->setScale(1.8);
		Game::instance()->getRemainingBallPixmap()->setPos(QPoint(55 - Game::instance()->getRemainingBallPixmap()->boundingRect().width() / 2, 180));


		new Button(QRect(1315, 942, 300, 150), ButtonType::AI);
		new Button(QRect(10, 942, 300, 150), ButtonType::MENU_BUTTON);

		// cannon
		Game::instance()->setCannon(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("cannon"))));
		Game::instance()->getCannon()->setScale(1.3);
		Game::instance()->getCannon()->setPos((Game::instance()->sceneRect().width() / 2) - (40), 185);
		double screenHeight = Game::instance()->sceneRect().height();


		//left current score colored band
		Game::instance()->setBandOne(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("band"))));
		Game::instance()->getBandOne()->setZValue(5);
		Game::instance()->getBandOne()->setPos(11, 924);
		Game::instance()->getBandOne()->setScale(1.5);

		Game::instance()->setBandTwo(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("band").transformed(QTransform().scale(-1, 1)))));
		Game::instance()->getBandTwo()->setZValue(5);
		Game::instance()->getBandTwo()->setPos(107, 924);
		Game::instance()->getBandTwo()->setScale(1.5);

		//green band

		//

		Game::instance()->lateral_mp.resize(10);
		for (int i = 0; i < 10; i++) {
			Game::instance()->lateral_mp[i] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("lateral_mp")));
			Game::instance()->lateral_mp[i]->setX(55);
			Game::instance()->lateral_mp[i]->setY((int)420 + (i * 35));
		}

		//moltiplicatori x2 x3 x5 x10
		Game::instance()->molt_x.resize(4);
		Game::instance()->molt_x[0] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt-x2")));
		Game::instance()->molt_x[1] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt-x3")));
		Game::instance()->molt_x[2] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt-x5")));
		Game::instance()->molt_x[3] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt-x10")));

		for (int i = 0; i < 4; i++)
		{
			Game::instance()->molt_x[i]->setScale(1.8);
			Game::instance()->molt_x[i]->setVisible(false);
			Game::instance()->molt_x[i]->setZValue(5);
		}
		Game::instance()->molt_x[0]->setPos(1344, 667);
		Game::instance()->molt_x[1]->setPos(1344, 543);
		Game::instance()->molt_x[2]->setPos(1344, 440);
		Game::instance()->molt_x[3]->setPos(1344, 369);
		//

		Game::instance()->molt.resize(25);
		for (int i = 0; i < 25; i++)
		{
			Game::instance()->molt[i] = Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("molt")));
			Game::instance()->molt[i]->setScale(1.75);
			Game::instance()->molt[i]->setPos(1325, ((int)915 - (25 * i)));
			Game::instance()->molt[i]->setVisible(false);
			Game::instance()->molt[i]->setZValue(3);
		}

		Game::instance()->setPaused(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("paused"))));
		Game::instance()->getPaused()->setScale(1.5);
		Game::instance()->getPaused()->setPos(QPointF((690 - (Game::instance()->getPaused()->boundingRect().width() / 2)), 540 - (Game::instance()->getPaused()->boundingRect().height() / 2)));
		Game::instance()->getPaused()->setVisible(false);
		Game::instance()->getPaused()->setZValue(10);

		switch (Game::instance()->getCharacter()) {
		case Character::UNICORN:
			Game::instance()->setCharacterFace(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("unicorn_face_right"))));
			break;
		case Character::BEAVER:
			Game::instance()->setCharacterFace(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("beaver_face_right"))));
			break;
		case Character::CRAB:
			Game::instance()->setCharacterFace(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("crab_face_right"))));
			break;
		case Character::FLOWER:
			Game::instance()->setCharacterFace(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("flower_face_right"))));
			break;
		case Character::PUMPKIN:
			Game::instance()->setCharacterFace(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("pumpkin_face_right"))));
			break;
		case Character::ALIEN:
			Game::instance()->setCharacterFace(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("alien_face_right"))));
			break;
		case Character::OWL:
			Game::instance()->setCharacterFace(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("owl_face_right"))));
			break;
		case Character::DRAGON:
			Game::instance()->setCharacterFace(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("dragon_face_right"))));
			break;
		case Character::RABBIT:
			Game::instance()->setCharacterFace(Game::instance()->world()->addPixmap(QPixmap(Sprites::instance()->get("rabbit_face_right"))));
			break;
		}

		Game::instance()->getCharacterFace()->setScale(1.5);
		Game::instance()->getCharacterFace()->setPos(720 - Game::instance()->getCharacterFace()->sceneBoundingRect().width() / 2, 68);

		Game::instance()->scoreGraphics.resize(6);
		for (int i = 0; i < 6; i++) {
			Game::instance()->scoreGraphics[i] = new QGraphicsPixmapItem();
			Game::instance()->scoreGraphics[i]->setPixmap(QPixmap(Sprites::instance()->get("0-score")).scaled(50, 50));
			Game::instance()->scoreGraphics[i]->setY(15);
			Game::instance()->scoreGraphics[i]->setX((int)500 - (i * 50));
			Game::instance()->world()->addItem(Game::instance()->scoreGraphics[i]);
		}

		Game::instance()->scoreGraphicsTwo.resize(6);
		for (int i = 0; i < 6; i++) {
			Game::instance()->scoreGraphicsTwo[i] = new QGraphicsPixmapItem();
			Game::instance()->scoreGraphicsTwo[i]->setPixmap(QPixmap(Sprites::instance()->get("0-score")).scaled(50, 50));
			Game::instance()->scoreGraphicsTwo[i]->setY(15);
			Game::instance()->scoreGraphicsTwo[i]->setX((int)1150 - (i * 50));
			Game::instance()->world()->addItem(Game::instance()->scoreGraphicsTwo[i]);
		}


		Game::instance()->remainingSimulation.resize(3);
		for (int i = 0; i < 3; i++) {
			Game::instance()->remainingSimulation[i] = new QGraphicsPixmapItem();
			Game::instance()->remainingSimulation[i]->setY(540 - (Game::instance()->getPaused()->boundingRect().height() / 2));
			Game::instance()->remainingSimulation[i]->setX((int)740 - (i * 50));
			Game::instance()->world()->addItem(Game::instance()->remainingSimulation[i]);
			Game::instance()->remainingSimulation[i]->setVisible(false);
			Game::instance()->remainingSimulation[i]->setZValue(2);
		}

		Game::instance()->remainingSimulation[0]->setPixmap(QPixmap(Sprites::instance()->get("0-score")).scaled(80, 80));
		Game::instance()->remainingSimulation[1]->setPixmap(QPixmap(Sprites::instance()->get("8-score")).scaled(80, 80));
		Game::instance()->remainingSimulation[2]->setPixmap(QPixmap(Sprites::instance()->get("1-score")).scaled(80, 80));

		// CREATE PHYSICS WORLD

		b2Vec2 gravity(0.0f, 0.0f);
		Game::instance()->setWorld2d(new b2World(gravity));
		Game::instance()->getWorld2d()->SetAllowSleeping(false);

		// CREATE PEGS
		Game::instance()->PegBox.resize(96);
		std::set<int> randomRed;
		while (randomRed.size() < 26)
			randomRed.insert(rand() % 95);

		// Definition
		b2BodyDef pegDef;
		pegDef.type = b2_staticBody;
		pegDef.linearDamping = 0;

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

			pegDef.position.Set((595 + (130 * k)) / 2 / 30.0, ((int)400 + (140 * j)) / 30.0);
			Game::instance()->PegBox[i] = Game::instance()->getWorld2d()->CreateBody(&pegDef);
			Game::instance()->setPegGraphic(new Peg(QPoint(pegDef.position.x * 30.0, (pegDef.position.y * 30.0)), color));
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
			pegDef.position.Set((663 + (130 * k)) / 2 / 30.0, ((int)470 + (140 * j)) / 30.0);
			Game::instance()->PegBox[i] = Game::instance()->getWorld2d()->CreateBody(&pegDef);
			Game::instance()->setPegGraphic(new Peg(QPoint(pegDef.position.x * 30.0, (pegDef.position.y * 30.0)), color));
			Game::instance()->PegBox[i]->CreateFixture(&shapeFixtureDef);
			Game::instance()->PegBox[i]->SetUserData(Game::instance()->getPegGraphic());
			k++;
		}
		Peg peg;
		int pos = peg.foundGreen();
		static_cast<Peg*>(Game::instance()->PegBox[pos]->GetUserData())->changeColor(PegColor::GREEN);


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
		ballFixtureDef.restitution = 0.8;
		ballFixtureDef.shape = &ballShape;
		ballFixtureDef.density = 50.0f;

		Game::instance()->getMasterPegBox()->CreateFixture(&ballFixtureDef);
		Game::instance()->getMasterPegBox()->SetLinearVelocity(b2Vec2(0, 0));
		Game::instance()->getMasterPegBox()->SetAngularVelocity(0);
		Game::instance()->getMasterPegGraphic()->setVisible(false);

		// CREATE BUCKET
		// Definition
		b2BodyDef bucketDef;
		bucketDef.type = b2_kinematicBody;
		bucketDef.linearDamping = 0;
		bucketDef.position.Set((Game::instance()->sceneRect().width() / 2) / 30.0, (screenHeight - 50) / 30.0);

		Game::instance()->setBucketBox(Game::instance()->getWorld2d()->CreateBody(&bucketDef));
		Game::instance()->setBucketGraphic(new Bucket(QPoint((bucketDef.position.x - 20) * 30.0, bucketDef.position.y * 30.0)));

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
		Game::instance()->getBucketBox()->GetFixtureList()->SetSensor(true);


		// CREATE PANELS
		// Definition
		b2BodyDef panel;
		b2Body * realPanelLeft;
		b2Body * realPanelRight;
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
		fdf.restitution = 0;
		fdf.density = 20.0;

		// Left side
		bd.angle = 20 * 3.14 / 180;

		bd.position.Set(142 / 30.0, 475 / 30.0);
		b2Body * bodyA = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyA->CreateFixture(&fdf);

		bd.position.Set(142 / 30.0, 610 / 30.0);
		b2Body * bodyB = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyB->CreateFixture(&fdf);

		bd.position.Set(142 / 30.0, 740 / 30.0);
		b2Body * bodyC = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyC->CreateFixture(&fdf);

		// Right side
		bd.angle = -20 * 3.14 / 180;

		bd.position.Set(1295 / 30.0, 400 / 30.0);
		b2Body * bodyD = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyD->CreateFixture(&fdf);

		bd.position.Set(1295 / 30.0, 540 / 30.0);
		b2Body * bodyE = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyE->CreateFixture(&fdf);

		bd.position.Set(1295 / 30.0, 685 / 30.0);
		b2Body * bodyF = Game::instance()->getWorld2d()->CreateBody(&bd);
		bodyF->CreateFixture(&fdf);

	}
	else
	{
		std::cerr << "Cannot load level: level " << level_name.toStdString() << " not found\n";

	}
}
