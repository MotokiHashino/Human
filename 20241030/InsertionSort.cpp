#include <iostream>
#include <format>

int main()
{
    //文字数
    const int CHARACTER_QUANTITY = 12;

    //文字の代入、+1は終端のNUL文字用
    char characters[CHARACTER_QUANTITY + 1] = "HUMANACADEMY";
    //ソート後の文字代入用
    char afterSortCharacters[CHARACTER_QUANTITY + 1];

    //charactersの出力
    for (int i = 0; i < CHARACTER_QUANTITY; ++i)
    {
        std::cout << characters[i];
    }
    std::cout << std::endl;

    //挿入ソート
    for (int i = 0; i < CHARACTER_QUANTITY; ++i)
    {
        //挿入するindexの捜索
        int insertionIndex = 0;
        for (insertionIndex; insertionIndex < i; ++insertionIndex)
        {
            if (characters[i] < afterSortCharacters[insertionIndex])
            {
                break;
            }

        }

        //配列の対応するindexに値を挿入
        for (int j = i; j >= 0; --j)
        {
            if (j == insertionIndex)
            {
                afterSortCharacters[j] = characters[i];
                break;
            }
            else
            {
                afterSortCharacters[j] = afterSortCharacters[j - 1];
            }
        }

    }

    //表示
    for (int i = 0; i < CHARACTER_QUANTITY; ++i)
    {
        std::cout << afterSortCharacters[i];
    }
    std::cout << std::endl;

    return 0;

}