#ifndef WIZARDBATTLE_RULES_ENUMS_H
#define WIZARDBATTLE_RULES_ENUMS_H

namespace WizardBattle
{
	namespace Rules
	{
		enum Action
		{
			ACTION_RAISE,
			ACTION_LOWER,
			ACTION_MOVE
		};

		enum Phase
		{
			PHASE_MOVE,
			PHASE_TEMPERATURE
		};
	}
}

#endif
