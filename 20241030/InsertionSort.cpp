#include <iostream>

int main()
{
    //文字数
    int const CHARACTER_QUANTITY = 12;

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

    return 0;

    
}