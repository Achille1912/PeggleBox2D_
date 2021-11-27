#pragma once

#include <QString>


namespace PGG
{
	class LevelBuilder;
}


class PGG::LevelBuilder
{
public:

	void load(const QString& level_name);
};