#ifndef WIZARDBATTLE_RULES_MOVE_H
#define WIZARDBATTLE_RULES_MOVE_H

#include <vector>

#include "enums.hpp"
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

			const Action action;
			const unsigned int x, y;

			Move(Action action, unsigned int x, unsigned int y)
				: action(action), x(x), y(y) { };

			Board apply(const Board & board, unsigned int wizardID) const
			{
				auto wizards = board.wizards;
				auto temperatures = board.temperatures;
				auto & temp = temperatures[board.getIndex(x, y)];
				auto & wiz = wizards[wizardID];
				Phase phase = board.phase;

				switch (action)
				{
					case ACTION_RAISE:
						temp += 1;
						phase = PHASE_MOVE;
						break;
					case ACTION_LOWER:
						temp -= 1;
						phase = PHASE_MOVE;
						break;

					case ACTION_MOVE:
						wiz = Wizard(x, y);
						if (temp == 0)
						{
							wiz = wiz.kill();
						}
						phase = PHASE_TEMPERATURE;
						break;
				}

				return Board(board.width, board.height, wizards, temperatures, phase);
			}
		};
	}
}

#endif
