#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<pair<int, int>> top(n), bot(n);
    top[0] = {a[0][0], a[0][0]};
    bot.back() = {a[1].back(), a[1].back()};
    for (int i = 1; i < n; i++) {
        top[i].first = min(top[i - 1].first, a[0][i]);
        top[i].second = max(top[i - 1].second, a[0][i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        bot[i].first = min(bot[i + 1].first, a[1][i]);
        bot[i].second = max(bot[i + 1].second, a[1][i]);
    }
    
    vector<int> mn(2*n + 1, INF);
    for (int i = 0; i < n; i++) {
        int l = min(top[i].first, bot[i].first);
        int r = max(top[i].second, bot[i].second);
        mn[l] =  min(mn[l], r);
    }

    ll ans = 0;
    int mn_r = INF;
    for (int l = 2*n; l >= 1; l--) {
        int r = mn[l];
        mn_r = min(mn_r, r);
        if (mn_r != INF) ans += 2*n - mn_r + 1;
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