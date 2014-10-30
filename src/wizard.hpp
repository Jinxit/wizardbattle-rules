#ifndef WIZARDBATTLE_RULES_WIZARD_H
#define WIZARDBATTLE_RULES_WIZARD_H

namespace WizardBattle
{
	namespace Rules
	{
		class Wizard
		{
		private:
		public:
			const unsigned int x, y;
			const bool alive;

			Wizard(unsigned int x, unsigned int y)
				: x(x), y(y), alive(false) { };
		};
	}
}

#endif
