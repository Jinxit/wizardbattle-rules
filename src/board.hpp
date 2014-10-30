#ifndef WIZARDBATTLE_RULES_BOARD_H
#define WIZARDBATTLE_RULES_BOARD_H

#include <vector>
#include "wizard.hpp"
#include "move.hpp"

namespace WizardBattle
{
	namespace Rules
	{
		class Board
		{
		private:
		public:
			unsigned int width, height;
			std::vector<Wizard> wizards;
			std::vector<unsigned int> temperatures;

			Board(unsigned int width, unsigned int height,
				std::vector<Wizard> wizards, std::vector<unsigned int> temperatures)
				: width(width), height(height), wizards(wizards), temperatures(temperatures) { };

			std::vector<Move> getPossibleMoves(unsigned int wizardID) const;
			std::vector<Board> getPossibleNextStates(unsigned int wizardID) const;
			unsigned int getIndex(unsigned int x, unsigned int y) const
			{
				return x + y * width;
			};
		};
	}
}

#endif
