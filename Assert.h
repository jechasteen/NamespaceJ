#ifndef ASSERT_H
#define ASSERT_H

#include <LogStream.h>

namespace J
{

void Assert(bool expression, std::string message = "") 
{
#ifdef DEBUG
    if (expression)
        J::dbg() << "Assertion passed: " << message;
#endif
    if (!expression)
    {
        J::dbg() << "Assertion failed: " << message;
        exit(1);
    }
}

}

#endif // Assert.h
