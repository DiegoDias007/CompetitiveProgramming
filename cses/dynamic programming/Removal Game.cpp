// https://cses.fi/problemset/task/1097/

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

pair<ll, ll> get_best(pair<ll, ll> p1, pair<ll, ll> p2) {
    if (p1.first > p2.first) {
        return p1;
    } else if (p1.first < p2.first) {
        return p2;
    } else {
        if (p1.second < p2.second) {
            return p1;
        } else {
            return p2;
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp[i][j]: State is {x, y}. Given that the game is played
    // in the array starting at index i and ending at index j,
    // if both players play optimally, x is the score of the current 
    // player and y of its opponent.
    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n));
    for (int i = 0; i < n; i++) dp[i][i] = {a[i], 0};

    for (int size = 2; size <= n; size++) {
        for (int l = 0, r = size - 1; r < n; l++, r++) {
            pair<ll, ll> take_left = {a[l] + dp[l + 1][r].second, dp[l + 1][r].first};
            pair<ll, ll> take_right = {a[r] + dp[l][r - 1].second, dp[l][r - 1].first};
            dp[l][r] = get_best(take_left, take_right);
        }
    }

    cout << dp[0][n - 1].first << endl;
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