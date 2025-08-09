// https://atcoder.jp/contests/abc418/tasks/abc418_b

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

double calc(string& t) {
    double n = t.size();
    double cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += t[i] == 't';
    }
    return (cnt - 2) / (n - 2);
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    double ans = 0;
    for (int i = 0; i < n; i++) {
        string t;
        for (int j = i; j < n; j++) {
            t += s[j];
            if (t.size() >= 3) {
                ans = max(ans, calc(t));
            }
        }
    }

    cout << fixed << setprecision(10);
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