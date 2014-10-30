#ifndef WIZARDBATTLE_RULES_MOVE_H
#define WIZARDBATTLE_RULES_MOVE_H

// forward declaration
class Board;

namespace WizardBattle
{
	namespace Rules
	{
		class Move
		{
		private:
		public:
			enum Type
			{
				RAISE,
				LOWER,
				UP,
				DOWN,
				LEFT,
				RIGHT
			};

			const Type type;
			const unsigned int x, y;

			Move(Type type, unsigned int x, unsigned int y)
				: type(type), x(x), y(y) { };

			const Board apply(const Board & board, unsigned int wizardID) const;
		};
	}
}

#endif
