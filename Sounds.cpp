#include <QDir>
#include "Sounds.h"

using namespace PGG;

Sounds* Sounds::instance()
{
    static Sounds uniqueInstance;
    return &uniqueInstance;
}

Sounds::Sounds()
{
    QStringList sound_files = QDir("sounds/").entryList(QStringList() << "*.wav", QDir::Files);
    for (auto& f : sound_files)
        _sounds[QFileInfo(f).baseName().toStdString()] = new QSound(QString("sounds/") + f);
}

void Sounds::play(const std::string & id, bool loop)
{
    if (_sounds.find(id) != _sounds.end() && _sounds[id]->isFinished())
    {
        _sounds[id]->play();
        if(loop)
            _sounds[id]->setLoops(QSound::Infinite);
    }
}

void Sounds::stop(const std::string & id)
{
    if(_sounds.find(id) != _sounds.end() && !_sounds[id]->isFinished())
        _sounds[id]->stop();
}

bool Sounds::isFinished(const std::string & id)
{
    if(_sounds.find(id) != _sounds.end())
        return _sounds[id]->isFinished();
    else
        return true;
}
