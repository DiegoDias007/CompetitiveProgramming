#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int ans(string& s, int n, int x) {
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (i < x && s[i] == '#') l = i;
        if (i > x && s[i] == '#') {
            r = i;
            break;
        }
    }
    if (l == -1 || r == -1) return 1;
    return min(l + 2, n - r + 1);
}

void solve() {
    int n, x;
    cin >> n >> x;
    x--;
    string s;
    cin >> s;

    string a = s, b = s;
    if (x > 0) a[x - 1] = '#';
    if (x < n - 1) b[x + 1] = '#';
    cout << max(ans(a, n, x), ans(b, n, x)) << endl;
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