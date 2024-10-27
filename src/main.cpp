#include <cinttypes>
#include <iostream>
#include "array.hpp"

std::int32_t main()
{
  memory::array<char, 13> test1 {'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '\n'};

  for (auto begin {test1.cbegin()}, end {test1.cend()}; begin != end; ++begin)
    std::cout << *begin;

  std::cout << '\n';
  return 0;
}
