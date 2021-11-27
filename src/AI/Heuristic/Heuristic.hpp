#ifndef SILO__HEURISTIC_HPP
#define SILO__HEURISTIC_HPP

#include "../../Game/Silo.hpp"

class Heuristic
{
  public:
  // Gets the value of the position from the perspective of the player whose turn it currently is
  virtual int getValue(const Silo &silo) const = 0;
};

#endif
