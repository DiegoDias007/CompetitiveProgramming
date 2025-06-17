#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt_0 = 0, cnt_1 = 0;
    for (int i = 0; i < n; i++) {
        cnt_0 += s[i] == '0';
        cnt_1 += s[i] == '1';
    }

    int dif = abs(cnt_0 - cnt_1);
    int mn = dif / 2;
    int mx = (cnt_0 / 2) + (cnt_1 / 2);
    if (mn <= k && k <= mx && (mn % 2 == k % 2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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