#include <QApplication>
#include <QDir>
#include <QCoreApplication>
#include "Game.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QDir::setCurrent(QApplication::applicationDirPath());
    PGG::Game::instance()->show();

    
    return app.exec();

}

