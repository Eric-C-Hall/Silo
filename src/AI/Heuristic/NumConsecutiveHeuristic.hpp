#ifndef SILO__NUM_CONSECUTIVE_HEURISTIC_HPP
#define SILO__NUM_CONSECUTIVE_HEURISTIC_HPP

#include "Heuristic.hpp"

class NumConsecutiveHeuristic : public Heuristic
{
  public:
  int getValue(const Silo &silo) const;
};

#endif
