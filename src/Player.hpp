#ifndef SILO__PLAYER_HPP
#define SILO__PLAYER_HPP

#include "Silo.hpp"

class Player
{
  public:
  virtual int chooseMove(const Silo &silo) = 0;
};

#endif
