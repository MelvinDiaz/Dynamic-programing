#include <bits/stdc++.h>
using namespace std;

void knapsack(int maxWeight, int *speedBoost, int *weight, int n) {
  // Initialize the 2x2 matrix and fill it with 0
  int count = 0;
  int itemsSelected[n] = {0};

  int M[n + 1][maxWeight + 1];
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= maxWeight; ++j) {
      if (i == 0 || j == 0) M[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= maxWeight; ++j) {
      if (weight[i - 1] <= j) {
        M[i][j] =
            max(speedBoost[i - 1] + M[i - 1][j - weight[i - 1]], M[i - 1][j]);
      } else
        M[i][j] = M[i - 1][j];
    }
  }

  int i = n, j = maxWeight;
  while (i > 0 && j > 0) {
    // If the value of the current row is not equal to the value of the previous
    // in the matrix
    // Remember, if the value in a ROW is not equal in all the row, it means
    // that the more items you add, the more value you get
    //[0,0,0,0,100,...] When the value passes from 0 to 100, the code adds 1 to
    // the count
    if (M[i][j] != M[i - 1][j]) {
      itemsSelected[i - 1] = i - 1;

      count++;
      j -= weight[i - 1];
    }
    i--;
  }

  cout << count << "\n";
  for (int i = 1; i < n; ++i) {
    if (itemsSelected[i] != 0) {
      cout << itemsSelected[i] << " ";
    }
  }
  cout << "\n";
}

int main() {
  int G, V;
  while (cin >> G >> V) {
    int weight[V], value[V];

    for (int i = 0; i < V; i++) {
      cin >> value[i] >> weight[i];
    }

    knapsack(G, value, weight, V);
  }
  return 0;
}