#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1;
    int start = 0;

    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
      if (i < n - 1 && s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        start = i;
        maxLen = 2;
      }
    }

    for (int len = 3; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          start = i;
          maxLen = len;
        }
      }
    }
    return s.substr(start, maxLen);
  }
};