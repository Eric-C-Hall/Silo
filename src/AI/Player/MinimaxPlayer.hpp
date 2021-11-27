#ifndef SILO__MINIMAXPLAYER_HPP
#define SILO__MINIMAXPLAYER_HPP

#include "Player.hpp"

#include "../Heuristic/Heuristic.hpp"

struct MoveValuePair
{
  int move;
  int value;
};

class MinimaxPlayer : public Player
{
  private:
  const int maxDepth;
  const Heuristic &heuristic;
  MoveValuePair chooseMove(const Silo &silo, int remainingDepth);

  public:
  MinimaxPlayer(int inputMaxDepth, const Heuristic &inputHeuristic) : maxDepth(inputMaxDepth), heuristic(inputHeuristic) {}

  int chooseMove(const Silo &silo);
};

#endif
