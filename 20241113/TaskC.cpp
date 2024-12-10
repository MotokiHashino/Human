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

    int target = 50;//探索対象
    int result = -1;//探索結果
    int left = 0;//探索左敷居
    int right = DATA_SIZE - 1;//探索右敷居

    //二分探索
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (data[mid] == target)
        {
            result = mid;
            break;
        }
        else
        {
            if (data[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
    }

    //出力
    if(result >= 0)
    {
        std::cout << std::format("targetのインデックスは{}です",result) << std::endl; 
    }
    else
    {
        std::cout << "targetは見つかりませんでした" << std::endl; 
    }
    
    return 0;
}
