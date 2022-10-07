#include <string>
#include <climits>
#include "vector"

using namespace std;

class Solution {
public:
    int Leetcode(vector<string> &words) {
        // 从一个单词中取一个字母所需要的代价，为该字母左边和右边字母数量之积
        // 返回取得字符串 helloleetcode 的最小代价
        string target = "helloleetcode"; // 从多个单词中取字母，使得取得的字符串为 helloleetcode
        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(target.size() + 1,
                                              INT_MAX));// dp[i][j]表示从第i个单词中取字母，取得字符串为need.substring(0,j)的最小代价

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (words[i][j] == target[0]) {
                    dp[i][1] = j;
                }
            }

            for (int j = 1; j < target.size(); j++) {
                for (int k = 0; k < words[i].size(); k++) {
                    if (words[i][k] == target[j]) {
                        for (int l = 0; l < words[i].size(); l++) {
                            if (dp[i][j] != INT_MAX && words[i][l] == target[j - 1]) {
                                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (k - l) * (k - l));
                            }
                        }
                    }
                }
            }

            for (int j = 0; j < words[i].size(); j++) {
                if (words[i][j] == target[target.size() - 1]) {
                    dp[i][target.size()] = min(dp[i][target.size()], dp[i][target.size() - 1] + j * j);
                }
            }

            if (dp[i][target.size()] == INT_MAX) {
                return -1;
            }

        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, dp[i][target.size()]);
        }

        return res;


    }

};