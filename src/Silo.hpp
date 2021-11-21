#ifndef SILO__SILO_HPP
#define SILO__SILO_HPP

#include <vector>

#include "SiloStack.hpp"

class Silo
{
  private:
  std::vector<SiloStack> stacks;
  bool isPlayerOneTurn = true;

  public:
  Silo();
  Silo(const Silo &otherSilo);
  void print() const;
  bool makeMove(int whichStack);
  bool canMove() const;
  bool canMove(int whichStack) const;

  // 1 -> player 1 won
  // -1 -> player 0 won
  // 0 -> ongoing
  int whoWon() const;
  bool getWhoseTurn() const {return isPlayerOneTurn;}
};


#endif
