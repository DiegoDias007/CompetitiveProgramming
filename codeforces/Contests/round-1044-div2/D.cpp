#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> dp(n + 1);
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
        ll case1 = dp[i - 1] + a[i] - 1;
        ll case2 = dp[i - 2] + a[i - 1] + max(0ll, a[i] - (i - 1));
        dp[i] = min(case1, case2);
    }
    cout << dp[n] << endl;
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