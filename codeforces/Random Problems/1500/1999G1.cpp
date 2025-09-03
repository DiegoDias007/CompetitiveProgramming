// https://codeforces.com/problemset/problem/1999/G1

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int l = 1, r = 999;
    int ok;
    while (l <= r) {
        int mid = (l + r) / 2;
        cout << "?" << " " << mid << " " << mid << endl << flush;
        int area;
        cin >> area;
        if (area == mid * mid) {
            ok = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << "! " << ok + 1 << endl;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}