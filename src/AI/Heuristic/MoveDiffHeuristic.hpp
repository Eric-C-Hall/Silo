#ifndef SILO__MOVE_DIFF_HEURISTIC_HPP
#define SILO__MOVE_DIFF_HEURISTIC_HPP

#include "Heuristic.hpp"

class MoveDiffHeuristic : public Heuristic
{
  public:
  int getValue(const Silo &silo) const;
};

#endif
