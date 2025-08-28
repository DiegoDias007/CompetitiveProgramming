// https://codeforces.com/problemset/problem/1875/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> seen(n);
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        mp[cur]++;
        if (cur < n) seen[cur] = true;
    }
    
    int mex_a = n;
    for (int i = 0; i < n; i++) {
        if (!seen[i]) {
            mex_a = i;
            break;
        }
    }

    if (mex_a == 0) {
        cout << 0 << endl;
        return;
    }

    // dp[x]: min score to get MEX(a) = x;
    vector<int> dp(mex_a + 1, 1e9);
    dp[mex_a] = 0;
    for (int ai = mex_a; ai >= 0; ai--) {
        for (int aj = ai - 1; aj >= 0; aj--) {
            dp[aj] = min(dp[aj], dp[ai] + (mp[aj] - 1) * ai + aj);
        }
    }
    cout << dp[0] << endl;
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