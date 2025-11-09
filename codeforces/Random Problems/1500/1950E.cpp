#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

bool check(string& s, int n, int d) {
    int cnt = 0;
    for (int i = d; i < n; i++) {
        cnt += s[i] != s[i % d];
    }
    return cnt <= 1;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> divisors;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) divisors.push_back(i);
    }

    for (auto d : divisors) {
        string t = s;
        for (int i = d; i < n && i < 2*d; i++) swap(t[i], t[i % d]);
        
        bool ok = check(s, n, d) || check(t, n, d);
        if (ok) {
            cout << d << endl;
            return;
        }
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