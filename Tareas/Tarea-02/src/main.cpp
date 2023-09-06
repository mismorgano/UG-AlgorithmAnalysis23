#include "binary_tree.h"
#include <iostream>
#include <random>
#include <string>

int main(int argc, char const *argv[]) {

  BST<long long> tree{};
  std::random_device rd; // a seed source for the random number engine
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<long long> distri(1, 1'000'000'000'000'000'000);

    auto n = std::stoull(argv[1]);

  for (size_t i = 0; i < n; i++) {
    auto c = distri(gen);
    tree.insert(c);
  }

  std::cout << n << ' ' << tree.getNumberOfComparasions() << '\n';

  return 0;
}