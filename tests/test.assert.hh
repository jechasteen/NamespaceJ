#include "assert.hh"

void test_assert()
{
    std::cout << "Testing Assertions";
    J::Assert(1 == 1, "1==1");
    J::Assert(!(1 == 2), "!(1==2)");
}
