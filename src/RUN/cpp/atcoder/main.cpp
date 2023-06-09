using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define fio                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Strawberry
{
    int x, y;
};

bool sortByX(const Strawberry &s1, const Strawberry &s2)
{
    if (s1.x == s2.x)
        return s1.y < s2.y;
    return s1.x < s2.x;
}

int main()
{
    int W, H, N;
    cin >> W >> H >> N;

    vector<Strawberry> strawberries(N);
    for (int i = 0; i < N; i++)
        cin >> strawberries[i].x >> strawberries[i].y;

    sort(strawberries.begin(), strawberries.end(), sortByX);

    int min_strawberries = N;
    int max_strawberries = 0;

    // Lines parallel to y-axis (x = a)
    for (int a = 1; a < W; a++)
    {
        int left_count = 0;
        int right_count = 0;

        for (int i = 0; i < N; i++)
        {
            if (strawberries[i].x < a)
                left_count++;
            else
                right_count++;
        }

        int curr_min_strawberries = left_count * (N - right_count);
        min_strawberries = min(min_strawberries, curr_min_strawberries);

        int max_interval = 0;

        if (left_count > 0)
            max_interval = max(max_interval, strawberries[left_count - 1].y - 1);
        if (right_count > 0)
            max_interval = max(max_interval, H - strawberries[left_count].y);

        max_strawberries = max(max_strawberries, max(max_interval, left_count + right_count));
    }

    // Lines parallel to x-axis (y = b)
    for (int b = 1; b < H; b++)
    {
        int above_count = 0;
        int below_count = 0;

        for (int i = 0; i < N; i++)
        {
            if (strawberries[i].y < b)
                above_count++;
            else
                below_count++;
        }

        int curr_min_strawberries = above_count * (N - below_count);
        min_strawberries = min(min_strawberries, curr_min_strawberries);

        int max_interval = 0;

        if (above_count > 0)
            max_interval = max(max_interval, strawberries[above_count - 1].x - 1);
        if (below_count > 0)
            max_interval = max(max_interval, W - strawberries[above_count].x);

        max_strawberries = max(max_strawberries, max(max_interval, above_count + below_count));
    }

    cout << min_strawberries << " " << max_strawberries << endl;

    return 0;
}
