#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int arr[n];
  int arrSum[n] = {0};
  int profit = 0, borrow = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < n; ++i)
  {
    borrow = max(borrow, arr[i] * 100);
    borrow -= k;

    if (borrow > arr[i] * 100)
    {
      profit = max(profit, borrow - arr[i] * 100);
    }
  }

  cout << profit << "\n";

  return 0;
}