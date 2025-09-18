#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> n_children(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--; v--;
        if (x > y) {
            adj[u].push_back(v);
            n_children[v]++;
        } else {
            adj[v].push_back(u);
            n_children[u]++;
        }
    }

    queue<int> topo;
    for (int node = 0; node < n; node++) {
        if (n_children[node] == 0) topo.push(node);
    }

    vector<int> ans(n);
    int permutation = n;
    while (!topo.empty()) {
        int node = topo.front();
        topo.pop();
        ans[node] = permutation;
        permutation--;
        for (auto child : adj[node]) {
            n_children[child]--;
            if (n_children[child] == 0) topo.push(child);
        }
    }
    print_vec(ans);
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