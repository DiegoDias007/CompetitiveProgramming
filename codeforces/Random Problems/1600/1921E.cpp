// https://codeforces.com/problemset/problem/1921/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int h, w, ra, ca, rb, cb;
    cin >> h >> w >> ra >> ca >> rb >> cb;
    if (ra >= rb) {
        cout << "DRAW" << endl;
        return;
    }
    
    bool alice_opposition = abs(ra - rb) % 2 == 1;
    if (alice_opposition) {
        int vert_dist = (rb - ra) / 2;
        int hor_dist;
        if (cb > ca) hor_dist = w - ca - 1;
        else hor_dist = ca - 2;
        if (abs(ca - cb) <= 1 || vert_dist >= hor_dist) cout << "ALICE" << endl;
        else cout << "DRAW" << endl;
    } else {
        int vert_dist = (rb - ra - 1) / 2;
        int hor_dist;
        if (ca > cb) hor_dist = w - cb - 1;
        else hor_dist = cb - 2;
        if (ca == cb || vert_dist >= hor_dist) cout << "BOB" << endl;
        else cout << "DRAW" << endl;
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