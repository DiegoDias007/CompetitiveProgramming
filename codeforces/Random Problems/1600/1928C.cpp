// https://codeforces.com/problemset/problem/1928/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

set<int> find_divisors(int gap) {
    set<int> divisors;
    for (int k = 1; k * k <= gap; k++) {
        if (gap % (2*k) == 0) {
            divisors.insert(k);
            divisors.insert(gap / (2*k));
        }
    }
    return divisors;
}


void solve() {
    int n, x;
    cin >> n >> x;
    int dif = x - 1;
    int gap1 = n - dif - 1;
    int gap2 = n + dif - 1;
    set<int> divisors1 = find_divisors(gap1);
    set<int> divisors2 = find_divisors(gap2);
    set<int> ans;
    for (int d : divisors1) if (d >= x - 1) ans.insert(d);
    for (int d : divisors2) if (d >= x - 1) ans.insert(d);
    cout << ans.size() << endl;
    
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