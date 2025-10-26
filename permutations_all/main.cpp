#include "../snowhouse/snowhouse.h"
#include "heap.hpp"
#include <string>

using namespace snowhouse;

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const T& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// TODO: more tests
int main(int argc, char **argv)
{
  std::string initialString;
  initialString = "ab";
  std::vector<std::string> result;
  result = permutations(initialString);
  AssertThat(result, Is().EqualTo(std::vector<std::string>{ "ab", "ba" }));
  std::cout << "Permutations: " << "\n";
  printArray(result);
  std::cout << "Test OK" << "\n";
}

