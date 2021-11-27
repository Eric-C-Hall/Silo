#include "SiloStack.hpp"
#include "Constants.hpp"

#include <iostream>
#include <algorithm>
#include <cassert>
#include <stdlib.h>

SiloStack::SiloStack(int height, bool color)
{
  for (int i = 0; i < height; i++)
  {
    counters.push_back(color);
  }
}

SiloStack::SiloStack(const SiloStack &otherStack)
{
  counters = std::vector<bool>(otherStack.counters);
}

void SiloStack::print() const
{
  for (bool c : counters)
  {
    std::cout << getCounterChar(c);
  }
}

bool SiloStack::makeMove(bool player, SiloStack & target)
{
  int topCounter;
  for (topCounter = (int)counters.size()-1; topCounter >= 0; topCounter--)
  {
    if (counters[topCounter] == player)
      break;
  }

  if (topCounter == -1)
    return false;

  for (int i = topCounter; i < (int)counters.size(); i++)
  {
    target.counters.push_back(counters[i]);
  }
  counters.resize(topCounter);

  return true;
}

bool SiloStack::canMove(bool player) const
{
  for (int i = 0; i < (int)counters.size(); i++)
  {
    if (counters[i] == player)
      return true;
  }
  return false;
}

// Does not work for n == 0
// Assumes that n is equal to the total number of counters, so we don't have any spare counters that can be in non-contiguous spots
bool SiloStack::nContiguousCounters(bool player, int n) const
{
  if ((int)counters.size() < n)
    return false;

  int firstPlayerCounterIndex;
  bool hasPlayerCounterEarlyEnough = false;
  for(firstPlayerCounterIndex = 0; firstPlayerCounterIndex <= (int)counters.size() - n; firstPlayerCounterIndex++)
  {
    if (counters[firstPlayerCounterIndex] == player)
    {
      hasPlayerCounterEarlyEnough = true;
      break;
    }
  }

  if (!hasPlayerCounterEarlyEnough)
    return false;

  for (int currPlayerCounterIndex = firstPlayerCounterIndex + 1; currPlayerCounterIndex < firstPlayerCounterIndex + n; currPlayerCounterIndex++)
  {
    if (counters[currPlayerCounterIndex] != player)
      return false;
  }

  return true;
}

int SiloStack::countCounters(bool player) const
{
  int returnValue = 0;
  for (const bool counter : counters)
  {
    if (counter == player)
      returnValue++;
  }
  return returnValue;
}


// ------------
// Unit Tests
// ------------

void expectNContiguousCounters(const SiloStack &stack, bool player, int n)
{
  for (int i = 1; i < 100; i++)
  {
    bool existIContiguous = stack.nContiguousCounters(player, i);
    bool shouldExistIContiguous = i <= n;
    if (existIContiguous != shouldExistIContiguous)
    {
      std::cout << "Wrong number of contiguous counters" << std::endl;
      stack.print();
      std::cout << std::endl;
      std::cout << "Expected " << n << " counters for player " << getCounterChar(player) << std::endl;
      std::cout << "i = " << i << ", existIContiguous = " << existIContiguous << ", shouldExistIContiguous = " << shouldExistIContiguous << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

void SiloStack::unitTests()
{
  // 10T
  SiloStack stack(10, true);
  expectNContiguousCounters(stack, true, 10);
  expectNContiguousCounters(stack, false, 0);

  // 10F
  SiloStack otherStack(10,false);
  expectNContiguousCounters(otherStack, true, 0);
  expectNContiguousCounters(otherStack, false, 10);

  // 9T
  // 10F1T
  stack.makeMove(true, otherStack);
  expectNContiguousCounters(stack, true, 9);
  expectNContiguousCounters(stack, false, 0);
  expectNContiguousCounters(otherStack, true, 1);
  expectNContiguousCounters(otherStack, false, 10);

  // 9T1F1T
  // 9F
  otherStack.makeMove(false, stack);
  expectNContiguousCounters(stack, true, 9);
  expectNContiguousCounters(stack, false, 1);
  expectNContiguousCounters(otherStack, true, 0);
  expectNContiguousCounters(otherStack, false, 9);

  // 9T1F 
  // 9F1T
  stack.makeMove(true, otherStack);
  // 8T 
  // 9F2T1F
  stack.makeMove(true, otherStack);
  // 7T 
  // 9F2T1F1T
  stack.makeMove(true, otherStack);
  // 6T 
  // 9F2T1F2T
  stack.makeMove(true, otherStack);
  // 5T 
  // 9F2T1F3T
  stack.makeMove(true, otherStack);
  // 4T 
  // 9F2T1F4T
  stack.makeMove(true, otherStack);

  expectNContiguousCounters(stack, true, 4);
  expectNContiguousCounters(stack, false, 0);
  expectNContiguousCounters(otherStack, true, 2);
  expectNContiguousCounters(otherStack, false, 9);

  otherStack.makeMove(false, stack);
  // 4T1F4T
  // 9F2T
  expectNContiguousCounters(stack, true, 4);
  expectNContiguousCounters(stack, false, 1);
  expectNContiguousCounters(otherStack, true, 2);
  expectNContiguousCounters(otherStack, false, 9);
}
