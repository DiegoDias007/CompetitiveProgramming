// https://codeforces.com/problemset/problem/1932/E

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
    string s;
    cin >> s;
    
    vector<int> ss(n);
    for (int i = 0; i < n; i++) {
        ss[i] = (i > 0 ? ss[i - 1] : 0) + (s[i] - '0');
    }

    vector<int> a(n + 10);
    for (int i = 0; i < n; i++) {
        int current = ss[n - i - 1] + a[i];
        a[i] = 0;
        for (int j = 0; j <= 10; j++) {
            if (!current) break;
            a[i + j] += current % 10;
            current /= 10;
        }
    }

    while (a.back() == 0) a.pop_back();
    for (int i = a.size() - 1; i >= 0; i--) cout << a[i];
    cout << endl;
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