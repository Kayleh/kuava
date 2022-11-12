#include <iostream>
#include <vector>
using namespace std;

// 高精度算法的缘由：计算机中的整数类型只能表示有限的整数，而且只能表示有限位数的整数，因此，当需要表示的整数超过了计算机能表示的范围时，就需要使用高精度算法。

/**
 * tCompare  高精比较
 * 设定a>b返回1 a<b返回-1 a=b返回0
 * @param a
 * @param b
 */
int tCompare(string a, string b)
{
    if (a.size() != b.size()) //如果字符串长度不同那么长度大的那个就是更大的大数
    {
        if (a.size() > b.size())
            return 1;
        else
            return -1;
    }
    else //如果字符串长度相同我们通过直接比较字符串的字典序来判断大小
    {
        if (a > b)
            return 1;
        else if (a == b)
            return 0;
        else
            return -1;
    }
}

/**
 * tAdd  高精加法
 * 通过字符串的形式来实现高精度的加法
 * @param a
 * @param b
 */
string tadd(string a, string b)
{
    int n = max(a.size(), b.size()) + 1;
    vector<int> ans(n, 0);                             //开辟一个足够存储结果的数组，结果的位数最多为 位数最多的那个数的位数加一(考虑进位)
    int i = a.size() - 1, j = b.size() - 1, k = n - 1; //从个位开始通过模拟竖式进行大数加法
    while (i >= 0 && j >= 0)                           //当两数均未加完时
    {
        ans[k--] = (a[i--] - '0') + (b[j--] - '0'); //我们让我们的数组存储每一位相加的结果注意将字符串转为整型数字
    }
    //检测是否有某个数的高位未加完将其直接存入数组中
    while (j >= 0)
    {
        ans[k--] = (b[j--] - '0');
    }
    while (i >= 0)
    {
        ans[k--] = (a[i--] - '0');
    }
    string c = "";                  //创建一个字符串去存储答案
    for (int i = n - 1; i > 0; i--) //因为之前的竖式加每一位都没考虑进位所以我们从最后开始检查进位
    {                               //因为是加法如果有进位最多也就进一
        if (ans[i] >= 10)           //如果大于10说明应该进位那么我们让此位减10它的高一位加1
        {
            ans[i] -= 10;
            ans[i - 1]++;
        }
        c.insert(0, 1, ans[i] + '0'); //处理后的结果转化为字符插入结果字符的首位
    }

    if (ans[0] > 0) //检查最最高位是否大于0如果两数相加没有进位那么这一位就是0我们就不必存储它否则则放入字符串
    {
        c.insert(0, 1, ans[0] + '0');
    }
    return c; //返回答案
}

/**
 * tSub  高精减法
 * @param a
 * @param b
 */
string tSub(string a, string b)
{
    string c = "";           //创建一个字符串去存储答案
    if (tCompare(a, b) == 0) //先比较一下两数大小如果相等我们直接返回0即可
        return "0";
    if (tCompare(a, b) == -1) //如果a<b那么我们交换两数的值同时在答案字符串中先放入一个负号
    {
        swap(a, b);
        c.push_back('-');
    }
    int n = a.size();
    //开辟一个足够存储结果的数组  减法结果的位数最多为位数最多的那个数的位数我们保证了a为的大数所以就是a的位数
    vector<int> ans(n, 0);
    int i = a.size() - 1, j = b.size() - 1, k = n - 1; //从个位开始模拟竖式减法
    int t = 0;                                         //表示低位的借位情况  0:无借位   1:有借位
    while (i >= 0)                                     //同加法一样模拟运算我们知道a是大数所以a遍历完竖式才完成
    {
        char nowb; //被减数当前位有数就正常减 没有数说明就是0
        if (j >= 0)
            nowb = b[j];
        else
            nowb = '0';
        ans[k] = a[i] - nowb - t; //对应位相减同时减去低位的借位
        if (ans[k] < 0)           //如果结果小于0 则向高位借一位
        {
            t = 1;
            ans[k] += 10;
        }
        else
            t = 0;     //否则向高位无借位
        k--, i--, j--; //继续判断高一位
    }
    bool flag = true; //这里与加法不同高位可能出现多个零开头的情况我们需要找到第一不是零的地方再存数
    for (int i = 0; i < n; i++)
    {
        if (flag && ans[i] == 0) //如果当前数为0且未存数则不执行存数操作
            continue;
        flag = false; //一旦存入数更改标志位
        c.push_back(ans[i] + '0');
    }
    return c; //返回结果
}

/**
 * tMul  高精乘法
 * @param a
 * @param b
 */
string tMul(string a, string b)
{
    if (a == "0" || b == "0") //其中有一个为0时直接返回0
        return "0";
    vector<int> ans; //开辟一个足够存储结果的数组
    int n = a.size(), m = b.size();
    ans.resize(n + m, 0);       //乘法结果的位数最多为两数的位数之和
    for (int i = 0; i < n; i++) //这里从高位开始和从低位开始无所谓我们将两数相乘的结果不考虑放到对应位上最后去检测进位即可
    {                           //例如个位乘百位的结果 以及十位乘十位的结果 都放到百位上
        for (int j = 0; j < m; j++)
        {
            ans[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int i = n + m - 1; i > 0; i--) //我们从低位开始检查进位
    {
        if (ans[i] >= 10) //如果大于10说明有进位但乘法的进位不一定只进1
        {
            ans[i - 1] += (ans[i] / 10); //高位加地位的高于个位部分
            ans[i] %= 10;                //低位对十求余
        }
    }
    string c = "";    //创建字符串存储答案
    bool flag = true; //同减法一样找到第一个不是0的位置开始存数
    for (int t = 0; t < n + m; t++)
    {
        if (flag && ans[t] == 0)
            continue;
        flag = false;
        c.push_back(ans[t] + '0');
    }
    return c; //返回答案
}

/**
 * tDiv  高精除法
 * @param a
 * @param b
 */
vector<string> tDiv(string a, string b) //高精除法
{
    vector<string> ans(2, "0"); //先创建两个字符串空间去存储答案一个存商一个存余数
    if (tCompare(a, b) == -1)   //如果被除数比除数小商为0余数为a返回答案即可
    {
        ans[1] = a;
        return ans;
    }
    else if (tCompare(a, b) == 0) //如果被除数与除数相等商为1余数为0返回答案即可
    {
        ans[0] = "1";
        return ans;
    }
    else //否则我们需要模拟除法的竖式来进行计算
    {
        string res = ""; //创建存储商的字符串
        int m1 = a.size(), m2 = b.size();
        string a1 = a.substr(0, m2 - 1);
        for (int i = m2 - 1; i < m1; i++) //模拟竖式从高位开始依次取数减去除数能减几个该位商的当前位就是几
        {
            if (a1 == "0") //如果a1为0为了防止a1出现0开头的情况我们将它清空
                a1 = "";
            a1.push_back(a[i]); //我们从被除数中取一个数放入a1继续减
            int e = 0;
            while (tCompare(a1, b) >= 0) //当a1大于等于除数时便一直减同时e累加
            {
                e++;
                a1 = tSub(a1, b);
            }
            if (res.size() || e) //如果res不为空或者e不为0我们存储他
                res.push_back(e + '0');
        }
        ans[0] = res; //最后res就是商
        ans[1] = a1;  // a1就是余数
        return ans;   //返回答案
    }
}

/**
 * tfac  高精阶乘
 * @param a
 * @param b
 */
string tfac(string a) //高精阶乘
{                     /*我们还可以利用高精度减法和乘法实现大数的阶乘(最大可运行出10000左右的阶乘)*/
    if (a == "1")
        return a;
    else
        return tMul(a, tfac(tSub(a, "1")));
}

/**
 * 高精度快速幂
 * @param a
 * @param b
 */
string tPow(string a, string b) //高精快速幂
{
    if (b == "0")
        return "1";
    else if (b == "1")
        return a;
    else
    {
        string ans = tPow(a, tDiv(b, "2")[0]);
        ans = tMul(ans, ans);
        if (tDiv(b, "2")[1] == "1")
            ans = tMul(ans, a);
        return ans;
    }
}

/**
 * 高精度快速幂取模
 * @param a
 * @param b
 * @param c
 */
string tPowMod(string a, string b, string c) //高精快速幂取模
{
    if (b == "0")
        return "1";
    else if (b == "1")
        return tDiv(tMul(a, "1"), c)[1];
    else
    {
        string ans = tPowMod(a, tDiv(b, "2")[0], c);
        ans = tDiv(tMul(ans, ans), c)[1];
        if (tDiv(b, "2")[1] == "1")
            ans = tDiv(tMul(ans, a), c)[1];
        return ans;
    }
}

/**
 * 高精度欧拉函数
 * @param a
 */
string tEuler(string a) //高精欧拉函数
{
    string ans = a;
    for (int i = 2; i <= sqrt(stoi(a)); i++)
    {
        if (tDiv(a, to_string(i))[1] == "0")
        {
            ans = tMul(ans, to_string(i - 1));
            ans = tDiv(ans, to_string(i))[0];
            while (tDiv(a, to_string(i))[1] == "0")
                a = tDiv(a, to_string(i))[0];
        }
    }
    if (a != "1")
        ans = tMul(ans, tSub(a, "1"));
    return ans;
}

/**
 * 高精度取模
 *
 * @param a
 * @param b
 */
string tMod(string a, string b) //高精取模
{
    return tDiv(a, b)[1];
}

int main()
{
    string a, b;
    string add_ans, subtract_ans, multiply_ans, factorial_ans;
    vector<string> divide_ans;
    int compare_ans;
    cin >> a >> b;

    compare_ans = tCompare(a, b);
    cout << compare_ans << endl;

    add_ans = tadd(a, b);
    cout << add_ans << endl;

    subtract_ans = tSubtract(a, b);
    cout << subtract_ans << endl;

    multiply_ans = tMultiply(a, b);
    cout << multiply_ans << endl;

    divide_ans = tDivide(a, b);
    cout << divide_ans[0] << endl
         << divide_ans[1] << endl;

    //	factorial_ans=myFactorial(a);
    //	cout<<factorial_ans<<endl;
    return 0;
}
//......................................................................................
