#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Const
{
    static const int QUEUE_CAPACITY = 64;

};

struct Maps
{
    struct Const
    {
        static const int HEIGHT     = 8;
        static const int WIDTH      = 8;

    };
    static inline const int FIELD_A[Const::HEIGHT][Const::WIDTH] = 
    {
        { 0, 0, 1, 0, 0, 0, 0, 0},
        { 0, 1, 1, 0, 1, 0, 1, 0},
        { 0, 1, 1, 0, 1, 0, 1, 0},
        { 0, 0, 0, 0, 1, 0, 1, 0},
        { 0, 1, 0, 1, 1, 1, 0, 0},
        { 0, 1, 0, 1, 1, 0, 0, 1},
        { 0, 0, 0, 1, 1, 1, 0, 1},
        { 0, 1, 0, 0, 0, 1, 0, 1}
    };
};

struct Plane
{
    int x;
    int y;

    bool operator==(const Plane pos)
    {
        return x == pos.x && y == pos.y;
    }

    bool operator!=(const Plane pos)
    {
        return x != pos.x || y != pos.y;
    }
};

int main()
{
    Plane start = {2, 3};
    Plane goal = {6, 6};

    vector<Plane> path;
    vector<Plane> queue;
    bool visited[Maps::Const::HEIGHT][Maps::Const::WIDTH];
    Plane parent[Maps::Const::HEIGHT][Maps::Const::WIDTH];
    for (int i = 0; i < Maps::Const::HEIGHT; ++i)
    {
        for (int j = 0; j < Maps::Const::WIDTH; ++j)
        {
            visited[i][j] = false;
            parent[i][j] = {-1, -1};
        }
    }

    vector<Plane> directions = 
    {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };

    int enqueueCount = 0, dequeueCount = 0;
    int loopCount = 0;
    queue.resize(Const::QUEUE_CAPACITY - 1, {-1, -1});
    queue[enqueueCount] = start;
    ++enqueueCount;
    visited[start.y][start.x] = true;

    while (enqueueCount % Const::QUEUE_CAPACITY != dequeueCount % Const::QUEUE_CAPACITY)
    {
        Plane pos = queue[loopCount % Const::QUEUE_CAPACITY];
        queue[dequeueCount % Const::QUEUE_CAPACITY] = {-1, -1};
        ++dequeueCount;
        // ゴール判定
        if (pos.x == goal.x && pos.y == goal.y)
        {
            Plane current = goal;

            while (!(current.x == start.x && current.y == start.y))
                {
                    path.insert(path.begin(), current);
                    current = parent[current.y][current.x];
                }
            path.insert(path.begin(), start);
            break;
        }

        // 探索処理
        for (int i = 0; i < directions.size(); ++i)
        {
            int searchX = pos.x + directions[i].x;
            int searchY = pos.y + directions[i].y;
            if (searchX >= 0 && searchX < Maps::Const::WIDTH && searchY >= 0 && searchY < Maps::Const::HEIGHT)
            {
                if(Maps::FIELD_A[searchY][searchX] == 0 && !visited[searchY][searchX])
                {
                    Plane hold = {searchX, searchY};
                    auto it = find(queue.begin(), queue.end(), hold);
                    if (it == queue.end())
                    {
                    queue[enqueueCount % Const::QUEUE_CAPACITY] = hold;
                    ++enqueueCount;
                    visited[searchY][searchX] = true;
                    parent[searchY][searchX] = pos;
                    }
                }
            }
        }
        ++loopCount;
    }

    // エラー判定
    if (path.size() <= 0)
    {
        cout << "目的地に到達できません" << endl;
        return -1;
    }
    // 成功処理
    for (int i = 0; i < path.size(); ++i)
    {
        cout << format("({},{})", path[i].x, path[i].y) << endl;
    }
    return 0;
}