// https://codeforces.com/problemset/problem/2121/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        b[i] = t[i] - '0';
    }

    int ans = 0;
    int i = 0;
    while (i < n && a[i] == b[i]) {
        ans += 2;
        i++;
    }

    bool end = false;
    if (i < n) {
        ans += abs(a[i] - b[i]) == 1;
        end = abs(a[i] - b[i]) >= 2;
        i++;
    }

    if (!end) {
        while (i < n && a[i] == 9 && b[i] == 0) {
            ans++;
            i++;
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