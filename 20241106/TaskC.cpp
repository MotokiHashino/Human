#include <iostream>
#include <format>

int main()
{
    int data[] = { 6, 2, 4, 3, 9, 0, 1, 5, 7, 8};

    for (int i = 0; i < std::size(data); ++i)
    {
        std::cout << std::format("{}\n", data[i]);
    } 

    std::cout << std::endl;
    return 0;
}