#ifndef WIZARDBATTLE_RULES_UTILS_H
#define WIZARDBATTLE_RULES_UTILS_H

#include <vector>
#include <algorithm>

#include "board.hpp"
#include "wizard.hpp"

namespace WizardBattle
{
	namespace Rules
	{
		namespace
		{
			unsigned int unifRandInt(unsigned int min, unsigned int max)
			{
				return min + (rand() % (unsigned int)(max - min + 1));
			}
		}

		inline Board createBoard(unsigned int numPlayers,
			unsigned int width = 5, unsigned int height = 5)
		{
			std::vector<Wizard> wizards;
			auto it = wizards.begin();

			switch (numPlayers)
			{
				case 4:
					wizards.emplace(it, width - 1, 0);
				case 3:
					it = wizards.begin();
					wizards.emplace(it, 0, height - 1);
				case 2:
					it = wizards.begin();
					wizards.emplace(it, width - 1, height - 1);
				case 1:
					it = wizards.begin();
					wizards.emplace(it, 0, 0);
			}


			std::vector<unsigned int> temperatures;
			for (unsigned int y = 0; y < height; y++)
			{
				for (unsigned int x = 0; x < width; x++)
				{
					unsigned int limit = std::max(
						std::max(x, width - x - 1),
						std::max(y, height - y - 1)
					);
					temperatures.emplace_back(unifRandInt(1, limit));
				}
			}

			return Board(width, height, wizards, temperatures, PHASE_MOVE);
		}
	}
}

#endif
