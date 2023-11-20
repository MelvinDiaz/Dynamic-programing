#include <iostream>
using namespace std;

int main()
{
  int n, m, k;
  cin >> k;
  while (k--)
  {
    cin >> n >> m;
    int arrSum[n];
    int maxSum = 0;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
      arrSum[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
      int j = i - 1;
      int l = i + 1;

      if (arr[i] == m)
      {

        arrSum[i] = arr[i];
        while (arr[j] != m && j >= 0 && arr[j] > m)
        {
          arrSum[i] = arrSum[i] + arr[j];
          j--;
        }
        while (arr[l] != m && l <= n && arr[l] > m)
        {
          arrSum[i] = arrSum[i] + arr[l];
          l++;
        }
        if (arrSum[i] > maxSum)
        {
          maxSum = arrSum[i];
        }
      }
    }
    cout << maxSum << "\n";
  }
}