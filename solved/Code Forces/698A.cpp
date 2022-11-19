#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1e5 + 9;
const long long mod = 1e9+7;
const long long inf = 2e9;
 
int dp[109][10], n, a[102];

int main() { 
  ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  // 1 = libur
  // 2 = kontes
  // 3 = gym
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= 3; ++j) {
      if(a[i] == 0) { // hari ini libur
        dp[i][1] = max(dp[i][1], dp[i-1][j]);
      } else if(a[i] == 3) {
        // case contest is the last activity
        if(j != 2) dp[i][2] = max(dp[i][2], dp[i-1][j] + 1);
        else dp[i][2] = max(dp[i][2], dp[i-1][j]);

        // case gym the last activity 
        if(j != 3) dp[i][3] = max(dp[i][3], dp[i-1][j] + 1);
        else dp[i][3] = max(dp[i][3], dp[i-1][j]);

        dp[i][1] = max(dp[i][1], dp[i-1][j]);
      } else {
        if(a[i] == 1) {
          if(j != 2) dp[i][2] = max(dp[i][2], dp[i-1][j] + 1);
          else dp[i][1] = max(dp[i][1], dp[i-1][j]);
        } else {
          if(j != 3) dp[i][3] = max(dp[i][3], dp[i-1][j] + 1);
          else dp[i][1] = max(dp[i][1], dp[i-1][j]);
        }
      }
    }
  }
  int ex = dp[n][1];
  if(a[n] == 1) ex = max(ex,dp[n][2]);
  if(a[n] == 2) ex = max(ex,dp[n][3]);
  if(a[n] == 3) {
    ex = max(ex,dp[n][2]);
    ex = max(ex,dp[n][3]);
  }
  printf("%d\n",n - ex);
}
/*
-jika stak maka lakukan pendeketan lain
-coba kerja dari belakang
-at least do smth instead nothing
-don't get distract from another problem
*/
