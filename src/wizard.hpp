#ifndef WIZARDBATTLE_RULES_WIZARD_H
#define WIZARDBATTLE_RULES_WIZARD_H

namespace WizardBattle
{
	namespace Rules
	{
		class Wizard
		{
		private:
			Wizard(unsigned int x, unsigned int y, bool alive)
				: x(x), y(y), alive(alive) { };
		public:
			unsigned int x, y;
			bool alive;

			Wizard(unsigned int x, unsigned int y)
				: Wizard(x, y, true) { };

			Wizard kill() const
			{
				return Wizard(x, y, false);
			};
		};
	}
}

#endif
