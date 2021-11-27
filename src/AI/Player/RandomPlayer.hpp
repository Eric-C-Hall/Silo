#ifndef SILO__RANDOMPLAYER_HPP
#define SILO__RANDOMPLAYER_HPP

#include "Player.hpp"

class RandomPlayer : public Player
{
  int chooseMove(const Silo &silo);
};

#endif
