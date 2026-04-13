#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x;
    return x;
}

void ans(char c) {
    cout << "! " << c << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> seen(n + 1, -1);
    for (int i = 0; i < n; i++) seen[a[i]] = i + 1;

    for (int i = 1; i <= n; i++) {
        if (seen[i] != -1) continue;

        int dif_i = (i % n) + 1;
        
        if (ask(i, dif_i) == 0) ans('A');
        else ans('B');
        return;
    }

    int i1 = seen[1], in = seen[n];

    int x1 = ask(i1, in);
    int x2 = ask(in, i1);

    if (x1 != n - 1) {
        if (x1 < n - 1) ans('A');
        else ans('B');
        return;
    }

    if (x1 != x2) ans('A');
    else ans('B'); 
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}