#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll a, b;
    cin >> a >> b;
    if (a % 2 == 0 && b % 2 == 1) {
        cout << -1 << endl;
        return;
    }

    if (a % 2 == 1 && b % 2 == 1) {
        cout << a * b + 1 << endl;
        return;
    }
    
    ll mult_2 = 0;
    ll b_copy = b;
    while (b_copy % 2 == 0) {
        b_copy /= 2;
        mult_2++;
    }

    if (a % 2 == 1 && mult_2 == 1) {
        cout << -1 << endl;
        return;
    }
    
    a *= b / 2;
    cout << a + 2 << endl;
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