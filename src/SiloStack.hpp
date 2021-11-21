#ifndef SILO__SILOSTACK_HPP
#define SILO__SILOSTACK_HPP

#include <vector>

class SiloStack
{
  private:
  std::vector<bool> counters;

  public:
  SiloStack(int height, bool color);
  SiloStack(const SiloStack &otherStack);
  void print() const;
  bool makeMove(bool player, SiloStack & target);
  bool canMove(bool player) const;

  bool nContiguousCounters(bool player, int n) const;

  static void unitTests();
};

#endif
