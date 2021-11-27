#ifndef SILO__SIMPLEPLAYER_HPP
#define SILO__SIMPLEPLAYER_HPP

#include "Player.hpp"

class SimplePlayer : public Player
{
  int chooseMove(const Silo &silo);
};

#endif
