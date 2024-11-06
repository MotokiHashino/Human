#include <iostream>
#include <format>

int main()
{
    const int LOOP_COUNT = 10;

    int i = 1;
    while (i <= LOOP_COUNT)
    {
        std::cout << std::format("{}\n", i);
        ++i;
    }
    std::cout << std::endl;

    return 0;
}