#include <iostream>
#include <vector>

using namespace std;

vector<string> grid;
vector<vector<bool>> visited;
int iceCount = 0;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

bool valid(int x, int y)
{
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
}

// 如果移动后的位置是冰块. ，那么继续移动到遇到石头#或者边界为止
// 如果移动后的位置是石头#或边界，那么尝试转向
void dfs(int x, int y)
{
    visited[x][y] = true;
    if (grid[x][y] == '.')
    {
        iceCount++;
    }

    for (int i = 0; i < 4; ++i)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (valid(newX, newY) && !visited[newX][newY])
        {
            dfs(newX, newY);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    grid.resize(n);
    visited.resize(n, vector<bool>(m, false));
    iceCount = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    dfs(1, 1);
    cout << "Number of ice squares touched: " << iceCount << endl;
    return 0;
}
