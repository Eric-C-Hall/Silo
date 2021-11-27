#include "HumanPlayer.hpp"

#include <iostream>

int HumanPlayer::chooseMove(const Silo &silo)
{
  int currTryMove;
  do
  {
    std::cin >> currTryMove;
  } while (!silo.canMove(currTryMove));
  return currTryMove;
}
