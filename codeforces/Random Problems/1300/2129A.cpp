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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<pair<int, int>> best(2*n + 1, {-1, -1});
    for (int i = 0; i < n; i++) {
        int x = a[i].first;
        int y = a[i].second;
        if (y > best[x].first) {
            best[x].first = y;
            best[x].second = i + 1;
        }
    }

    vector<int> ans;
    for (int i = 0; i <= 2*n; i++) {
        if (best[i].first != -1) ans.push_back(best[i].second);
    }

    cout << ans.size() << endl;
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