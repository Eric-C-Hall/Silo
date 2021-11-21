#include "Silo.hpp"
#include "Constants.hpp"

#include <iostream>

Silo::Silo()
{
  bool playerOne = true;
  for (int i = 0; i < NUM_STACKS_TOTAL; i++)
  {
    stacks.push_back(SiloStack(STACK_HEIGHT, playerOne));
    playerOne = !playerOne;
  }
}

Silo::Silo(const Silo &otherSilo)
{
  for (const SiloStack &stack : otherSilo.stacks)
  {
    stacks.push_back(SiloStack(stack));
  }
}

void Silo::print() const
{
  for (const SiloStack &stack : stacks)
  {
    stack.print();
    std::cout << "\n";
  }
  std::cout << getPlayerName(isPlayerOneTurn) << "'s turn\n";
  std::cout << std::flush;
}

bool Silo::makeMove(int whichStack)
{
  if (whichStack > NUM_STACKS_TOTAL || whichStack < 0)
    return false;

  if (isPlayerOneTurn ? whichStack == NUM_STACKS_TOTAL - 1 : whichStack == 0)
    return false;

  int nextStack = whichStack + (isPlayerOneTurn ? 1 : -1);

  bool success = stacks[whichStack].makeMove(isPlayerOneTurn, stacks[nextStack]);

  if (success)
  {
    isPlayerOneTurn = !isPlayerOneTurn;
    if (!canMove())
      isPlayerOneTurn = !isPlayerOneTurn;
  }
    
  return success;
}

bool Silo::canMove() const
{
  for (int i = (isPlayerOneTurn ? 0 : 1); i < (int)stacks.size() - (isPlayerOneTurn ? 1 : 0); i++)
  {
    if (canMove(i))
      return true;
  }
  return false;
}

bool Silo::canMove(int whichStack) const
{
  if (whichStack > NUM_STACKS_TOTAL || whichStack < 0)
    return false;

  if (isPlayerOneTurn ? whichStack == NUM_STACKS_TOTAL - 1 : whichStack == 0)
    return false;

  return stacks[whichStack].canMove(isPlayerOneTurn);
}

int Silo::whoWon() const
{
  for (const SiloStack &stack : stacks)
  {
    if (stack.nContiguousCounters(true, NUM_COUNTERS_PER_PLAYER))
    {
      return 1;
    }
    else if (stack.nContiguousCounters(false, NUM_COUNTERS_PER_PLAYER))
    {
      return -1;
    }
  }
  return 0;
}
