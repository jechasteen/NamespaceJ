#include <iostream>

#define DEBUG_OUTPUT

#ifndef DEBUG_OUTPUT
#define D false
#else
#define D true
#endif

namespace J
{

    void Assert(bool expression, std::string message = "") 
    { 
        if (D) 
        {
            if (expression)
                std::cout << "Assertion passed: " << message << std::endl;
        }
        if (!expression)
        {
            std::cout << "Assertion failed: " << message << std::endl;
            exit(1);
        }
    }
}
