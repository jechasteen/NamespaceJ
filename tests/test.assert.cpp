#include <assert.h>

int main()
{
    J::dbg() << "Testing Assertions\n";
    J::Assert(1 == 1, "1==1");
    J::Assert(!(1 == 2), "!(1==2)");
    return 0;
}