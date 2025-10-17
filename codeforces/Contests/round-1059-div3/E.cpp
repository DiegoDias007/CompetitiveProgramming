#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> seen(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        seen[a[i]] = true;
    }

    int flag = -1;
    for (int x = 1; x <= n; x++) {
        if (!seen[x]) {
            flag = x;
            break;
        }
    }

    int first;
    if (flag != -1) first = flag;
    else first = a[0];
    
    vector<int> order;
    order.push_back(first);
    for (int x = 1; x <= n; x++) {
        if (x != first && x != a[n-1]) order.push_back(x);
    }
    order.push_back(a[n-1]);

    for (int i = 0; i < n && k--; i++) cout << order[i] << " ";
    cout << endl;
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