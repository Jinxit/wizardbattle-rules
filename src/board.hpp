#ifndef WIZARDBATTLE_RULES_BOARD_H
#define WIZARDBATTLE_RULES_BOARD_H

#include <vector>
#include <tuple>

#include "enums.hpp"
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
			Phase phase;

			Board(unsigned int width, unsigned int height, std::vector<Wizard> wizards,
				std::vector<unsigned int> temperatures, Phase phase)
				:	width(width), height(height), wizards(wizards), temperatures(temperatures),
					phase(phase) { };

			Board move(Move move, unsigned int wizardID) const
			{
				auto newWizards = wizards;
				auto newTemperatures = temperatures;
				auto & temp = newTemperatures[getIndex(move.x, move.y)];
				auto & wiz = newWizards[wizardID];
				Phase newPhase = phase;

				switch (move.action)
				{
					case ACTION_RAISE:
						temp += 1;
						newPhase = PHASE_MOVE;
						break;
					case ACTION_LOWER:
						temp -= 1;
						newPhase = PHASE_MOVE;
						break;

					case ACTION_MOVE:
						wiz = Wizard(move.x, move.y);
						if (temp == 0)
						{
							wiz = wiz.kill();
						}
						newPhase = PHASE_TEMPERATURE;
						break;
				}

				return Board(width, height, newWizards, newTemperatures, newPhase);
			}

			std::vector<Move> getPossibleMoves(unsigned int wizardID) const
			{
				std::vector<Move> moves;

				if (phase == PHASE_TEMPERATURE)
				{
					for (std::vector<unsigned int>::size_type i = 0; i < temperatures.size(); i++)
					{
						unsigned int x = -1, y = -1;
						std::tie(x, y) = getPosition(i);

						if (!isWizardAt(x, y))
						{
							if (temperatures[i] < std::min(width, height))
							{
								moves.emplace_back(ACTION_RAISE, x, y);
							}
							if (temperatures[i] > 0)
							{
								moves.emplace_back(ACTION_LOWER, x, y);
							}
						}
					}
				}
				else if (phase == PHASE_MOVE)
				{
					auto & wiz = wizards[wizardID];
					auto & temp = temperatures[getIndex(wiz.x, wiz.y)];

					if (wiz.x + temp < width)
					{
						if (!isWizardAt(wiz.x + temp, wiz.y))
						{
							moves.emplace_back(ACTION_MOVE, wiz.x + temp, wiz.y);
						}
					}
					if (temp <= wiz.x)
					{
						if (!isWizardAt(wiz.x - temp, wiz.y))
						{
							moves.emplace_back(ACTION_MOVE, wiz.x - temp, wiz.y);
						}
					}
					if (wiz.y + temp < height)
					{
						if (!isWizardAt(wiz.x, wiz.y + temp))
						{
							moves.emplace_back(ACTION_MOVE, wiz.x, wiz.y + temp);
						}
					}
					if (temp <= wiz.y)
					{
						if (!isWizardAt(wiz.x, wiz.y - temp))
						{
							moves.emplace_back(ACTION_MOVE, wiz.x, wiz.y - temp);
						}
					}
				}

				return moves;
			};

			std::vector<Board> getPossibleNextStates(unsigned int wizardID) const
			{
				std::vector<Move> moves = getPossibleMoves(wizardID);
				std::vector<Board> states;

				for (std::vector<Move>::size_type i = 0; i < moves.size(); i++)
				{
					states.emplace_back(move(moves[i], wizardID));
				}

				return states;
			}

			unsigned int getIndex(unsigned int x, unsigned int y) const
			{
				return x + y * width;
			};

			std::tuple<unsigned int, unsigned int> getPosition(unsigned int index) const
			{
				return std::tuple<unsigned int, unsigned int>(index % width, index / width);
			};

			bool isWizardAt(unsigned int x, unsigned int y) const
			{
				bool found = false;
				for (std::vector<Wizard>::size_type i = 0; i < wizards.size(); i++)
				{
					if (wizards[i].x == x && wizards[i].y == y)
					{
						found = true;
						break;
					}
				}
				return found;
			};
		};
	}
}

#endif
