#include <bits/stdc++.h>

#define endl "\n"
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    string s;
    getline(cin, s);
    int n = s.size();
    string ans = "";
    bool want = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') want = true;
        if (want && s[i] != ' ') {
            ans += s[i];
            want = false;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }

    return 0;
}