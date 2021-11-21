#ifndef SILO__CONSTANTS_HPP
#define SILO__CONSTANTS_HPP

constexpr int NUM_STACKS_PER_PLAYER = 3;
constexpr int NUM_STACKS_TOTAL = 2 * NUM_STACKS_PER_PLAYER;
constexpr int STACK_HEIGHT = 3;
constexpr int NUM_COUNTERS_PER_PLAYER = STACK_HEIGHT * NUM_STACKS_PER_PLAYER;

inline constexpr char getCounterChar(bool player)
{
  return (player ? 'X' : 'O');
}

inline const char * getPlayerName(bool player)
{
  return (player ? "Player One" : "Player Two");
}

#endif
