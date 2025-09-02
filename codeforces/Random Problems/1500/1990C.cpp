// https://codeforces.com/problemset/problem/1990/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll operation(vector<int>& a, int n) {
    vector<int> new_a(n);
    vector<int> cnt(n + 1);
    int mad = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] >= 2 && a[i] > mad) mad = a[i];
        new_a[i] = mad;
    }
    a = new_a;
    return sum;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = operation(a, n);
    ans += operation(a, n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        ans += sum;
        sum -= a[i];
    }
    cout << ans << endl;
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