/*
    $ codeforce

    Copyright 2022  Kayleh. All rights reserved.
    @see {@link https://github.com/Kayleh/kuava}

           ,-.                              ,--,                 ,---,
       ,--/ /|                            ,--.'|               ,--.' |
     ,--. :/ |                            |  | :               |  |  :
     :  : ' /                             :  : '               :  :  :
     |  '  /       ,--.--.          .--,  |  ' |       ,---.   :  |  |,--.
     '  |  :      /       \       /_ ./|  '  | |      /     \  |  :  '   |
     |  |   \    .--.  .-. |   , ' , ' :  |  | :     /    /  | |  |   /' :
     '  : |. \    \__\/: . .  /___/ \: |  '  : |__  .    ' / | '  :  | | |
     |  | ' \ \   ," .--.; |   .  \  ' |  |  | '.'| '   ;   /| |  |  ' | :
     '  : |--'   /  /  ,.  |    \  ;   :  ;  :    ; '   |  / | |  :  :_:,'
     ;  |,'     ;  :   .'   \    \  \  ;  |  ,   /  |   :    | |  | ,'
     '--'       |  ,     .-./     :  \  \  ---`-'    \   \  /  `--''
                 `--`---'          \  ' ;             `----'
                                    `--`
@Date: 2020/6/14 19:34
*/
#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define gcd(a, b) __gcd(a, b)             // 最大公约数
#define bitcount(a) __builtin_popcount(a) // 二进制中1的个数
#define lcm(a, b) (a * b / gcd(a, b))     // 最小公倍数
#define swapp(a, b) (a ^= b; b ^= a; a ^= b)
#define forin(item, arr) for (auto item : arr)
#define rep(i, from, to) for (int i = from; i <= to; i++)
#define dep(i, from, to) for (int i = from; i >= to; i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define changeCase(c) (c ^ (1 << 5))           // 大小写互换
#define isLetter(c) (isalpha(c))               // 判断是否为字母
#define INF 0x3f3f3f3f                         // 无穷大
#define NINF 0xc0c0c0c0                        // 无穷小
#define randd(a, b) (rand() % (b - a + 1) + a) // [a, b]
#define all(x) (x).begin(), (x).end()
#define fio                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);
//__builtin_popcountll 用于计算一个数的二进制中1的个数
#ifdef debug
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

using namespace std;

int main()
{
    fio;
    // 9行9列的二维数组
    // 一个二维码的样式是：左上角3*3、右下角3*3的格子是黑色的，这些黑色相邻的（14个格子）是白色的
    // 黑色是#，白色是.
    // 输出一张图中的二维码的左上角的坐标
    // 二维码的左上角的坐标是(1,1)

    int n, m;
    cin >> n >> m;
    char map[n + 1][m + 1];
    rep(i, 1, n)
    {
        string s;
        cin >> s;
        rep(j, 1, m)
        {
            // 
        }
    }

    // 1. 前3行的前3个格子是###.
    // 2. 第4行的前4个格子是....
    // 3. 第7、8、9行的后3个格子是.###
    // 4. 第6行的后4个格子是....

    for (int i = 1; i <= n - 8; i++)
    {
        for (int j = 0; j < m - 8; j++)
        {
            bool isQRCode = true;
            for (int row = i; row <= i + 8; row++)
            {
                for (int col = j; col <= j + 8; col++)
                {
                    // 1. 前3行的前3个格子是###.
                    for (int k = 1; k <= 3; k++)
                    {
                        if (row <= i + 2 && col <= j + 2 && map[row][col] != '#')
                        {
                            isQRCode = false;
                            break;
                        }
                    }
                    // 2. 第4行的前4个格子是....
                    for (int k = 1; k <= 4; k++)
                    {
                        if (row == i + 3 && col <= j + 3 && map[row][col] != '.')
                        {
                            isQRCode = false;
                            break;
                        }
                    }
                    // 3. 第7、8、9行的后3个格子是.###
                    for (int k = 1; k <= 3; k++)
                    {
                        if (row >= i + 6 && col >= j + 6 && map[row][col] != '#')
                        {
                            isQRCode = false;
                            break;
                        }
                    }
                    // 4. 第6行的后4个格子是....
                    for (int k = 1; k <= 4; k++)
                    {
                        if (row == i + 5 && col >= j + 5 && map[row][col] != '.')
                        {
                            isQRCode = false;
                            break;
                        }
                    }
                }
                if (!isQRCode)
                {
                    break;
                }
            }

            if (isQRCode)
            {
                cout << i << " " << j + 1 << endl;
            }
        }
    }

    return 0;
}
