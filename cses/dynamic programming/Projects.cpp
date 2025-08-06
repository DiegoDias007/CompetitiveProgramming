// https://cses.fi/problemset/task/1140/

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
    vector<pair<pair<ll, ll>, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }

    sort(a.begin(), a.end(), [&](auto p1, auto p2) {
        ll p1_start = p1.first.first, p1_end = p1.first.second;
        ll p2_start = p2.first.first, p2_end = p2.first.second;
        if (p1_end != p2_end) return p1_end < p2_end;
        else return p1_start < p2_start; 
    });

    // dp[i]: maximum profit if we consider projects
    // that end at most at day i
    map<ll, ll> dp;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        ll start_day = a[i].first.first, end_day = a[i].first.second, profit = a[i].second;
        auto ptr = dp.lower_bound(start_day);
        if (ptr != dp.begin()) ptr--;

        auto already_best = dp.lower_bound(end_day);
        if (already_best != dp.begin()) already_best--;

        // take
        dp[end_day] = max(dp[end_day], profit + ptr->second);
        // dont take
        dp[end_day] = max(dp[end_day], already_best->second);
    }

    ll ans = 0;
    for (auto [day, profit] : dp) {
        ans = max(ans, profit);
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