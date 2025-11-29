#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<bool> prefixXOR(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        char C;
        cin >> C;
        bool val = (C == 'F');
        prefixXOR[i] = prefixXOR[i - 1] ^ val;
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;

        bool parity;

        if (L <= R) {
            parity = prefixXOR[R] ^ prefixXOR[L - 1];
        } else {
            parity = (prefixXOR[N] ^ prefixXOR[L - 1]) ^ prefixXOR[R];
        }

        cout << (parity ? "YES\n" : "NO\n");
    }

    return 0;
}
