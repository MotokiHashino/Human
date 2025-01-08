#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <algorithm>

#define MAP_HEIGHT  8
#define MAP_WIDTH   8

using namespace std;

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
    int map[MAP_HEIGHT][MAP_WIDTH] = 
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

    Plane start = {2,3};
    Plane goal = {6,6};

    vector<Plane> path;
    vector<Plane> stack;
    bool visited[MAP_HEIGHT][MAP_WIDTH];
    Plane parent[MAP_HEIGHT][MAP_WIDTH];
    for (int i = 0; i < MAP_HEIGHT; ++i)
    {
        for (int j = 0; j < MAP_WIDTH; ++j)
        {
            visited[i][j] = false;
            parent[i][j] = {-1, -1};
        }
    }

    vector<Plane> directions = 
    {
        {-1,0},{0,-1},{1,0},{0,1}
    };

    stack.push_back(start);
    visited[start.y][start.x] = true;

    while (stack.size() > 0)
    {
        Plane pos = stack.back();
        stack.pop_back();

        // ゴール判定
        if (pos.x == goal.x && pos.y == goal.y)
        {
            Plane current = goal;

            while (!(current.x == start.x && current.y == start.y))
                {
                    path.insert(path.begin(),current);
                    current = parent[current.y][current.x];

                }
            path.insert(path.begin(),start);

            break;
        }

        //探索処理
        for (int i = 0; i < directions.size(); ++i)
        {
            int searchX = pos.x + directions[i].x;
            int searchY = pos.y + directions[i].y;
            if (searchX >= 0 && searchX < MAP_WIDTH && searchY >= 0 && searchY < MAP_HEIGHT)
            {
                if(map[searchY][searchX] == 0 && !visited[searchY][searchX])
                {
                    Plane hold = {searchX,searchY};
                    auto it = find(stack.begin(), stack.end(), hold);
                    if (it == stack.end())
                    {
                    stack.emplace_back(hold);
                    visited[searchY][searchX] = true;
                    parent[searchY][searchX] = pos;
                    }
                }
            }
        }
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