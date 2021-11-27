#pragma once

#include <QSound>

namespace PGG
{
class Sounds;
}

class PGG::Sounds
{
private:

    // sounds indexed by filename
    std::map< std::string, QSound* > _sounds;

    Sounds();

public:

    // singleton
    static Sounds* instance();

    // play/stop sound of the given id
    void play(const std::string & id, bool loop = false);
    void stop(const std::string & id);
    bool isFinished(const std::string & id);
};
