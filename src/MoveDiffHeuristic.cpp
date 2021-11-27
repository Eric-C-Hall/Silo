#include "MoveDiffHeuristic.hpp"

#include "Constants.hpp"

int MoveDiffHeuristic::getValue(const Silo &silo) const
{
  int p1MoveDiff = 0;

  const auto &stacks = silo.getStacks();
  for (int i = 0; i < NUM_STACKS_TOTAL; i++)
  {
    const auto &stack = stacks[i];
    int p1Counters = stack.countCounters(true);
    int p2Counters = stack.countCounters(false);
    
    p1MoveDiff += p1Counters * (NUM_STACKS_TOTAL - 1 - i);
    p1MoveDiff -= p2Counters * i;
  }

  return (silo.getWhoseTurn() ? 1 : -1) * p1MoveDiff;
}
