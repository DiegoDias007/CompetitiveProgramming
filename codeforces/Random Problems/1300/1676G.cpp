#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

string s;
int n;
vector<vector<int>> adj;
vector<int> w, b;
int ans;

void dfs(int node) {
    w[node] += s[node] == 'W';
    b[node] += s[node] == 'B';
    for (auto child : adj[node]) {
        dfs(child);
        w[node] += w[child];
        b[node] += b[child];
    }

    ans += w[node] == b[node];
}


void solve() {
    cin >> n;
    adj.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
    }

    cin >> s;

    w.assign(n, 0), b.assign(n, 0);
    ans = 0;
    dfs(0);
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