#include <iostream>
#include <format>

int main()
{
    const int DATA_SIZE = 100;//配列の数
    const int RAND_SIZE = 100;//乱数の幅
    int data[DATA_SIZE];//配列宣言

    srand((unsigned int)time(NULL));//乱数シャッフル

    //乱数代入
    for (int i = 0; i < DATA_SIZE; ++i)
    {
        data[i] = rand() % RAND_SIZE;
    }

    //ソート
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

    //出力
    for (int i = 0; i < DATA_SIZE; ++i)
    {
        std::cout << data[i] << std::endl;
    }
    return 0;
}