#ifndef SILO__MINIMAXPLAYER_HPP
#define SILO__MINIMAXPLAYER_HPP

#include "Player.hpp"

class MinimaxPlayer : public Player
{
  int chooseMove(const Silo &silo);
};

#endif
