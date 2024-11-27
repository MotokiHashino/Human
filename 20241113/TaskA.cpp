#include <iostream>
#include <format>

int main()
{
    int data[] = {0,1,2,3,4,5,6,7,8,9,10};
    bool shuffledChecker[std::size(data)];
    int shuffledData[std::size(data)];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < std::size(data); ++i)
    {
        int index = rand() % std::size(data);
        if (!shuffledChecker[index])
        {
            shuffledData[i] = data[index];
            shuffledChecker[index] = true;
        }
        else
        {
            --i;
        }
    }

    int result = -1;
    int target = 5;

    for (int i = 0; i < std::size(shuffledData); ++i)
    {
        if (target == shuffledData[i])
        {
            result = i;
            break;
        }
    }

    std::cout << std::format("targetのインデックスは{}です",result) << std::endl;

    return 0;
}