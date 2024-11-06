#include <iostream>
#include <format>

int main()
{
    int loopCount = 10;
    for (int i = 1; i <= loopCount; ++i)
    {
        std::cout << std::format("{}\n",i);
    }
    std::cout << std::endl;
}