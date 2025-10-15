// https://codeforces.com/problemset/problem/2147/C

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
    
    vector<bool> suf(n);
    suf.back() = true;
    int cnt = s.back() == '0' ? 0 : 1e5;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = cnt <= 1;
        if (s[i] == '1') cnt++;
        else cnt = 0;
    }

    vector<int> dp(n);
    dp[0] = s[0] == '0';
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') continue;
        
        if (s[i - 1] == '0') {
            dp[i] = 1;
        } else {
            if (i >= 2 && s[i - 2] == '0') {
                dp[i] = 2 - dp[i - 2];
            } else {
                dp[i] = 2;
            }
        }

        if (dp[i] == 2 && !suf[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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