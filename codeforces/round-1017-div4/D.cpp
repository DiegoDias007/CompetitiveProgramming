#include <bits/stdc++.h>

#define endl "\n"
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    string p, s;
    cin >> p >> s;
    int n = p.size(), m = s.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        char prev = p[i];
        int cnt1 = 0;
        while (i < n && p[i] == prev) {
            i++;
            cnt1++;
        }

        int cnt2 = 0;
        while (j < m && s[j] == prev) {
            cnt2++;
            j++;
        }

        if (cnt2 < cnt1 || cnt2 > cnt1 * 2) {
            cout << "NO" << endl;
            return;
        }
    }

    if (i == n && j == m) {
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
    cin.ignore();
    while (t--) {
        solve();
    }

    return 0;
}