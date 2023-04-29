#include <bits/stdc++.h>

using namespace std;

class bit
{
private:
    /* data */
public:
    /**
     *
     * @brief lowbit
     * @param num
     * @return  num 的二进制表示中，最低位的 1 的位置。
     */
    int lowbit(int num)
    {
        return num & (-num);
    }

    bit(/* args */);
    ~bit();
};

bit::bit(/* args */)
{
}

bit::~bit()
{
}
