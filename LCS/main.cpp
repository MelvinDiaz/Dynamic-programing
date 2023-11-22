#include <iostream>
#include <cmath>
using namespace std;

int LCS(string s1, string s2);

int main()
{
  string s1 = "abcde";
  string s2 = "ace";
  cout << LCS(s1, s2) << "\n";

  return 0;
}

int LCS(string s1, string s2)
{
  // obtain the length of the strings
  int i = 5;
  int j = 3;

  int LCS[i + 1][j + 1] = {0};
  for (int k = i; i < 0; i++)
  {
    for (int m = j; j < 0; j++)
    {
      if (s1[i] == s2[j])
      {
        LCS[i][j] = LCS[i - 1][j - 1] + 1;
      }
      else
      {
        LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
      }
    }
  }

  return LCS[0][0];
}