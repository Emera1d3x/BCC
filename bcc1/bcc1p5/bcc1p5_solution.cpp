#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int N;
vector<vector<int>> adjList;
vector<int> visited;

vector<long long> dpEmpty, dpNestParent, dpNestAlone;
// dp arrays for each node:
// dpEmpty[u] = number of ways the subtree of u has no nest at u
// dpNestParent[u] = number of ways the subtree of u has a nest at u and u has a parent nest
// dpNestAlone[u] = number of ways the subtree of u has a nest at u without relying on parent

// dfs to fill dp arrays
void dfs(int u, int parent) {
    if (visited[u]) return; // memo (not actually used cause dfs)
    visited[u] = 1;
    long long prodEmpty = 1; // for dpEmpty
    long long prodParent = 1; // for dpNestParent
    long long prodAllEmpty = 1; // helper dpNestAlone

  // for children
    for (int v : adjList[u]) {
        if (v == parent) continue;
        dfs(v, u); 

        long long emptyChild = dpEmpty[v];
        long long withParent = dpNestParent[v];
        long long alone = dpNestAlone[v];

    // if u has a nest and its parent has a nest, child can be empty or with parent
        prodParent = (prodParent * ((emptyChild + withParent) % MOD)) % MOD;

    // if u is empty, child can be empty or alone
        prodEmpty = (prodEmpty * ((emptyChild + alone) % MOD)) % MOD;

    // product of empty children (used to remove invalid "alone" configurations)
        prodAllEmpty = (prodAllEmpty * emptyChild) % MOD;
    }

    dpNestParent[u] = prodParent % MOD;
    // subtract off unallowable case (has nest but no adjacent neighbours with nest)
    dpNestAlone[u] = ((prodParent - prodAllEmpty) % MOD + MOD) % MOD;
    dpEmpty[u] = prodEmpty % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N;
    adjList.assign(N + 1, {});
    dpEmpty.assign(N + 1, 0);
    dpNestParent.assign(N + 1, 0);
    dpNestAlone.assign(N + 1, 0);
    visited.assign(N + 1, 0);

    for (int i = 0; i < N - 1; ++i) {
        int u, v; 
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(1, -1);

    long long ans;
    if (N == 1) {
        ans = 1;
    } else {
        ans = (dpEmpty[1] + dpNestAlone[1]) % MOD;
    }

    cout << ans << "\n";
}
