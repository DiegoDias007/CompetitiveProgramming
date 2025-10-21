#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 1e9 + 7;

void add(int& x, int& y) {
    x = (1ll * x + y) % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1)), dp0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {

        dp0 = dp;

        // iniciando nova subsequence
        add(dp[a[i]][0], dp[0][0]);

        // adicionando a[i] subsequences existentes
        for (int mx1 = 1; mx1 <= n; mx1++) {
            for (int mx2 = 0; mx2 < mx1; mx2++) {
                if (a[i] >= mx1) add(dp[a[i]][mx2], dp0[mx1][mx2]);
                if (mx2 <= a[i] && a[i] < mx1) add(dp[mx1][a[i]], dp0[mx1][mx2]); 
            }
        }
    }

    int ans = 0;
    for (int mx1 = 0; mx1 <= n; mx1++) {
        for (int mx2 = 0; mx2 <= n; mx2++) {
            add(ans, dp[mx1][mx2]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}