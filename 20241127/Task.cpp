#include <iostream>
#include <format>
#include <string>

class CStackChar//char型スタッククラス
{
private:
    int count = 0;
    char characters[20];

public:
    void push(char character)
    {
        characters[count++] = character;
    }

    char pop()
    {
        char popChar = characters[--count];
        characters[count] = {};
        return popChar;
    }

    std::string debugDescription() 
    {
        std::string result = "[";
        for (int i = 0; i < count; ++i)
        {
            result += characters[i];
            if (i != count - 1)
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
private:
    int enqueueCount = 0;
    int dequeueCount = 0;
    char characters[6];

public:
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

int main()
{
    char result;

    //スタック演習
    CStackChar stack;
    stack.push('A');
    stack.debugLog();
    stack.push('B');
    stack.debugLog();
    stack.push('C');
    stack.debugLog();
    result = stack.pop();
    std::cout << result << " " << stack.debugDescription() << std::endl;
    stack.push('D');
    stack.debugLog();
    result = stack.pop();
    std::cout << result << " " << stack.debugDescription() << std::endl;
    result = stack.pop();
    std::cout << result << " " << stack.debugDescription() << std::endl;
    std::cout << std::endl;

    //キュー演習
    CQueueChar queue;
    queue.enqueue('E');
    queue.debugLog();
    queue.enqueue('F');
    queue.debugLog();
    queue.enqueue('G');
    queue.debugLog();
    result = queue.dequeue();
    std::cout << result << " " << queue.debugDescription() << std::endl;
    result = queue.dequeue();
    std::cout << result << " " << queue.debugDescription() << std::endl;
    queue.enqueue('H');
    queue.debugLog();
    queue.enqueue('I');
    queue.debugLog();
    queue.enqueue('J');
    queue.debugLog();
    result = queue.dequeue();
    std::cout << result << " " << queue.debugDescription() << std::endl;
    queue.enqueue('K');
    queue.debugLog();
    queue.enqueue('L');
    queue.debugLog();
    result = queue.dequeue();
    std::cout << result << " " << queue.debugDescription() << std::endl;
    result = queue.dequeue();
    std::cout << result << " " << queue.debugDescription() << std::endl;
    queue.enqueue('M');
    queue.debugLog();
    result = queue.dequeue();
    std::cout << result << " " << queue.debugDescription() << std::endl;
    result = queue.dequeue();
    std::cout << result << " " << queue.debugDescription() << std::endl;
    return 0;
}
