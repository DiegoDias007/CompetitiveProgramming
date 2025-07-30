// https://codeforces.com/contest/2004/problem/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

bool match(string s, string t) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (s[i] == t[j]) return true;
        }
    } 
    return false;
}

pair<char, char> get_key(string s) {
    sort(s.begin(), s.end());
    return {s[0], s[1]};
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> a(n);
    map<pair<char, char>, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[get_key(a[i])].push_back(i);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (x > y) swap(x, y);

        if (match(a[x], a[y])) {
            cout << y - x << endl;
            continue;
        }

        int ans = 1e8;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                string s = "";
                s += a[x][i];
                s += a[y][j];
                pair<char, char> key = get_key(s);
                if (mp[key].empty()) continue;
                auto it_greater = upper_bound(mp[key].begin(), mp[key].end(), y);
                int greater = (it_greater != mp[key].end()) ? *it_greater : -1;

                auto it_less = lower_bound(mp[key].begin(), mp[key].end(), y);
                int less = (it_less != mp[key].begin()) ? *(it_less - 1) : -1;

                if (greater != -1) ans = min(ans, abs(x - greater) + abs(y - greater));
                if (less != -1) ans = min(ans, abs(x - less) + (y - less));
            }
        }
        if (ans == 1e8) cout << -1 << endl;
        else cout << ans << endl;
    }
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