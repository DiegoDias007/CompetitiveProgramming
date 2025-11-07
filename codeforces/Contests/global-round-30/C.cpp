#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<pair<int, int>> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i].second;
    }

    int ans = 0;
    sort(b.begin(), b.end(), [&](auto p1, auto p2) {
        int y1 = p1.first, c1 = p1.second;
        int y2 = p2.first, c2 = p2.second;
        if (c1 == 0 && c2 == 0) return y1 < y2;
        if (c1 == 0) return false;
        if (c2 == 0) return true;
        return y1 < y2;
    });

    for (int i = 0; i < m; i++) {
        int y = b[i].first;
        int ci = b[i].second;
        
        auto it = mp.lower_bound(y);
        if (it == mp.end()) continue;
        
        ans++;
        int x = (*it).first;
        mp[x]--;
        if (mp[x] == 0) mp.erase(x);
        if (ci != 0) {
            int new_x = max(x, ci);
            mp[new_x]++;
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