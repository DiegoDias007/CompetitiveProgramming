// https://codeforces.com/problemset/problem/1976/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll N, M;
    cin >> N >> M;
    ll n = N + M + 1;
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<char> took(n);
    vector<int> cant_a, cant_b;
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > b[i]) {
            if (N > 0) {
                sum += a[i];
                N--;
                took[i] = 'a';
            } else {
                sum += b[i];
                M--;
                cant_a.push_back(i);
                took[i] = 'b';
            }
        } else {
            if (M > 0) {
                sum += b[i];
                M--;
                took[i] = 'b';
            } else {
                sum += a[i];
                N--;
                cant_b.push_back(i);
                took[i] = 'a';
            }
        }
    }

    vector<ll> ans(n);
    ans.back() = sum;
    for (int i = 0; i < n - 1; i++) {
        if (took[i] == 'a') {
            auto ptr = upper_bound(cant_a.begin(), cant_a.end(), i);
            if (ptr == cant_a.end()) {
                ans[i] = sum - a[i] + a.back();
            } else {
                int idx = *ptr;
                ans[i] = sum - a[i] - b[idx] + a[idx] + b.back();
            }
        } else {
            auto ptr = upper_bound(cant_b.begin(), cant_b.end(), i);
            if (ptr == cant_b.end()) {
                ans[i] = sum - b[i] + b.back();
            } else {
                int idx = *ptr;
                ans[i] = sum - b[i] - a[idx] + b[idx] + a.back();
            }
        }
    }

    print_vec(ans);
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