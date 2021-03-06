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

  const std::vector<bool> &getCounters() const {return counters;}
  int countContiguousCounters(bool player) const;
  int countCounters(bool player) const;

  static void unitTests();
};

#endif
