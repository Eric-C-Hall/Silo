#include <iostream>
#include <cassert>
#include <climits>

#include "MinimaxPlayer.hpp"

MoveValuePair MinimaxPlayer::chooseMove(const Silo &silo, int remainingDepth)
{
  assert(remainingDepth > 0);

  MoveValuePair bestMoveValue;
  bestMoveValue.move = 0;
  bestMoveValue.value = INT_MIN;
  for (int move : silo.possibleMoves())
  {
    Silo modifiableSilo(silo);
    modifiableSilo.makeMove(move);

    bool whoseTurnAfterMove = modifiableSilo.getWhoseTurn();

    int value;
    if (remainingDepth == 1)
      value = heuristic.getValue(silo);
    else
      value = chooseMove(modifiableSilo, remainingDepth-1).value;

    if (whoseTurnAfterMove != silo.getWhoseTurn())
      value = -value;

    if (value >= bestMoveValue.value)
    {
      bestMoveValue.move = move;
      bestMoveValue.value = value;
    }
  }
  return bestMoveValue;  
}


int MinimaxPlayer::chooseMove(const Silo &silo)
{
  return chooseMove(silo, maxDepth).move;
}
