#include <bits/stdc++.h>

#define endl '\n'
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
    
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < k; i++) {
        cnt0 += s[i] == '0';
        cnt1 += s[i] == '1';
        cnt2 += s[i] == '2';
    }

    vector<char> ans(n, '+');
    for (int i = 0; i < cnt0; i++) {
        ans[i] = '-';
    }

    for (int i = n - 1; i >= n - cnt1; i--) {
        ans[i] = '-';
    }

    if (k == n) {
        for (int i = 0; i < n; i++) {
            ans[i] = '-';
        }
    } else {
        for (int i = cnt0; i < cnt0 + cnt2; i++) {
            ans[i] = '?';
        }

        int idx = n - cnt1 - 1;
        for (int i = idx; i > idx - cnt2; i--) {
            ans[i] = '?';
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i];
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