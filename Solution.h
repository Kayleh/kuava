#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int Leetcode(vector<string> &words) {
        const string target = "leetcode";
        int minIndex = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].find(target) != string::npos) {
                minIndex = min(minIndex, i);
            }
        }
        return minIndex == INT_MAX ? -1 : minIndex;


    };
};
