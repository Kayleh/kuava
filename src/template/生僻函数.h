// accumulate 累加函数

// 匿名函数
/*
 int main()
{
    // 递归
    function<void(int, int, int)> dfs = [&](int x, int y, int n)
    {

    };
    dfs(0, 0, n);
    return 0;
}
*/

//  mp.find(r)!=mp.end()) 表示在哈希表中找到了r

// 产生随机数
/*
vector<int> nums;
// 用时间做种，每次产生随机数不一样 , srand()用来设置rand()产生随机数时的随机数种子,参数seed是个整数，用来设置随机数生成器的种子值, 用srand()产生随机数时一定要先用rand()产生一个随机数作为种子，否则srand()产生的随机数序列在相同的程序中是一样的; sramd的作用域是全局的，一旦设置，后面的rand()都会使用这个种子，直到 下一次srand()被调用。
srand((unsigned)time(NULL));
for (int i = 0; i < 10; i++)
    nums.push_back(rand() % 100); // 产生100以内的随机数
 */