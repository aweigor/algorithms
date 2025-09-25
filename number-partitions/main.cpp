#include "snowhouse/snowhouse.h"
#include "partitions.h"
#include <vector>

using namespace snowhouse;

int main(int argc, char **argv)
{
  AssertThat(find_paritions_basic(10), Is().EqualTo(42));
  AssertThat(find_paritions_basic(50), Is().EqualTo(204226));
  std::cout << "Test OK" << "\n";
}
