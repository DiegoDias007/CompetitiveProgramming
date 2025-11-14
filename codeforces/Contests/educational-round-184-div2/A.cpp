#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int get_ans(vector<int>& a, int y, bool flag) {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (flag) ans += a[i] <= y;
        else ans += a[i] >= y;
    }
    return ans;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans1 = get_ans(a, x - 1, true);
    int ans2 = get_ans(a, x + 1, false);
    if (ans1 > ans2) cout << x-1 << endl;
    else cout << x + 1 << endl;
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