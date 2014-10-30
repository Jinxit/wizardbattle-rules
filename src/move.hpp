#ifndef WIZARDBATTLE_RULES_MOVE_H
#define WIZARDBATTLE_RULES_MOVE_H

#include <vector>

#include "wizard.hpp"

namespace WizardBattle
{
	namespace Rules
	{
		// forward declaration
		class Board;

		class Move
		{
		private:
		public:
			enum Type
			{
				RAISE,
				LOWER,
				MOVE
			};

			const Type type;
			const unsigned int x, y;

			Move(Type type, unsigned int x, unsigned int y)
				: type(type), x(x), y(y) { };

			Board apply(const Board & board, unsigned int wizardID) const
			{
				auto wizards = board.wizards;
				auto temperatures = board.temperatures;
				auto & temp = temperatures[board.getIndex(x, y)];
				auto & wiz = wizards[wizardID];

				switch (type)
				{
					case RAISE:
						temp += 1;
						break;
					case LOWER:
						temp -= 1;
						break;

					case MOVE:
						wiz = Wizard(x, y);
						if (temp == 0)
						{
							wiz = wiz.kill();
						}
						break;
				}

				return Board(board.width, board.height, wizards, temperatures);
			}
		};
	}
}

#endif
