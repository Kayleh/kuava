using namespace std;
#include <bits/stdc++.h>

/**
 * 您的计算机的键盘具有三个键：“a”键、Shift 键和 Caps Lock 键。Caps Lock 键上有一盏灯。最初，Caps Lock 键上的灯熄灭，屏幕显示空字符串。
 * 您可以按任意顺序任意次数地执行以下三个操作：
 *
 * 花费X仅按下“a”键的毫秒数。如果 Caps Lock 键上的灯熄灭，a则会附加到屏幕上的字符串；如果它打开则为A。
 * 花费Y同时按下“a”键和 Shift 键的毫秒数。如果 Caps Lock 键上的灯熄灭，A则会附加到屏幕上的字符串；如果它打开，则为a。
 * 花费Z为按下 Caps Lock 键的毫秒数。如果 Caps Lock 键上的灯熄灭，它就会亮起；如果它打开，它会关闭。
 * 
 * 给定一个字符串S:
 * 由A和a组成，确定至少需要多少毫秒才能使屏幕上显示的字符串等于S.
 */
int main()
{
    // N: 移动的次数
    // M: 恢复健康的物品数
    // H：初始健康值
    // K：低于K点健康值时，无法移动
    int N, M, H, K;
    string S; // 移动的方向，移动一次消耗 1点健康值(R:向右移动，L:向左移动，U:向上移动，D:向下移动 )

    cin >> N >> M >> H >> K;
    cin >> S;

    // 恢复健康的物品
    vector<pair<int, int>> items(M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        items[i] = make_pair(a, b);
    }

    // 从(0,0)开始移动，移动一次消耗 1点健康值(R:向右移动，L:向左移动，U:向上移动，D:向下移动 )
    // 如果健康值小于0，无法继续移动
    // 如果健康值小于K，可以使用恢复健康的物品，恢复健康值到K
    // 如果N次移动完成，且健康值大于等于0，输出Yes，否则输出No
    int x = 0, y = 0;

    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'R')
        {
            x++;
        }
        else if (S[i] == 'L')
        {
            x--;
        }
        else if (S[i] == 'U')
        {
            y++;
        }
        else if (S[i] == 'D')
        {
            y--;
        }

        H--;
        if (H < 0)
        {
            cout << "No" << endl;
            return 0;
        }

        if (H < K)
        {
            // 恢复健康值到K
            for (int j = 0; j < M; j++)
            {
                if (items[j].first == x && items[j].second == y)
                {
                    H = K;
                    break;
                }
            }
        }
    }

    cout << "Yes" << endl;
    // 能否完成N次移动 且 健康值大于等于0
    return 0;
}
