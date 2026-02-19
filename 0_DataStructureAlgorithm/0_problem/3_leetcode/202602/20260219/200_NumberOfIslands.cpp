#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int result = 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        cout << grid.size() << endl;
        cout << grid[0].size() << endl;
        cout << visited.size() << endl;
        cout << visited[0].size() << endl;

        int maxX = visited[0].size();
        int maxY = visited.size();


        queue<pair<int, int>> q;
        
        for (int i = 0; i < maxY; i++)
        {
            for (int j = 0; j < maxX; j++)
            {
                cout << i << "//" << j << ":" << visited[i][j] << "," << grid[i][j] << endl;

                if (visited[i][j] || grid[i][j] == '0')
                    continue;

                cout << "in !! " << endl;
                
                q.push(make_pair(j, i));
                visited[i][j] = true;
                result++;

                while (!q.empty())
                {
                    auto pop = q.front();
                    q.pop();

                    int popX = pop.first;
                    int popY = pop.second;

                    if (popX + 1 >= 0 && popX + 1 < maxX && !visited[popY][popX + 1] && grid[popY][popX + 1] == '1')
                    {
                        q.push(make_pair(popX + 1, popY));
                        visited[popY][popX + 1] = true;
                    }

                    if (popX - 1 >= 0 && popX - 1 < maxX && !visited[popY][popX - 1] && grid[popY][popX - 1] == '1')
                    {
                        q.push(make_pair(popX - 1, popY));
                        visited[popY][popX - 1] = true;
                    }

                    if (popY + 1 >= 0 && popY + 1 < maxY && !visited[popY + 1][popX] && grid[popY + 1][popX] == '1')
                    {
                        q.push(make_pair(popX, popY + 1));
                        visited[popY + 1][popX] = true;
                    }

                    if (popY - 1 >= 0 && popY - 1 < maxY && !visited[popY - 1][popX] && grid[popY - 1][popX] == '1')
                    {
                        q.push(make_pair(popX, popY - 1));
                        visited[popY - 1][popX] = true;
                    }
                }
            }
        }
        
        return result;
    }
};

int main(void)
{
    Solution solusion;

    //vector<vector<char>> v
    //{
    //    {'1','1','1','1','0'},
    //    {'1','1','0','1','0'},
    //    {'1','1','0','0','0'},
    //    {'0','0','0','0','0'}
    //};

    vector<vector<char>> v
    {
        { '0', '1', '0' },
        { '1', '0', '1' },
        { '0', '1', '0' }
    };

    cout << "reslut : " << solusion.numIslands(v);

}