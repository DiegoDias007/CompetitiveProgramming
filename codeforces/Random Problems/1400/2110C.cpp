// https://codeforces.com/contest/2110/problem/C

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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i].first >> b[i].second;
    }

    vector<pair<int, int>> in(n);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            l++;
            r++;
        } else if (a[i] == -1) {
            r++;
        }

        int l_intersec = max(l, b[i].first);
        int r_intersec = min(r, b[i].second);
        if (l_intersec > r_intersec) {
            cout << -1 << endl;
            return;
        }

        l = l_intersec;
        r = r_intersec;
        in[i] = {l, r};
    }

    // depois de aplicar operacao em i
    int height = in[n - 1].first;
    for (int i = n - 1; i >= 0; i--) {
        int l_prev = 0, r_prev = 0;
        if (i > 0) {
            l_prev = in[i - 1].first;
            r_prev = in[i - 1].second;
        }

        if (a[i] == 1) {
            height--;
        } else if (a[i] == -1) {
            if (height >= l_prev && height <= r_prev) {
                a[i] = 0;
            } else {
                a[i] = 1;
                height--;
            }
        }

        assert(height >= l_prev);
        assert(height <= r_prev);
    }
    print_vec(a);
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