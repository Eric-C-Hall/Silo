#ifndef SILO__HUMANPLAYER_HPP
#define SILO__HUMANPLAYER_HPP

#include "Player.hpp"

class HumanPlayer : public Player
{
  int chooseMove(const Silo &silo);
};

#endif
