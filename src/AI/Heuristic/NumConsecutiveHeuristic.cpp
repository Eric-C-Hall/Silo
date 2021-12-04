#include "NumConsecutiveHeuristic.hpp"

#include <algorithm>

int calculateMaxNumConsecutive(const Silo &silo, bool player)
{
  int maxNumConsecutive = 0;
  for (const SiloStack &siloStack : silo.getStacks())
  {
    int currNumConsecutive = siloStack.countContiguousCounters(player);
    maxNumConsecutive = std::max(maxNumConsecutive, currNumConsecutive);
  }
  return maxNumConsecutive;
}

int NumConsecutiveHeuristic::getValue(const Silo &silo) const
{
  int p1MaxNumConsecutive = calculateMaxNumConsecutive(silo, true);
  int p2MaxNumConsecutive = calculateMaxNumConsecutive(silo, false);

  int p1Diff = p1MaxNumConsecutive - p2MaxNumConsecutive;

  return p1Diff * (silo.getWhoseTurn() ? 1 : -1);
}
