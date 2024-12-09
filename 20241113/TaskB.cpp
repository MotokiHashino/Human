#include <iostream>
#include <format>

int main()
{
    const int DATA_SIZE = 100;
    const int RAND_SIZE = 100;
    int data[DATA_SIZE];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < DATA_SIZE; ++i)
    {
        data[i] = rand() % RAND_SIZE;
    }

    for (int i = 0; i < DATA_SIZE; ++i)
    {
        for (int j = DATA_SIZE - 1; j >= i + 1; --j)
        {
            int valueA = data[i];
            int valueB = data[j];
            if (valueA > valueB)
            {
                int max = valueA;
                int min = valueB;
                data[i] = min;
                data[j] = max;
            }
        }
    }

    return 0;
}