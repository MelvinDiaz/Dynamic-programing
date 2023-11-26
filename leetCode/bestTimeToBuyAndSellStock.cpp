#include <bits/stdc++.h>
using namespace std;

// Explanation of the problem
// The problem consisnt of you buying stock one day and only that day and
// selling it on a future day. You can only buy one stock and sell one stock.
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // Initialize maxProfit to 0 because if there istn't any profit to be made
    int maxProfit = 0;
    // Initialize minSoFar to the first element of the array, because is the min
    // value at the start
    int minSoFar = prices[0];

    for (int i = 1; i < n; ++i) {
      // Update the minSoFar if the current element is less than the minSoFar,
      // we do this because the objective is to buy at the lowest price possible
      minSoFar = min(minSoFar, prices[i]);
      // After we have the minSoFar, we check if its convinient to add it to the
      // maxProfit, we do this by substracting the minSoFar from the current
      // price
      // This will only aplly if the current price is greater than the minSoFar,
      // meaning that the minSoFar is not the current price
      maxProfit = max(maxProfit, prices[i] - minSoFar);
    }

    return maxProfit;
  }
};
