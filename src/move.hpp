#ifndef WIZARDBATTLE_RULES_MOVE_H
#define WIZARDBATTLE_RULES_MOVE_H

#include <vector>

#include "enums.hpp"
#include "wizard.hpp"

namespace WizardBattle
{
	namespace Rules
	{
		class Move
		{
		private:
		public:

			const Action action;
			const unsigned int x, y;

			Move(Action action, unsigned int x, unsigned int y)
				: action(action), x(x), y(y) { };
		};
	}
}

#endif
