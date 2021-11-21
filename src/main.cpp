#include <iostream>
#include <cassert>

#include "Silo.hpp"
#include "Constants.hpp"

#include "Player.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"

void play(Silo &silo, Player &p1, Player &p2)
{
  while (true)
  {
    silo.print();

    bool whoseTurn = silo.getWhoseTurn();

    int currMove = (whoseTurn ? p1.chooseMove(silo) : p2.chooseMove(silo));

    bool successfullyMoved = silo.makeMove(currMove);

    if (!successfullyMoved)
    {
      assert(!silo.canMove(currMove));
      std::cout << "Error: failed to move during " << getPlayerName(whoseTurn) << "'s turn." << std::endl;
      exit(EXIT_FAILURE);
    }

    // Check if a player has won
    if (silo.whoWon() != 0)
      break;
  }

  bool winningPlayer = (silo.whoWon() == 1);

  std::cout << getPlayerName(winningPlayer) << " has won!" << std::endl;
}

int main(int argc, char **argv)
{
  SiloStack::unitTests();

  Silo silo;
  HumanPlayer humanPlayer;
  RandomPlayer randomPlayer;

  play(silo, humanPlayer, randomPlayer);
}
