#include <iostream>
#include <format>
#include <string>
#include <vector>

using namespace std;

class CStackChar//char型スタッククラス
{
private:
    vector<char> characters;

public:
    void push(char character)
    {
        characters.emplace_back(character);
    }

    char pop()
    {
        char popChar = characters.back();
        characters.pop_back();
        return popChar;
    }

    std::string debugDescription() 
    {
        std::string result = "[";
        for (int i = 0; i < characters.size(); ++i)
        {
            result += characters[i];
            if (i != characters.size() - 1)
            {
                result += ",";
            }
        }
        result += "]";
        return result;
    }

    void debugLog()
    {
        std::string description = debugDescription();
        std::cout << description << std::endl;
    }
};

class CQueueChar//char型キュークラス
{
    struct Const
    {
        static const int CAPACITY = 20;
    };

private:
    int enqueueCount = 0;
    int dequeueCount = 0;
    vector<char> characters;

public:
    CQueueChar()
    {
        characters.resize(Const::CAPACITY);
    } 

    void enqueue(char character)
    {
        characters[enqueueCount++] = character;
        if (enqueueCount >= std::size(characters))
        {
            enqueueCount = 0;
        }
    }

    char dequeue()
    {
        char dequeueChar = characters[dequeueCount];
        characters[dequeueCount++] = {};
        if (dequeueCount >= std::size(characters))
        {
            dequeueCount = 0;
        }
        return dequeueChar;
    }

    std::string debugDescription() 
    {
        std::string result = "[";
        int loopCorrect = dequeueCount > enqueueCount ? std::size(characters) : 0;
        for (int i = dequeueCount; i < enqueueCount + loopCorrect; ++i)
        {
            if (i < std::size(characters))
            {
                result += characters[i];
                if (i != enqueueCount + loopCorrect - 1)
                {
                    result += ",";
                }
            }
            else
            {
                result += characters[i - std::size(characters)];
                if (i != enqueueCount + loopCorrect - 1)
                {
                    result += ",";
                }
            }
            
        }
        result += "]";
        return result;
    }

    void debugLog()
    {
        std::string description = debugDescription();
        std::cout << description << std::endl;
    }


};

void stackProcess()
{
    std::cout << "Stack" << std::endl;
    CStackChar stack;
    for (char character = 'A'; character <= 'Z'; ++character)
    {
        stack.push(character);
        stack.debugLog();
        if (character % 3 == 0)
        {
            std::cout << stack.pop() << " " << stack.debugDescription() << std::endl;
        }
    
    }
    std::cout << std::endl;
}

void queueProcess()
{
    std::cout << "Queue" << std::endl;
    CQueueChar queue;
    for (char character = 'A'; character <= 'Z'; ++character)
    {
        queue.enqueue(character);
        queue.debugLog();
        if (character % 3 == 0)
        {
            std::cout << queue.dequeue() << " " << queue.debugDescription() << std::endl;
        }
    
    }
    std::cout << std::endl;
}

int main()
{
    char result;

    //スタック演習
    stackProcess();

    //キュー演習
    queueProcess();

    return 0;
}
