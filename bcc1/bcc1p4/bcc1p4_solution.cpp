#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  string s;
  cin >> N >> K >> s;

  // Storing bird positions and worm positions
  vector<int> birds, worms;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'B') birds.push_back(i);
    if (s[i] == 'W') worms.push_back(i);
  }

  int B = birds.size();
  int W = worms.size();

  if (B == 0 || W == 0) {
    cout << 0 << "\n";
    return 0;
  }

  // DP Table, dp[i][j] = maximum worms eaten using first i birds and first j worms.
  vector<vector<int>> dp(B+1, vector<int>(W+1, 0));

  // For each bird
  for (int i = 1; i <= B; i++) {
    int bird = birds[i-1];

    // For each worm
    for (int j = 1; j <= W; j++) {
      dp[i][j] = max(dp[i][j], dp[i][j-1]); // skip worm
      dp[i][j] = max(dp[i][j], dp[i-1][j]); // skip bird

      int R = j - 1;// worm index if we end interval at j-1

      // try all L such that bird eats interval [L..R]
      for (int L = R; L >= 0; L--) {
        int cost = (worms[R] - worms[L]) +
                   min(abs(bird - worms[L]), abs(bird - worms[R]));

        if (cost > K) break; // (Cost cannot exceed K, K = 50 at most)

        int gained = (R - L + 1);
        // Update dp, maximum worms = previous birds dp[i-1][L] + worms eaten by this bird in this interval.
        dp[i][j] = max(dp[i][j], dp[i-1][L] + gained);
      }
    }
  }

  cout << dp[B][W] << "\n";
  return 0;
}
