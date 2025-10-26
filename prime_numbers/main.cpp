#include "../snowhouse/snowhouse.h"
#include "sum-of-divided.h"
#include <vector>

using namespace snowhouse;

int main(int argc, char **argv)
{
  std::vector<int> testNumbers = { 12, 15 };
  AssertThat(sumOfDivided(testNumbers), Is().EqualTo("(2 12)(3 27)(5 15)"));
  std::cout << "Test OK" << "\n";
}
