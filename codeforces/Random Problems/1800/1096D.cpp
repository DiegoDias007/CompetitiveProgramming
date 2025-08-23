// https://codeforces.com/problemset/problem/1096/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const ll INF = 2e18;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<char, int> mp;
    mp['h'] = 1; mp['a'] = 2; mp['r'] = 3; mp['d'] = 4;
    vector<ll> dp(5, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (mp.find(s[i]) == mp.end()) continue;
        int k = mp[s[i]];
        dp[k] = min(dp[k], dp[k - 1]);
        dp[k - 1] += a[i];
    }
    ll ans = INF;
    for (int i = 0; i <= 3; i++) ans = min(ans, dp[i]);
    cout << ans << endl; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}