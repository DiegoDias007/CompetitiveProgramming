// https://codeforces.com/problemset/problem/2072/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int arit(int n) {
    return (1 + n) * n / 2;
}

void solve() {
    int k;
    cin >> k;

    bool flag = false;
    int base_x = 0;
    int base_y = 0;

    vector<pair<int, int>> a;
    a.push_back({0, 0});

    while (k > 0) {
        int l = 1, r = 499;
        int best = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int cur = arit(mid);
            if (cur <= k) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        k -= arit(best);
        if (!flag) {
            for (int i = 1; i <= best; i++) {
                a.push_back({base_x, base_y + i});
            }
            base_y += best;
        } else {
            for (int i = 1; i <= best; i++) {
                a.push_back({base_x + i, base_y});
            }
            base_x += best;
        }

        flag = !flag;
    } 

    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i].first << " " << a[i].second << endl;
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