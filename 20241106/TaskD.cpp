#include <iostream>
#include <format>

int main()
{
    const int LOOP_COUNT = 100;

    for (int i = 1; i <= LOOP_COUNT; i++)
    {
        std::cout << std::format("{:3}:",i);
        if (i % 3 == 0 && i % 5 == 0)
        {
            std::cout << std::format("fizz buzz");
        }
        else if (i % 3 == 0)
        {
            std::cout << std::format("fizz");
        }
        else if (i % 5 == 0)
        {
            std::cout << std::format("buzz");
        }
        std::cout << std::endl;
    }
    
    return 0;
}