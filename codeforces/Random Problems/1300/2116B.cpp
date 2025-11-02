#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 998244353;

int pw(int a, int b) {
    if (b == 0) return 1;
    int p = pw(a, b / 2);
    int pp = (1ll * p * p) % MOD;
    if (b % 2 == 1) pp = (1ll * pp * a) % MOD;
    return pp;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int best_a = 0, best_b = 0;
    vector<int> ans(n);
    ans[0] = (pw(2, a[0]) + pw(2, b[0])) % MOD;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[best_a]) best_a = i;
        if (b[i] > b[best_b]) best_b = i;
        bool use_a = a[best_a] > b[best_b];
        use_a |= a[best_a] == b[best_b] && a[best_a] + b[i - best_a] > a[i - best_b] + b[best_b];
        if (use_a) ans[i] = (pw(2, a[best_a]) + pw(2, b[i - best_a])) % MOD;
        else ans[i] = (pw(2, a[i - best_b]) + pw(2, b[best_b])) % MOD;
    }
    print_vec(ans);
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