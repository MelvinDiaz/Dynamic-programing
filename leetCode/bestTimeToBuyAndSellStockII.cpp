#include <bits/stdc++.h>
using namespace std;

// Explanation of the problem
// In this case we can buy and sell as many times as we want, so we can buy and
// sell every day that passes, so we can add the profit of every day that we can
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // Initialize maxProfit to 0 because if there istn't any profit to be made
    int maxProfit = 0;
    int n = prices.size();
    for (int i = 1; i < n; ++i) {
      // If the current price is greatet than the previous one
      if (prices[i] > prices[i - 1]) {
        // We add the profit of the current day to the maxProfit
        maxProfit += prices[i] - prices[i - 1];
      }
    }
    return maxProfit;
  }
};

/*
if you have a sequence of prices where each price is larger than the previous
one (like 1, 2, 3, 4), it's the same as if you bought on the first day and sold
on the last day (profit = 4 - 1 = 3), or if you bought and sold on each day
(profit = (2 - 1) + (3 - 2) + (4 - 3) = 3).
That's why, in the loop, whenever the current price is greater than the previous
price, you add the difference to maxProfit. This difference represents the
profit you make by buying on the previous day and selling on the current day. By
doing this for every increase in price, you are effectively capturing every
opportunity to make a profit, which leads to the maximum total profit.
*/