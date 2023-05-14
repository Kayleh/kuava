#include "Solution.h"
#include "testIO.h"
#define debug
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

#ifdef debug
#define INPUT_FILE "D:/project/kayleh/kuava/src/RUN/cpp/leetcode/test.in"
#define OUTPUT_FILE "D:/project/kayleh/kuava/src/RUN/cpp/leetcode/test.out"
#endif
using namespace std;

int main()
{
    REGISTER_CONSTRUCTOR_SOLUTION;
    REGISTER_MEMBERFUNCTION_SOLUTION(doesValidArrayExist);
    while (true)
    {
        executor.constructSolution();
        executor.executeSolution();
    }
}
