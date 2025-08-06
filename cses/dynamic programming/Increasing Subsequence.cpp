// https://cses.fi/problemset/task/1145/

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int INF = 2E9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp[k]: minimum possible tail element of a 
    // increasing subsequence of size k.
    vector<int> dp(n + 1, INF);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (idx > 0) idx--;
        dp[idx + 1] = min(dp[idx + 1], a[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] != INF) {
            ans = i;
        }
    }
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