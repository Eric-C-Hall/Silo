#include <random>

#include "RandomPlayer.hpp"
#include "../../Game/Constants.hpp"

std::default_random_engine gen;
std::uniform_int_distribution<int> dist(0, NUM_STACKS_TOTAL-1);

int RandomPlayer::chooseMove(const Silo &silo)
{
  int currTryMove;
  do
  {
    currTryMove = dist(gen);
  } while (!silo.canMove(currTryMove));
  return currTryMove;
}
